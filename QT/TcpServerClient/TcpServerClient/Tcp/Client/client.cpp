#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    connection = new Connection(this);

}

void Client::connectToServer(QHostAddress *address, qint16 port, QIODevice::OpenMode openMode)
{
   connection->connectToHost(*address,port,openMode);
   return;
}


