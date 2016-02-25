#include "weathercom.h"

WeatherCom::WeatherCom(QObject *parent) : QObject(parent)
{

    httpRequest = new NetworkRequest(this);
    searchList  = new SearchList(this);

    connect(httpRequest,SIGNAL(requestCompleted()),
            this,SLOT(onFinishedRequest()));


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
QString WeatherCom::getWeatherComUrl(void)
{
    return QString(WETHER_URL);
}

void WeatherCom::onFinishedRequest()
{

}

QString WeatherCom::getCityUrl() const
{
    return cityUrl;
}

void WeatherCom::setCityUrl(const QString &value)
{
    cityUrl = value;
}

void WeatherCom::searchCityRequest(QString &city)
{
    QString url = getWeatherComUrl() + city;
    httpRequest->requestWebsite(url);
}

