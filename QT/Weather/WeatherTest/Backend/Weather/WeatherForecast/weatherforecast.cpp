#include "weatherforecast.h"
#include "patternhandler.h"

WeatherForecast::WeatherForecast(QObject *parent) : Search(parent)
{

}

Search::FilterStatus_t WeatherForecast::filterData(QString webData)
{
    Pattern *windPattern, *tempPattern, *rainPattern, *sunPattern;
    windPattern = PatternHandler::getInstance()->getPattern(PatternHandler::WIND)

}
