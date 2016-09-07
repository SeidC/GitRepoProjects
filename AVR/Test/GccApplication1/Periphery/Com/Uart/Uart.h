/* 
* Uart.h
*
* Created: 10.07.2016 14:16:32
* Author: AP02
*/


#ifndef __UART_H__
#define __UART_H__
#include "AVRConfig.h"
#include "Ubrr.h"
#include "Ucsra.h"
#include "Ucsrb.h"
#include "Ucsrc.h"
#include "Udr.h"


class Uart : public Ubrr , public Ucsra , public Ucsrb , public Ucsrc , public Udr
{
//variables
public:
protected:
private:

//functions
public:
	Uart(UartConfig_t* uartConfig);
	~Uart();
protected:
private:
	Uart( const Uart &c );
	Uart& operator=( const Uart &c );

}; //Uart

#endif //__UART_H__
