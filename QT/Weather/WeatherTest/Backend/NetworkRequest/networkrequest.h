#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>

class NetworkRequest : public QNetworkAccessManager
{

    Q_OBJECT

public:
    explicit NetworkRequest(QObject* parent = 0);
    void requestWebsite(QString websiteUrl);
    bool isDownloadFinished(void);


    QString getWebsite() const;


private:

    QNetworkReply *getRequest() const;
    void setRequest(QNetworkReply *value);
    void requestURL(QString url);
    void setWebsite(const QString &value);
private:
    QNetworkReply *request;
    QString website;

Q_SIGNALS:
    void requestCompleted(void);

private Q_SLOTS:
    void downloadFinished(QNetworkReply* reply);

};

#endif // NETWORKREQUEST_H
