#include "weathercom.h"

WeatherCom::WeatherCom(QObject *parent) : QObject(parent)
{

    httpRequest = new NetworkRequest(this);

    connect(httpRequest,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(downloadFinished(QNetworkReply*)));


}

void WeatherCom::setCity(QString cityName)
{
    city = cityName;
    return;
}

QString WeatherCom::getCity(void)
{
    return city;
}

QNetworkReply * WeatherCom::requestWebsite(void)
{
    QString url;
    QNetworkReply* ret;
    if (!getCity().isEmpty())
    {
        url = getWeatherComUrl() + getCity();
        ret = httpRequest->requestURL(url);
    }
    return ret;
}

QString WeatherCom::getWeatherComUrl(void)
{
    return QString(WETHER_URL);
}


bool WeatherCom::isDownloadFinished(QNetworkReply* reply)
{
    bool status = false;
    if (reply != NULL)
    {
        status = reply->isFinished();
    }
    return status;
}

void WeatherCom::downloadFinished(QNetworkReply *reply)
{

}
