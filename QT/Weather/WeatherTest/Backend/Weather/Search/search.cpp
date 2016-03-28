#include "Search.h"
#include "patternhandler.h"
#include "regexp.h"

#include <QDebug>

/*******************************************************************************
 * Search(...)
 ******************************************************************************/
Search::Search(QObject *parent) : QObject(parent)
{

}

/*******************************************************************************
 * void searchCitys(...)
 ******************************************************************************/
QStringList *Search::searchCitys(QString websiteToSearch, Pattern &cityPattern)
{
    return search(websiteToSearch, cityPattern);
}

/*******************************************************************************
 * void searchResults(...)
 ******************************************************************************/
QStringList *Search::searchResults(QString websiteToSearch, Pattern &resultPattern)
{
    return search(websiteToSearch, resultPattern);
}

/*******************************************************************************
 * void searchResults(...)
 ******************************************************************************/
QStringList *Search::searchRain(QString websiteToSerach, Pattern &rainPattern)
{
    return search(websiteToSerach, rainPattern);
}

/*******************************************************************************
 * void searchResults(...)
 ******************************************************************************/
QStringList *Search::searchTemperature(QString websiteToSearch, Pattern &temperaturePattern)
{
    return search(websiteToSearch, temperaturePattern);
}

/*******************************************************************************
 * void searchResults(...)
 ******************************************************************************/
QStringList *Search::searchSunshine(QString websiteToSearch, Pattern &sunshinePattern)
{
    return search(websiteToSearch, sunshinePattern);
}

/*******************************************************************************
 * void searchResults(...)
 ******************************************************************************/
QStringList *Search::searchWind(QString websiteToSearch, Pattern &windPattern)
{
    return search(websiteToSearch, windPattern);
}

/*******************************************************************************
 * FilterStatus_t filterData(...)
 ******************************************************************************/
Search::FilterStatus_t Search::filterData(QString webData)
{
    (void) webData;
    return FILTERN_NOT_SUPPORTED;
}

/*******************************************************************************
 * QStringList search(...)
 ******************************************************************************/
QStringList *Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
