#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QString>


class Result;

/**
 * @brief QResultList
 */
typedef QList<Result*> ResultList;


/**
 * @brief The Result class
 */
class Result : public QObject
{
    Q_OBJECT
public: //Methods
    /**
     * @brief Result
     * @param parent
     */
    explicit Result(QObject *parent = 0);
    /**
     * @brief Result
     * @param sSize
     * @param sTxt
     * @param parent
     */
    Result(int sSize,QString sTxt, QObject *parent = 0);
    /**
     * @brief getCountry
     * @return
     */

    QString getCountry(void) const;
    void setCountry(const QString &value);

    int getNumberOfResults(void) const;
    void setNumberOfResults(int value);

    int getMaxStoredResults(void) const;

    bool isMaxStoredReached

public:  //Parameter
    const int maxStoredResults = 20;



private: //Parameter
    /**
     * @brief country
     */
    QString country;
    /**
     * @brief numberOfResults
     */
    int numberOfResults;

signals:

public slots:
};

#endif // RESULT_H
