/* 
* Ucsra.h
*
* Created: 11.07.2016 22:07:51
* Author: AP
*/


#ifndef __UCSRA_H__
#define __UCSRA_H__
#include "RegIf.h"

class Ucsra : public RegIf
{
//variables
public:
protected:
private:

//functions
public:
	Ucsra();
	~Ucsra();
protected:
private:
	Ucsra( const Ucsra &c );
	Ucsra& operator=( const Ucsra &c );

}; //Ucsra

#endif //__UCSRA_H__
