#include "cityresult.h"

CityResult::CityResult(QObject *parent) : QObject(parent)
{

}

void CityResult::addResult(QString country, int numberOfResults)
{
    results.setCountry(country);
    results.setNumberOfResults(numberOfResults);
    return;
}


void CityResult::addCity(QString city, QString url)
{
    cityList.push_back(new City(city,url));
    return;
}
