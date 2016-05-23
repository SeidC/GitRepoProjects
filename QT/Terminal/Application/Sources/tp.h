#ifndef TP_H
#define TP_H

#include "header.h"
#include "body.h"
#include "footer.h"


class Statemachine;

class TP : public Header, public Body, public Footer
{

public: //Enum

public:
    TP();
    void stateMachine(Statemachine &sm);

private:
    Statemachine sm;

public slots:
    void doEnterState(Statemachine::State_t state);
    void doExitState(Statemachine::State_t state);
    void doStateTransition(Statemachine::Transition_t transition);

};


class Statemachine : public QObject
{
     Q_OBJECT

public:

    typedef enum
    {


    }Transition_t;

    typedef enum
    {
        TP_HEADER_START         = 0x00,
        TP_HEADER_ID            = 0x01,
        TP_HEADER_DATA_LENGTH   = 0x02,

        TP_BODY_SIZE            = 0x10,
        TP_BODY_DATA            = 0x11,

        TP_FOOTER_SQC           = 0x20,
        TP_FOOTER_CRC           = 0x21,
        TP_FOOTER_STOP          = 0x22,

    }State_t;

public:
    State_t lastState;
    State_t currentState;
    Transition_t transition;

signals:
    void onEnter(State_t state);
    void onTransition(Transition_t transition);
    void onExit(State_t state);
    void onCyclic(State_t state);


};

#endif // TP_H
