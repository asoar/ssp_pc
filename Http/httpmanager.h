#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include "Utils/config.h"

#define HTTP_ACCOUNTLOGIN_REQUEST_TAG 1000
#define HTTP_PHONELOGIN_REQUEST_TAG   1001

#define HttpManagerRequest HttpManager::instance();
class HttpManager : public QObject
{
    Q_OBJECT
public:
    static HttpManager *instance();
private:
    HttpManager();
    static HttpManager* pInstance_s ;
public slots:
    void replyFinish(QNetworkReply *reply);
public:
    /** 手机号密码登陆请求*/
    void httpPhonePasswordLoginRequest(QMap<QString, QString> params);
    /** 手机号验证码登陆请求*/
    void httpPhoneVerifyLoginRequest(QMap<QString, QString> params);
//    /** 验证码请求*/
//    void httpVerifyCodeRequest(QMap params);
//    /** 刷新Token请求*/
//    void httpRefreshTokenRequest(QMap params);
//    /** 退出账号请求*/
//    void httpLoginOutRequest(QMap params);

//    /** 赛事活动列表请求*/
//    void httpDataEventListRequest(QMap params);
//    /** 赛事状态检查请求*/
//    void httpDataCheckRequest();
//    /** 数据上传*/
//    void httpDataUpLoadRequest();
//    /** 数据删除*/
//    void httpDataDeleteRequest();
//    /** 数据上传完成*/
//    void httpDataUpLoadOverRequest();
};

#endif // HTTPMANAGER_H
