#ifndef CITYRESULT_H
#define CITYRESULT_H

#include <QObject>
#include <QList>
#include <QString>
#include "city.h"
#include "result.h"

class CityResult;

typedef QList<CityResult*> CityResultList;


class CityResult : public QObject
{
    Q_OBJECT
public:
    explicit CityResult(QObject *parent = 0);

    void addResult(QString country, int numberOfResults);
    void addCity(QString city,QString url);

private:

    Result results;
    CityList cityList;
signals:

public slots:
};

#endif // CITYRESULT_H
