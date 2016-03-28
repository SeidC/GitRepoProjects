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

public: //Datatypes
    typedef enum
    {
        FILTERN_OK            = 0x00,
        FILTERN_NOT_SUPPORTED = 0xFF,

    }FilterStatus_t;


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
     * @param cityPattern
     *
     * This method allows to search Citys with URLs of a given Website
     * The results will be stored in the parameter cityRequest
     */
    QStringList *searchCitys(QString websiteToSearch, Pattern &cityPattern);
    /**
     * @brief searchResults
     * @param websiteToSearch
     * @param resultPattern
     *
     * This method allows to search Results of the given Website.
     * Results are number of found citys in of different countrys.
     */
    QStringList *searchResults(QString websiteToSearch, Pattern &resultPattern);
    /**
     * @brief searchRain
     * @param websiteToSerach
     * @param rainPattern
     * @return
     */
    QStringList *searchRain(QString websiteToSerach, Pattern &rainPattern);
    /**
     * @brief searchTemperature
     * @param websiteToSearch
     * @param temperaturePattern
     * @return
     */
    QStringList *searchTemperature(QString websiteToSearch,Pattern &temperaturePattern);
    /**
     * @brief searchSunshine
     * @param websiteToSearch
     * @param sunshinePattern
     * @return
     */
    QStringList *searchSunshine(QString websiteToSearch, Pattern &sunshinePattern);
    /**
     * @brief searchWind
     * @param websiteToSearch
     * @param windPattern
     * @return
     */
    QStringList *searchWind(QString websiteToSearch, Pattern &windPattern);
    /**
     * @brief searchTypes
     * @param websiteToSearch
     * @param typePattern
     * @return
     */
    QStringList *searchTypes(QString websiteToSearch, Pattern &typePattern);


    virtual FilterStatus_t filterData(QString webData) = 0;
private:
    /**
     * @brief search
     * @param txt
     * @param pattern
     * @return
     */
    QStringList *search(QString &txt, Pattern &pattern);

signals:

public slots:
};

#endif // Search_H
