/* 
* Ucsrb.h
*
* Created: 11.07.2016 22:08:26
* Author: AP
*/


#ifndef __UCSRB_H__
#define __UCSRB_H__
#include "RegIf8.h"

class Ucsrb : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Ucsrb();
	~Ucsrb();
protected:
private:
	Ucsrb( const Ucsrb &c );
	Ucsrb& operator=( const Ucsrb &c );

}; //Ucsrb

#endif //__UCSRB_H__
