/* 
* Ubrr.h
*
* Created: 11.07.2016 22:08:55
* Author: AP
*/


#ifndef __UBRR_H__
#define __UBRR_H__
#include "RegIf16.h"

class Ubrr : public RegIf16
{
//variables
public:
protected:
private:

//functions
public:
	Ubrr(volatile uint8_t * ubrrPtr);
	~Ubrr();
protected:
private:
	Ubrr( const Ubrr &c );
	Ubrr& operator=( const Ubrr &c );

}; //Ubrr

#endif //__UBRR_H__
