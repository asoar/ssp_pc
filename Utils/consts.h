#ifndef CONSTS
#define CONSTS

#include <QSettings>


//获取实际屏幕大小
#define kScreenW QApplication::desktop()->screenGeometry()->width()
#define kScreenH QApplication::desktop()->screenGeometry()->height()
//可获取虚拟屏幕大小
#define kVirtualScreenW QApplication::desktop()->width()
#define kVirtualScreenH QApplication::desktop()->height()

#define TextLocal(a) QString::fromLocal8Bit(a)

#pragma mark ======底层通信======
#define kBroadcastIP  QHostAddress("255.255.255.255")
#define BROADCAST_PORT 36879


#define kSettings QSettings("settings.ini", QSettings::IniFormat)
#define dataKey "data"
#define tokenKey "token"
#define userIdKey "userId"


#endif // CONSTS

