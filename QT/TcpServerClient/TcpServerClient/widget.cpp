#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>


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
    bool serverStatus, ret = false;
    qint16 port;

    server = new Server(this);
    port = getPort().toInt();
    serverStatus = server->listen(QHostAddress::Any,port);
    if (serverStatus == true)
    {
        editIf->serverStarted();
        editIf->setServerConfig(getPort());
        ret = true;
    }
    return ret;
}

bool Widget::startClient()
{
    QHostAddress ip;
    qint16 port;
    bool ret = false;

    ip.setAddress(getIp());
    port = getPort().toInt();

    client = new Client(this);
    client->connectToServer(&ip,port,QIODevice::ReadWrite);
    if (client->isClientConnected() == Client::CONNECTED)
    {
        editIf->clientConnected();
        ret = true;
    }
    else if (client->isClientConnected() == Client::CONNECTION_PENDING)
    {
        editIf->clientConnectionPending();
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}


bool Widget::stopServer()
{
    if(server->isListening())
    {
        server->close();
        delete server;
    }
    return true;
}


bool Widget::stopClient()
{
    delete client;
    return true;
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

bool Widget::checkConfigBeforeStart()
{
    bool ret = false;
    if (ui->NetworkCombo->currentText() == "Client")
    {
        if(!ui->PortLineEdit->text().isEmpty() &&
           !ui->ServerLineEdit->text().isEmpty())
        {
            ret = true;
        }
    }
    else
    {
        if(!ui->PortLineEdit->text().isEmpty())
        {
            ret = true;
        }
    }
    return ret;
}

QString Widget::getPort()
{
    return ui->PortLineEdit->text();
}

QString Widget::getIp()
{
    return ui->ServerLineEdit->text();
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
       if(checkConfigBeforeStart())
       {
            appStart();
            ui->StartButton->setText("Stop");
       }
       else
       {
           QMessageBox::warning(this,"Invalid configuration",
                                "Please check your settings");
       }
   }
   else
   {
       appStop();
       ui->StartButton->setText("Start");
   }
}

