/* 
* Tccr16.h
*
* Created: 17.07.2016 13:14:07
* Author: AP02
*/


#ifndef __TCCR16_H__
#define __TCCR16_H__
#include "TccrA.h"
#include "TccrB.h"
#include "TccrIf.h"

class Tccr16 : public TccrIf
{
//variables
public:
protected:
private:
    TccrA tccra;
    TccrB tccrb;

//functions
public:
	Tccr16();
	~Tccr16();
    void toggleTimer(Toggle_e stauts);
    
protected:
private:
	Tccr16( const Tccr16 &c );
	Tccr16& operator=( const Tccr16 &c );

}; //Tccr16

#endif //__TCCR16_H__
