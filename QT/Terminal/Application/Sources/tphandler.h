#ifndef TPHANDLER_H
#define TPHANDLER_H

#include <QObject>
#include "Tp.h"
#include <QList>
#include <QTimer>


typedef QList<TP*> TpList;


class TpHandler : public QObject
{
    Q_OBJECT
public:
    explicit TpHandler(QObject *parent = 0);
    void startCheck(void);
    void putData(QByteArray &data);
    void createNewTp(void);

private:
    TpList *tpMessages;
    QByteArray *buffer;
    TP *bufferTp;
    QTimer *timer;
    static const int DEFAULT_CHECK_TIME = 50;
    bool start;
signals:

public slots:
    void checkData(void);
};

#endif // TPHANDLER_H
