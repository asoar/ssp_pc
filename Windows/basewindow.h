#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "../Utils/config.h"
#include "Widgets/Base/uititlebar.h"

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();
private:
    void Initial();
    void InitView();
    void InitConnect();
protected:
    void resizeEvent(QResizeEvent* size);
    void paintEvent(QPaintEvent *event);

public slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    UITitleBar *m_titleBar;
};

#endif // BASEWINDOW_H
