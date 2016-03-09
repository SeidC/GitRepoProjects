#include "Search.h"
#include "patternhandler.h"
#include "regexp.h"

#include <QDebug>

/*******************************************************************************
 * Search
 ******************************************************************************/
Search::Search(QObject *parent) : QObject(parent)
{

}


/*******************************************************************************
 * void searchCitys
 ******************************************************************************/
QStringList Search::searchCitys(QString websiteToSearch)
{
    PatternHandler *handler = PatternHandler::getInstance();
    return search(websiteToSearch,CityAndUrl);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchResults(QString websiteToSearch)
{
    return search(websiteToSearch,Count);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchRain(QString websiteToSerach)
{
    return search(websiteToSerach, WeatherType);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchTemperature(QString websiteToSearch)
{
    return search(websiteToSearch, WeatherTemp);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchSunshine(QString websiteToSearch)
{
    return search(websiteToSearch, WeatherSunshine);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchWind(QString websiteToSearch)
{
     return search(websiteToSearch, WeatherWind);
}


/*******************************************************************************
 * QStringList search()
 ******************************************************************************/
QStringList Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
