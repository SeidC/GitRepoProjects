#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <QObject>

class Statemachine : public QObject
{
    Q_OBJECT
public:
    enum Transition_t
    {
        NO_Transition           = 0x00,

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

    };

public:
    explicit Statemachine(QObject *parent = 0);
public:
    State_t lState;
    State_t state;
    Transition_t transition;

public:


    State_t getState() const;
    void setState(const State_t &value);
    void exec(void);
    void setTransition(Transition_t transition);

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
