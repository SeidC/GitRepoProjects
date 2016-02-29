#ifndef DAYTIME_H
#define DAYTIME_H

#include <QObject>
#include "day.h"
#include "wind.h"
#include "sunshine.h"
#include "temperature.h"
#include "rain.h"

class DayTime : public Day, public Rain, public Temperature, public Sunshine
{

typedef enum
{
    MORNING   = 0x00,
    MIDDAY    = 0x01,
    AFTERNOON = 0x02,
    EVENING   = 0x03

}DayTime_t;

public:
    explicit DayTime();


};



#endif // DAYTIME_H
