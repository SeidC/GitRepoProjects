/* 
* Ubrr.h
*
* Created: 11.07.2016 22:08:55
* Author: AP
*/


#ifndef __UBRR_H__
#define __UBRR_H__
#include "RegIfUbrr.h"

class Ubrr : public RegIfUbrr
{
//variables
public:
protected:
private:

//functions
public:
	Ubrr(vuint8_t* ubrrHPtr,vuint8_t* ubrrLPtr);
	~Ubrr();
protected:
private:
	Ubrr( const Ubrr &c );
	Ubrr& operator=( const Ubrr &c );

}; //Ubrr

#endif //__UBRR_H__
