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
           Frontend/Sources/weather.cpp \
           Frontend/Sources/dayinfo.cpp \
           Frontend/Sources/DayInfoColumn/dayinfocolumn.cpp \
           Frontend/Sources/daygraphic.cpp \
           Frontend/Sources/day.cpp \
           Frontend/Sources/DayInfoColumn/raininfo.cpp \
           Frontend/Sources/DayInfoColumn/temperatureinfo.cpp \
           Frontend/Sources/DayInfoColumn/windinfo.cpp \
           Frontend/Sources/DayInfoColumn/sunshineinfo.cpp \
           Backend/WeatherCom/weathercom.cpp \
           Backend/RegExp/regexp.cpp \
           Backend/NetworkRequest/networkrequest.cpp \
           Backend/RegExp/regexpdefs.cpp \
           Backend/WeatherCom/Search/search.cpp \
           Backend/WeatherCom/Search/CityRequest/city.cpp \
           Backend/WeatherCom/Search/CityRequest/cityrequest.cpp \
           Backend/WeatherCom/Search/CityRequest/result.cpp


HEADERS  += widget.h \
            Frontend/Header/weather.h \
            Frontend/Header/dayinfo.h \
            Frontend/Header/DayInfoColumn/dayinfocolumn.h \
            Frontend/Header/daygraphic.h \
            Frontend/Header/day.h \
            Frontend/Header/DayInfoColumn/raininfo.h \
            Frontend/Header/DayInfoColumn/temperatureinfo.h \
            Frontend/Header/DayInfoColumn/windinfo.h \
            Frontend/Header/DayInfoColumn/sunshineinfo.h \
            Backend/WeatherCom/weathercom.h \
            Backend/RegExp/regexp.h \
            Backend/NetworkRequest/networkrequest.h \
            Data/datastorage.h \
            Backend/RegExp/regexpdefs.h \
            Backend/WeatherCom/Search/search.h \
            Backend/WeatherCom/Search/CityRequest/city.h \
            Backend/WeatherCom/Search/CityRequest/cityrequest.h \
            Backend/WeatherCom/Search/CityRequest/result.h


FORMS    += widget.ui \
            Frontend/Ui/weather.ui \
            Frontend/Ui/dayinfo.ui \
            Frontend/Ui/dayinfocolumn.ui \
            Frontend/Ui/daygraphic.ui \
            Frontend/Ui/day.ui

INCLUDEPATH += Frontend \
               Frontend/Header/  \
               Frontend/Sources  \
               Frontend/Header/DayInfoColumn \
               Frontend/Sources/DayInfoColumn \
               Backend \
               Backend/WeatherCom \
               Backend/WeatherCom/Search \
               Backend/WeatherCom/Search/CityRequest/ \
               Backend/RegExp \
               Backend/NetworkRequest \

