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

}

/*******************************************************************************
 * ~CityRequest
 ******************************************************************************/
CityRequest::FilterStatus_t CityRequest::filterData(QString webData)
{
    QStringList citys  = search.searchCitys(webData);
    QStringList result = search.searchResults(webData);
    cityResultList     = createCityResultList(&citys, &result);
    return FILTER_OK;
}

CityResultList *CityRequest::createCityResultList(QStringList *citys, QStringList *results)
{

}

