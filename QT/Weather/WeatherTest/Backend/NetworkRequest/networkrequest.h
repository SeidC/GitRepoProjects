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
    typedef enum {
            REQUEST_CITY = 0,
            REQUEST_WEATHER,
            REQUEST_NOT_AVAILABLE,

        }RequestType;
public:
    explicit NetworkRequest(QObject* parent = 0);

    void requestWebsite(RequestType type,QString websiteUrl);

    bool isDownloadFinished(void);


    QString getWebsite() const;


private:

    QNetworkReply *getRequest() const;
    void setRequest(QNetworkReply *value);
    void requestURL(QString url);
    void setWebsite(const QString &value);

    RequestType getCurrentRequest() const;
    void setCurrentRequest(const RequestType &value);
    void resetCurrentRequest(void);


private:
    QNetworkReply *request;
    QString website;
    RequestType currentRequest;

Q_SIGNALS:
    void requestCompleted(NetworkRequest::RequestType type);

private Q_SLOTS:
    void downloadFinished(QNetworkReply* reply);

};

#endif // NETWORKREQUEST_H
