#include "patternhandler.h"


PatternHandler* PatternHandler::handler = NULL;

PatternHandler::PatternHandler(QObject *parent) : QObject(parent)
{
    addPattern(QString(WEATHER_TEMP),2);
    addPattern(QString(WEATHER_DAY_DATE),2);
    addPattern(QString(WEATHER_SUNNSHINE),3);
    addPattern(QString(WEATHER_WIND),2);
    addPattern(QString(WEATER_WTYPE),1);
    addPattern(QString(SEARCH_LIST_PLACES_AND_URL),2);
    addPattern(QString(SEARCH_LIST_RESULT_COUNT),2);
}

PatternHandler::PatternHandler(PatternHandler &)
{

}

PatternHandler::~PatternHandler()
{

}

void PatternHandler::addPattern(QString regExpStr, int match)
{
    patternList.push_back(new Pattern(regExpStr,match));
}

void PatternHandler::addPattern(Pattern *pattern)
{
    patternList.push_back(pattern);
    return;
}

PatternHandler *PatternHandler::getInstance()
{
    if (handler == NULL)
    {
        handler = new PatternHandler();
    }
    return handler;
}
