#ifndef DAYTIME_H
#define DAYTIME_H

#include <QObject>
#include <QString>
#include <QList>
#include "wind.h"
#include "sunshine.h"
#include "temperature.h"
#include "rain.h"

class DayTime;

typedef QList<DayTime> DayTimeList;


class DayTime : public Rain, public Temperature, public Sunshine, public Wind
{

public:
    typedef enum
    {
        MORNING             = 0x00,
        MIDDAY              = 0x01,
        AFTERNOON           = 0x02,
        EVENING             = 0x03,
        NUMBER_OF_DAYTIMES  = 0x04

    }DayTime_t;

public:
    explicit DayTime();
    DayTime_t dayTime;

private:


};



#endif // DAYTIME_H
