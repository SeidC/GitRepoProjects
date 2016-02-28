#include "cityrequest.h"


/*******************************************************************************
 * CityRequest
 ******************************************************************************/
CityRequest::CityRequest(QObject *parent) : QObject(parent)
{

}

/*******************************************************************************
 * QResultList getCityResults()
 ******************************************************************************/
QResultList CityRequest::getCityResults() const
{
    return cityResults;
}

/*******************************************************************************
 * void setCityResults()
 ******************************************************************************/
void CityRequest::setCityResults(QResultList value)
{
    cityResults = value;
    return;
}

/*******************************************************************************
 * QCityList getCityList()
 ******************************************************************************/
QCityList CityRequest::getCityList() const
{
    return cityList;
}

/*******************************************************************************
 * void setCityList()
 ******************************************************************************/
void CityRequest::setCityList(QCityList value)
{
    cityList = value;
    return;
}

/*******************************************************************************
 * void add()
 ******************************************************************************/
void CityRequest::add(QString city, QString url)
{
    cityList.push_back(new City(city,url));
    return;
}

/*******************************************************************************
 * void add()
 ******************************************************************************/
void CityRequest::add(int size, QString txt)
{
    cityResults.push_back(new Result(size,txt));
    return;
}

