#ifndef DBCOMM_H
#define DBCOMM_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDir>
#include <QDebug>


//该类作为数据库底层类，不涉及业务，不拼接sql
class DBComm
{
public:
    DBComm();
    ~DBComm();
public:
    /** 打开数据库*/
    bool openDB(const QString &dbname = 0, const QString &username = 0, const QString &password = 0, const QString &dbPath = 0);
    /** 关闭数据库*/
    void closeDB();

    /** 判断数据表是否已经存在*/
    bool isTableExist(const QString &tableName);
    /** 创建数据表，sql必须完整*/
    bool createTable(const QString &sql);
    /** 插入记录*/
    bool insertRecord(const QString &sql);
    /** 删除记录*/
    bool deleteRecord(const QString &sql);
    /** 更新记录*/
    bool updateRecord(const QString &sql);
    /** 查询记录*/
    QList<QMap<QString, QVariant> > selectRecord(const QString &sql);

    /** 开启事务*/
    bool transaction();
    /** 提交事务*/
    bool commit();
    /** 事务回滚*/
    bool rollback();
private:
    /** 故障信息*/
    bool error(const QSqlQuery &query);
private:
    QString m_dbname;
    QString m_username;
    QString m_password;
    QString m_dbPath;
    QSqlDatabase m_sqlite;
};

#endif // DBCOMM_H
