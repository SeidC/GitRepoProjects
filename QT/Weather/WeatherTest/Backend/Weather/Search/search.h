#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include "pattern.h"



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



private:
    /**
     * @brief searchCitys
     * @param websiteToSearch Website which should be searched
     * @param cityPattern
     *
     * This method allows to search Citys with URLs of a given Website
     * The results will be stored in the parameter cityRequest
     */
    QStringList searchCitys(QString websiteToSearch, Pattern &cityPattern);
    /**
     * @brief searchResults
     * @param websiteToSearch
     * @param resultPattern
     *
     * This method allows to search Results of the given Website.
     * Results are number of found citys in of different countrys.
     */
    QStringList searchResults(QString websiteToSearch, Pattern &resultPattern);
    /**
     * @brief searchRain
     * @param websiteToSerach
     * @param rainPattern
     * @return
     */
    QStringList searchRain(QString websiteToSerach, Pattern &rainPattern);
    /**
     * @brief searchTemperature
     * @param websiteToSearch
     * @param temperaturePattern
     * @return
     */
    QStringList searchTemperature(QString websiteToSearch,Pattern &temperaturePattern);
    /**
     * @brief searchSunshine
     * @param websiteToSearch
     * @param sunshinePattern
     * @return
     */
    QStringList searchSunshine(QString websiteToSearch, Pattern &sunshinePattern);
    /**
     * @brief searchWind
     * @param websiteToSearch
     * @param windPattern
     * @return
     */
    QStringList searchWind(QString websiteToSearch, Pattern &windPattern);
    /**
     * @brief search
     * @param txt
     * @param pattern
     * @return
     */
    QStringList search(QString &txt, Pattern &pattern);

signals:

public slots:
};

#endif // Search_H
