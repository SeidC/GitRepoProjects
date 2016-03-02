#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include "regexpdefs.h"
#include "cityrequest.h"
#include "weatherforecast.h"



/**
 * @brief The Search class
 */
class Search : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Search
     * @param parent
     *
     * Constructor of the Search Class
     */
    explicit Search(QObject *parent = 0);


    /**
     * @brief searchCitys
     * @param websiteToSearch Website which should be searched
     *
     * This method allows to search Citys with URLs of a given Website
     * The results will be stored in the parameter cityRequest
     */
    void searchCitys(QString websiteToSearch);
    /**
     * @brief searchResults
     * @param websiteToSearch
     *
     * This method allows to search Results of the given Website.
     * Results are number of found citys in of different countrys.
     */
    void searchResults(QString websiteToSearch);

    void searchRain(QString websiteToSerach);

    void searchTemperature(QString websiteToSearch);

    void searchSunshine(QString websiteToSearch);

    void searchWind(QString websiteToSearch);
    /**
     * @brief makeCityRequest
     * @param websiteToSearch
     *
     * This method makes a combined reques to search citys and results.
     * Both results will be sotred in the pareameter cityrequest.
     */
    void makeCityRequest(QString websiteToSearch);

    /**
     * @brief getCityRequest
     * @return
     *
     * This Getter - methode returns the parameter cityRequest, wich contains all
     * found Citys and Results
     */
    CityRequest *getCityRequest(void) const;
    
    /**
     * @brief makeWeatherForecast
     * @param websiteToSearch
     */
    void makeWeatherForecast(QString websiteToSearch);
private:
    /**
     * @brief cityRequest
     */
    CityRequest *cityRequest;
    /**
     * @brief weatherForecast
     */
    WeatherForecast *weatherForecast;



private:
    /**
     * @brief search
     * @param txt
     * @param pattern
     * @return
     */
    QStringList search(QString &txt, Pattern &pattern);

    /**
     * @brief newCityRequest
     *
     * This methode creats a new object of the class CitiyRequest.
     * If a CityRequest Object is allready exist, then the current data will
     * be deleted.
     */
    void newCityRequest(void);
signals:

public slots:
};

#endif // Search_H
