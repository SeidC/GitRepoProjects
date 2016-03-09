#include "pattern.h"

Pattern::Pattern(QObject *parent) : QObject(parent)
{

}


/*******************************************************************************
 * Pattern
 ******************************************************************************/
Pattern::Pattern(QString sPattern, int iMatches)
{
    pattern = sPattern;
    matches = iMatches;
}

/*******************************************************************************
 * Pattern
 ******************************************************************************/
Pattern::Pattern(QString sPattern, int iMatches, MatchTypeList matchList)
{
    pattern = sPattern;
    matches = iMatches;
    matchTypes = matchList;
}


/*******************************************************************************
 * QString getPattern
 ******************************************************************************/
QString Pattern::getPattern() const
{
    return pattern;
}

/*******************************************************************************
 * int getMatches
 ******************************************************************************/
int Pattern::getMatches() const
{
    return matches;
}

MatchTypeList Pattern::getMatchTypes()
{
    return matchTypes;
}
