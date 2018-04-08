#ifndef MATCHTIMEWINDOW_H
#define MATCHTIMEWINDOW_H

#include <QWidget>

namespace Ui {
class MatchTimeWindow;
}

class MatchTimeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MatchTimeWindow(QWidget *parent = 0);
    ~MatchTimeWindow();

private:
    Ui::MatchTimeWindow *ui;
};

#endif // MATCHTIMEWINDOW_H
