#include "weather.h"


/*******************************************************************************
 * Weather
 ******************************************************************************/
Weather::Weather(QObject *parent) : QObject(parent)
{

    httpRequest = new NetworkRequest(this);
    search      = new Search(this);

    connect(httpRequest,SIGNAL(requestCompleted(NetworkRequest::RequestType)),
            this,SLOT(onFinishedRequest(NetworkRequest::RequestType)));


}

/*******************************************************************************
 * Weather
 ******************************************************************************/
QString Weather::getWeatherUrl(void)
{
    return QString(WETHER_URL);
}

/*******************************************************************************
 * Weather
 ******************************************************************************/
void Weather::onFinishedRequest(NetworkRequest::RequestType type)
{
    QString web;

    switch(type)
    {
        case NetworkRequest::REQUEST_CITY:
            web = httpRequest->getWebsite();
            search->makeCityRequest(web);
            emit cityRequestFinished();
        break;
        case NetworkRequest::REQUEST_WEATHER:

        break;
        default:
        break;
    }
}

/*******************************************************************************
 * void cityRequest()
 ******************************************************************************/
void Weather::cityRequest(QString &city)
{
    QString url = getWeatherUrl() + city;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_CITY,url);
}

QCityList Weather::getCityList()
{
    return search->getCityRequest()->getCityList();
}

/*******************************************************************************
 * CityRequest * getRequestData()
 ******************************************************************************/
CityRequest *Weather::getCityRequestData(void)
{
    return search->getCityRequest();
}

/*******************************************************************************
 * void weatherForcast()
 ******************************************************************************/
void Weather::weatherForcast(QString &cityUrl)
{

}

