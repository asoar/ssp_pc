#include "dbcomm.h"

#define kDBConnectName "my_conn"
DBComm::DBComm()
{
    m_dbname = "test.db";
    m_username = "anpb";
    m_password = "anpb";
    m_dbPath = QDir::homePath() + "/DB/";
}

DBComm::~DBComm()
{

}

bool DBComm::openDB(const QString &dbname, const QString &username, const QString &password, const QString &dbPath)
{
    if(dbname.compare("") != 0) m_dbname = dbname;
    if(username.compare("") != 0) m_username = username;
    if(password.compare("") != 0) m_password = password;
    if(dbPath.compare("") != 0) m_dbPath = dbPath;

    QDir dir(m_dbPath);
    if (!dir.exists()) dir.mkdir(m_dbPath);

    //数据库建立连接
    if (QSqlDatabase::contains(kDBConnectName)) {//检查连接是否存在
        this->m_sqlite = QSqlDatabase::database(kDBConnectName);
    } else {
        this->m_sqlite = QSqlDatabase::addDatabase("QSQLITE", kDBConnectName);
        this->m_sqlite.setDatabaseName(QString("%1%2").arg(m_dbPath).arg(m_dbname));
        this->m_sqlite.setHostName("localhost"); //数据库主机名
        this->m_sqlite.setUserName(m_username);//数据库登入用户名
        this->m_sqlite.setPassword(m_password);//数据库登入密码
    }
    if (!this->m_sqlite.open())  return false;

    return true;
}

void DBComm::closeDB()
{
    this->m_sqlite.close();
}

#pragma mark 判断数据表是否存在
bool DBComm::isTableExist(const QString &tableName)
{
    this->m_sqlite.tables().contains(tableName);
    return false;
}

#pragma mark 创建数据表
bool DBComm::createTable(const QString &sql)
{
    QSqlQuery query;
    query.exec(sql);
    return this->error(query);
}

#pragma mark 插入记录
bool DBComm::insertRecord(const QString &sql)
{
    QSqlQuery query(sql);
    return this->error(query);
}

#pragma mark 删除记录
bool DBComm::deleteRecord(const QString &sql)
{
    QSqlQuery query(sql);
    return this->error(query);
}

#pragma mark 更新记录
bool DBComm::updateRecord(const QString &sql)
{
    QSqlQuery query(sql);
    return this->error(query);
}

#pragma mark 查询记录
QList<QMap<QString, QVariant> > DBComm::selectRecord(const QString &sql)
{
    QSqlQuery query(sql);
    QList<QMap<QString, QVariant> > list;
    QMap<QString, QVariant> map;
    QSqlRecord record = query.record();
    int cnt = record.count();
    while (query.next()) {
        for (int i = 0; i < cnt; ++i) {
            map.insert(record.fieldName(i),query.value(i));
        }
        list.append(map);
    }
    return list;
}

#pragma mark 开启事务
bool DBComm::transaction()
{
    qDebug() << "transaction";
    return this->m_sqlite.transaction();
}

#pragma mark 提交事务
bool DBComm::commit()
{
    qDebug() << "commit";
    return this->m_sqlite.commit();
}

#pragma mark 事务回滚
bool DBComm::rollback()
{
    qDebug() << "rollback";
    return this->m_sqlite.rollback();
}

#pragma mark sql执行故障信息
bool DBComm::error(const QSqlQuery &query)
{
#ifdef QT_DEBUG
    QStringList info;
    info << "【sql=>" << query.lastQuery() << ", Error=>" << query.lastError().text() << "】";
    qDebug() << info;
#endif
    return query.lastError().type() == QSqlError::NoError;
}
