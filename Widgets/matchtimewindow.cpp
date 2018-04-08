#include "matchtimewindow.h"
#include "ui_matchtimewindow.h"

MatchTimeWindow::MatchTimeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchTimeWindow)
{
    ui->setupUi(this);
}

MatchTimeWindow::~MatchTimeWindow()
{
    delete ui;
}
