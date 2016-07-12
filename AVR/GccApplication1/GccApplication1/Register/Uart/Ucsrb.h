/* 
* Ucsrb.h
*
* Created: 11.07.2016 22:08:26
* Author: AP
*/


#ifndef __UCSRB_H__
#define __UCSRB_H__
#include "RegIf8.h"

class Ucsrb : public RegIf8
{
//types
public: 
    typedef enum
    {
        Uart_DISABLE       = 0x00,
        Uart_ENABLE        = 0x01,
        
    }Uart_Enable_t;
    
    
//variables
public:
protected:
private:

//functions
public:
	Ucsrb();
	~Ucsrb();
    void toggleRxInterrupt(Uart_Enable_t status);
    void toggleTxInterrupt(Uart_Enable_t status);
    void toggleEmptyInterrupt(Uart_Enable_t status);
    void toggleRx(Uart_Enable_t status);
    void toggleTx(Uart_Enable_t status);    
    void setCharacterSize2Bit(BaseTypes::BitStatus_e status);
    
protected:
private:
	Ucsrb( const Ucsrb &c );
	Ucsrb& operator=( const Ucsrb &c );

}; //Ucsrb

#endif //__UCSRB_H__
