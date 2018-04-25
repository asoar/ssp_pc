#include "loginmodewidget.h"

LoginModeWidget::LoginModeWidget(QWidget *parent)
    : QWidget(parent)
{
    QPalette pal(this->palette());
    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

