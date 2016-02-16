#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class NetworkRequest : public QNetworkAccessManager
{
public:
    NetworkRequest();
};

#endif // NETWORKREQUEST_H
