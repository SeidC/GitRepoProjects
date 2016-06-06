#include "flash.h"
#include "ui_flash.h"
#include <QFileDialog>

Flash::Flash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flash)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->tpLengthBox->setValue(10);

    hide();
    setEnabled(false);
    setConnections();
    onCancle();
    updateSettings();
}


Flash::~Flash()
{
    delete ui;
}

void Flash::setConnections(void)
{
    connect(ui->hexButton,SIGNAL(clicked(bool)),this,SLOT(openDialog()));

    connect(ui->flashButton,SIGNAL(clicked(bool)),this,SLOT(onStart()));
    connect(ui->cancleButton,SIGNAL(clicked(bool)),this,SLOT(onCancle()));

    connect(ui->flashButton,SIGNAL(clicked(bool)),this,SIGNAL(start()));
    connect(ui->cancleButton,SIGNAL(clicked(bool)),this,SIGNAL(cancle()));    
}

void Flash::updateSettings(void)
{
    settings.useCrc = ui->crcCheckBox->isChecked();
    settings.useSqc = ui->sqcCheckBox->isChecked();
    settings.tpLength = ui->tpLengthBox->value();
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

void Flash::onCancle(void)
{
    ui->flashButton->setEnabled(true);
    ui->cancleButton->setEnabled(false);
    ui->hexButton->setEnabled(true);
    ui->hexLineEdit->setEnabled(true);
    ui->progressBar->setEnabled(false);

}

void Flash::onStart(void)
{
    updateSettings();
    ui->flashButton->setEnabled(false);
    ui->cancleButton->setEnabled(true);
    ui->hexButton->setEnabled(false);
    ui->hexLineEdit->setEnabled(false);
    ui->progressBar->setEnabled(true);
}

void Flash::showOrHideUi(void)
{
    if (this->isHidden())
        this->show();
    else
        this->hide();
}
