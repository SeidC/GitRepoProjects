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
           Weather/Sources/weather.cpp \
           Weather/Sources/dayinfo.cpp \
           Weather/Sources/DayInfoColumn/dayinfocolumn.cpp \
           Weather/Sources/daygraphic.cpp \
           Weather/Sources/day.cpp \
           Weather/Sources/DayInfoColumn/raininfo.cpp \
           Weather/Sources/DayInfoColumn/temperatureinfo.cpp \
           Weather/Sources/DayInfoColumn/windinfo.cpp \
           Weather/Sources/DayInfoColumn/sunshineinfo.cpp

HEADERS  += widget.h \
            Weather/Header/weather.h \
            Weather/Header/dayinfo.h \
            Weather/Header/DayInfoColumn/dayinfocolumn.h \
            Weather/Header/daygraphic.h \
            Weather/Header/day.h \
            Weather/Header/DayInfoColumn/raininfo.h \
            Weather/Header/DayInfoColumn/temperatureinfo.h \
            Weather/Header/DayInfoColumn/windinfo.h \
            Weather/Header/DayInfoColumn/sunshineinfo.h

FORMS    += widget.ui \
            Weather/Ui/weather.ui \
            Weather/Ui/dayinfo.ui \
            Weather/Ui/dayinfocolumn.ui \
            Weather/Ui/daygraphic.ui \
            Weather/Ui/day.ui

INCLUDEPATH += Weather \
               Weather/Header/  \
               Weather/Sources  \
               Weather/Header/DayInfoColumn \
               Weather/Sources/DayInfoColumn \
