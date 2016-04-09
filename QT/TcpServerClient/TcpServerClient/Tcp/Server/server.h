#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "connection.h"

class Server : public QTcpServer
{
public:
    explicit Server(QObject* parent = 0);

};

#endif // SERVER_H
