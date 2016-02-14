#include "dayinfocolumn.h"
#include "ui_dayinfocolumn.h"

DayInfoColumn::DayInfoColumn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DayInfoColumn)
{
    ui->setupUi(this);
}

DayInfoColumn::~DayInfoColumn()
{
    delete ui;
}
