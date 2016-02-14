#include "daygraphic.h"
#include "ui_daygraphic.h"

DayGraphic::DayGraphic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DayGraphic)
{
    ui->setupUi(this);
}

DayGraphic::~DayGraphic()
{
    delete ui;
}
