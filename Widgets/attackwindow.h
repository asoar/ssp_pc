#ifndef ATTACKWINDOW_H
#define ATTACKWINDOW_H

#include <QWidget>

namespace Ui {
class AttackWindow;
}

class AttackWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AttackWindow(QWidget *parent = 0);
    ~AttackWindow();

private:
    Ui::AttackWindow *ui;
};

#endif // ATTACKWINDOW_H
