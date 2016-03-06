#include "result.h"

/*******************************************************************************
 * Result
 ******************************************************************************/
Result::Result(QObject *parent)
    : QObject(parent)
{
    country  = "";
    numberOfResults = 0;
}

/*******************************************************************************
 * Result
 ******************************************************************************/
Result::Result(int numberOfResults,QString country, QObject *parent)
    : QObject(parent)
{
    this->country  = country;
    this->numberOfResults = numberOfResults;

}

/*******************************************************************************
 * QString getCountry
 ******************************************************************************/
QString Result::getCountry() const
{
    return this->country;
}

/*******************************************************************************
 * void setCountry
 ******************************************************************************/
void Result::setCountry(const QString &value)
{
    this->country = value;
}

/*******************************************************************************
 * int getNumberOfResults
 ******************************************************************************/
int Result::getNumberOfResults() const
{
    return this->numberOfResults;
}

/*******************************************************************************
 * void setNumberOfResults
 ******************************************************************************/
void Result::setNumberOfResults(int value)
{
    this->numberOfResults = value;
}


