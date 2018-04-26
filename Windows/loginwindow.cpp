#include "loginwindow.h"

#define kLoginWindowW 500
#define kLoginWindowH 500
#define kLoginModeWidgetH 60
#define kLoginAccountEditW 360
#define kLoginAccountEditH 50
#define kLoginVerifyEditW 220
#define kLoginVerifyBtnW 130

LoginWindow::LoginWindow(QWidget *parent)
    : BaseWindow(parent)
{
    initial();
    initSize();
    initText();
    initLayout();
    initView();
    initConnect();
}

LoginWindow::~LoginWindow()
{

}

void LoginWindow::initial()
{
    m_loginModeWidget = new LoginModeWidget(this);
    m_accountEdit = new LoginEditWidget(this);
    m_passwordEdit = new LoginEditWidget(this);
    m_phoneAccountEdit = new LoginEditWidget(this);
    m_verifyEdit = new LoginEditWidget(this);
    m_verifyBtn = new UIPushButton(this);
    m_loginBtn = new UIPushButton(this);
}

void LoginWindow::initSize()
{
    resize(kLoginWindowW, kLoginWindowH);
    m_loginModeWidget->resize(kLoginWindowW, kLoginModeWidgetH);
    m_accountEdit->resize(kLoginAccountEditW, kLoginAccountEditH);
    m_passwordEdit->resize(kLoginAccountEditW, kLoginAccountEditH);
    m_phoneAccountEdit->resize(kLoginAccountEditW, kLoginAccountEditH);
    m_verifyEdit->resize(kLoginVerifyEditW, kLoginAccountEditH);
    m_verifyBtn->resize(kLoginVerifyBtnW, kLoginAccountEditH);
    m_loginBtn->resize(kLoginAccountEditW, kLoginAccountEditH);
}

void LoginWindow::initText()
{
    m_accountEdit->setTextPlaceholder(TextLocal("请输入账号"));
    m_passwordEdit->setTextPlaceholder(TextLocal("请输入密码"));
    m_phoneAccountEdit->setTextPlaceholder(TextLocal("请输入手机账号"));
    m_verifyEdit->setTextPlaceholder(TextLocal("请输入验证码"));
    m_verifyBtn->setText(TextLocal("发送验证码"));
    m_loginBtn->setText(TextLocal("登录"));
}

void LoginWindow::initLayout()
{
    int nSpaceH1 = 50;
    int nSpaceH2 = 30;
    int nAccount_y = m_titleBar->size().height()+kLoginModeWidgetH+nSpaceH1;
    int nPassword_y = nAccount_y + kLoginAccountEditH + nSpaceH2;

    m_loginModeWidget->move(0, m_titleBar->size().height());
    m_accountEdit->move(70, nAccount_y);
    m_passwordEdit->move(70, nPassword_y);

    m_phoneAccountEdit->move(70, nAccount_y);
    m_verifyEdit->move(70, nPassword_y);
    m_verifyBtn->move(70 + m_verifyEdit->size().width()+ 10, nPassword_y);

    m_loginBtn->move(70, nPassword_y+100);
}

void LoginWindow::initView()
{
    m_titleBar->setTitleIcon(":/image/Resources/login_logo.png", QSize(35,35));
    m_titleBar->setButtonType(MIN_BUTTON);

    m_accountEdit->setIcon(":/image/Resources/login_phone.png");
    m_accountEdit->setTextRegExp(QRegExp("^((13[0-9])|(14[5|7])|(15([0-3]|[5-9]))|(18[0,5-9]))\\d{8}$"));

    m_passwordEdit->setIcon(":/image/Resources/login_pass.png");
    m_passwordEdit->setTextRegExp(QRegExp("^([0-9a-zA-Z]{6,20})$"));
    m_passwordEdit->setPasswordMode();

    m_phoneAccountEdit->setIcon(":/image/Resources/login_phone.png");
    m_phoneAccountEdit->setTextRegExp(QRegExp("^((13[0-9])|(14[5|7])|(15([0-3]|[5-9]))|(18[0,5-9]))\\d{8}$"));
    m_phoneAccountEdit->hide();

    m_verifyEdit->setIcon(":/image/Resources/login_pass.png");
    m_verifyEdit->setTextRegExp(QRegExp("^([0-9]{4,6})$"));
    m_verifyEdit->hide();

    m_verifyBtn->hide();
    m_verifyBtn->setStyleSheet("background-color:rgb(45,153,253);\
                                border:0px; border-radius:4px;\
                                font-size:16px;color:white;");

    m_loginBtn->setStyleSheet("background-color:rgb(239,83,80);\
                              border:0px; border-radius:4px;\
                              font-size:18px;color:white;");
}

void LoginWindow::initConnect()
{
    connect(m_loginModeWidget, SIGNAL(signalAccountLoginClicked()), this, SLOT(onAccountLoginClicked()));
    connect(m_loginModeWidget, SIGNAL(signalMessageLoginClicked()), this, SLOT(onMessageLoginClicked()));
    connect(m_verifyBtn, SIGNAL(clicked()), this, SLOT(onVerifyBtnClicked()));
    connect(m_loginBtn, SIGNAL(clicked()), this, SLOT(onLoginBtnClicked()));
}

void LoginWindow::onAccountLoginClicked()
{
    m_accountEdit->show();
    m_passwordEdit->show();

    m_phoneAccountEdit->hide();
    m_verifyEdit->hide();
    m_verifyBtn->hide();
}

void LoginWindow::onMessageLoginClicked()
{
    m_accountEdit->hide();
    m_passwordEdit->hide();

    m_phoneAccountEdit->show();
    m_verifyEdit->show();
    m_verifyBtn->show();
}

void LoginWindow::onVerifyBtnClicked()
{

}

void LoginWindow::onLoginBtnClicked()
{

}
