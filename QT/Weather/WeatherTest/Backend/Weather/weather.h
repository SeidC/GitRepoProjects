#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include "networkrequest.h"
#include "search.h"

#define WETHER_URL "http://mobile.wetter.com/suche/?q="


class Weather : public QObject
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
    explicit Weather(QObject *parent = 0);
    void setCity(QString cityName);
    void cityRequest(QString &city);
    void weatherForcast(void);

private:

private:
    QString getWeatherUrl(void);

private:
    NetworkRequest* httpRequest;
    Search* search;

private slots:
    void onFinishedRequest(NetworkRequest::RequestType type);

};

#endif // WEATHER_H
