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
    Pattern *cPattern, *rPattern;
    QStringList *citys, *result;

    cPattern = PatternHandler::getInstance()->getPattern(PatternHandler::CITY_AND_URL);
    citys  = search.searchCitys(webData,*cPattern);

    rPattern = PatternHandler::getInstance()->getPattern(PatternHandler::COUNT_AND_COUNTRIES);
    result = search.searchResults(webData,*rPattern);

    cityResultList     = createCityResultList(citys, result,*cPattern,*rPattern);
    return FILTER_OK;
}

CityResultList *CityRequest::createCityResultList(QStringList *citys, QStringList *results, Pattern &cityPattern, Pattern& resultPattern)
{
    CityResultList *lst;
    CityResult *res;

    lst = new CityResultList();

}

void CityRequest::setResultsToList(QStringList *results, Pattern &resultPatten)
{
    int offset;
    offset = resultPatten.getMatches();
    for(int i = 0; i < results->size(); i+= offset)
    {
        for(int j = 0; j < offset; j++)
        {

        }
    }
}


