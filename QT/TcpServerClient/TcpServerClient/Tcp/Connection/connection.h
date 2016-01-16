#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpSocket>

class Connection : public QTcpSocket
{
public:
    Connection(QObject *parent = 0);
};

#endif // CONNECTION_H
