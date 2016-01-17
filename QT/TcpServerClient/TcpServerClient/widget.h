#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "client.h"
#include "server.h"
#include "texteditif.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Server* server;
    Client* client;
    TextEditIf* editIf;

private:
    void disableServerSettings(void);
    void enableServerSettings(void);

    bool startServer(void);
    bool startClient(void);
    bool stopServer(void);
    bool stopClient(void);

    bool appStart(void);
    bool appStop(void);

    bool checkConfigBeforeStart(void);


    QString getPort(void);
    QString getIp(void);


public slots:
    void networkComboIndexChanged(QString name);
    void exit(void);
    void appButtonClicked(void);
//Client Slots
    void clientConnected(void);
    void clientDisconnected(void);
    void clientError(QAbstractSocket::SocketError socketError);
//Server Slots


};

#endif // WIDGET_H
