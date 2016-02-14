#-------------------------------------------------
#
# Project created by QtCreator 2016-02-12T18:07:19
#
#-------------------------------------------------

QT       += core gui webkitwidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeatherTest
TEMPLATE = app


SOURCES += main.cpp\
            widget.cpp \
         weather.cpp \
        dayinfo.cpp \
        dayinfocolumn.cpp \
        daygraphic.cpp \
        day.cpp

HEADERS  += widget.h \
            weather.h \
            dayinfo.h \
            dayinfocolumn.h \
            daygraphic.h \
            day.h

FORMS    += widget.ui \
            weather.ui \
            dayinfo.ui \
            dayinfocolumn.ui \
            daygraphic.ui \
            day.ui
