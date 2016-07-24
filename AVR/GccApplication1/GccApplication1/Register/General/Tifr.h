/* 
* Tifr.h
*
* Created: 17.07.2016 00:16:14
* Author: AP
*/


#ifndef __TIFR_H__
#define __TIFR_H__
#include "RegIf8.h"

class Tifr : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Tifr();
	~Tifr();
protected:
private:
	Tifr( const Tifr &c );
	Tifr& operator=( const Tifr &c );

}; //Tifr

#endif //__TIFR_H__
