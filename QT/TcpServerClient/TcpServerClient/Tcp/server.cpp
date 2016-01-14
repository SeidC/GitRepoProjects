#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    address.setAddress("0.0.0.0");
    port = 0;
}

Server::ServerStatus Server::startServer(void)
{
    ServerStatus ret;
    if (address.toString() != "0.0.0.0.")
    {
        if (port != 0)
        {
            tcpServer->listen(&address,port);
        }
        else
        {
            ret = PORT_NDEF;
        }
    }
    else
    {
        ret = ADDRESS_NDEF;
    }

    return ret;
}

bool Server::setIp(QString ip)
{
    return address.setAddress(ip);
}

bool Server::setPort(qint16 portNumber)
{
    bool ret = false;
    if (portNumber > 0 && portNumber <= MAX_PORT)
    {
        port = portNumber;
        ret = true;
    }
    return ret;
}


