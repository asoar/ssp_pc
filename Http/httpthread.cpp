#include "httpthread.h"

HttpThread::HttpThread(QNetworkAccessManager *manager, QNetworkReply *reply, int timeoutms, QObject *parent)
    :QThread(parent),m_netManager(manager),m_timeOutms(timeoutms),m_reply(reply)
{
    m_waitTimeOut = false;
    m_isWaitTimeOut = false;
}

HttpThread::~HttpThread()
{
}

void HttpThread::run()
{
    m_isWaitTimeOut = waitForConnect();
}

bool HttpThread::waitForConnect()
{
    QEventLoop eventLoop;
    QTimer * timer = NULL;
    m_waitTimeOut = false;
    bool bWaitTimeOut = false;
    if (m_timeOutms > 0) {
        timer = new QTimer;
        connect(timer, SIGNAL(timeout()), this, SLOT(slot_waitTimeout()));
        timer->setSingleShot(true);
        timer->start(m_timeOutms);
        connect(this, SIGNAL(sig_waitTimeout()), &eventLoop, SLOT(quit()));
    }

    connect(m_netManager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    if (m_reply != NULL) {
        connect(m_reply, SIGNAL(readyRead()), &eventLoop, SLOT(quit()));
    }
    eventLoop.exec();

    if (timer != NULL) {
        timer->stop();
        delete timer;
        timer = NULL;
    }

    bWaitTimeOut = m_waitTimeOut;
    m_waitTimeOut = false;
    return !bWaitTimeOut;
}

void HttpThread::slot_waitTimeout()
{
    m_waitTimeOut = true;
    emit sig_waitTimeout();
}

bool HttpThread::getIsWaitTimeOut() const
{
    return m_isWaitTimeOut;
}
