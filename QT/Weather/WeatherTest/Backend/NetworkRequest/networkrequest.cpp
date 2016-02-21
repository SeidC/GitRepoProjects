#include "networkrequest.h"

NetworkRequest::NetworkRequest(QObject *parent)
    : QNetworkAccessManager(parent)
{
    request = new QNetworkReply();
}

void NetworkRequest::requestURL(QString url)
{
    QNetworkReply *req;
    QUrl qUrl(url);
    req = get(QNetworkRequest(qUrl));
    setRequest(req);
    return;
}


void NetworkRequest::requestWebsite(QString websiteUrl)
{

    return;
}


bool NetworkRequest::isDownloadFinished(void)
{
    bool status = false;
    if (reply != NULL)
    {
        status = reply->isFinished();
    }
    return status;
}

QNetworkReply *NetworkRequest::getRequest() const
{
    return request;
}

void NetworkRequest::setRequest(QNetworkReply *value)
{
    request = value;
}

void NetworkRequest::downloadFinished(QNetworkReply *reply)
{

}
