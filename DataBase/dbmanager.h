#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>

#define kDBManager DBManager::instance()
class DBManager : public QObject
{
    Q_OBJECT
private:
    static DBManager* instance();
private:
    DBManager(QObject *parent=0);
    ~DBManager();
    static DBManager *pInstance;

signals:

public slots:
};

#endif // DBMANAGER_H
