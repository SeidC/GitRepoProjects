/* 
* Udr.h
*
* Created: 11.07.2016 22:08:10
* Author: AP
*/


#ifndef __UDR_H__
#define __UDR_H__
#include "RegIf8.h"


class Udr : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Udr(volatile uint8_t* udrPtr);
	~Udr();
protected:
private:
	Udr( const Udr &c );
	Udr& operator=( const Udr &c );

}; //Udr

#endif //__UDR_H__
