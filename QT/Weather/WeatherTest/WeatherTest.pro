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
           Backend/Weather/CityRequest/CityResult/City/city.cpp \
           Backend/Weather/CityRequest/cityrequest.cpp \
           Backend/Weather/CityRequest/CityResult/Result/result.cpp \
           Backend/Weather/weather.cpp \
           Backend/Weather/WeatherForecast/weatherforecast.cpp \
           Backend/Weather/WeatherForecast/day.cpp \
           Backend/Weather/WeatherForecast/daytime.cpp \
           Backend/Weather/WeatherForecast/Params/sunshine.cpp \
           Backend/Weather/WeatherForecast/Params/rain.cpp \
           Backend/Weather/WeatherForecast/Params/temperature.cpp \
           Backend/Weather/WeatherForecast/Params/wind.cpp \
           Backend/Weather/WeatherForecast/Params/clock.cpp \
           Backend/RegExp/pattern.cpp \
           Backend/RegExp/patternhandler.cpp \
           Backend/Weather/CityRequest/CityResult/cityresult.cpp \



HEADERS  += widget.h \
            Backend/RegExp/regexp.h \
            Backend/NetworkRequest/networkrequest.h \
            Backend/RegExp/regexpdefs.h \
            Backend/Weather/Search/search.h \
            Backend/Weather/CityRequest/CityResult/City/city.h \
            Backend/Weather/CityRequest/cityrequest.h \
            Backend/Weather/CityRequest/CityResult/Result/result.h \
            Backend/Weather/weather.h \
            Backend/Weather/WeatherForecast/weatherforecast.h \
            Backend/Weather/WeatherForecast/day.h \
            Backend/Weather/WeatherForecast/daytime.h \
            Backend/Weather/WeatherForecast/Params/sunshine.h \
            Backend/Weather/WeatherForecast/Params/rain.h \
            Backend/Weather/WeatherForecast/Params/temperature.h \
            Backend/Weather/WeatherForecast/Params/wind.h \
            Backend/Weather/WeatherForecast/Params/clock.h \
            Backend/RegExp/pattern.h \
            Backend/RegExp/patternhandler.h \
            Backend/Weather/CityRequest/CityResult/cityresult.h \



FORMS    += widget.ui \


INCLUDEPATH += Backend \
               Backend/Weather \
               Backend/Weather/Search \
               Backend/Weather/CityRequest/ \
               Backend/Weather/CityRequest/CityResult \
               Backend/Weather/CityRequest/CityResult/Result \
               Backend/Weather/CityRequest/CityResult/City \
               Backend/RegExp \
               Backend/NetworkRequest \
               Backend/Weather/WeatherForecast \
               Backend/Weather/WeatherForecast/Params \
               Backend/Weather/Data/

