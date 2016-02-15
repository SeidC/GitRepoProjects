#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>
#include "day.h"

#define URL "http://mobile.wetter.com/wetter_aktuell/wettervorhersage/7_tagesvorhersage/?id=DE0003830012"
#define WEATHER_REG ">([\\w+|\\d]+[\\s+°C]*)<"

#define WEATHER_TEMP "\\s*([-]?\\d+)\\s*\\/\\s*\\<.*\\>([-]?\\d+)\\s*°C"
#define WEATHER_DAY_DATE "\\>(\\s*\\w+)\\<.*\\>\\s*(\\d+\\.\\d+\\.\\d+)"
#define WEATHER_SUNNSHINE "\\>\\w+\\:\\s+(\\d*[\\.\\d*]*)\\s+\\w\\<.*\\>(\\d*\\:\\d*)<.*>(\\d*\\:\\d*)"
#define WEATHER_WIND ">(\\w+\\-*\\w+)\\<.*\\s*\\>\\s*\\<.*\\>(\\d+\\s+[\\w+|\\/]+)"
#define WEATER_WTYPE "\\>\\s*(\\w+\\s*[\\w+|\\-]+)[\\s*<\\/|\\w+|\\=\\\"\\-\\:\\;\\#\\>]+gefühlt"


namespace Ui {
class Weather;
}

class Weather : public QWidget
{
    Q_OBJECT
enum {
        TEMPERATUR = 0,
        DAYS_AND_DATE,
        SUNNSHINE,
        WIND,
        WEATHER_TYPE

     }DataFilterType;

enum {
        DAY_INFO = 0,
        DAY_GRFICS

     }WeatherGuiType;

enum {
        DAY_1 = 0,
        DAY_2,
        DAY_3,
        DAY_4,
        DAY_5,
        DAY_6,
        DAY_7,
        NUMBER_OF_DAYS

     }WeatherDayType;

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
