/* 
* RegIf.h
*
* Created: 08.07.2016 21:44:29
* Author: AP02
*/


#ifndef __REGIF_H__
#define __REGIF_H__

#include "BaseTypes.h"


class RegIf 
{
//functions
public:
	virtual ~RegIf(){}
	virtual void setRegister(volatile uint8_t *reg) = 0;
	virtual void setBit(BaseTypes::Bits_e bit) = 0;
    virtual void setBits(uint8_t bits) = 0;
    virtual BaseTypes::BitRegister_t* getRegister(void) = 0;
}; //RegIf

#endif //__REGIF_H__
