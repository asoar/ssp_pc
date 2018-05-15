#include <QApplication>
#include "Windows/homewindow.h"
#include "Windows/loginwindow.h"
#include "Windows/creatematchwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    HomeWindow w;
//    LoginWindow w;
    CreateMatchWindow w;
    w.show();

    return a.exec();
}
