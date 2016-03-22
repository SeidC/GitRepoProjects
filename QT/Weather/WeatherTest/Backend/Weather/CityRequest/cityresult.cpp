#include "cityresult.h"

CityResult::CityResult(QObject *parent) : QObject(parent)
{

}

void CityResult::addResult(QString country, int numberOfResults)
{
    result.setCountry(country);
    result.setNumberOfResults(numberOfResults);
    return;
}


void CityResult::addCity(QString city, QString url)
{
    cityList.push_back(new City(city,url));
    return;
}

Result *CityResult::getResult(void)
{
    return &sresult;
}
