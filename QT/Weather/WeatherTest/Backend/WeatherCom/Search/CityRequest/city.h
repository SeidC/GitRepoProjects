#ifndef CITY_H
#define CITY_H

#include <QObject>
#include <QString>

class City;

/**
 * @brief QCityList
 */
typedef QList<City*> QCityList;


/**
 * @brief The City class
 */
class City : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief City
     * @param parent
     */
    explicit City(QObject *parent = 0);
    /**
     * @brief City
     * @param sCity
     * @param sUrl
     * @param parent
     */
    City(QString sCity, QString sUrl, QObject *parent = 0);
    /**
     * @brief getCity
     * @return
     */
    QString getCity() const;
    /**
     * @brief setCity
     * @param value
     */
    void setCity(const QString &value);
    /**
     * @brief getUrl
     * @return
     */
    QString getUrl() const;
    /**
     * @brief setUrl
     * @param value
     */
    void setUrl(const QString &value);

private:
    /**
     * @brief city
     */
    QString city;
    /**
     * @brief url
     */
    QString url;
};

#endif // CITY_H
