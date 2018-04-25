#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "basewindow.h"
#include "Widgets/Login/loginmodewidget.h"

class LoginWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
private:
    void Initial();
    void InitSize();
    void InitText();
    void InitLayout();
    void InitView();
    void InitConnect();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:

private:
    LoginModeWidget  *m_loginWidget;//登陆方式
    QLineEdit   *m_accountEdit;//账号
    QLineEdit   *m_phoneEdit;//手机号
    QLineEdit   *m_passwordEdit;//密码
    QLineEdit   *m_verifyEdit;//验证码
    QLabel      *m_tipL;
    QPushButton *m_verifyBtn;
    QPushButton *m_loginBtn;

private:
    QPoint last;
};

#endif // LOGINWINDOW_H
