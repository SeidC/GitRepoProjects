#include "weather.h"
#include "ui_weather.h"
#include <QFile>
#include <QRegularExpressionMatch>

#include <QDebug>


Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    netManager = new QNetworkAccessManager(this);
    connect(netManager,SIGNAL(finished(QNetworkReply*)),
              this,SLOT(dataLoadingFinished(QNetworkReply*)));

    ui->setupUi(this);

}

Weather::~Weather()
{
    delete ui;
}

void Weather::requestWeather(QString url)
{
    QUrl tUrl(url);
    netManager->get(QNetworkRequest(tUrl));
}


Day *Weather::getDay(Weather::WeatherDayType day)
{
    Day* ret = NULL;
    switch (day) {
    case Weather::DAY_1:
        ret = ui->Day_1;
        break;
    case Weather::DAY_2:
        ret = ui->Day_2;
        break;
    case Weather::DAY_3:
        ret = ui->Day_3;
        break;
    case Weather::DAY_4:
        ret = ui->Day_4;
        break;
    case Weather::DAY_5:
        ret = ui->Day_5;
        break;
    case Weather::DAY_6:
        ret = ui->Day_6;
        break;

    case Weather::DAY_1:

        break;
    default:
        break;
    }
    return ret;
}

void Weather::filterWeatherData(QString data)
{
    QRegularExpression regExp;
    QRegularExpressionMatch match;

    regExp.setPattern(WEATHER_REG);
    //weatherData = regExp.match(data,0,QRegularExpression::NormalMatch,QRegularExpression::NoMatchOption).capturedTexts();
    QRegularExpressionMatchIterator iter = regExp.globalMatch(data);
    while(iter.hasNext())
    {
       qDebug() << iter.next().captured(1);

    }
    return;
}


void Weather::dataLoadingFinished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QFile file("Test.html");
    file.open(QIODevice::WriteOnly);
    file.write(data);
    filterWeatherData(QString(data));

//    for (int i = 0; i < weatherData.size(); i++)
//    {
//        QString dump = weatherData.at(i);
//        qDebug()<< weatherData.at(i);
//        file.write(dump.toLocal8Bit());
//    }
}


