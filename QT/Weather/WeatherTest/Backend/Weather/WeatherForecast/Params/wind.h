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
    NORTH_WEST        ,
    NUMBER_OF_WIND_DIRECTIONS

}WindDirection_t;

public:
    Wind();




private:
    QString windDirectionStr[NUMBER_OF_WIND_DIRECTIONS] = { "North", "North_East", "East", "South_East", "South", "South_West", "North_West"};
    WindDirection_t windDriection;
    int windSpeed;

};

#endif // WIND_H
