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
    Pattern *pattern = handler->getPattern(PatternHandler::CITY_AND_URL);
    return search(websiteToSearch, *pattern);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchResults(QString websiteToSearch)
{
    PatternHandler *handler = PatternHandler::getInstance();
    Pattern *pattern = handler->getPattern(PatternHandler::COUNT);
    return search(websiteToSearch, *pattern);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchRain(QString websiteToSerach)
{
    PatternHandler *handler = PatternHandler::getInstance();
    Pattern *pattern = handler->getPattern(PatternHandler::TYPE);
    return search(websiteToSerach, *pattern);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchTemperature(QString websiteToSearch)
{
    PatternHandler *handler = PatternHandler::getInstance();
    Pattern *pattern = handler->getPattern(PatternHandler::TEMPERATURE);
    return search(websiteToSearch, *pattern);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchSunshine(QString websiteToSearch)
{
    PatternHandler *handler = PatternHandler::getInstance();
    Pattern *pattern = handler->getPattern(PatternHandler::SUNSHINE);
    return search(websiteToSearch, *pattern);
}

/*******************************************************************************
 * void searchResults()
 ******************************************************************************/
QStringList Search::searchWind(QString websiteToSearch)
{
    PatternHandler *handler = PatternHandler::getInstance();
    Pattern *pattern = handler->getPattern(PatternHandler::WIND);
    return search(websiteToSearch, *pattern);
}


/*******************************************************************************
 * QStringList search()
 ******************************************************************************/
QStringList Search::search(QString &txt,Pattern &pattern)
{
    RegExp reg;
    return reg.findRegExp(txt,pattern);
}
