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

WeatherCom::DownloadType WeatherCom::requestWebsite(QNetworkReply *replyRet)
{
    QString url;
    QNetworkReply* rep;
    WeatherCom::DownloadType ret = WeatherCom::DOWNLOAD_CITY_FAILED;

    if (!getCity().isEmpty())
    {
        url = getWeatherComUrl() + getCity();
        rep = httpRequest->requestURL(url);
        if (replyRet != NULL)
        {
            replyRet = rep;
        }
        ret = WeatherCom::DOWNLOAD_STARTED;
    }
    return ret;
}

QString WeatherCom::getWeatherComUrl(void)
{
    return QString(WETHER_URL);
}




void WeatherCom::downloadFinished(QNetworkReply *reply)
{

}
