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
    enum Error_t{
        START_SIGN_ERROR =           0x00,
        ID_ERROR                         ,
        BODY_SIZE_ERROR                  ,
        MESSAGE_DATA_ERROR               ,
        SQC_ERROR                        ,
        CRC_ERROR                        ,
        STOP_SIGN_ERROR

    };

public:
    explicit TpHandler(QObject *parent = 0);
    void startCheck(void);
    void putData(const QByteArray &data);
    void createNewTp(void);
    void bufferData(const QByteArray &data);
    void stateMachine(Statemachine &sm);

    void storeTpMessage(TP* msg);
    TP *getLastReceivedMessage(void);

    bool isTpMessage(void);
    void doStatemachine(void);

    void setNextData(const QByteArray &data);
    void resetBufferTp(void);

    int getNextDataSize(void);
    int getDataSize(Statemachine::State_t state);

    unsigned short prepareIncomingStaticData(Statemachine::State_t state);
    void pepareIncomingDynamicData(Statemachine::State_t state, QByteArray &data);


private:
    TpList *tpMessages;
    TP *bufferTp;

    QByteArray *buffer;
    QByteArray nextData;

    QTimer *timer;
    static const int DEFAULT_CHECK_TIME = 5;


    Statemachine sm;


signals:
    void tpMessageReceived(void);
    void tpMessageError(Error_t error);

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
