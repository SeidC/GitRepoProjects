#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include "networkrequest.h"
#include "cityrequest.h"
#include "weatherforecast.h"

#define WEATHER_URL         "http://mobile.wetter.com/"
#define WEATHER_SEARCH_EXT  "suche/?q="
#define WEATHER_SEVEN_DAYS  "wetter_aktuell/wettervorhersage/7_tagesvorhersage/?id="

class Weather : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Weather
     * @param parent Pointer to parent Object
     *
     * Constructor for the weather class
     */
    explicit Weather(QObject *parent = 0);
    /**
     * @brief Start City Request
     * @param city String of City which has to be searched
     *
     * Metode to initiate a search request of a City.
     * This will make a html request an returns a List of City and URLs
     */
    void startCityRequest(QString &city);
    /**
     * @brief Start Weather Forcast
     * @param cityUrl
     */
    void startWeatherForcast(QString &cityUrl);

private:
    /**
     * @brief Execute City Request
     * @param webSite - String which contains the Website to filter all cities and results.
     *
     *
     */
    void execCityRequest(QString webSite);
    /**
     * @brief Execute Weather Forecast
     * @param website
     */
    void execWeatherForecast(QString website);

private:
    /**
     * @brief Get Weather Url
     * @return String of the weather.com Url
     *
     * Getter Methode to get the weather.com url
     */
    QString getWeatherUrl(void);
    /**
     * @brief Get Weather Search Url
     * @return String of the weather.com Url with Search extension.
     *
     * Getter Methode to get the weather.com search url.
     */
    QString getWeatherSearchUrl(void);
    /**
     * @brief Get Weather Seven Days Url
     * @return String of the weather.com Url with seven days request.
     *
     * Getter Methode to get the weather.com seven days request.
     */
    QString getWeatherSevenDaysUrl(void);

private:
    /**
     * @brief Http Request
     */
    NetworkRequest *httpRequest;
    /**
     * @brief City Request
     */
    CityRequest *cityRequest;
    /**
     * @brief Weather Forecast
     */
    WeatherForecast *weatherForecast;

signals:
    /**
     * @brief City Request Finished
     */
    void cityRequestFinished(void);
    /**
     * @brief Weather Request Finished
     */
    void weatherRequestFinished(void);

private slots:
    /**
     * @brief On Finished Request
     * @param type
     */
    void onFinishedRequest(NetworkRequest::RequestType type);

};

#endif // WEATHER_H
