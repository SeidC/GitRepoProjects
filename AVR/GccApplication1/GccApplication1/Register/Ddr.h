/* 
* Ddr.h
*
* Created: 08.07.2016 20:58:57
* Author: AP02
*/


#ifndef __DDR_H__
#define __DDR_H__
#include "BaseTypes.h"

class Ddr : public BaseTypes
{
    
// Datatypes
public:
    enum Direction_e
    {
        OUTPUT          = 0x00,
        INPUT           = 0x01,    
    };
    
//variables
public:
protected:
private:
     BitRegister_t ddr;

//functions
public:
	Ddr();
	~Ddr();
    void setDirection(BaseTypes::Bits_e, Direction_e dirStatus);
protected:
    void setRegister(volatile uint8_t *reg);
    void setBit(BaseTypes::Bits_e bit);
    void setBits(uint8_t bits);
    BaseTypes::BitRegister_t* getRegister(void);
private:
	Ddr( const Ddr &c );
	Ddr& operator=( const Ddr &c );

}; //Ddr

#endif //__DDR_H__
