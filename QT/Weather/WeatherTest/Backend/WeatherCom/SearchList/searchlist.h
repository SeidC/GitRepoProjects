#ifndef SEARCHLIST_H
#define SEARCHLIST_H

#include <QObject>
#include "regexp.h"

#define NR_POS 0

#define P_POS 0
#define U_POS 1


class City
{
public:
    City(QString sCity, QString sUrl) {city = sCity; url = sUrl;}

    QString getCity() const;
    void setCity(const QString &value);

    QString getUrl() const;
    void setUrl(const QString &value);

private:
    QString city;
    QString url;

};

typedef QList<City> QCityList;

class SearchList : public QObject
{
    Q_OBJECT
private:
    typedef enum
    {
        SEARCH_NUMBER_OF_RESULTS,
        SEARCH_PLACES,
        SEARCH_URLS,

    }SearchType;
public:
    explicit SearchList(QObject *parent = 0);

    void searchCitys(QString strToFilter);

    int getNumberOfResults(void);
    QCityList *getCitys(void);

private:
    int numberOfResults;
    QCityList* cityList;


private:
    int search(QString &txt, Pattern pattern);
    QCityList *search(QString &txt, Pattern &pattern);

signals:

public slots:
};

#endif // SEARCHLIST_H
