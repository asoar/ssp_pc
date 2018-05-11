#include "httpmanager.h"

HttpManager *HttpManager::pInstance = new HttpManager();
HttpManager *HttpManager::instance()
{
    return pInstance;
}

HttpManager::HttpManager(QObject *parent)
    :QObject(parent)
{
    manager = new QNetworkAccessManager();
    m_errCode= QNetworkReply::NoError;
}

HttpManager::~HttpManager()
{
    manager->deleteLater();
}

#pragma mark =====拼接API=====
QString HttpManager::api(QString host, QMap<QString, QVariant> params)
{
    QMap<QString,QVariant>::iterator it;
    QString urlStr = host + "?";
    for ( it = params.begin(); it != params.end(); ++it ) {
        urlStr = urlStr + it.key() + "=" + it.value().toString() + "&";
    }
    urlStr = urlStr.left(urlStr.length() - 1);

    return urlStr;
}

#pragma mark =====手机号密码登陆请求======
bool HttpManager::httpPhonePasswordLoginRequest(QMap<QString, QVariant> params)
{
    QByteArray buffer;
    QString loginUrl = api(kPathAuthLogin, params);
    QNetworkReply::NetworkError ret = this->sendGetRequest(loginUrl,buffer, 10000);
    QJsonObject doucment = QJsonDocument::fromJson(buffer).object();

    if(ret == QNetworkReply::NoError) {
        //保存token和userId
        QJsonObject data = doucment.value("data").toObject();
        if(doucment.value("ec").toInt() == 200){
            kSettings.setValue(tokenKey, data.value(tokenKey).toString());
            kSettings.setValue(userIdKey, QString::number(data.value(userIdKey).toDouble(), 10, 0));
        }
        return true;
    } else {
        qDebug() << "网络错误，请检查网络!";
        return false;
    }
}

#pragma mark =====手机号验证码登陆请求======
void HttpManager::httpPhoneVerifyLoginRequest(QMap<QString, QVariant> params)
{

}

#pragma mark =====验证码请求======
void HttpManager::httpVerifyCodeRequest(QMap<QString, QVariant> params)
{

}

#pragma mark =====刷新Token请求======
void HttpManager::httpRefreshTokenRequest(QMap<QString, QVariant> params)
{

}

#pragma mark =====退出账号请求======
void HttpManager::httpLoginOutRequest(QMap<QString, QVariant> params)
{

}

#pragma mark =====赛事活动列表请求======
void HttpManager::httpDataEventListRequest(QMap<QString, QVariant> params)
{

}

#pragma mark =====赛事状态检查请求======
void HttpManager::httpDataCheckRequest()
{

}

#pragma mark =====数据上传======
void HttpManager::httpDataUpLoadRequest()
{

}

#pragma mark =====数据删除======
void HttpManager::httpDataDeleteRequest()
{

}

#pragma mark =====数据上传完成======
void HttpManager::httpDataUpLoadOverRequest()
{

}

QNetworkReply::NetworkError HttpManager::sendGetRequest(QString urlStr, QByteArray &buffer,int timeOutms)
{
    QNetworkReply::NetworkError retError = QNetworkReply::NoError;
    m_errCode = QNetworkReply::NoError;
    QNetworkRequest request;
    QUrl url(urlStr);
    request.setUrl(url);
    QNetworkReply *reply = manager->get(request);
    connect(reply,static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&HttpManager::slot_error);
    QEventLoop eventLoop;
    HttpThread *thread = new HttpThread(manager,reply,timeOutms);
    connect(thread, &HttpThread::finished,&eventLoop,&QEventLoop::quit);
    thread->start();
    eventLoop.exec();

    if(thread->getIsWaitTimeOut()) {
        buffer = reply->readAll();
    } else {
        m_errCode=QNetworkReply::TimeoutError;
    }
    thread->deleteLater();
    delete reply;
    delete thread;
    thread = NULL;
    retError = m_errCode;
    m_errCode= QNetworkReply::NoError;
    return retError;
}

QNetworkReply::NetworkError HttpManager::sendPostRequest(QString website, const QByteArray &postBa, QByteArray &retBa, int timeOutms)
{
    QString urlStr = website;
    QNetworkReply::NetworkError retError = QNetworkReply::NoError;
    m_errCode= QNetworkReply::NoError;
    QNetworkRequest request;
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1SslV3);
    request.setSslConfiguration(config);
    QUrl url(urlStr);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader,postBa.length());
    QNetworkReply *reply = manager->post(request,postBa);
    connect(reply,static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&HttpManager::slot_error);
    QEventLoop eventLoop;
    HttpThread * thread = new HttpThread(manager,reply,timeOutms);
    connect(thread, &HttpThread::finished,&eventLoop,&QEventLoop::quit);
    thread->start();
    eventLoop.exec();

    if(thread->getIsWaitTimeOut()) {
        retBa = reply->readAll();
    } else {
        m_errCode = QNetworkReply::TimeoutError;
    }
    thread->deleteLater();
    delete reply;
    delete thread;
    thread = NULL;
    retError = m_errCode;
    m_errCode= QNetworkReply::NoError;
    return retError;
}

void HttpManager::slot_error(QNetworkReply::NetworkError code)
{
    m_errCode = code;
}
