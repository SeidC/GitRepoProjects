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

void Statemachine::exec(void)
{
    emitSignal(getState());
    lState = state;
}

void Statemachine::setTransition(Statemachine::Transition_t transition)
{
    stateTrans = transition;
    return;
}

bool Statemachine::hasStateChanged(void)
{
    bool ret = false;
    if (lState != state)
    {
        ret = true;
    }
    return ret;
}

void Statemachine::emitSignal(Statemachine::State_t state)
{
    switch(state)
    {
        case Statemachine::TP_HEADER_START:
            emit onHeaderStart();
            break;
        case Statemachine::TP_HEADER_ID:
            emit onHeaderId();
            break;
        case Statemachine::TP_HEADER_DATA_LENGTH:
            emit onHeaderDataLength();
            break;
        case Statemachine::TP_BODY_SIZE:
            emit onBodySize();
            break;
        case Statemachine::TP_BODY_DATA:
            emit onBodyData();
            break;
        case Statemachine::TP_FOOTER_SQC:
            emit onFooterSqc();
            break;
        case Statemachine::TP_FOOTER_CRC:
            emit onFooterCrc();
            break;
        case Statemachine::TP_FOOTER_STOP:
            emit onFooterStop();
            break;
        default:
            break;
   }
    return;
}

void Statemachine::switchState(Statemachine::Transition_t transition)
{
    switch(transition)
    {
        case Statemachine::GO_TO_HEADER_START_STATE  :
            state = Statemachine::TP_HEADER_START;
            break;
        case Statemachine::GO_TO_ID_STATE            :
            state = Statemachine::TP_HEADER_ID;
            break;
        case Statemachine::GO_TO_DATALENGTH_STATE    :
            state = Statemachine::TP_HEADER_DATA_LENGTH;
        break;
        case Statemachine::GO_TO_BODY_SIZE_STATE     :
            state = Statemachine::TP_BODY_SIZE;
        break;
        case Statemachine::GO_TO_BODY_DATA_STATE     :
            state = Statemachine::TP_BODY_DATA;
        break;
        case Statemachine::GO_TO_FOOTER_SQC_STATE    :
            state = Statemachine::TP_FOOTER_SQC;
        break;
        case Statemachine::GO_TO_FOOTER_CRC_STATE    :
            state = Statemachine::TP_FOOTER_CRC;
        break;
        case Statemachine::GO_TO_FOOTER_STOP_STATE   :
            state = Statemachine::TP_FOOTER_STOP;
        default:
            break;
   }
}
