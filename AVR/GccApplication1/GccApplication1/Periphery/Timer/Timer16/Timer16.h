/* 
* Timer16.h
*
* Created: 17.07.2016 13:43:08
* Author: AP02
*/


#ifndef __TIMER16_H__
#define __TIMER16_H__
#include "Tcnt16.h"
#include "Tccr16.h"
#include "Ocr16.h"
#include "Icr16.h"

class Timer16 : public Tcnt16, public Tccr16, public Ocr16, public Icr16
{
//variables
public:
   
protected:
private:

//functions
public:
	Timer16();
	~Timer16();
protected:
private:
	Timer16( const Timer16 &c );
	Timer16& operator=( const Timer16 &c );

}; //Timer16

#endif //__TIMER16_H__
