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
#include <QPainter>

//获取实际屏幕大小
#define kScreenW QApplication::desktop()->screenGeometry()->width()
#define kScreenH QApplication::desktop()->screenGeometry()->height()
//可获取虚拟屏幕大小
#define kVirtualScreenW QApplication::desktop()->width()
#define kVirtualScreenH QApplication::desktop()->height()


#endif // CONFIG_H

