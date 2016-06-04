#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <QObject>

class Statemachine : public QObject
{
    Q_OBJECT
public:
    enum Transition_t
    {
        NO_STATE_CHANGFE         = 0x00,
        GO_TO_HEADER_START_STATE       ,
        GO_TO_HEADER_ID_STATE          ,
        GO_TO_HEADER_DATALENGTH_STATE  ,
        GO_TO_BODY_SIZE_STATE          ,
        GO_TO_BODY_DATA_STATE          ,
        GO_TO_FOOTER_SQC_STATE         ,
        GO_TO_FOOTER_CRC_STATE         ,
        GO_TO_FOOTER_STOP_STATE        ,
    };

    enum State_t
    {
        TP_HEADER_START         = 0x00,
        TP_HEADER_ID            = 0x01,
        TP_HEADER_DATA_LENGTH   = 0x02,

        TP_BODY_SIZE            = 0x10,
        TP_BODY_DATA            = 0x11,

        TP_FOOTER_SQC           = 0x20,
        TP_FOOTER_CRC           = 0x21,
        TP_FOOTER_STOP          = 0x22,

        TP_NO_STATE             = 0xFF,

    };

public:
    explicit Statemachine(QObject *parent = 0);
public:
    State_t lState;
    State_t state;
    Transition_t stateTrans;
    bool smReset;
public:


    State_t getState() const;
    void setState(const State_t &value);
    void exec(void);
    void setTransition(Transition_t transition);
    bool hasStateChanged(void);
    void emitSignal(Statemachine::State_t state);
    void switchState(Statemachine::Transition_t transition);
    bool isStateChangeRequested(void);
    void reset(void);

    void setLState(const State_t &value);

    bool getSmReset() const;
    void setSmReset(bool value);

signals:
    void onHeaderStart(void);
    void onHeaderId(void);
    void onHeaderDataLength(void);
    void onBodySize(void);
    void onBodyData(void);
    void onFooterSqc(void);
    void onFooterCrc(void);
    void onFooterStop(void);


public slots:
};

#endif // STATEMACHINE_H
