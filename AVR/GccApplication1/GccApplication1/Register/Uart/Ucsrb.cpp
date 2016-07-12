/* 
* Ucsrb.cpp
*
* Created: 11.07.2016 22:08:26
* Author: AP
*/


#include "Ucsrb.h"

// default constructor
Ucsrb::Ucsrb(volatile uint8_t* ucsrbPtr)
{
    setRegister(ucsrbPtr);
} //Ucsrb

// default destructor
Ucsrb::~Ucsrb()
{
} //~Ucsrb


void Ucsrb::toggleRxInterrupt(Uart_Enable_t status)
{
    Ucsrb::Bits_e bit = (Ucsrb::Bits_e)RXCIE;
    status == Uart_ENABLE ? setBit(bit) : resetBit(bit);
}

void Ucsrb::toggleTxInterrupt(Uart_Enable_t status)
{
     Ucsrb::Bits_e bit = (Ucsrb::Bits_e)TXCIE;
     status == Uart_ENABLE ? setBit(bit) : resetBit(bit);    
}
void Ucsrb::toggleEmptyInterrupt(Uart_Enable_t status)
{
     Ucsrb::Bits_e bit = (Ucsrb::Bits_e)UDRIE;
     status == Uart_ENABLE ? setBit(bit) : resetBit(bit);
    
}

void Ucsrb::toggleRx(Uart_Enable_t status)
{
     Ucsrb::Bits_e bit = (Ucsrb::Bits_e)RXEN;
     status == Uart_ENABLE ? setBit(bit) : resetBit(bit);
}

void Ucsrb::toggleTx(Uart_Enable_t status)
{
 Ucsrb::Bits_e bit = (Ucsrb::Bits_e)TXEN;
 status == Uart_ENABLE ? setBit(bit) : resetBit(bit);
}

void Ucsrb::setCharacterSize2Bit(Ucsrb::BitStatus_e status)
{
    
}