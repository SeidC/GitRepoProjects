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
