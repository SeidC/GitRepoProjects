/* 
* Pwm8.h
*
* Created: 17.07.2016 13:43:48
* Author: AP02
*/


#ifndef __PWM8_H__
#define __PWM8_H__
#include "PwmIf"
#include "Tcnt8.h"
#include "Tccr8.h"
#include "Ocr8.h"
#include "Timsk.h"
#include "Tifr.h"

class Pwm8 : public PwmIf
{
//variables
public:
protected:
private:
      Tcnt8 tcnt;
      Tccr8 tccr;
      Ocr8  ocr;
      Timsk timsk;
      Tifr  tifr;

//functions
public:
	Pwm8();
	~Pwm8();
protected:
private:
	Pwm8( const Pwm8 &c );
	Pwm8& operator=( const Pwm8 &c );

}; //Pwm8

#endif //__PWM8_H__
