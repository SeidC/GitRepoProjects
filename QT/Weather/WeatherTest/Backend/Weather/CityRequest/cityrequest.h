#ifndef CITYREQUEST_H
#define CITYREQUEST_H

#include <QObject>
#include <QList>
#include "cityresult.h"
#include "search.h"


/**
 * @brief The CityRequest class
 */
class CityRequest : public QObject
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

    FilterStatus_t filterData(QString webData);

private:
     CityResultList *createCityResultList(QStringList *citys, QStringList *results);

private:
    CityResultList *cityResultList;
    Search search;

};

#endif // CITYREQUEST_H
