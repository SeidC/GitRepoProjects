#ifndef CITY_H
#define CITY_H

#include <QObject>
#include <QString>

class City : public QObject
{
    Q_OBJECT

public:
    explicit City(QObject *parent = 0);
    City(QString sCity, QString sUrl, QObject *parent = 0);

    QString getCity() const;
    void setCity(const QString &value);

    QString getUrl() const;
    void setUrl(const QString &value);

private:
    QString city;
    QString url;
};

#endif // CITY_H
