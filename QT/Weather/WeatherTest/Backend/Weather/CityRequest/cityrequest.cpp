#include "cityrequest.h"
#include "patternhandler.h"


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
    Pattern *pattern;

    pattern = PatternHandler::getInstance()->getPattern(PatternHandler::CITY_AND_URL);
    QStringList citys  = search.searchCitys(webData,*pattern);

    pattern = PatternHandler::getInstance()->getPattern(PatternHandler::COUNT_AND_COUNTRIES);
    QStringList result = search.searchResults(webData);

    cityResultList     = createCityResultList(&citys, &result);
    return FILTER_OK;
}

CityResultList *CityRequest::createCityResultList(QStringList *citys, QStringList *results)
{

}

