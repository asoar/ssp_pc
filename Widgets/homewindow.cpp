#include "homewindow.h"
#include "ui_homewindow.h"
#include <QPropertyAnimation>

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
