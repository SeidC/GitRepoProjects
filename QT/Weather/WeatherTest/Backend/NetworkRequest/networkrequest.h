#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class NetworkRequest : public QNetworkAccessManager
{
public:
    explicit NetworkRequest(QObject* parent = 0);
    void requestWebsite(QString websiteUrl);
    bool isDownloadFinished(void);


    QString getWebsite() const;
    void setWebsite(const QString &value);

private:

    QNetworkReply *getRequest() const;
    void setRequest(QNetworkReply *value);
    void requestURL(QString url);

private:
    QNetworkReply *request;
    QString website;

private slots:
    void downloadFinished(QNetworkReply* reply);

};

#endif // NETWORKREQUEST_H
