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
