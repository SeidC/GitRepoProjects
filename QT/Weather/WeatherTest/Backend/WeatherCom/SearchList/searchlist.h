#ifndef SEARCHLIST_H
#define SEARCHLIST_H

#include <QObject>
#include "regexp.h"

#define NR_POS 0

#define P_POS 0
#define U_POS 1

class SearchList : public QObject
{
    Q_OBJECT
private:
    typedef enum
    {
        SEARCH_NUMBER_OF_RESULTS,
        SEARCH_PLACES,
        SEARCH_URLS,

    }SearchType;
public:
    explicit SearchList(QObject *parent = 0);


    void searchNumberOfResults(QString &txt);
    void searchPlaces(QString &txt);
    void searchUrl(QString &txt);

    int getNumberOfResults(void);
    QStringList getPlaces(void);
    QStringList getUrl();

private:
    int numberOfResults;
    QStringList places;
    QStringList url;

private:
    int search(QString &txt);
    QStringList search(QString &txt, SearchType type);

signals:

public slots:
};

#endif // SEARCHLIST_H
