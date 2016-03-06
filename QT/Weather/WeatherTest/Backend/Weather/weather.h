#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include "networkrequest.h"
#include "search.h"

#define WEATHER_URL         "http://mobile.wetter.com/"
#define WEATHER_SEARCH_EXT  "suche/?q="
#define WEATHER_SEVEN_DAYS  "wetter_aktuell/wettervorhersage/7_tagesvorhersage/?id="

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
    /**
     * @brief Weather
     * @param parent Pointer to parent Object
     *
     * Constructor for the weather class
     */
    explicit Weather(QObject *parent = 0);
    /**
     * @brief cityRequest
     * @param city String of City which has to be searched
     *
     * Metode to initiate a search request of a City.
     * This will make a html request an returns a List of City and URLs
     */
    void cityRequest(QString &city);
    /**
     * @brief weatherForcast
     * @param cityUrl
     */
    void weatherForcast(QString &cityUrl);
    /**
     * @brief getCityRequestData
     * @return Pointer of a City Request Object
     *
     * This Methode returns the data after a  cityRequest was done.
     */
    CityRequest* getCityRequestData(void);
    /**
     * @brief getCityList
     * @return List of Citys
     *
     * This Methode returns a List of Citys. This List is also available
     * in the CityRequest Obect. see getCityRequestData
     */
    QCityList getCityList(void);

private:

private:
    QString getWeatherUrl(void);
    QString getWeatherSearchUrl(void);
    QString getWeatherSevenDaysUrl(void);

private:
    NetworkRequest* httpRequest;
    CityRequest *cityRequest;
    WeatherForecast *weatherForecast;


signals:
    void cityRequestFinished(void);
    void weatherRequestFinished(void);

private slots:
    void onFinishedRequest(NetworkRequest::RequestType type);

};

#endif // WEATHER_H
