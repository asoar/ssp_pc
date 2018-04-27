#ifndef HTTPAPI_H
#define HTTPAPI_H

#include <QUrl>

class HttpApi
{
public:
    HttpApi(QUrl url, int tag);

inline QUrl getUrl() const
{
    return this->m_url;
}

inline int getTag() const
{
    return this->m_tag;
}

private:
    QUrl m_url;
    int  m_tag;
};

#endif // HTTPAPI_H
