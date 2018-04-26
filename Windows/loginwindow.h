#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "basewindow.h"

class LoginWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
private:
    void initial();
    void initSize();
    void initText();
    void initLayout();
    void initView();
    void initConnect();
signals:

private slots:
    void onAccountLoginClicked();
    void onMessageLoginClicked();
    void onVerifyBtnClicked();
    void onLoginBtnClicked();
private:
    LoginModeWidget *m_loginModeWidget;//登陆方式
    LoginEditWidget *m_accountEdit;//账号
    LoginEditWidget *m_passwordEdit;//密码
    LoginEditWidget *m_phoneAccountEdit;//手机账号
    LoginEditWidget *m_verifyEdit;//验证码
    UIPushButton     *m_verifyBtn;
    UIPushButton     *m_loginBtn;
    UILabel          *m_tipL;
};

#endif // LOGINWINDOW_H
