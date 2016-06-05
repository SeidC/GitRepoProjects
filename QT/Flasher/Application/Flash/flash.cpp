#include "flash.h"
#include "ui_flash.h"
#include <QFileDialog>

Flash::Flash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flash)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    hide();
    setEnabled(false);
    setConnections();
}


Flash::~Flash()
{
    delete ui;
}

void Flash::setConnections()
{
    connect(ui->hexButton,SIGNAL(clicked(bool)),this,SLOT(openDialog()));

}

void Flash::enableUi(void)
{
    if(!this->isEnabled())
        this->setEnabled(true);
}

void Flash::disableUi(void)
{
    if(this->isEnabled())
        this->setEnabled(false);
}

void Flash::openDialog(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Hex - File"),
                                                    "/usr",tr("Hex (*.hex)"));
    if(!fileName.isEmpty())
    {
        ui->hexLineEdit->setText(fileName);
    }
}

void Flash::showOrHideUi(void)
{
    if (this->isHidden())
        this->show();
    else
        this->hide();
}
