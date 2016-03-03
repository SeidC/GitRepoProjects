#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include "weather.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(startRequest(bool)));
    connect(&weather,SIGNAL(cityRequestFinished()),this,SLOT(execAfterRequest()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(startWeather(bool)));
    requestStatus = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startRequest(bool clicked)
{
    QString city = ui->lineEdit->text();
    for(int i = ui->comboBox->count() - 1; i >= 0;i--)
    {
        ui->comboBox->removeItem(i);
    }

    weather.cityRequest(city);
}

void Widget::startWeather(bool clicked)
{
    QCityList lst = weather.getCityList();
    int index = ui->comboBox->currentIndex();
    QString url = lst.at(index)->getUrl();
    url = lst.at(index)->getUrlId(url).at(0);
    weather.weatherForcast(url);

}

void Widget::execAfterRequest()
{
    QCityList req = weather.getCityList();

    for(int i = 0; i< req.size(); i++)
    {
       QString txt = req.at(i)->getCity();
       ui->comboBox->addItem(txt);
    }
    requestStatus = true;
}

