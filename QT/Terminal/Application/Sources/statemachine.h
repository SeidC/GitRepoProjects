#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <QObject>

class Statemachine : public QObject
{
    Q_OBJECT
public:
    enum Transition_t
    {
            Trans,

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
    State_t lastState;
    State_t currentState;
    Transition_t transition;


signals:
    void onEnter(State_t state);
    void onTransition(Transition_t transition);
    void onExit(State_t state);
    void onCyclic(State_t state);

public slots:
};

#endif // STATEMACHINE_H
