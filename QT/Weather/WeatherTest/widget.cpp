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
    connect(ui->countryBox,SIGNAL(currentIndexChanged(QString)),
                                  this,SLOT(onCountryChanged(QString)));
    requestStatus = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::deleteCombobox(QComboBox *combo)
{
    for(int i = combo->count(); i >= 0; i--)
    {
        combo->removeItem(i);
    }
    return;
}

void Widget::startRequest(bool clicked)
{
    QString city = ui->lineEdit->text();

    deleteCombobox(ui->comboBox);
    weather.startCityRequest(city);
}

void Widget::startWeather(bool clicked)
{
//    QCityList lst = weather.getCityList();
//    int index = ui->comboBox->currentIndex();
//    QString url = lst.at(index)->getUrl();
//    url = lst.at(index)->getUrlId(url).at(0);
//    weather.weatherForcast(url);

}

void Widget::onCountryChanged(QString country)
{
    QStringList *lst = weather.getListOfCities(country);
    deleteCombobox(ui->comboBox);
    for(int i = 0; i < lst->size(); i++)
    {
        ui->comboBox->addItems(*lst);
    }
    delete lst;
}

void Widget::execAfterRequest()
{
    QStringList *lst = weather.getListOfCountries();

    deleteCombobox(ui->countryBox);
    for(int i = 0; i < lst->size(); i++)
    {
       ui->countryBox->addItem(lst->at(i));
    }
    delete lst;
    requestStatus = true;
    return;
}


