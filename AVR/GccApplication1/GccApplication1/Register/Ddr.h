/* 
* Ddr.h
*
* Created: 08.07.2016 20:58:57
* Author: AP02
*/


#ifndef __DDR_H__
#define __DDR_H__
#include "BaseTypes.h"

class Ddr : public RegIf
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

//functions
public:
	Ddr();
	~Ddr();
    void setDirection(BaseTypes::Bits_e, Direction_e dirStatus);

private:
	Ddr( const Ddr &c );
	Ddr& operator=( const Ddr &c );

}; //Ddr

#endif //__DDR_H__
