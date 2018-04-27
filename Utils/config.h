#ifndef CONFIG_H
#define CONFIG_H

#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPainter>
#include <QUdpSocket>
#include <QMessageBox>

#include <QMap>
#include <QObject>
#include <QString>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include "apis.h"
#include "Widgets/Base/uilabel.h"
#include "Widgets/Base/uilineedit.h"
#include "Widgets/Base/uititlebar.h"
#include "Widgets/Base/uipushbutton.h"
#include "Widgets/Base/uiimagebutton.h"
#include "Widgets/Login/loginmodewidget.h"
#include "Widgets/Login/logineditwidget.h"

#include "Http/httpkit.h"
#include "Http/httpmanager.h"


//获取实际屏幕大小
#define kScreenW QApplication::desktop()->screenGeometry()->width()
#define kScreenH QApplication::desktop()->screenGeometry()->height()
//可获取虚拟屏幕大小
#define kVirtualScreenW QApplication::desktop()->width()
#define kVirtualScreenH QApplication::desktop()->height()


#define TextLocal(a) QString::fromLocal8Bit(a)



#pragma mark ======底层通信======
#define kBroadcastIP  QHostAddress("255.255.255.255")
#define BROADCAST_PORT 36879

#endif // CONFIG_H

