#include "loginmodewidget.h"


LoginModeWidget::LoginModeWidget(QWidget *parent)
    : QWidget(parent)
    , m_loginMode(AccountLoginMode)
{
    initial();
    initView();
    initLayout();
    initConnect();
}

void LoginModeWidget::initial()
{
    //设置背景白色
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    m_accountLoginBtn = new UiImageButton(this);
    m_accountLoginBtn->setFixedSize(80, 44);
    m_messageLoginBtn = new UiImageButton(this);
    m_messageLoginBtn->setFixedSize(80, 44);
}

void LoginModeWidget::initView()
{
    updateSelectStatus();
}

void LoginModeWidget::initLayout()
{
    QHBoxLayout* hlayout = new QHBoxLayout();
    hlayout->addWidget(m_accountLoginBtn);
    hlayout->addStretch();
    hlayout->addWidget(m_messageLoginBtn);
    hlayout->setContentsMargins(100, 22, 100, 0);
    this->setLayout(hlayout);
}

void LoginModeWidget::initConnect()
{
    connect(m_accountLoginBtn, SIGNAL(clicked()), this, SLOT(onAccountLoginClicked()));
    connect(m_messageLoginBtn, SIGNAL(clicked()), this, SLOT(onMessageLoginClicked()));
}

void LoginModeWidget::updateSelectStatus()
{
    if(m_loginMode == AccountLoginMode){
        m_accountLoginBtn->setBtnBackImgFile(":/image/Resources/login_account.png", \
                                        ":/image/Resources/login_account.png", \
                                        ":/image/Resources/login_account.png", \
                                        ":/image/Resources/login_account_gray.png");

        m_messageLoginBtn->setBtnBackImgFile(":/image/Resources/login_message_gray.png", \
                                        ":/image/Resources/login_message.png", \
                                        ":/image/Resources/login_message.png", \
                                        ":/image/Resources/login_message.png");
    } else {
        m_accountLoginBtn->setBtnBackImgFile(":/image/Resources/login_account_gray.png", \
                                        ":/image/Resources/login_account.png", \
                                        ":/image/Resources/login_account.png", \
                                        ":/image/Resources/login_account.png");

        m_messageLoginBtn->setBtnBackImgFile(":/image/Resources/login_message.png", \
                                        ":/image/Resources/login_message.png", \
                                        ":/image/Resources/login_message.png", \
                                        ":/image/Resources/login_message.png");

    }
}


LoginModeType LoginModeWidget::loginMode()
{
    return m_loginMode;
}

void LoginModeWidget::onAccountLoginClicked()
{
    if(m_loginMode == AccountLoginMode)
        return;

    m_loginMode = AccountLoginMode;
    updateSelectStatus();

    emit signalAccountLoginClicked();
}

void LoginModeWidget::onMessageLoginClicked()
{
    if(m_loginMode == MessageLoginMode)
        return;

    m_loginMode = MessageLoginMode;
    updateSelectStatus();

    emit signalMessageLoginClicked();
}
