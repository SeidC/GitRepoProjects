#include "Search.h"
#include "regexp.h"
#include <QDebug>

/*******************************************************************************
 * Search
 ******************************************************************************/
Search::Search(QObject *parent) : QObject(parent)
{
    cityRequest = new CityRequest(this);
}

/*******************************************************************************
 * void searchCitys
 ******************************************************************************/
void Search::searchCitys(QString strToFilter)
{
    QStringList lst = search(strToFilter,CityAndUrl);

    for(int i = 0; i < lst.size(); i+= CityAndUrl.getMatches())
    {
        cityRequest->add(lst.at(i+1),lst.at(i));
    }
    return;
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
void Search::searchResults(QString strToFilter)
{
    QStringList lst = search(strToFilter,Count);
    for(int i = 0; i < lst.size();i+= Count.getMatches() )
    {
        QString size(lst.at(i));
        QString txt(lst.at(i+1));
        cityRequest->add(size.toInt(),txt);
    }
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
