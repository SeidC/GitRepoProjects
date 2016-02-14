#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include "weather.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ui->weather->requestWeather(URL);


}

Widget::~Widget()
{
    delete ui;
}
