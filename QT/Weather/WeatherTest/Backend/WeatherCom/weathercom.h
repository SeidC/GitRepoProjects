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
    QNetworkReply *requestWebsite(void);
    bool isDownloadFinished(QNetworkReply* repl);

private:
    QString getWeatherComUrl(void);

private:
    NetworkRequest* httpRequest;
    QString city;



signals:

private slots:
    void downloadFinished(QNetworkReply* reply);
};

#endif // WEATHERCOM_H
