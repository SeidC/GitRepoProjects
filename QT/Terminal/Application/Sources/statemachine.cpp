#include "statemachine.h"

Statemachine::Statemachine(QObject *parent) : QObject(parent)
{
    setState(TP_HEADER_START);
}

Statemachine::State_t Statemachine::getState() const
{
    return state;
}

void Statemachine::setState(const State_t &value)
{
    state = value;
}

void Statemachine::exec()
{

}

void Statemachine::setTransition(Statemachine::Transition_t transition)
{

}
