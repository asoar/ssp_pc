#include "dbmanager.h"

DBManager *DBManager::pInstance = new DBManager();
DBManager *DBManager::instance()
{
    return pInstance;
}

DBManager::DBManager(QObject *parent)
    :QObject(parent)
{

}

DBManager::~DBManager()
{

}
