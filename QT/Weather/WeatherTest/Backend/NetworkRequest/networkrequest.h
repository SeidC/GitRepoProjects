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
    QNetworkReply *requestWebsite(void);
    bool isDownloadFinished(QNetworkReply* repl);

private slots:
  void downloadFinished(QNetworkReply* reply);

};

#endif // NETWORKREQUEST_H
