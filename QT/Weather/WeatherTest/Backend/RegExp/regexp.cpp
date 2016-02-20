#include "regexp.h"

RegExp::RegExp()
{

}

RegExp::RegExp(QString pattern)
{
    setPattern(pattern);
}

QStringList RegExp::findRegExp(QString &txt)
{
    QStringList ret;
    QRegularExpressionMatchIterator iter = globalMatch(txt);

    while (iter.hasNext())
    {
        ret.push_back(iter.next().captured());
    }
    return ret;
}
