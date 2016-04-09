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

void DayInfoColumn::setInfoRow(DayInfoColumn::InfoRowType row, QString &txt)
{

}


QLabel* DayInfoColumn::getLable(DayInfoColumn::InfoRowType label)
{
    QLabel ret;
    switch (label)
    {
        case DayInfoColumn::INFO_ROW_1:
            ret  = ui->InfoRow1;
        break;
        case DayInfoColumn::INFO_ROW_2:
            ret  = ui->InfoRow2;
        break;
        case DayInfoColumn::INFO_ROW_3:
            ret  = ui->InfoRow3;
        break;
        case DayInfoColumn::INFO_ROW_4:
            ret  = ui->InfoRow4;
        break;
        default:
            ret = NULL;
        break;
    }
    return ret;
}
