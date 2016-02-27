#include "Search.h"
#include "regexp.h"
#include <QDebug>

/*******************************************************************************
 * Search
 ******************************************************************************/
Search::Search(QObject *parent) : QObject(parent)
{
    cityList = new QCityList();
}

/*******************************************************************************
 * void searchCitys
 ******************************************************************************/
void Search::searchCitys(QString strToFilter)
{
    QStringList lst = search(strToFilter,CityAndUrl);

    for(int i = 0; i < size; i++)
    {

    }
    return;
}

/*******************************************************************************
 * int getNumberOfResults()
 ******************************************************************************/
void Search::searchResults(QString strToFilter)
{
    QStringList = search(strToFilter,Count);
    return;
}

/*******************************************************************************
 * QCityList getCitys()
 ******************************************************************************/
QCityList *Search::getCitys()
{
    return cityList;
}

/*******************************************************************************
 * QResultListt getCityResults()
 ******************************************************************************/
QResultList *Search::getCityResults() const
{
    return cityResults;
}

/*******************************************************************************
 * QCityList search()
 ******************************************************************************/
QStringList Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
