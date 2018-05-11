#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include "basewindow.h"

class HomeWindow : public BaseWindow
{
public:
    explicit HomeWindow(QWidget *parent = 0);
    ~HomeWindow();
private:
    void initial();
    void initSize();
    void initText();
    void initLayout();
    void initView();
    void initConnect();
};

#endif // HOMEWINDOW_H
