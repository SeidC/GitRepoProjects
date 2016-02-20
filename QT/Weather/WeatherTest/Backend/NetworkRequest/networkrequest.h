#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class NetworkRequest : public QNetworkAccessManager
{
public:
    explicit NetworkRequest(QObject* parent = 0);
    QNetworkReply* requestURL(QString url);
};

#endif // NETWORKREQUEST_H
