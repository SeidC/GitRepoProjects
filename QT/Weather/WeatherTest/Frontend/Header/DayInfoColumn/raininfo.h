#ifndef RAININFO_H
#define RAININFO_H

#include <QObject>
#include "dayinfocolumn.h"


#define RAIN_QUANTITY "l/m²"
#define RAIN_RISK     "% Risiko"
#define RAIN_CAPTION  "Regenrisiko:"

class RainInfo : public DayInfoColumn
{

public:
   explicit RainInfo(QWidget *parent = 0);
};

#endif // RAININFO_H
