/* 
* TimerIf.h
*
* Created: 02.08.2016 22:52:28
* Author: AP02
*/


#ifndef __TIMERIF_H__
#define __TIMERIF_H__
#include "BaseTypes.h"
#include "TccrIf.h"


class TimerIf : public BaseTypes
{
//functions
public:
	virtual ~TimerIf(){}
	virtual void setOutputCompare(uint8_t value)  {};
	virtual uint16_t getOutputCompare(void) {};
	virtual StdReturn_e setTimerMode(TccrIf::TimerMode_e tmode) {};
	virtual void setOutputMode(TccrIf::OutputMode_e omode) {};
	virtual void setPreScaler(TccrIf::Prescaler_e prescaler) {};
	virtual TccrIf::Prescaler_e getPrescaler(void) {};
	virtual void toggleTimer(TimerIf::Toggle_e status) {};
	virtual uint16_t getTime(void) {};


}; //TimerIf

#endif //__TIMERIF_H__
