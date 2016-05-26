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
    void putData(const QByteArray &data);
    void createNewTp(void);
    void bufferData(const QByteArray &data);
    void stateMachine(Statemachine &sm);
    Statemachine::State_t getState(void);

    bool isTpMessage(void);
    void doStatemachine(void);

    void setNextData(const QByteArray &data);


    int getNextDataSize(void);
    int getDataSize(Statemachine::State_t state);

    unsigned short prepareIncomingStaticData(Statemachine::State_t state);


private:
    TpList *tpMessages;
    TP *bufferTp;

    QByteArray *buffer;
    QByteArray nextData;

    QTimer *timer;
    static const int DEFAULT_CHECK_TIME = 50;


    Statemachine sm;


signals:


public slots:
    void checkData(void);
    void doHeaderStart(void);
    void doHeaderId(void);
    void doHeaderDataLength(void);
    void doBodySize(void);
    void doBodyData(void);
    void doFooterSqc(void);
    void doFooterCrc(void);
    void doFooterStop(void);
};

#endif // TPHANDLER_H
