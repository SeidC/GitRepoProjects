/* 
* Ddr.h
*
* Created: 08.07.2016 20:58:57
* Author: AP02
*/


#ifndef __DDR_H__
#define __DDR_H__
#include "RegIf8.h"

class Ddr : public RegIf8
{
    
// Datatypes
public:
   enum DdrPin_e
   {
      DDR_0           = 0x00,
      DDR_1           = 0x01,
      DDR_2           = 0x02,
      DDR_3           = 0x03,
      DDR_4           = 0x04,
      DDR_5           = 0x05,
      DDR_6           = 0x06,
      DDR_7           = 0x07,
   };
   
   enum DdrDirection_e
   {
      DDR_INPUT           = 0x00,
      DDR_OUTPUT          = 0x01,    
   };
    
//variables
public:
protected:

//functions
public:
   Ddr();
	Ddr(vuint8_t* ddrPtr);
	~Ddr();
    void setDirection(DdrPin_e pin, DdrDirection_e dirStatus);
    DdrDirection_e getDirection(DdrPin_e pin);

private:
	Ddr( const Ddr &c );
	Ddr& operator=( const Ddr &c );

}; //Ddr

#endif //__DDR_H__
