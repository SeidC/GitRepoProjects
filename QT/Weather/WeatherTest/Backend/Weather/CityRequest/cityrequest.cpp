#include "cityrequest.h"


/*******************************************************************************
 * CityRequest
 ******************************************************************************/
CityRequest::CityRequest(QObject *parent) : QObject(parent)
{

}

/*******************************************************************************
 * ~CityRequest
 ******************************************************************************/
CityRequest::~CityRequest()
{
    deleteEntries();
    deleteCitys();
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

/*******************************************************************************
 * void deleteEntries()
 ******************************************************************************/
void CityRequest::deleteEntries(void)
{
    deleteResults();
    deleteCitys();
    return;
}

/*******************************************************************************
 * void deleteResults()
 ******************************************************************************/
void CityRequest::deleteResults(void)
{
    for (int i = cityResults.size()-1; i >= 0; i--)
    {
        if (cityResults.at(i) != NULL)
        {
            delete cityResults.at(i);
        }
    }
    return;
}

/*******************************************************************************
 * void deleteCitys()
 ******************************************************************************/
void CityRequest::deleteCitys(void)
{
    for(int i = cityList.size()-1; i >= 0; i--)
    {
        if (cityList.at(i) != NULL)
        {
            delete cityList.at(i);
        }
    }
    return;
}

