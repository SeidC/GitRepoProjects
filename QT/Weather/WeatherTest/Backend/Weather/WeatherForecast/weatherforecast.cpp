#include "weatherforecast.h"
#include "patternhandler.h"

WeatherForecast::WeatherForecast(QObject *parent) : Search(parent)
{
    days = NULL;
}

WeatherForecast::FilterStatus_t WeatherForecast::filterData(QString webData)
{
    Pattern *windPattern, *tempPattern,
            *rainPattern, *sunPattern, *typePattern;
    QStringList *wind, *temp, *rain, *sun, *type;

    windPattern = PatternHandler::getInstance()->getPattern(PatternHandler::WIND);
    tempPattern = PatternHandler::getInstance()->getPattern(PatternHandler::TEMPERATURE);
    rainPattern = PatternHandler::getInstance()->getPattern(PatternHandler::RAIN);
    sunPattern  = PatternHandler::getInstance()->getPattern(PatternHandler::SUNSHINE);
    typePattern = PatternHandler::getInstance()->getPattern(PatternHandler::TYPE);

    wind = searchWind(webData,*windPattern);
    temp = searchTemperature(webData,*tempPattern);
    rain = searchRain(webData,*rainPattern);
    sun  = searchSunshine(webData,*sunPattern);
    type = searchTypes(webData,*typePattern);

    deleteWeatherForecast();
    days = createWeatherData(*wind,*temp,*rain,*sun,*type);

    return FILTERN_OK;
}

 DayList *WeatherForecast::createWeatherData(QStringList &wind, QStringList &temp, QStringList &rain,
                                             QStringList &sun, QStringList &type)
 {
     DayList* lst = new DayList();

     return lst;
 }

 void WeatherForecast::deleteWeatherForecast(void)
 {
    if(days != NULL)
    {
        delete days;
        days = NULL;
    }
    return;
 }
