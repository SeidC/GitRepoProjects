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

typedef QList<DayTime*> DayTimeList;

class DayTime : public Rain, public Temperature, public Sunshine, public Wind
{

public:
    explicit DayTime();

private:


};



#endif // DAYTIME_H
