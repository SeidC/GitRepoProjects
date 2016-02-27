#include "searchlist.h"
#include <QDebug>

/*******************************************************************************
 * SearchList
 ******************************************************************************/
SearchList::SearchList(QObject *parent) : QObject(parent)
{
    cityList = new QCityList();
}

/*******************************************************************************
 * void searchCitys
 ******************************************************************************/
void SearchList::searchCitys(QString strToFilter)
{
    QCityList lst = search(strToFilter,CityAndUrl);
    int size      = search(strToFilter,Count);

    numberOfResults = size;
    for(int i = 0; i < size; i++)
    {
        cityList->push_back(City(places.at(i),url.at(i)));
    }

    return;
}

/*******************************************************************************
 * int getNumberOfResults()
 ******************************************************************************/
int SearchList::getNumberOfResults()
{
    return numberOfResults;
}

/*******************************************************************************
 * QCityList getCitys()
 ******************************************************************************/
QCityList *SearchList::getCitys()
{
    return cityList;
}

/*******************************************************************************
 * int search()
 ******************************************************************************/
int SearchList:: search(QString &txt,Pattern pattern)
{
    RegExp reg;
    QStringList lst = reg.findRegExp(txt,pattern);
    QString str;
    int ret;
    if(lst.size() == 1)
    {
        str = lst.at(NR_POS).toInt();
        ret = str.toInt();
    }
    return ret;
}

/*******************************************************************************
 * QCityList search()
 ******************************************************************************/
QCityList SearchList::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    QCityList cityLst;
    QStringList lst = reg.findRegExp(txt,pattern);
    return ret;
}
