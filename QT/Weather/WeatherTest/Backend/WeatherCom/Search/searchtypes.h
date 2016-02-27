#ifndef SEARCHTYPES_H
#define SEARCHTYPES_H
#include<QList>
#include <QString>




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

typedef QList<City>     QCityList;
typedef QList<QString>  QResultList;


#endif // SEARCHTYPES_H
