#ifndef PATTERNHANDLER_H
#define PATTERNHANDLER_H

#include <QObject>
#include "pattern.h"
#include "regexpdefs.h"

class PatternHandler;

class PatternHandler : public QObject
{
    Q_OBJECT
public:
     void addPattern(QString regExpStr, int match);
     void addPattern(Pattern *pattern);
     static PatternHandler *getInstance(void);

private: /*Constructor/ CopyConstructor and Destructor for Singelton Pattern*/
     explicit PatternHandler(QObject *parent = 0);
     PatternHandler (PatternHandler & );
     ~PatternHandler();

private:
    PatternList patternList;
    static PatternHandler* handler;
signals:

public slots:
};

#endif // PATTERNHANDLER_H
