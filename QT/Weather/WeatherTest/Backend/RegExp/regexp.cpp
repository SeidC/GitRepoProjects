#include "regexp.h"
#include <QDebug>

/*******************************************************************************
 * Result
 ******************************************************************************/
RegExp::RegExp()
{

}


/*******************************************************************************
 * QStringList findRegExp
 ******************************************************************************/
QStringList RegExp::findRegExp(QString &txt,Pattern &pattern)
{
    QStringList ret;
    QRegularExpressionMatch match;
    QRegularExpressionMatchIterator iter;

    this->setPattern(pattern.getPattern());
    this->setPatternOptions(QRegularExpression::MultilineOption);
    iter = this->globalMatch(txt,0,QRegularExpression::PartialPreferCompleteMatch);

    while (iter.hasNext())
    {
        match = iter.next();
        for(int i = 1; i < pattern.getMatches() + 1; i++)
        {
            ret.push_back(match.captured(i));
        }
    }
    return ret;
}


