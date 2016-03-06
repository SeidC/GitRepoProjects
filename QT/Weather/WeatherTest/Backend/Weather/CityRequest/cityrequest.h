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
    /**
     * @brief CityRequest
     * @param parent
     */
    explicit CityRequest(QObject *parent = 0);

    /**
     *
     */
    ~CityRequest();

private:

private:
    CityResult *cityResult;
    Search* search;
};

#endif // CITYREQUEST_H
