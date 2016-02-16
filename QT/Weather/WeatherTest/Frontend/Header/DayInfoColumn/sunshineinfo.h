#ifndef SUNSHINEINFO_H
#define SUNSHINEINFO_H

#include <QObject>
#include "dayinfocolumn.h"

#define SUNSHINE_CAPTION "Sonnenschein"
#define SUNSHINE_EXTENSION "h"

class SunshineInfo : public DayInfoColumn
{
public:
   explicit SunshineInfo(QWidget *parent = 0);
};

#endif // SUNSHINEINFO_H
