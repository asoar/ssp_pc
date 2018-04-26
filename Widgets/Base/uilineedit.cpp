#include "uilineedit.h"

UILineEdit::UILineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setStyleSheet("QLineEdit{Border:Opx none black;}");
    setFont(QFont("Timers" , 16 ,  QFont::Normal));
}

