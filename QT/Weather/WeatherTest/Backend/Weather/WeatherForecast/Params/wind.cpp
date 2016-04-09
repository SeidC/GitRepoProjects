#include "wind.h"

Wind::Wind()
{
    windDirectionList.push_back("North");
    windDirectionList.push_back("North_East");
    windDirectionList.push_back("East");
    windDirectionList.push_back("South_East");
    windDirectionList.push_back("South");
    windDirectionList.push_back("South_West");
    windDirectionList.push_back("North_West");

}

int Wind::getWindSpeed() const
{
    return windSpeed;
}

void Wind::setWindSpeed(int value)
{
    windSpeed = value;
}

Wind::WindDirection_t Wind::getWindDriection() const
{
    return windDriection;
}

void Wind::setWindDriection(const WindDirection_t &value)
{
    windDriection = value;
}

QString Wind::windDirectionToString(Wind::WindDirection_t direction)
{
    QString directionString = "";
    if(direction < windDirectionList.size())
    {
        directionString = windDirectionList.at((int)direction);
    }
    return directionString;
}

