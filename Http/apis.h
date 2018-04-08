#ifndef APIS
#define APIS

#include <QString>

const QString kApiExtension = QString(".dtm");
//授权接口
const QString kApiBaseAuthHost = QString("https://ufssp.ikaihuo.com:8443");
//数据接口
const QString kApiBaseDataHost = QString("https://ufssp.ikaihuo.com:8443");

//手机号登陆
const QString kPathAuthLogin = kApiBaseAuthHost + QString("/auth/login") + kApiExtension;

//发送手机验证码
const QString kPathUserSendCode = kApiBaseAuthHost +QString("/auth/send_verify_code") + kApiExtension;

//当前技统用户服务的活动列表
const QString kPathDataEventList = kApiBaseAuthHost+QString("/data/event_list") + kApiExtension;

//检查活动状态
const QString kPathDataCheckEvent = kApiBaseAuthHost + QString("/data/check_event") + kApiExtension;

//数据上传
const QString kPathDataUpload = kApiBaseAuthHost + QString("/data/upload") + kApiExtension;

//数据上传完成
const QString kPathDataFinishedUp = kApiBaseAuthHost + QString("/data/finished_up") + kApiExtension;

//刷新token
const QString kPathAuthRefreshToken = kApiBaseAuthHost + QString("/auth/refresh_token") + kApiExtension;

//比赛状态
const QString kPathMatchStatu = kApiBaseAuthHost + QString("/data/event/status") + kApiExtension;

//比赛信息
const QString kPathMatchInfo = kApiBaseAuthHost + QString("/data/event/info") + kApiExtension;

//数据记录上传
const QString kPathUploadRecord = kApiBaseAuthHost + QString("/data/event/data") + kApiExtension;

//修改球员信息
const QString kPathModifyPlayer = kApiBaseAuthHost + QString("/data/player/info") + kApiExtension;

#endif // APIS

