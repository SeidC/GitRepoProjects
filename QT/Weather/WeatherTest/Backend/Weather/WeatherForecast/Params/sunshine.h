#ifndef SUNSHINE_H
#define SUNSHINE_H

#include <QObject>
#include "clock.h"

class Sunshine : public QObject
{
    Q_OBJECT

public:
    Sunshine();

private:
    Clock sunrise;
    Clock sunset;
    float sunshineDuration;
};

#endif // SUNSHINE_H
