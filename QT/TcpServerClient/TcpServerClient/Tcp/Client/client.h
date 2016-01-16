#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QHostAddress>
#include "connection.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    Connection *connection;

    void connectToServer(QHostAddress *address,
                         qint16 port,
                         QIODevice::OpenMode openMode);
signals:

public slots:
};

#endif // CLIENT_H
