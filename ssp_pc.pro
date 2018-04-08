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



###############CommCore#################
#DataBase
SOURCES += DataBase/xsqlitemanager.cpp
SOURCES += DataBase/xdatabase.cpp

HEADERS += DataBase/xsqlitemanager.h
HEADERS += DataBase/xdatabase.h

#Http
SOURCES += Http/xhttpmanager.cpp

HEADERS += Http/apis.h
HEADERS += Http/xhttpmanager.h

#Core===TCP&UDP====与机器通信
SOURCES += Core/xmachinemanager.cpp
SOURCES += Core/xprofessional.cpp
SOURCES += Core/xremote.cpp
SOURCES += Core/xsimple.cpp

HEADERS += Core/xmachinemanager.h
HEADERS += Core/xprofessional.h
HEADERS += Core/xremote.h
HEADERS += Core/xsimple.h

#Models
HEADERS += Models/model.h

#Widgets
SOURCES += Widgets/attackwindow.cpp
SOURCES += Widgets/homewindow.cpp
SOURCES += Widgets/loginwindow.cpp
SOURCES += Widgets/matchtimewindow.cpp

HEADERS += Widgets/attackwindow.h
HEADERS += Widgets/homewindow.h
HEADERS += Widgets/loginwindow.h
HEADERS += Widgets/matchtimewindow.h

#Utils
SOURCES += Utils/xpublicmethods.cpp
SOURCES += Utils/log.cpp

HEADERS += Utils/xpublicmethods.h
HEADERS += Utils/utils.h
HEADERS += Utils/log.h
HEADERS += Utils/consts.h

RESOURCES += Resources/ssprc.qrc

FORMS += Widgets/attackwindow.ui
FORMS += Widgets/homewindow.ui
FORMS += Widgets/loginwindow.ui
FORMS += Widgets/matchtimewindow.ui

