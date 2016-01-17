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

   client = NULL;
   server = NULL;
   editIf = new TextEditIf(this);
   editIf->setTextEdit(ui->StatusEdit);

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
    server = new Server(this);
    editIf->serverStarted();
    editIf->setServerConfig(65000);

}

bool Widget::startClient()
{
    client = new Client(this);
    editIf->clientConnected();
}

bool Widget::stopServer()
{
    delete server;
}

bool Widget::stopClient()
{
    delete client;
}

bool Widget::appStart()
{
    bool ret = false;
    if (ui->StartButton->text() == "Start" &&
        ui->NetworkCombo->currentText() == "Server")
    {
       if (startServer())
       {
           ui->NetworkCombo->setDisabled(true);
           ret = true;
       }
    }
    else if (ui->StartButton->text() == "Start" &&
             ui->NetworkCombo->currentText() == "Client")
    {
        if(startClient())
        {
            ui->NetworkCombo->setDisabled(true);
            ret = true;
        }
    }
    else
    {

    }
    return ret;
}

bool Widget::appStop()
{
    bool ret = false;
    if (ui->StartButton->text() == "Stop" &&
        ui->NetworkCombo->currentText() == "Server")
    {
        if(stopServer())
        {
            ui->NetworkCombo->setDisabled(false);
            ret = true;
        }
    }
    else if (ui->StartButton->text() == "Stop" &&
             ui->NetworkCombo->currentText() == "Client")
    {
        if(stopClient())
        {
            ui->NetworkCombo->setDisabled(false);
            ret = true;
        }
    }
    else
    {

    }
    return ret;
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
       appStart();
       ui->StartButton->setText("Stop");

   }
   else
   {
       appStop();
       ui->StartButton->setText("Start");
   }
}

