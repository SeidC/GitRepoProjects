#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T21:23:39
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServerClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Tcp/server.cpp

HEADERS  += widget.h \
    Tcp/server.h

FORMS    += widget.ui
