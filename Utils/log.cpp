#include "log.h"
#include <QDebug>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

Log::Log()
{

}
void Log::printQMap(const QMap<QString, QVariant> &map)
{
#ifdef QT_DEBUG
    QMapIterator<QString, QVariant> i(map);
    while (i.hasNext()) {
        i.next();
        qDebug() << "【 key=>" << i.key() << ": val=>" << i.value() << "】\t";
    }
#endif
}

void Log::print(const QVariant &data)
{
#ifdef QT_DEBUG
    qDebug() << "\n【" << data << "】\n";
#endif
}


#pragma GCC diagnostic pop
