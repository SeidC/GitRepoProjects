#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include "day.h"
#include "search.h"

class WeatherForecast : public Search
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = 0);

    FilterStatus_t filterData(QString webData);
private:
    DayList days;

signals:


public slots:
};

#endif // WEATHERFORECAST_H
