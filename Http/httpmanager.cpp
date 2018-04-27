#include "httpmanager.h"

HttpManager *HttpManager::pInstance_s = new HttpManager;//采用饿汉单例模式，线程安全
HttpManager *HttpManager::instance()
{
    return pInstance_s;
}

HttpManager::HttpManager()
{
}

#pragma mark =====手机号密码登陆请求======
void HttpManager::httpPhonePasswordLoginRequest(QMap<QString, QString> params)
{


//    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

//    m_request.setUrl(QUrl("https://ufssp.ikaihuo.com:8443/auth/login.dtm?phone=18001221261&type=1&pwd=123456"));
//    m_manager->get(m_request);
//    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinish(QNetworkReply*)));
//    qDebug() << "m_manager;
}

#pragma mark =====手机号验证码登陆请求=====
void HttpManager::httpPhoneVerifyLoginRequest(QMap<QString, QString> params)
{

}

//void HttpManager::httpRequest(QUrl url)
//{
//    m_request.setUrl(url);

//}

void HttpManager::replyFinish(QNetworkReply *reply)
{
    qDebug() << reply->manager();
    if(reply && reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            int len = data.size();
            QString s=QString::fromStdString(data.toStdString());
            qDebug() << s;
        } else {
            qDebug() << reply->errorString();
        }
        reply->close();
}
