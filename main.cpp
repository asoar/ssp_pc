#include <QApplication>
#include <QTextCodec>
#include <QPixmap>
#include <QFile>
#include <QSplashScreen>
#include "Widgets/loginwindow.h"
#include "Widgets/attackwindow.h"
#include "Widgets/matchtimewindow.h"
#include "DataBase/xsqlitemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    XSQLiteManager::getDBInstance()->initDBManager();


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    //style
    QFile file(":/qss/style.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(QString(file.readAll()));
    file.close();

    //启动动画
    QPixmap pixmap(":/img/icon.png");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();


    LoginWindow w;
    w.show();

    //登陆页面启动后，释放动画
    splash->finish(&w);
    delete splash;

    return a.exec();
}
