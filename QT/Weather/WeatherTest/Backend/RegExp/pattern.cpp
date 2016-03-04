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
