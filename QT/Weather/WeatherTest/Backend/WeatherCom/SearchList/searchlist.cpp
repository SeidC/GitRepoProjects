#include "searchlist.h"

SearchList::SearchList(QObject *parent) : QObject(parent)
{

}

void SearchList::searchNumberOfResults(QString &txt)
{
    numberOfResults = search(txt);
    return;
}

void SearchList::searchPlaces(QString &txt)
{
    places = search(txt,SearchList::SEARCH_PLACES);
}

void SearchList::searchUrl(QString &txt)
{
    url = search(txt,SearchList::SEARCH_URLS);
}

int SearchList::getNumberOfResults()
{
    return numberOfResults;
}

QStringList SearchList::getPlaces()
{
    return places;
}

QStringList SearchList::getUrl()
{
    return url;
}

int SearchList::search(QString &txt)
{
    RegExp reg(QString(SEARCH_LIST_RESULT_COUNT));
    QStringList lst = reg.findRegExp(txt);
    QString str;
    int ret;
    if(lst.size() == 1)
    {
        str = lst.at(NR_POS).toInt();
        ret = str.toInt();
    }
    return ret;
}

QStringList SearchList::search(QString &txt,SearchList::SearchType type)
{
    RegExp reg(QString(SEARCH_LIST_PLACES_AND_URL));
    QStringList lst = reg.findRegExp(txt);
    QStringList ret;
    int pos;
    if (type == SearchList::SEARCH_PLACES)
    {
        pos = P_POS;
    }
    else if (type == SearchList::SEARCH_URLS)
    {
        pos = U_POS;
    }

    for (int i = pos; i < lst.size(); i+= 2)
    {
        ret.push_back(lst.at(i));
    }
    return ret;
}






