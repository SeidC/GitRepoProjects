#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include "searchtypes.h"



/**
 * @brief The Search class
 */
class Search : public QObject
{
    Q_OBJECT

public:
    explicit Search(QObject *parent = 0);

    void searchCitys(QString strToFilter);
    void searchResults(QString strToFilter);


    QCityList *getCitys(void);
    QResultList *getCityResults() const;

private:
    QResultList *cityResults;
    QCityList *cityList;


private:
    QStringList search(QString &txt, Pattern &pattern);

signals:

public slots:
};

#endif // Search_H
