#include "city.h"
#include "regexp.h"


/*******************************************************************************
 * City
 ******************************************************************************/
City::City(QObject *parent) : QObject(parent)
{
    city = "";
    url = "";
}

/*******************************************************************************
 * City
 ******************************************************************************/
City::City(QString sCity, QString sUrl, QObject *parent) : QObject(parent)
{
    city = sCity;
    url = sUrl;
    return;
}

/*******************************************************************************
 * QString getCity()
 ******************************************************************************/
QString City::getCity() const
{
    return city;
}

/*******************************************************************************
 * void setCity()
 ******************************************************************************/
void City::setCity(const QString &value)
{
    city = value;
}

/*******************************************************************************
 * QString getUrl()
 ******************************************************************************/
QString City::getUrl() const
{
    return url;
}

/*******************************************************************************
 * void setUrl()
 ******************************************************************************/
void City::setUrl(const QString &value)
{
    url = value;
}

QStringList City::getUrlId(QString url)
{
    Pattern pattern("([A-Z]\\w+)");
    pattern.addMatchType(Pattern::URL_ID);
    RegExp reg;
    QStringList lst = reg.findRegExp(url,pattern);
    return lst;
}

