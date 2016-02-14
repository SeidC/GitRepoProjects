#include "day.h"
#include "ui_day.h"

Day::Day(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Day)
{
    ui->setupUi(this);
}

Day::~Day()
{
    delete ui;
}
