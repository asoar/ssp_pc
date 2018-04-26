#include "commsimple.h"

//旧协议
unsigned char oldProtocol[] = {
    //5个字节为协议头
    0xAA, 0x55, 0x01, 0xF2, 0x00,
    //主队比分,空,客队比分,局数,主队局分,客队局分
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    //24s,分,秒,1/10秒,球权,喇叭
    0x18, 0x0A, 0x00, 0x00, 0x6F, 0x9D,
    //主队换人,客队换人,主队犯规,客队犯规,主队暂停,客队暂停
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    //其他
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFA
};

//最新协议
//第36个字节为控制机器的灭灯功能位:
//0x00: 0000 0000 表示全亮
//第一位表示大时间控制:0x01--->0000 0001 表示大时间全灭
//第二位表示24秒时间控制:0x02->0000 0010 表示24秒全灭
unsigned char newestProtocol[] = {
    //5个字节为协议头
    0xBB, 0x33, 0x22, 0xF1, 0x00,
    //主队比分,空,客队比分,局数,主队局分,客队局分
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    //24s,分,秒,1/10秒,球权,喇叭
    0x18, 0x0A, 0x00, 0x00, 0x6F, 0x9D,
    //主队换人,客队换人,主队犯规,客队犯规,主队暂停,客队暂停
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    //其他
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFC
};

CommSimple::CommSimple()
{
    m_pUDPClient = new QUdpSocket();
    this->isCheckNewestProtocol(false);//默认是旧协议
}

CommSimple::~CommSimple()
{

}

void CommSimple::isCheckNewestProtocol(bool flag)
{
    if (flag) {
        for (int i = 0; i < 37; i++) {//切换使用新协议
            m_dataProtocol[i] = newestProtocol[i];
        }
    } else {
        for (int i = 0; i < 37; i++) {//切换使用旧协议
            m_dataProtocol[i] = oldProtocol[i];
        }
    }
}

#pragma mark 设置主队比分
void CommSimple::setHomeScore(unsigned char score)
{
    m_dataProtocol[5] = score;
}

#pragma mark 设置客队比分
void CommSimple::setGuestScore(unsigned char score)
{
    m_dataProtocol[7] = score;
}

#pragma mark 设置局数
void CommSimple::setGameCount(unsigned char count)
{
    if (count > 5) {
        count = 5;
    }
    m_dataProtocol[8] = count;
}

#pragma mark 设置主队局分
void CommSimple::setHomeGameScore(unsigned char score)
{
    m_dataProtocol[9] = score;
}

#pragma mark 设置客队局分
void CommSimple::setGuestGameScore(unsigned char score)
{
    m_dataProtocol[10] = score;
}

#pragma mark 设置主队犯规数
void CommSimple::setHomeFoulCount(unsigned char count)
{
    if (count > 9) {
        count = 9;
    }
    m_dataProtocol[19] = count;
}

#pragma mark 设置客队犯规数
void CommSimple::setGuestFoulCount(unsigned char count)
{
    if (count > 9) {
        count = 9;
    }
    m_dataProtocol[20] = count;
}

#pragma mark 设置主队暂停数
void CommSimple::setHomePauseCount(unsigned char count)
{
    if (count > 4) {
        count = 4;
    }
    m_dataProtocol[21] = count;
}

#pragma mark 设置客队暂停数
void CommSimple::setGuestPauseCount(unsigned char count)
{
    if (count > 4) {
        count = 4;
    }
    m_dataProtocol[22] = count;
}

#pragma mark 设置24s
void CommSimple::setAttackSecond(unsigned char second)
{
    m_dataProtocol[11] = second;
}

#pragma mark 设置分钟
void CommSimple::setMinute(unsigned char minute)
{
    m_dataProtocol[12] = minute;
}

#pragma mark 设置秒
void CommSimple::setSecond(unsigned char second)
{
    m_dataProtocol[13] = second;
}

#pragma mark 设置十分之一秒
void CommSimple::set1_10Second(unsigned char second)
{
    m_dataProtocol[14] = second;
}

#pragma mark 设置球权:YES表示主队球权，NO表示客队球权
void CommSimple::setBallControl(bool isHomeTeam)
{
    if (isHomeTeam) {
        m_dataProtocol[15] = 0x6F;
    } else {
        m_dataProtocol[15] = 0xEF;
    }
}

#pragma mark 设置喇叭:YES表示开启蜂鸣器,NO则反
void CommSimple::setDing(bool isDing)
{
    if (isDing) {
        m_dataProtocol[16] = 0xFF;
    } else {
        m_dataProtocol[16] = 0x00;
    }
}

#pragma mark ====设置关闭机器大时间显示====
void CommSimple::setCloseBigTimeLed(void)
{
    m_dataProtocol[35] = (m_dataProtocol[35] | (1<<0));//1左移0位将控制位set进去
}

#pragma mark ====设置关闭机器进攻时间显示====
void CommSimple::setCloseAttackTimeLed(void)
{
    m_dataProtocol[35] = (m_dataProtocol[35] | (1<<1));//将控制位set进去
}

#pragma mark 发送数据给机器
void CommSimple::sendData(void)
{
    m_pUDPClient->writeDatagram((char *)m_dataProtocol, 37, kBroadcastIP, BROADCAST_PORT);
}
