#ifndef TP_H
#define TP_H

#include "header.h"
#include "body.h"
#include "footer.h"
#include "statemachine.h"


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


#endif // TP_H
