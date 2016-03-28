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
 * QStringList *searchCitys(...)
 ******************************************************************************/
QStringList *Search::searchCitys(QString websiteToSearch, Pattern &cityPattern)
{
    return search(websiteToSearch, cityPattern);
}

/*******************************************************************************
 * QStringList *searchResults(...)
 ******************************************************************************/
QStringList *Search::searchResults(QString websiteToSearch, Pattern &resultPattern)
{
    return search(websiteToSearch, resultPattern);
}

/*******************************************************************************
 * QStringList *searchRain(...)
 ******************************************************************************/
QStringList *Search::searchRain(QString websiteToSerach, Pattern &rainPattern)
{
    return search(websiteToSerach, rainPattern);
}

/*******************************************************************************
 * QStringList *searchTemperature(...)
 ******************************************************************************/
QStringList *Search::searchTemperature(QString websiteToSearch, Pattern &temperaturePattern)
{
    return search(websiteToSearch, temperaturePattern);
}

/*******************************************************************************
 * QStringList *searchSunshine(...)
 ******************************************************************************/
QStringList *Search::searchSunshine(QString websiteToSearch, Pattern &sunshinePattern)
{
    return search(websiteToSearch, sunshinePattern);
}

/*******************************************************************************
 * QStringList *searchWind(...)
 ******************************************************************************/
QStringList *Search::searchWind(QString websiteToSearch, Pattern &windPattern)
{
    return search(websiteToSearch, windPattern);
}

/*******************************************************************************
 * QStringList *searchTypes(...)
 ******************************************************************************/
QStringList *Search::searchTypes(QString websiteToSearch, Pattern &typePattern)
{
    return search(websiteToSearch,typePattern);
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
 * QStringList *search(...)
 ******************************************************************************/
QStringList *Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
