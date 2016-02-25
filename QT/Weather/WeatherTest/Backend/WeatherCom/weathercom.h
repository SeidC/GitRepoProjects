#ifndef WEATHERCOM_H
#define WEATHERCOM_H

#include <QObject>
#include "networkrequest.h"
#include "searchlist.h"

#define WETHER_URL "http://mobile.wetter.com/suche/?q="


class WeatherCom : public QObject
{
    Q_OBJECT
public:
    typedef enum
    {
        DOWNLOAD_ERROR = 0,
        DOWNLOAD_STARTED,
        DOWNLOAD_CITY_FAILED,
        DOWNLOAD_SUCCESS,

    }DownloadType;


public:
    explicit WeatherCom(QObject *parent = 0);
    void setCity(QString cityName);
    QString getCity(void);

    QString getCityUrl() const;
    void setCityUrl(const QString &value);

    void searchCityRequest(QString &city);


private:
    QString getWeatherComUrl(void);

private:
    NetworkRequest* httpRequest;
    SearchList* searchList;
    QString city;
    QString cityUrl;

private slots:
    void onFinishedRequest(void);

};

#endif // WEATHERCOM_H
