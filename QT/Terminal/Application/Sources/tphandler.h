#ifndef TPHANDLER_H
#define TPHANDLER_H

#include <QObject>
#include "Tp.h"
#include <QList>
#include "QTimer"


typedef QList<TP*> TpList;


class TpHandler : public QObject
{
    Q_OBJECT
public:
    explicit TpHandler(QObject *parent = 0);
    void checkData(QByteArray &data);

private:
    TpList *tpMessages;
    QByteArray *buffer;
    QTimer *timer;

signals:

public slots:

};

#endif // TPHANDLER_H
