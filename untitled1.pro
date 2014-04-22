#-------------------------------------------------
#
# Project created by QtCreator 2014-04-18T09:42:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp

HEADERS  += \
    mainwindow.h

INCLUDEPATH += D:\vlc-2.1.3\sdk\include
LIBS    += -LD:\vlc-2.1.3\sdk\lib -llibvlc
LIBS    += -LD:\vlc-2.1.3\sdk\lib -llibvlccore

FORMS += \
    mainwindow.ui
