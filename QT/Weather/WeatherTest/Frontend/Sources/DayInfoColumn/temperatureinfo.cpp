#include "temperatureinfo.h"

TemperatureInfo::TemperatureInfo(QWidget *parent) :
    DayInfoColumn(parent)
{
    setCaption(QString(TEMPERATURE_CAPTION));
}
