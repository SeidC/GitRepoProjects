#include "Search.h"
#include "regexp.h"
#include <QDebug>

/*******************************************************************************
 * Search
 ******************************************************************************/
Search::Search(QObject *parent) : QObject(parent)
{
    cityRequest = NULL;
}

/*******************************************************************************
 * void searchCitys
 ******************************************************************************/
void Search::searchCitys(QString websiteToSearch)
{
    QStringList lst = search(websiteToSearch,CityAndUrl);

    for(int i = 0; i < lst.size(); i+= CityAndUrl.getMatches())
    {
        cityRequest->add(lst.at(i+1),lst.at(i));
    }
    return;
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
void Search::searchResults(QString websiteToSearch)
{
    QStringList lst = search(websiteToSearch,Count);
    for(int i = 0; i < lst.size();i+= Count.getMatches() )
    {
        QString size(lst.at(i));
        QString txt(lst.at(i+1));
        cityRequest->add(size.toInt(),txt);
    }
    return;
}

/*******************************************************************************
 * void makeCityRequest()
 ******************************************************************************/
void Search::makeCityRequest(QString websiteToSearch)
{
    newCityRequest();
    searchResults(websiteToSearch);
    searchCitys(websiteToSearch);
    return;
}

CityRequest *Search::getCityRequest(void) const
{
    return cityRequest;
}

/*******************************************************************************
 * void newCityRequest()
 ******************************************************************************/
void Search::newCityRequest()
{
    if (cityRequest != NULL)
    {
        delete cityRequest;
    }

    cityRequest = new CityRequest(this);
    return;
}


/*******************************************************************************
 * QStringList search()
 ******************************************************************************/
QStringList Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
