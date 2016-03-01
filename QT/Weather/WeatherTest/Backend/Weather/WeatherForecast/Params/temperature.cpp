#include "temperature.h"

Temperature::Temperature()
{

}

int Temperature::getMin() const
{
    return min;
}

void Temperature::setMin(int value)
{
    min = value;
}

int Temperature::getMax() const
{
    return max;
}

void Temperature::setMax(int value)
{
    max = value;
}

Temperature::Unit_t Temperature::getUnit() const
{
    return unit;
}

void Temperature::setUnit(const Unit_t &value)
{
    unit = value;
}
