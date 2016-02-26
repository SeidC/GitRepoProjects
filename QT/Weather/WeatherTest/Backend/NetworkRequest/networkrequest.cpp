#include "networkrequest.h"

NetworkRequest::NetworkRequest(QObject *parent) : QNetworkAccessManager(parent)
{
    request = NULL;
    connect(this,SIGNAL(finished(QNetworkReply*)),SLOT(downloadFinished(QNetworkReply*)));

}

void NetworkRequest::requestURL(QString url)
{
    QUrl qUrl(url);
    get(QNetworkRequest(qUrl));
    return;
}

QString NetworkRequest::getWebsite() const
{
    return website;
}

void NetworkRequest::setWebsite(const QString &value)
{
    website = value;
    return;
}

RequestType NetworkRequest::getCurrentRequest() const
{
    return currentRequest;
}

void NetworkRequest::setCurrentRequest(const RequestType &value)
{
    currentRequest = value;
}

void NetworkRequest::resetCurrentRequest()
{
    currentRequest = NetworkRequest::REQUEST_NOT_AVAILABLE;
}


void NetworkRequest::requestWebsite(NetworkRequest::RequestType type,QString websiteUrl)
{
    setRequest(type);
    requestURL(websiteUrl);
    return;
}


bool NetworkRequest::isDownloadFinished(void)
{
    bool status = false;
    if (getRequest() != NULL)
    {
        status = getRequest()->isFinished();
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
    return;
}

void NetworkRequest::downloadFinished(QNetworkReply *reply)
{
    QByteArray rawData;
    setRequest(reply);
    rawData = reply->readAll();
    setWebsite(QString(rawData));
    emit requestCompleted(getCurrentRequest());
    resetCurrentRequest();
    return;
}
