#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    connection = new Connection(this);

    clientStatus = DISCONNECTED;

    connect(connection,SIGNAL(connected()),
            this,SLOT(connectionEstablished()));

    connect(connection,SIGNAL(disconnected()),
            this,SLOT(connectionClosed()));

    connect(connection, SIGNAL(connected()),
            this,SIGNAL(connected()));

    connect(connection,SIGNAL(disconnected()),
            this,SIGNAL(disconnected()));

    connect(connection,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SIGNAL(error(QAbstractSocket::SocketError)));

    return;
}

void Client::connectToServer(QHostAddress *address, qint16 port, QIODevice::OpenMode openMode)
{
   connection->connectToHost(*address,port,openMode);
   clientStatus = CONNECTION_PENDING;
   return;
}


Client::ClientStatus Client::isClientConnected(void)
{
    return clientStatus;
}


void Client::disconnectFromHost(void)
{
    connection->disconnectFromHost();
    return;
}


void Client::connectionEstablished(void)
{
    clientStatus = CONNECTED;
    return;
}


void Client::connectionClosed(void)
{
    clientStatus = DISCONNECTED;
    return;
}


