/* 
* Ucsrc.h
*
* Created: 11.07.2016 22:08:34
* Author: AP
*/


#ifndef __UCSRC_H__
#define __UCSRC_H__
#include "RegIf8.h"

class Ucsrc : public RegIf8
{
//types
public:
    enum Uart_ParityMode_t
    {
        UART_PARITY_DISABLED        = 0x00,
        UART_EVEN_PARITY            = 0x02,
        UART_ODD_PARITY             = 0x03,
        
    };
    
    /**
 * @brief 
 */
    enum Uart_TransmitionMode_t
    {
        UART_USE_SYNCHRONOUS_MODE                  = 0x00,
        UART_USE_ASYNCHRONOUS_MODE                 = 0x01,
        UART_USE_ASYNCHRONOUS_MODE_W_DOUBLE_SPEED  = 0x00,
    };
//variables
public:
protected:
private:

//functions
public:
	Ucsrc();
	~Ucsrc();
    void setMode()
protected:
private:
	Ucsrc( const Ucsrc &c );
	Ucsrc& operator=( const Ucsrc &c );

}; //Ucsrc

#endif //__UCSRC_H__
