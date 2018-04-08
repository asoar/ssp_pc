#ifndef CONSTS
#define CONSTS

#include <QString>
#include <QDate>

#ifdef QT_DEBUG
#define DEBUG_MODE
#endif

// 版本号
const QString SSP_VERSION = QString("v1.0.1");
const int SSP_BUILD_VERSION = 1014;
const int SSP_DB_VERSION = QDate::currentDate().year()+SSP_BUILD_VERSION;//base year
// 软件名
const QString SOFTWARE_NAME = QString("神启闪电(PC)技术统计软件");
// 硬件端口
const unsigned int BROADCAST_PORT = 36879;
// 遥控器端口
const int REMOTECTRL_PORT = 10125;
const int REMOTECTRL_24S_PORT = 10126;


#endif // CONSTS

