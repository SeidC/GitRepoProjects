#ifndef CITYREQUEST_H
#define CITYREQUEST_H

#include <QObject>
#include <QList>
#include "cityresult.h"
#include "search.h"
#include "Data.h"

/**
 * @brief The CityRequest class
 */
class CityRequest : public QObject, public Data
{
public:
    typedef enum
    {
        FILTER_OK   = 0x00,

    }FilterStatus_t;

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

private:
     CityResultList *createCityResultList(QStringList *citys, QStringList *results, Pattern &cityPattern, Pattern &resultPattern);
     void setResultsToList(CityResultList *list, QStringList *results, Pattern &resultPattern);
     void setCitysToList  (CityResultList *list, QStringList *citys, Pattern &cityPattern);
private:
    CityResultList *cityResultList;
    Search search;

};

#endif // CITYREQUEST_H
