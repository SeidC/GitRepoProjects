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
public:
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

    QString getCountry() const;
    void setCountry(const QString &value);

    int getNumberOfResults() const;
    void setNumberOfResults(int value);

private:
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
