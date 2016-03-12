#ifndef PATTERNHANDLER_H
#define PATTERNHANDLER_H

#include <QObject>
#include "pattern.h"


class PatternHandler;

class PatternHandler : public QObject
{
    Q_OBJECT
public:
    typedef enum
    {
        TEMPERATURE   = 0x00,
        DAY                 ,
        SUNSHINE            ,
        WIND                ,
        TYPE                ,
        CITY_AND_URL        ,
        COUNT               ,
        RAIN

    }Handler_t;
public:
     void addPattern(QString regExpStr);
     void addPattern(Pattern *pattern);
     static PatternHandler *getInstance(void);
     Pattern* getPattern(Handler_t handle);

private: /*Constructor/ CopyConstructor and Destructor for Singelton Pattern*/
     explicit PatternHandler(QObject *parent = 0);
     PatternHandler (PatternHandler & pattern);
     ~PatternHandler();

private:
    PatternList patternList;
    static PatternHandler* handler;
signals:

public slots:
};

#endif // PATTERNHANDLER_H
