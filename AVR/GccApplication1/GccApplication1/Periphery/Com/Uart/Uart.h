/* 
* Uart.h
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#ifndef __UART_H__
#define __UART_H__
#include "Ubrr.h"
#include "Ucsra.h"
#include "Ucsrb.h"
#include "Ucsrc.h"


class Uart : public Ubrr , public Ucsra , public Ucsrb , public Ucsrc
{
//variables
public:
protected:
private:

//functions
public:
	Uart(volatile uint8_t* udrPtr);
	~Uart();
protected:
private:
	Uart( const Uart &c );
	Uart& operator=( const Uart &c );

}; //Uart

#endif //__UART_H__
