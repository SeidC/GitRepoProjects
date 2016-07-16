/* 
* Tcnt16.h
*
* Created: 17.07.2016 00:15:05
* Author: AP
*/


#ifndef __TCNT16_H__
#define __TCNT16_H__
#include "TcntIf.h"
#include "RegIf16.h"

class Tcnt16 : public RegIf16, public TcntIf
{
//variables
public:
protected:
private:

//functions
public:
	Tcnt16();
	~Tcnt16();
protected:
private:
	Tcnt16( const Tcnt16 &c );
	Tcnt16& operator=( const Tcnt16 &c );

}; //Tcnt16

#endif //__TCNT16_H__
