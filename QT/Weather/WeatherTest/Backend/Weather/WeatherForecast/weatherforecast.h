#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include "day.h"
#include "search.h"

class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = 0);

private:
    DayList days;
    Search* search;
signals:


public slots:
};

#endif // WEATHERFORECAST_H
