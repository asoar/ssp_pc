#include "uilineedit.h"

UILineEdit::UILineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setStyleSheet("background:transparent;border-width:0px;border-style:outset;}");

    setFont(QFont("Timers" , 16 ,  QFont::Normal));
}

