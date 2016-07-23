/* 
* Ucsra.cpp
*
* Created: 11.07.2016 22:07:47
* Author: AP
*/


#include "Ucsra.h"

// default constructor
Ucsra::Ucsra(vuint8_t *ucsraPtr)
{
    setRegister(ucsraPtr);
} //Ucsra

// default destructor
Ucsra::~Ucsra()
{
} //~Ucsra



bool Ucsra::isDataAvailable(void)
{
    return getBit((Ucsra::Bits_e)RXC);
}


bool Ucsra::isTransmitCompleted(void)
{
    return getBit((Ucsra::Bits_e)TXC);
}


bool Ucsra::canReceiveNewData(void)
{
    return getBit((Ucsra::Bits_e)UDRE);
}


bool Ucsra::isFrameError(void)
{
    return getBit((Ucsra::Bits_e)FE);
}


bool Ucsra::isDataOverRun(void)
{
    return getBit((Ucsra::Bits_e)DOR);
}


bool Ucsra::isParityError(void)
{
    return getBit((Ucsra::Bits_e)PE);
}


void Ucsra::activateDoubleSpeed(Ucsra::BitStatus_e status)
{
    status == Ucsra::BIT_HIGH ? setBit((Ucsra::Bits_e)U2X) : 
                  resetBit((Ucsra::Bits_e)U2X);
   
}