#include "weather.h"


/*******************************************************************************
 * Weather(...)
 ******************************************************************************/
Weather::Weather(QObject *parent) : QObject(parent)
{
    cityRequest     = new CityRequest(this);
    weatherForecast = new WeatherForecast(this);
    httpRequest = new NetworkRequest(this);

    connect(httpRequest,SIGNAL(requestCompleted(NetworkRequest::RequestType)),
            this,SLOT(onFinishedRequest(NetworkRequest::RequestType)));


}

/*******************************************************************************
 * QString getWeatherUrl(...)
 ******************************************************************************/
QString Weather::getWeatherUrl(void)
{
    return QString(WEATHER_URL);
}

/*******************************************************************************
 * QString getWeatherSearchUrl(...)
 ******************************************************************************/
QString Weather::getWeatherSearchUrl(void)
{
    return getWeatherUrl() + QString(WEATHER_SEARCH_EXT);
}

/*******************************************************************************
 * QString getWeatherSevenDaysUrl(...)
 ******************************************************************************/
QString Weather::getWeatherSevenDaysUrl()
{
    return getWeatherUrl() + QString(WEATHER_SEVEN_DAYS);
}

/*******************************************************************************
 * void onFinishedRequest(...)
 ******************************************************************************/
void Weather::onFinishedRequest(NetworkRequest::RequestType type)
{
    QString web;

    switch(type)
    {
        case NetworkRequest::REQUEST_CITY:
            web = httpRequest->getWebsite();
            execCityRequest(web);
            emit cityRequestFinished();
        break;
        case NetworkRequest::REQUEST_WEATHER:
            web = httpRequest->getWebsite();
            execWeatherForecast(web);
            emit weatherRequestFinished();
        break;
        default:
        break;
    }
    return;
}

/*******************************************************************************
 * void cityRequest(...)
 ******************************************************************************/
void Weather::startCityRequest(QString &city)
{
    QString url = getWeatherSearchUrl() + city;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_CITY,url);
    return;
}


/*******************************************************************************
 * void weatherForcast(...)
 ******************************************************************************/
void Weather::startWeatherForcast(QString &cityUrl)
{
    QString url = getWeatherSevenDaysUrl() + cityUrl;
    httpRequest->requestWebsite(NetworkRequest::REQUEST_WEATHER,url);
    return;
}

/*******************************************************************************
 * void filterCityRequest(...)
 ******************************************************************************/
void Weather::execCityRequest(QString webSite)
{

    return;
}

/*******************************************************************************
 * void execWeatherForecast(...)
 ******************************************************************************/
void Weather::execWeatherForecast(QString website)
{

    return;
}

