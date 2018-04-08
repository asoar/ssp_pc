#ifndef LOG_H
#define LOG_H

#include <QMap>
#include <QVariant>
#include <QtCore>

class Log
{
private:
    Log();
public:
    static void printQMap(const QMap<QString, QVariant> &map);
    static void print(const QVariant &url);
};

#endif // LOG_H
