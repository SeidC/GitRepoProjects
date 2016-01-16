#include "widget.h"
#include "ui_widget.h"

#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

    connect(ui->ExitButton,SIGNAL(clicked(bool)),
            this,SLOT(exit()));

    connect(ui->NetworkCombo,SIGNAL(currentIndexChanged(QString)),
            this,SLOT(networkComboIndexChanged(QString)));

    connect(ui->StartButton,SIGNAL(clicked(bool)),
            this,SLOT(appButtonClicked()));

   ui->ServerLable->setVisible(false);
   ui->ServerLineEdit->setVisible(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::disableServerSettings(void)
{
    if(ui->ServerLable->isVisible())
    {
        ui->ServerLable->setVisible(false);
    }

    if(ui->ServerLineEdit->isVisible())
    {
        ui->ServerLineEdit->setVisible(false);
    }
    return;
}

void Widget::enableServerSettings()
{
    if(!ui->ServerLable->isVisible())
    {
        ui->ServerLable->setVisible(true);
    }

    if(!ui->ServerLineEdit->isVisible())
    {
        ui->ServerLineEdit->setVisible(true);
    }
    return;
}

bool Widget::startServer()
{

}

bool Widget::startClient()
{

}

bool Widget::stopServer()
{

}

bool Widget::stopClient()
{

}


void Widget::networkComboIndexChanged(QString name)
{
    if(name == "Server")
    {
        disableServerSettings();
    }
    else if( name == "Client")
    {
        enableServerSettings();
    }
    return;
}


void Widget::exit(void)
{
    this->close();
    return;
}


void Widget::appButtonClicked(void)
{
   if(ui->StartButton->text() == "Start")
   {
       ui->StartButton->setText("Stop");
   }
   else
   {
       ui->StartButton->setText("Start");
   }
}

