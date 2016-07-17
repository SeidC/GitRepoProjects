/* 
* Tcnt8.h
*
* Created: 17.07.2016 00:14:56
* Author: AP
*/


#ifndef __TCNT8_H__
#define __TCNT8_H__

#include "TcntIf.h"
#include "RegIf8.h"

class Tcnt8 : public RegIf8, public TcntIf
{
//variables
public:
protected:
private:

//functions
public:
	Tcnt8();
	~Tcnt8();
    uint16_t getTime(void);
     
protected:
private:
	Tcnt8( const Tcnt8 &c );
	Tcnt8& operator=( const Tcnt8 &c );

}; //Tcnt8

#endif //__TCNT8_H__
