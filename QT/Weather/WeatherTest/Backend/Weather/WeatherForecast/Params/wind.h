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




    int getWindSpeed() const;
    void setWindSpeed(int value);

    WindDirection_t getWindDriection() const;
    void setWindDriection(const WindDirection_t &value);

    QString windDirectionToString(WindDirection_t direction);

private:
    QStringList     windDirectionList;
    WindDirection_t windDriection;
    int windSpeed;

};

#endif // WIND_H
