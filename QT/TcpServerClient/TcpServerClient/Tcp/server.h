#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT

    enum
    {
        PORT_NDEF       = 0x01,
        ADDRESS_NDEF    = 0x02,
        CONNECTED       = 0x10,

    }ServerStatus;

    const qint16 MAX_PORT = 65535;

public: // Constructors
    explicit Server(QObject *parent = 0);

public:
   ServerStatus startServer(void);
   bool setIp(QString ip);
   bool setPort(qint16 portNumber);

private:
    QHostAddress address;
    qint16 port;
    QTcpServer *tcpServer;

signals:

public slots:
};

#endif // SERVER_H
