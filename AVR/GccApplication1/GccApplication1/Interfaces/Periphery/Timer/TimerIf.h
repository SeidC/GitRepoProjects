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


class TimerIf : BaseTypes
{
//functions
public:
	virtual ~TimerIf(){}
	virtual void setOutputCompare(uint8_t value) = 0;
	virtual uint16_t getOutputCompare(void) = 0;
	virtual void setTimerMode(TccrIf::TimerMode_e tmode) = 0;
	virtual void setOutputMode(TccrIf::OutputMode_e omode) = 0;
	virtual void setPreScaler(TccrIf::Prescaler_e prescaler) = 0;
	virtual TccrIf::Prescaler_e getPrescaler(void) = 0;
	virtual void toggleTimer(Toggle_e status) = 0;
	virtual uint16_t getTime(void) = 0;


}; //TimerIf

#endif //__TIMERIF_H__
