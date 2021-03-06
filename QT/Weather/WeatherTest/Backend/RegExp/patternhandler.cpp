#include "patternhandler.h"


PatternHandler* PatternHandler::handler = NULL;

PatternHandler::PatternHandler(QObject *parent) : QObject(parent)
{

}

PatternHandler::PatternHandler(PatternHandler & pattern)
{
    /*--- Nothing To Do ---*/
}

PatternHandler::~PatternHandler()
{
    /*--- Nothing To Do ---*/
}

void PatternHandler::addPattern(QString regExpStr)
{
    patternList.push_back(new Pattern(regExpStr));
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

Pattern *PatternHandler::getPattern(PatternHandler::Handler_t handle)
{
    Pattern *pattern = NULL;
    if(handle < patternList.size())
    {
        pattern = patternList.at((int)handle);
    }
    return pattern;
}
