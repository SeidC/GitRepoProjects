#include "dayinfo.h"
#include "ui_dayinfo.h"

DayInfo::DayInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DayInfo)
{
    ui->setupUi(this);
}

DayInfo::~DayInfo()
{
    delete ui;
}
