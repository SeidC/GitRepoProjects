#include "tp.h"

uint Tp::dataAv[Tp::PART_QUANTITY] = {HEADER_SIGN_SIZE     ,
                     HEADER_LENGTH_SIZE   ,
                     BODY_DATA_LENGTH_SIZE,
                     0                    ,
                     FOOTER_SQC_SIZE      ,
                     FOOTER_CRC_SIZE      ,
                     FOOTER_STOP_SIGN_SIZE
           };


Tp::Tp(QObject *parent) : QObject(parent)
{
    setMsgValidStatus(false);
}

void Tp::setMsgValidStatus(bool val)
{
    valid = val;
}

bool Tp::isMsgValid()
{
    return valid;
}



void Tp::setToNextPart(void)
{
    if(currentPart < PART_QUANTITY)
    {
        int i = (int)currentPart;
        currentPart = ((MsgPart_t)++i);
    }
    else
    {
        currentPart = HEADER_START_SIGN;
    }
}

Tp::MsgPart_t Tp::getCurrentMsgPart()
{
    return currentPart;
}

uint Tp::getNextMsgPartSize(Tp::MsgPart_t part)
{
    if(part < Tp::PART_QUANTITY)
        return dataAv[part];
}
