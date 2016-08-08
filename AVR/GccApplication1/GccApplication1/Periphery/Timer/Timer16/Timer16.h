/* 
* Timer16.h
*
* Created: 17.07.2016 13:43:08
* Author: AP02
*/


#ifndef __TIMER16_H__
#define __TIMER16_H__
#include "TimerIf.h"
#include "Tcnt16.h"
#include "Tccr16.h"
#include "Ocr16.h"
#include "Icr16.h"

class Timer16 : public TimerIf
{
//variables
public:
   
protected:
private:
   Tcnt16 tcnt;
   Tccr16 tccr;
   Ocr16 ocrA;
   Ocr16 ocrB;
   Icr16 icr;

//functions
public:
	Timer16();
	~Timer16();
   void setOutputCompare(Ocr16::OutputCompareRegister_e ocr, uint8_t value);
   uint16_t getOutputCompare(Ocr16::OutputCompareRegister_e ocr);
   StdReturn_e setTimerMode(Tccr16::TimerMode_e tmode);
   void setOutputMode(Tccr16::OutputMode_e omode);
   void setPreScaler(Tccr16::Prescaler_e prescaler);
   Tccr16::Prescaler_e getPrescaler(void);
   void toggleTimer(BaseTypes::Toggle_e status);
   uint16_t getTime(void);
   bool hasTimerOverflow(void);

protected:
private:
	Timer16( const Timer16 &c );
	Timer16& operator=( const Timer16 &c );

}; //Timer16

#endif //__TIMER16_H__
