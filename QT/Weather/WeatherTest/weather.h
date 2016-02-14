#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>

#define URL "http://mobile.wetter.com/wetter_aktuell/wettervorhersage/7_tagesvorhersage/?id=DE0003830012"
#define WEATHER_REG ">([\\w+|\\d]+[\\s+°C]*)<"

#define WEATHER_TEMP "\\s*([-]?\\d+)\\s*\\/\\s*\\<.*\\>([-]?\\d+)\\s*°C"
#define WEATHER_DAY_DATE "\\>(\\s*\\w+)\\<.*\\>\\s*(\\d+\\.\\d+\\.\\d+)"
#define WEATHER_SUNNSHINE "\\>\\w+\\:\\s+(\\d*[\\.\\d*]*)\\s+\\w\\<.*\\>(\\d*\\:\\d*)<.*>(\\d*\\:\\d*)
#define WEATHER_WIND ">(\\w+\\-*\\w+)\\<.*\\s*\\>\\s*\\<.*\\>(\\d+\\s+[\\w+|\\/]+)"
#define WEATER_WTYPE "\\>\\s*(\\w+\\s*[\\w+|\\-]+)[\\s*<\\/|\\w+|\\=\\\"\\-\\:\\;\\#\\>]+gefühlt"


namespace Ui {
class Weather;
}

class Weather : public QWidget
{
    Q_OBJECT
enum {
        TEMPERATUR,
        DAYS_AND_DATE,
        SUNNSHINE,
        WIND,
        WEATHER_TYPE



     }DataFilterType;
public:
    explicit Weather(QWidget *parent = 0);
    ~Weather();
    void requestWeather(QString url);
private:
    void filterWeatherData(QString data);

private:
    Ui::Weather *ui;
    QNetworkAccessManager *netManager;
    QString tWebsite;
    QStringList weatherData;

private slots:
    void dataLoadingFinished(QNetworkReply *reply);
};

#endif // WEATHER_H
