#include "weathercom.h"

WeatherCom::WeatherCom(QObject *parent) : QObject(parent)
{

    httpRequest = new NetworkRequest(this);
    search      = new Search(this);

    connect(httpRequest,SIGNAL(requestCompleted(NetworkRequest::RequestType)),
            this,SLOT(onFinishedRequest(NetworkRequest::RequestType)));


}


QString WeatherCom::getWeatherComUrl(void)
{
    return QString(WETHER_URL);
}

void WeatherCom::onFinishedRequest(NetworkRequest::RequestType type)
{
    QString web;

    switch(type)
    {
        case NetworkRequest::REQUEST_CITY:
            web = httpRequest->getWebsite();
            search->makeCityRequest(web);
            search->getCityRequest();
        break;
        case NetworkRequest::REQUEST_WEATHER:

        break;
        default:
        break;
    }
}


void WeatherCom::cityRequest(QString &city)
{
    QString url = getWeatherComUrl() + city;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_CITY,url);
}

