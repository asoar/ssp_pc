#-------------------------------------------------
#
# Project created by QtCreator 2018-03-19T14:33:59
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ssp_pc
TEMPLATE = app

SOURCES += main.cpp


#comm
SOURCES += Comm/commsimple.cpp

HEADERS += Comm/commsimple.h


#database
SOURCES += DataBase/dbcomm.cpp
SOURCES += DataBase/dbmanager.cpp

HEADERS += DataBase/dbcomm.h
HEADERS += DataBase/dbmanager.h

#model
SOURCES += Model/basemodel.cpp
SOURCES += Model/httpresultbasemodel.cpp

HEADERS += Model/basemodel.h
HEADERS += Model/httpresultbasemodel.h

#http
SOURCES += Http/httpthread.cpp
SOURCES += Http/httpmanager.cpp

HEADERS += Http/httpthread.h
HEADERS += Http/httpmanager.h

#windows
SOURCES += Windows/loginwindow.cpp
SOURCES += Windows/basewindow.cpp
SOURCES += Windows/homewindow.cpp

HEADERS += Windows/loginwindow.h
HEADERS += Windows/basewindow.h
HEADERS += Windows/homewindow.h

#utils
HEADERS += Utils/config.h
HEADERS += Utils/apis.h
HEADERS += Utils/consts.h
HEADERS += Utils/globals.h

#base widget
SOURCES += Widgets/Base/uiimagebutton.cpp
SOURCES += Widgets/Base/uilineedit.cpp
SOURCES += Widgets/Base/uipushbutton.cpp
SOURCES += Widgets/Base/uilabel.cpp
SOURCES += Widgets/Base/uititlebar.cpp
SOURCES += Widgets/Base/uitextedit.cpp

HEADERS += Widgets/Base/uiimagebutton.h
HEADERS += Widgets/Base/uilabel.h
HEADERS += Widgets/Base/uilineedit.h
HEADERS += Widgets/Base/uipushbutton.h
HEADERS += Widgets/Base/uititlebar.h
HEADERS += Widgets/Base/uitextedit.h

#login widget
SOURCES += Widgets/Login/loginmodewidget.cpp
SOURCES += Widgets/Login/logineditwidget.cpp

HEADERS += Widgets/Login/loginmodewidget.h
HEADERS += Widgets/Login/logineditwidget.h

RESOURCES += ssprc.qrc




