#include "raininfo.h"

RainInfo::RainInfo(QWidget *parent) :
    DayInfoColumn(parent)
{
    setCaption(QString(RAIN_CAPTION));
}
