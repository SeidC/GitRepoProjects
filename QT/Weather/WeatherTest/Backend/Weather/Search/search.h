#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include "regexpdefs.h"



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
    QStringList searchCitys(QString websiteToSearch);
    /**
     * @brief searchResults
     * @param websiteToSearch
     *
     * This method allows to search Results of the given Website.
     * Results are number of found citys in of different countrys.
     */
    QStringList searchResults(QString websiteToSearch);

    QStringList searchRain(QString websiteToSerach);

    QStringList searchTemperature(QString websiteToSearch);

    QStringList searchSunshine(QString websiteToSearch);

    QStringList searchWind(QString websiteToSearch);

private:


private:
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
