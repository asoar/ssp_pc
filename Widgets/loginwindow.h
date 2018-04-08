#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
public:
    void initial();
    void initConnect();
signals:

private slots:
    void slotVerifyBtnClick();
    void slotLoginBtnCLick();
private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
