#ifndef XDATABASE_H
#define XDATABASE_H

#include "../Utils/utils.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class XDataBase
{
public:
    XDataBase();
    ~XDataBase();
public:
    void setDBInfo(const QString &dbname, const QString &username, const QString &password);
    void createDBConn(void);
    bool openDB(void);
    void closeDB(void);
private:
    QString m_dbname;
    QString m_username;
    QString m_password;
    QSqlDatabase m_sql;
};

#endif // XDATABASE_H
