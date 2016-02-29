#ifndef WIND_H
#define WIND_H

#include <QObject>

class Wind : QObject
{
    Q_OBJECT
public:
typedef enum
{
    NORTH       = 0x00,
    NORTH_EAST        ,
    EAST              ,
    SOUTH_EAST        ,
    SOUTH             ,
    SOUTH_WEST        ,
    NORTH_WEST

}WindDirection_t;

public:
    Wind();



private:



};

#endif // WIND_H
