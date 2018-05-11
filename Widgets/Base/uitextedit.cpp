#include "uitextedit.h"

UITextEdit::UITextEdit(QWidget *parent)
    :QTextEdit(parent)
{
    setStyleSheet("background:transparent;border-width:0px;border-style:outset;border:0;outline:none;}");

    setFont(QFont("Timers" , 16 ,  QFont::Normal));
}

