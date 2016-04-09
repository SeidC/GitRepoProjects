#include "city.h"
#include "patternhandler.h"


/*******************************************************************************
 * City(...)
 ******************************************************************************/
City::City(QObject *parent) : QObject(parent)
{
    city = "";
    url = "";
}

/*******************************************************************************
 * City(...)
 ******************************************************************************/
City::City(QString sCity, QString sUrl, QObject *parent) : QObject(parent)
{
    city = sCity;
    url = sUrl;
    return;
}

/*******************************************************************************
 * QString getCity(...)
 ******************************************************************************/
QString City::getCity() const
{
    return city;
}

/*******************************************************************************
 * void setCity(...)
 ******************************************************************************/
void City::setCity(const QString &value)
{
    city = value;
}

/*******************************************************************************
 * QString getUrl(...)
 ******************************************************************************/
QString City::getUrl() const
{
    return url;
}

/*******************************************************************************
 * void setUrl(...)
 ******************************************************************************/
void City::setUrl(const QString &value)
{
    url = value;
}

/*******************************************************************************
 * QStringList getUrlId(...)
 *******************************************************************************/
QStringList *City::getUrlId(QString url)
{
    Pattern *pattern = PatternHandler::getInstance()->
                                getPattern(PatternHandler::ULR_ID);
    RegExp reg;
    QStringList *lst = reg.findRegExp(url,*pattern);
    return lst;
}
