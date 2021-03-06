#include "pattern.h"



/*******************************************************************************
 * Pattern(...)
 ******************************************************************************/
Pattern::Pattern(QObject *parent) : QObject(parent)
{

    return;
}

/*******************************************************************************
 * Pattern(...)
 ******************************************************************************/
Pattern::Pattern(QString sPattern)
{
    pattern = sPattern;
    return;
}

/*******************************************************************************
 * Pattern(...)
 ******************************************************************************/
Pattern::Pattern(QString sPattern, MatchTypeList matchList)
{
    pattern = sPattern;
    matchTypes = matchList;
    return;
}


/*******************************************************************************
 * QString getPattern(...)
 ******************************************************************************/
QString Pattern::getPattern(void) const
{
    return pattern;
}

/*******************************************************************************
 * int getMatches(...)
 ******************************************************************************/
int Pattern::getMatches(void) const
{
    return matchTypes.size();
}

/*******************************************************************************
 * MatchTypeList getMatchTypes(...)
 ******************************************************************************/
Pattern::MatchTypeList Pattern::getMatchTypes(void)
{
    return matchTypes;
}

/*******************************************************************************
 * void addMatchType(...)
 ******************************************************************************/
void Pattern::addMatchType(Pattern::MatchType_t type)
{
    matchTypes.push_back(type);
    return;
}

/*******************************************************************************
 * void addMatchType(...)
 ******************************************************************************/
void Pattern::addMatchType(Pattern::MatchTypeList lst)
{
    matchTypes = lst;
    return;
}

/*******************************************************************************
 * MatchType_t getMatchTypeAtIndex(...)
 ******************************************************************************/
Pattern::MatchType_t Pattern::getMatchTypeAtIndex(int index)
{
    Pattern::MatchType_t ret = INVALID_MATCH;
    if (index < matchTypes.size())
    {
        ret = matchTypes.at(index);
    }
    return ret;
}
