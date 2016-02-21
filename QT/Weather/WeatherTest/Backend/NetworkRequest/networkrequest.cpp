#include "networkrequest.h"

NetworkRequest::NetworkRequest(QObject *parent)
    : QNetworkAccessManager(parent)
{

}

QNetworkReply *NetworkRequest::requestURL(QString url)
{
    QUrl qUrl(url);
    return get(QNetworkRequest(qUrl));
}


QNetworkReply * NetworkRequest::requestWebsite(void)
{
    QString url;
    QNetworkReply* ret;
    if (!getCity().isEmpty())
//    {
//        url = getWeatherComUrl() + getCity();
//        ret = httpRequest->requestURL(url);
//    }
    return ret;
}


bool NetworkRequest::isDownloadFinished(QNetworkReply* reply)
{
    bool status = false;
    if (reply != NULL)
    {
        status = reply->isFinished();
    }
    return status;
}

void NetworkRequest::downloadFinished(QNetworkReply *reply)
{

}
