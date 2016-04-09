#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T19:51:40
#
#-------------------------------------------------

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uicomponent.cpp

HEADERS  += mainwindow.h \
    uicomponent.h

FORMS    += mainwindow.ui

DISTFILES += \
    UiComponent.qml

RESOURCES += \
    res.qrc
