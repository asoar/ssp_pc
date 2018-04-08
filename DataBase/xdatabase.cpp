#include "xdatabase.h"
#include <QDebug>

#define kDBConnection "my_conn"
XDataBase::XDataBase()
{
    m_dbname = "MyDataBase";
    m_username = "linuxsex.com";
    m_password = "123456";
}

XDataBase::~XDataBase()
{

}

void XDataBase::setDBInfo(const QString &dbname, const QString &username, const QString &password)
{
    m_dbname = dbname;
    m_username = username;
    m_password = password;
}

void XDataBase::createDBConn(void)
{
    QString path = QDir::homePath() + "/SSPDataBase/";
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkdir(path);
    }

    //数据库建立连接
    if (QSqlDatabase::contains(kDBConnection)) {//检查连接是否存在
        m_sql = QSqlDatabase::database(kDBConnection);
    } else {
        m_sql = QSqlDatabase::addDatabase("QSQLITE", kDBConnection);
        m_sql.setDatabaseName(QString("%1%2%3%4").arg(path).arg(m_dbname).arg(SSP_DB_VERSION).arg(".db"));
        m_sql.setUserName(m_username);
        m_sql.setPassword(m_password);
    }
}

bool XDataBase::openDB()
{
    if (!m_sql.open()) {
        Log::print("Open database failed!");
        return false;
    } else {
        return true;
    }
}

void XDataBase::closeDB(void)
{
    m_sql.close();
}
