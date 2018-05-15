#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "../Utils/config.h"

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();
private:
    void initial();
    void initView();
    void initConnect();
public:
    /** 设置window背景颜色*/
    void setBackgroundColor(QColor color);
    /** 提醒消息框*/
    void showInfoMessage(const QString &message);
protected:
    void resizeEvent(QResizeEvent* size);
    void paintEvent(QPaintEvent *event);
public slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    UITitleBar *m_titleBar;
private:
    QColor m_bgColor;
};

#endif // BASEWINDOW_H
