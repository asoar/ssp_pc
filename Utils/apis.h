#ifndef APIS
#define APIS

#include <QString>

const QString kApiExtension = QString(".dtm");

//授权接口===测试服务器
//const QString kApiBaseAuthHost = QString("http://192.168.1.153:8082");
//授权接口===正式服务器
const QString kApiBaseAuthHost = QString("https://ufssp.ikaihuo.com:8443");
//手机号登陆
const QString kPathAuthLogin = kApiBaseAuthHost + QString("/auth/login") + kApiExtension;
//发送手机验证码
const QString kPathUserSendCode = kApiBaseAuthHost +QString("/auth/send_verify_code") + kApiExtension;
//刷新用户token
const QString kRefreshToken = kApiBaseAuthHost + QString("/auth/refresh_token") + kApiExtension;
//退出登录
const QString kPathAuthLoginOut = kApiBaseAuthHost + QString("/auth/logout") + kApiExtension;

//当前技统用户服务的活动列表
const QString kPathDataEventList = kApiBaseAuthHost+QString("/data/event_list") + kApiExtension;
//检查活动状态
const QString kPathDataCheckEvent = kApiBaseAuthHost + QString("/data/check_event") + kApiExtension;
//数据上传
const QString kPathDataUpload = kApiBaseAuthHost + QString("/data/upload") + kApiExtension;
//数据上传完成
const QString kPathDataFinishedUp = kApiBaseAuthHost + QString("/data/finished_up") + kApiExtension;
//数据一条删除
const QString kPathDataDelete = kApiBaseAuthHost + QString("/data/delete") + kApiExtension;

//客服信息
const QString kPath = kApiBaseAuthHost + QString("/common/service_info") + kApiExtension;



#endif // APIS

