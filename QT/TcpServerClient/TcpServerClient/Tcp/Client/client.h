#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QHostAddress>
#include "connection.h"

class Client : public QObject
{
    Q_OBJECT

public: // Datatypes
    typedef enum
    {
        DISCONNECTED        = 0x00,
        CONNECTION_PENDING  = 0x01,
        CONNECTED           = 0x02,
    }ClientStatus;

public:  // Methods & Constructors
    explicit Client(QObject *parent = 0);
    Connection *connection;

    void connectToServer(QHostAddress *address,
                         qint16 port,
                         QIODevice::OpenMode openMode);

    ClientStatus isClientConnected(void);

    void disconnectFromHost(void);

private: // Parameters
    ClientStatus clientStatus;
signals:


private slots:
    void connectionEstablished(void);
    void connectionClosed(void);

public slots:

};

#endif // CLIENT_H
