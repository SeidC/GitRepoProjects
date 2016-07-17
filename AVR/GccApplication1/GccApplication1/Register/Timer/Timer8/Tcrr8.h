/* 
* Tcrr8.h
*
* Created: 17.07.2016 13:11:56
* Author: AP02
*/


#ifndef __TCRR8_H__
#define __TCRR8_H__
#include "TccrIf.h"
#include "RegIf8.h"

class Tcrr8 : public TccrIf, public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Tcrr8();
	~Tcrr8();
protected:
private:
	Tcrr8( const Tcrr8 &c );
	Tcrr8& operator=( const Tcrr8 &c );

}; //Tcrr8

#endif //__TCRR8_H__
