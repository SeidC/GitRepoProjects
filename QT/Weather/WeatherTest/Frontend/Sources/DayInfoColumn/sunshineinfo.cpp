#include "sunshineinfo.h"

SunshineInfo::SunshineInfo(QWidget *parent) :
    DayInfoColumn(parent)
{
    setCaption(QString(SUNSHINE_CAPTION));
}
