#include "xsqlitemanager.h"

//访问量大==采用饿汉模式
XSQLiteManager* XSQLiteManager::m_pInstance = new XSQLiteManager();
XSQLiteManager *XSQLiteManager::getDBInstance()
{
    return m_pInstance;
}

XSQLiteManager::XSQLiteManager()
{
    m_db = new XDataBase();
}

XSQLiteManager::~XSQLiteManager()
{
    delete m_db;
    m_db = NULL;
}

bool XSQLiteManager::initDBManager()
{
    m_db->createDBConn();
    return m_db->openDB();
}
