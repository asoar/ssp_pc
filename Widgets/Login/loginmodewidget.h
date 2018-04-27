#ifndef LOGINMODEWIDGET_H
#define LOGINMODEWIDGET_H

#include "../Utils/config.h"

enum LoginModeType
{
    AccountLoginMode = 0,         // 最小化和关闭按钮;
    MessageLoginMode        // 最小化、最大化和关闭按钮;
};

class LoginModeWidget : public QWidget
{
    Q_OBJECT
public:
    LoginModeWidget(QWidget *parent);
private:
    void initial();
    void initView();
    void initLayout();
    void initConnect();
    void updateSelectStatus();
public:
    LoginModeType loginMode();
signals:
    void signalAccountLoginClicked();
    void signalMessageLoginClicked();
private slots:
    void onAccountLoginClicked();
    void onMessageLoginClicked();
private:
    UiImageButton *m_accountLoginBtn;//账号登陆
    UiImageButton *m_messageLoginBtn;//短信登陆
    LoginModeType  m_loginMode;
};

#endif // LOGINMODEWIDGET_H
