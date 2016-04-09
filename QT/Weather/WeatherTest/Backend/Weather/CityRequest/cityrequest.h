#ifndef CITYREQUEST_H
#define CITYREQUEST_H

#include <QObject>
#include <QList>
#include "cityresult.h"
#include "search.h"


/**
 * @brief The CityRequest class
 */
class CityRequest : public Search
{
public:


public:
    /**
     * @brief CityRequest
     * @param parent
     */
    explicit CityRequest(QObject *parent = 0);

    /**
     *
     */
    ~CityRequest();
    /**
     * @brief filterData
     * @param webData
     * @return
     */
    FilterStatus_t filterData(QString webData);

    QStringList* getListOfCities(QString country);

    QStringList *getListOfCountries(void);

    int getCountryListIndex(QString country);
private:
     CityResultList *createCityResultList(QStringList *citys, QStringList *results, Pattern &cityPattern, Pattern &resultPattern);
     void setResultsToList(CityResultList *list, QStringList *results, Pattern &resultPattern);
     void setCitysToList  (CityResultList *list, QStringList *citys, Pattern &cityPattern);
     void deleteResultList(void);

private:
    CityResultList *cityResultList;


};

#endif // CITYREQUEST_H
