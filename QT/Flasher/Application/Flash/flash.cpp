#include "flash.h"
#include "ui_flash.h"

Flash::Flash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flash)
{
    ui->setupUi(this);
}

Flash::~Flash()
{
    delete ui;
}
