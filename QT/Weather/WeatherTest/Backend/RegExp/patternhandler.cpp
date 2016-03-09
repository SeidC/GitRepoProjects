#include "patternhandler.h"


PatternHandler* PatternHandler::handler = NULL;

PatternHandler::PatternHandler(QObject *parent) : QObject(parent)
{

}

PatternHandler::PatternHandler(PatternHandler &)
{
    /*--- Nothing To Do ---*/
}

PatternHandler::~PatternHandler()
{
    /*--- Nothing To Do ---*/
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
