#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "homewindow.h"
#include "../Utils/log.h"

#define INPUTACCOUNT_TIP    "请输入账号"
#define INPUTPHONENUM_TIP   "请输入手机账号"
#define INPUTPASSWORD_TIP   "请输入密码"
#define INPUTVERIFYCODE_TIP "请输入短信验证码"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->initial();
    this->initConnect();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::initial()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");

    QRegExp regx("[0-9]+$");
    QValidator *accountV = new QRegExpValidator(regx, ui->accountEdit );
    ui->accountEdit->setValidator(accountV);

    QValidator *phoneV = new QRegExpValidator(regx, ui->phoneNumEdit );
    ui->phoneNumEdit->setValidator(phoneV);

    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->tipLab->setPalette(pa);
    ui->tipLab->setText(INPUTACCOUNT_TIP);
}

void LoginWindow::initConnect()
{
    connect(ui->verifyBtn, SIGNAL(clicked()), this, SLOT(slotVerifyBtnClick));
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(slotLoginBtnCLick()));
}

void LoginWindow::slotVerifyBtnClick()
{

}

void LoginWindow::slotLoginBtnCLick()
{

    //界面动画，改变透明度的方式消失1 - 0渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    HomeWindow *home = new HomeWindow();
    home->show();
}
