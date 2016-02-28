#ifndef CITYREQUEST_H
#define CITYREQUEST_H

#include <QObject>
#include <QList>
#include "city.h"
#include "result.h"


typedef QList<City> QCityList;
typedef QList<Result> QResultList;


class CityRequest : public QObject
{
public:
    explicit CityRequest(QObject *parent = 0);
    CitiRequest();

    QResultList *getCityResults() const;
    void setCityResults(QResultList *value);

    QCityList *getCityList() const;
    void setCityList(QCityList *value);

    void add(QString city, QString url);
    void add(int size, QString txt);


private:
    QResultList *cityResults;
    QCityList   *cityList;
};

#endif // CITYREQUEST_H
