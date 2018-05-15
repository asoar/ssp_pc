#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include "basewindow.h"
#include <QDateTimeEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QTableView>

class HomeWindow : public BaseWindow
{
    Q_OBJECT
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
private slots:
    void onDateTimeEditChanged(const QDate &date);
    void onCreateMatchBtn();
private:
    QWidget     *m_topWhiteWidget;
    QDateTimeEdit   *m_dateTimeEdit;
    UIPushButton *m_createMatchBtn;
    QTableView *m_tableView;
};

#endif // HOMEWINDOW_H
