#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include "weather.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);



}

Widget::~Widget()
{
    delete ui;
}
