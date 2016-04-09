#ifndef REGEXP_H
#define REGEXP_H

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include "patternhandler.h"

class RegExp : public QRegularExpression
{

public:


private:


public:
    RegExp();
    QStringList *findRegExp(QString &txt, Pattern &pattern);



};

#endif // REGEXP_H
