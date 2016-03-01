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
     *
     */
    ~CityRequest();
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

    /**
     * @brief deleteEntries
     */
    void deleteEntries(void);
private:
    /**
     * @brief deleteResults
     */
    void deleteResults(void);
    /**
     * @brief deleteCitys
     */
    void deleteCitys(void);
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
