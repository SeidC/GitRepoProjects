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
           Backend/RegExp/regexp.cpp \
           Backend/NetworkRequest/networkrequest.cpp \
           Backend/RegExp/regexpdefs.cpp \
           Backend/Weather/Search/search.cpp \
           Backend/Weather/CityRequest/city.cpp \
           Backend/Weather/CityRequest/cityrequest.cpp \
           Backend/Weather/CityRequest/result.cpp \
           Backend/Weather/weather.cpp \
           Backend/Weather/WeatherForecast/weatherforecast.cpp \
    Backend/Weather/WeatherForecast/day.cpp \
    Backend/Weather/WeatherForecast/daytime.cpp \
    Backend/Weather/WeatherForecast/sunshine.cpp \
    Backend/Weather/WeatherForecast/rain.cpp \
    Backend/Weather/WeatherForecast/temperature.cpp \
    Backend/Weather/WeatherForecast/wind.cpp


HEADERS  += widget.h \
            Backend/RegExp/regexp.h \
            Backend/NetworkRequest/networkrequest.h \
            Backend/RegExp/regexpdefs.h \
            Backend/Weather/Search/search.h \
            Backend/Weather/CityRequest/city.h \
            Backend/Weather/CityRequest/cityrequest.h \
            Backend/Weather/CityRequest/result.h \
            Backend/Weather/weather.h \
            Backend/Weather/WeatherForecast/weatherforecast.h \
            Backend/Weather/WeatherForecast/day.h \
            Backend/Weather/WeatherForecast/daytime.h \
            Backend/Weather/WeatherForecast/sunshine.h \
            Backend/Weather/WeatherForecast/rain.h \
            Backend/Weather/WeatherForecast/temperature.h \
            Backend/Weather/WeatherForecast/wind.h


FORMS    += widget.ui \


INCLUDEPATH += Backend \
               Backend/Weather \
               Backend/Weather/Search \
               Backend/Weather/CityRequest/ \
               Backend/RegExp \
               Backend/NetworkRequest \
               Backend/Weather/WeatherForcast

