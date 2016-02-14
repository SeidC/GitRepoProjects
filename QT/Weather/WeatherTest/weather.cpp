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


