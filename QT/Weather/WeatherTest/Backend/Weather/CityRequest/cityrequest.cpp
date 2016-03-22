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
 * FilterStatus_t filterData(...)
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

/*******************************************************************************
 * CityResultList *createCityResultList(...)
 ******************************************************************************/
CityResultList *CityRequest::createCityResultList(QStringList *citys, QStringList *results, Pattern &cityPattern, Pattern& resultPattern)
{
    CityResultList *lst;
    CityResult *res;

    lst = new CityResultList();
    setResultsToList(lst,results,resultPattern);
}

/*******************************************************************************
 * void setResultsToList(...)
 ******************************************************************************/
void CityRequest::setResultsToList(CityResultList *list, QStringList *results, Pattern &resultPatten)
{
    int offset;
    CityResult* result;
    QString country;
    int quantity;

    /*Ask the number of available matches*/
    offset = resultPatten.getMatches();
    for(int i = 0; i < results->size(); i+= offset)
    {
        result = new CityResult();
        country = "";
        quantity = 0;

        for(int j = 0; j < offset; j++)
        {
            switch(resultPatten.getMatchTypeAtIndex(j+i))
            {
                case Pattern::RESULT_COUNTRY:
                    country = results->at(j+i);
                break;
                case Pattern::RESULT_QUANTITY:
                    quantity = results->at(j+i).toInt();
                break;
                default:
                    country = "";
                    quantity = 0;
                break;
             }
             result->addResult(country,quantity);
             list->push_back(result);
        }
    }
    return;
}

/*******************************************************************************
 * void setCitysToList(...)
 ******************************************************************************/
void CityRequest::setCitysToList(CityResultList *list, QStringList *citys, Pattern &cityPatten)
{
    int jOffset;

}


