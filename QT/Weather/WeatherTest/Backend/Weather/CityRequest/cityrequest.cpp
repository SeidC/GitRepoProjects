#include "cityrequest.h"
#include "patternhandler.h"


/*******************************************************************************
 * CityRequest
 ******************************************************************************/
CityRequest::CityRequest(QObject *parent) : Search(parent)
{
    cityResultList = NULL;
}

/*******************************************************************************
 * ~CityRequest
 ******************************************************************************/
CityRequest::~CityRequest()
{
    deleteResultList();
}

/*******************************************************************************
 * FilterStatus_t filterData(...)
 ******************************************************************************/
CityRequest::FilterStatus_t CityRequest::filterData(QString webData)
{
    Pattern *cPattern, *rPattern;
    QStringList *citys, *result;

    /*Request Reg Exp Pattern to filter all Citys*/
    cPattern = PatternHandler::getInstance()->getPattern(PatternHandler::CITY_AND_URL);
    /*Request Reg Exp Pattern to filter all Countries and  the Quantity*/
    rPattern = PatternHandler::getInstance()->getPattern(PatternHandler::COUNT_AND_COUNTRIES);

    /*Filter all citys from website with the City Reg Exp*/
    citys  = searchCitys(webData,*cPattern);
    /*Filter all countrys and quantities from website wiht the Result Reg Exp*/
    result = searchResults(webData,*rPattern);

    /*Delete ResultList if allready exists*/
    deleteResultList();
    /*Split all returned value in the CityResultList*/
    cityResultList     = createCityResultList(citys, result,*cPattern,*rPattern);
    return FILTERN_OK;
}

QStringList *CityRequest::getListOfCities(QString country)
{
    int index = getCountryListIndex(country);
    int size = cityResultList->at(index)->getCityList()->size();
    QStringList* lst = new QStringList();
    QString txt;
    for(int i = 0; i< size ; i++ )
    {
        txt = cityResultList->at(index)->getCityList()->at(i)->getCity();
        lst->push_back(txt);
    }
    return lst;
}


/*******************************************************************************
 * QStringList *getListOfCountries(...)
 ******************************************************************************/
QStringList *CityRequest::getListOfCountries(void)
{
    QStringList* cList = new QStringList();
    QString country;
    for(int i = 0; i < cityResultList->size(); i++)
    {
        country = cityResultList->at(i)->getResult()->getCountry();
        cList->push_back(country);
    }
    return cList;
}

/*******************************************************************************
 * int getCountryListIndex(...)
 ******************************************************************************/
int CityRequest::getCountryListIndex(QString country)
{
    int index = -1;
    for(int i = 0; i < cityResultList->size(); i++)
    {
        if(country == cityResultList->at(i)->getResult()->getCountry())
        {
            index = i;
            break;
        }
    }
    return index;
}

/*******************************************************************************
 * CityResultList *createCityResultList(...)
 ******************************************************************************/
CityResultList *CityRequest::createCityResultList(QStringList *citys, QStringList *results, Pattern &cityPattern, Pattern& resultPattern)
{
    CityResultList *lst;

    lst = new CityResultList();
    setResultsToList(lst,results,resultPattern);
    setCitysToList(lst,citys,cityPattern);
    return lst;
}

/*******************************************************************************
 * void setResultsToList(...)
 ******************************************************************************/
void CityRequest::setResultsToList(CityResultList *list, QStringList *results, Pattern &resultPattern)
{
    CityResult* result;
    QString country;
    int quantity;


    for(int i = 0; i < results->size(); i+= resultPattern.getMatches())
    {
        result = new CityResult();
        country = "";
        quantity = 0;

        for(int j = 0; j < resultPattern.getMatches(); j++)
        {
            switch(resultPattern.getMatchTypeAtIndex(j))
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
        }
        result->addResult(country,quantity);
        list->push_back(result);
    }
    return;
}

/*******************************************************************************
 * void setCitysToList(...)
 ******************************************************************************/
void CityRequest::setCitysToList(CityResultList *list, QStringList *citys, Pattern &cityPattern)
{
    Result *result;
    CityResult* cityResult;
    QString city;
    QString url;
    int listCounter,offset = 0;

    for(int i = 0; i < list->size();i++)
    {
        cityResult = list->at(i);
        result = list->at(i)->getResult();

        if(result->isMaxStoredReached())
        {
            listCounter = result->getMaxStoredResults() *
                          cityPattern.getMatches();
        }
        else
        {
            listCounter = result->getNumberOfResults() *
                          cityPattern.getMatches();
        }

        for (int j = offset; j < (offset +listCounter); j+= cityPattern.getMatches())
        {
            for(int k = 0; k < cityPattern.getMatches(); k++)
            {
                switch (cityPattern.getMatchTypeAtIndex(k))
                {
                    case Pattern::CITY:
                        city = citys->at(j+k);
                    break;
                    case Pattern::URL:
                        url = citys->at(j+k);
                    break;
                    default:
                    break;
                }
            }
            cityResult->addCity(city,url);
            url = "";
            city = "";
        }
        offset += listCounter;
    }
    return;
}


/*******************************************************************************
 * void deleteResultList(...)
 ******************************************************************************/
void CityRequest::deleteResultList(void)
{
    if(cityResultList != NULL)
    {
        delete cityResultList;
        cityResultList = NULL;
    }
    return;
}


