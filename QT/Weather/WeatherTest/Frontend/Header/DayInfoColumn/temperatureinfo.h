#ifndef TEMPERATUREINFO_H
#define TEMPERATUREINFO_H

#include <QObject>
#include "dayinfocolumn.h"

#define TEMPERATURE_CAPTION "Temperatur"
#define TEMPERATURE_EXTENSION "°C"

class TemperatureInfo : public DayInfoColumn
{
public:
    explicit TemperatureInfo(QWidget *parent = 0);
};

#endif // TEMPERATUREINFO_H
