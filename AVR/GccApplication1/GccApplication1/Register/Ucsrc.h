/* 
* Ucsrc.h
*
* Created: 11.07.2016 22:08:34
* Author: AP
*/


#ifndef __UCSRC_H__
#define __UCSRC_H__
#include "RegIf.h"

class Ucsrc : public RegIf
{
//variables
public:
protected:
private:

//functions
public:
	Ucsrc();
	~Ucsrc();
protected:
private:
	Ucsrc( const Ucsrc &c );
	Ucsrc& operator=( const Ucsrc &c );

}; //Ucsrc

#endif //__UCSRC_H__
