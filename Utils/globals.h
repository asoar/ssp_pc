#ifndef GLOBALS
#define GLOBALS

#include <QDir>
#include <QDate>
#include <QString>

// 技统版本号
const QString SSP_VERSION = QString("v1.0.1");
// build版本号
const int SSP_BUILD_VERSION = 1014;
// 数据库版本号
const int SSP_DB_VERSION = QDate::currentDate().year()+SSP_BUILD_VERSION;//base year
// 数据库文件路径
const QString SSP_DB_PATH = QDir::homePath() + "/SSPDataBase/";
// 数据库文件名
const QString SSP_DB_NAME = "SSP_DB.db";
// 数据库登入用户名
const QString SSP_DB_USER_NAME = "gyound";
// 数据库登入密码
const QString SSP_DB_USER_PASSWORD = "123456";


#endif // GLOBALS

