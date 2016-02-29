#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QString>

class Temperature : QObject
{
    Q_OBJECT

public:
typedef enum
{
    DEGREE = 0x00,

}Unit_t;
public:
    Temperature();
private:
    int min;
    int max;
    Unit_t unit;
};

#endif // TEMPERATURE_H
