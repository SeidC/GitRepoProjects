/* 
* Timsk.h
*
* Created: 17.07.2016 00:16:06
* Author: AP
*/


#ifndef __TIMSK_H__
#define __TIMSK_H__
#include "RegIf8.h"


class Timsk : public RegIf8
{
//variables
public:
protected:
private:

//functions
public:
	Timsk();
	~Timsk();
protected:
private:
	Timsk( const Timsk &c );
	Timsk& operator=( const Timsk &c );

}; //Timsk

#endif //__TIMSK_H__
