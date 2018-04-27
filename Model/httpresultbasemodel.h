#ifndef HTTPRESULTBASEMODEL_H
#define HTTPRESULTBASEMODEL_H

#include "basemodel.h"


class HttpResultBaseModel : public BaseModel
{
public:
    HttpResultBaseModel();
public:
    QString ec;//服务器返回的 结果码
    QString em;//服务器返回的 描述信息
};

#endif // HTTPRESULTBASEMODEL_H
