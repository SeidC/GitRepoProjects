#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include "day.h"

class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = 0);

private:
    DayList dayList;
signals:


public slots:
};

#endif // WEATHERFORECAST_H
