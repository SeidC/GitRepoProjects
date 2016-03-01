#ifndef DAY_H
#define DAY_H

#include <QObject>
#include <QList>
#include "daytime.h"

class Day;

typedef QList<Day*> DayList;

class Day : public QObject
{
    Q_OBJECT
public:
typedef enum
{
    MORNING             = 0x00,
    MIDDAY              = 0x01,
    AFTERNOON           = 0x02,
    EVENING             = 0x03,
    NUMBER_OF_DAYTIMES  = 0x04

}DayTime_t;
public:
    explicit Day(QObject *parent = 0);

private:
    int dayTemperature;
    QString dayWeatherStatus;
    DayTimeList dayTime;
signals:

public slots:
};

#endif // DAY_H
