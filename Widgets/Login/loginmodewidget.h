#ifndef LOGINMODEWIDGET_H
#define LOGINMODEWIDGET_H

#include "../Utils/config.h"

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
signals:
    void signalAccountLoginClicked();
    void signalMessageLoginClicked();
private slots:
    void onAccountLoginClicked();
    void onMessageLoginClicked();
private:
    UiImageButton *m_accountLoginBtn;//账号登陆
    UiImageButton *m_messageLoginBtn;//短信登陆
    int m_selectPos;
};

#endif // LOGINMODEWIDGET_H
