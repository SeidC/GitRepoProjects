#ifndef WINDINFO_H
#define WINDINFO_H

#include <QObject>
#include "dayinfocolumn.h"

#define WIND_CAPTION "Wind"
#define WIND_EXTENSION "km/h"


class WindInfo : public DayInfoColumn
{
public:
    explicit WindInfo(QWidget *parent = 0);
};

#endif // WINDINFO_H
