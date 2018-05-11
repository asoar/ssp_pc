#ifndef HTTPTHREAD_H
#define HTTPTHREAD_H

#include "../Utils/config.h"
#include <QThread>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpThread : public QThread
{
    Q_OBJECT
public:
    HttpThread(QNetworkAccessManager *manager,QNetworkReply * reply,int timeoutms,QObject *parent = 0);
    ~HttpThread();
protected:
    virtual void run();
private:
    bool waitForConnect();
protected slots:
    void slot_waitTimeout();
signals:
    void sig_waitTimeout();
public:
    QByteArray getBa() const;
    bool getIsWaitTimeOut() const;
private:
    QNetworkAccessManager *m_netManager;
    QNetworkReply * m_reply;
    int m_timeOutms;
    bool m_waitTimeOut;
    bool m_isWaitTimeOut;
};



#endif // HTTPTHREAD_H
