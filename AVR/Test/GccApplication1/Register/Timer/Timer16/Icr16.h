/* 
* Icr16.h
*
* Created: 17.07.2016 13:13:47
* Author: AP02
*/


#ifndef __ICR16_H__
#define __ICR16_H__
#include "RegIf16.h"

class Icr16 : public RegIf16
{
//variables
public:
protected:
private:

//functions
public:
	Icr16();
	~Icr16();
protected:
private:
	Icr16( const Icr16 &c );
	Icr16& operator=( const Icr16 &c );

}; //Icr16

#endif //__ICR16_H__
