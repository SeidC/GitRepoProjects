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

}


int Tp::getNextData(void)
{
    int i = dataAv[(int)currentPart];
    return i;
}

void Tp::setToNextPart(void)
{
    if(currentPart < PART_QUANTITY)
    {
        int i = (int)currentPart;
        currentPart = ((TpParts_t)++i);
    }
    else
    {
        currentPart = HEADER_START_SIGN;
    }
}

Tp::TpParts_t Tp::getCurrentPart()
{
    return currentPart;
}
