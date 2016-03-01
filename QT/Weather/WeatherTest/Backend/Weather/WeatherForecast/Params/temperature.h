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
    DEGREE          = 0x00,
    NUMBER_OF_UNITS = 0x01,

}Unit_t;

public:
    Temperature();


    int getMin() const;
    void setMin(int value);

    int getMax() const;
    void setMax(int value);

    Unit_t getUnit() const;
    void setUnit(const Unit_t &value);

private:
    int min;
    int max;
    int feelMin;
    int feelMax;
    Unit_t unit;
    QString unitStr[NUMBER_OF_UNITS] = {"°C"};
};

#endif // TEMPERATURE_H
