#ifndef XSQLITEMANAGER_H
#define XSQLITEMANAGER_H

#include "xdatabase.h"

class XSQLiteManager
{
public:
    static XSQLiteManager *getDBInstance();
private:
    XSQLiteManager();
    ~XSQLiteManager();
public:
    bool initDBManager(void);
private:
    static XSQLiteManager *m_pInstance;
    XDataBase *m_db;
};

#endif // XSQLITEMANAGER_H
