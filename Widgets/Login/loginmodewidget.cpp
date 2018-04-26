#include "loginmodewidget.h"

enum SelectStatus
{
    AccountSelectStatus = 0, // 账号登陆选中状态
    MessageSelectStatus      // 短信登陆选中状态
};


LoginModeWidget::LoginModeWidget(QWidget *parent)
    : QWidget(parent)
    , m_selectPos(AccountSelectStatus)
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
    m_accountLoginBtn->setFixedSize(80, 40);
    m_messageLoginBtn = new UiImageButton(this);
    m_messageLoginBtn->setFixedSize(80, 40);
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
    hlayout->setContentsMargins(100, 27, 100, 0);
    this->setLayout(hlayout);
}

void LoginModeWidget::initConnect()
{
    connect(m_accountLoginBtn, SIGNAL(clicked()), this, SLOT(onAccountLoginClicked()));
    connect(m_messageLoginBtn, SIGNAL(clicked()), this, SLOT(onMessageLoginClicked()));
}

void LoginModeWidget::updateSelectStatus()
{
    if(m_selectPos == AccountSelectStatus){
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

void LoginModeWidget::onAccountLoginClicked()
{
    if(m_selectPos == AccountSelectStatus)
        return;

    m_selectPos = AccountSelectStatus;
    updateSelectStatus();

    emit signalAccountLoginClicked();
}

void LoginModeWidget::onMessageLoginClicked()
{
    if(m_selectPos == MessageSelectStatus)
        return;

    m_selectPos = MessageSelectStatus;
    updateSelectStatus();

    emit signalMessageLoginClicked();
}
