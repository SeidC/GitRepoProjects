#ifndef PATTERNHANDLER_H
#define PATTERNHANDLER_H

#include <QObject>
#include "pattern.h"
#include "regexpdefs.h"

class PatternHandler : public QObject
{
    Q_OBJECT
public:
    explicit PatternHandler(QObject *parent = 0);

private:
    void addPattern(QString regExpStr, int match);
private:
    PatternList patternList;

signals:

public slots:
};

#endif // PATTERNHANDLER_H
