#ifndef WEATHERCOM_H
#define WEATHERCOM_H

#include <QObject>
#include "networkrequest.h"
#include "search.h"

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
    void searchCity(QString &city);


private:

private:
    QString getWeatherComUrl(void);

private:
    NetworkRequest* httpRequest;
    Search* search;
    QCityList*  cityList;

private slots:
    void onFinishedRequest(NetworkRequest::RequestType type);

};

#endif // WEATHERCOM_H
