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
 * QString getWeatherUrl()
 ******************************************************************************/
QString Weather::getWeatherUrl(void)
{
    return QString(WEATHER_URL);
}

/*******************************************************************************
 * QString getWeatherSearchUrl()
 ******************************************************************************/
QString Weather::getWeatherSearchUrl(void)
{
    return getWeatherUrl() + QString(WEATHER_SEARCH_EXT);
}

/*******************************************************************************
 * QString getWeatherSevenDaysUrl()
 ******************************************************************************/
QString Weather::getWeatherSevenDaysUrl()
{
    return getWeatherUrl() + QString(WEATHER_SEVEN_DAYS);
}

/*******************************************************************************
 * void onFinishedRequest()
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
            web = httpRequest->getWebsite();
            search->makeWeatherForecast(web);
            emit weatherRequestFinished();
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
    QString url = getWeatherSearchUrl() + city;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_CITY,url);
}

/*******************************************************************************
 * QCityList getCityList()
 ******************************************************************************/
QCityList Weather::getCityList()
{
    return search->getCityRequest()->getCityList();
}

/*******************************************************************************
 * CityRequest* getRequestData()
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
    QString url = getWeatherSevenDaysUrl() + cityUrl;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_WEATHER,url);
}

