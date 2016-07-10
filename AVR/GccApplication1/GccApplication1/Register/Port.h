/* 
* Port.h
*
* Created: 08.07.2016 20:59:14
* Author: AP02
*/


#ifndef __PORT_H__
#define __PORT_H__
#include "BaseTypes.h"

class Port : public BaseTypes
{
//variables
public:
protected:
private:
    BitRegister_t port;

//functions
public:
	Port();
	~Port();
    void setOutput(BaseTypes::Bits_e bit,BaseTypes::boolean status);
    void setPullUp(BaseTypes::Bits_e bit,BaseTypes::boolean status);
    
protected:
    void setRegister(volatile uint8_t *reg);
    void setBit(BaseTypes::Bits_e bit);
    void setBits(uint8_t bits);
    BaseTypes::BitRegister_t* getRegister(void);
    
private:
	Port( const Port &c );
	Port& operator=( const Port &c );

}; //Port

#endif //__PORT_H__
