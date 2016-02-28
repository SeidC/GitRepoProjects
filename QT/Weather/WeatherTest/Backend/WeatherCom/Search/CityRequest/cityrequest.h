#ifndef CITYREQUEST_H
#define CITYREQUEST_H

#include <QObject>
#include <QList>
#include "city.h"
#include "result.h"


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
     * @brief getCityResults
     * @return
     */
    QResultList getCityResults() const;
    /**
     * @brief setCityResults
     * @param value
     */
    void setCityResults(QResultList value);
    /**
     * @brief getCityList
     * @return
     */
    QCityList getCityList() const;
    /**
     * @brief setCityList
     * @param value
     */
    void setCityList(QCityList value);
    /**
     * @brief add
     * @param city
     * @param url
     */
    void add(QString city, QString url);
    /**
     * @brief add
     * @param size
     * @param txt
     */
    void add(int size, QString txt);
private:
    /**
     * @brief cityResults
     */
    QResultList cityResults;
    /**
     * @brief cityList
     */
    QCityList   cityList;
};

#endif // CITYREQUEST_H
