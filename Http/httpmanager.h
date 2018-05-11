#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include "httpthread.h"
#include "../Utils/apis.h"
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonParseError>

#define kHttpManager HttpManager::instance()
class HttpManager : public QObject
{
    Q_OBJECT
public:
    static HttpManager* instance();
private:
    HttpManager(QObject *parent=0);
    ~HttpManager();
    static HttpManager *pInstance;
private:
    QString api(QString host, QMap<QString, QVariant> params);
public:
    /** 手机号密码登陆请求*/
    bool httpPhonePasswordLoginRequest(QMap<QString, QVariant> params);
    /** 手机号验证码登陆请求*/
    void httpPhoneVerifyLoginRequest(QMap<QString, QVariant> params);
    /** 验证码请求*/
    void httpVerifyCodeRequest(QMap<QString, QVariant> params);
    /** 刷新Token请求*/
    void httpRefreshTokenRequest(QMap<QString, QVariant> params);
    /** 退出账号请求*/
    void httpLoginOutRequest(QMap<QString, QVariant> params);

    /** 赛事活动列表请求*/
    void httpDataEventListRequest(QMap<QString, QVariant> params);
    /** 赛事状态检查请求*/
    void httpDataCheckRequest();
    /** 数据上传*/
    void httpDataUpLoadRequest();
    /** 数据删除*/
    void httpDataDeleteRequest();
    /** 数据上传完成*/
    void httpDataUpLoadOverRequest();

    /** 发送get请求*/
    QNetworkReply::NetworkError sendGetRequest(QString urlStr, QByteArray & ba, int timeOutms=3000);
    /**
     * @brief sendPostRequest 发送post请求
     * @param website  网址
     * @param methodName 方法名称
     * @param param 参数
     * @param postBa    post数据
     * @param code      返回代码
     * @param message   返回信息
     * @param data      返回数据
     * @param timeOutms 超时时间
     * @return 返回错误代码
     */
    QNetworkReply::NetworkError sendPostRequest(QString website,const QByteArray & postBa, QByteArray& retBa, int timeOutms=3000);
protected slots:
    void slot_error(QNetworkReply::NetworkError code);
private:
    QNetworkAccessManager *manager;
    QNetworkReply::NetworkError m_errCode;
};

#endif // HTTPMANAGER_H
