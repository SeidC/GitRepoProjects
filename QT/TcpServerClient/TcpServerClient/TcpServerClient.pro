#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T21:23:39
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServerClient
TEMPLATE = app

INCLUDEPATH += Tcp/Server/ \
               Tcp/Client/ \
               Tcp/Connection

SOURCES += main.cpp\
           widget.cpp \
           Tcp/Server/server.cpp \
           Tcp/Client/client.cpp \
           Tcp/Connection/connection.cpp \
           texteditif.cpp

HEADERS  += widget.h \
            Tcp/Server/server.h \
            Tcp/Client/client.h \
            Tcp/Connection/connection.h \
            texteditif.h

FORMS    += widget.ui
