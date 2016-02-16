#include "windinfo.h"

WindInfo::WindInfo(QWidget *parent) :
    DayInfoColumn(parent)
{
    setCaption(QString(WIND_CAPTION));
}
