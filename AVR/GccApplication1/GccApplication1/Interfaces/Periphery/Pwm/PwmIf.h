/* 
* PwmIf.h
*
* Created: 07.09.2016 22:39:03
* Author: AP
*/


#ifndef __PWMIF_H__
#define __PWMIF_H__
#include "BaseTypes.h"


class PwmIf : public BaseTypes
{

private: 
   TimerInfo_t *tInfo;
//functions
public:
	virtual ~PwmIf(){}
      
 virtual void setConfig(Timer8Config_t *config) {setInfo(&config->info);};
 virtual void setOutputCompare(uint8_t value)  {};
 virtual uint16_t getOutputCompare(void) { return 0;};
 virtual StdReturn_e setTimerMode(TccrIf::TimerMode_e tmode) {return BaseTypes::STD_NOT_SUPPORTED;};
 virtual void setOutputMode(TccrIf::OutputMode_e omode) {};
 virtual void setPreScaler(TccrIf::Prescaler_e prescaler) {};
 virtual TccrIf::Prescaler_e getPrescaler(void) { return TccrIf::NO_PRESCALER;};
 virtual void toggleTimer(TimerIf::Toggle_e status) {};
 virtual uint16_t getTime(void) {return 0;};
 virtual bool hasOverflow(void) { return false;}

 public:  //Methods
 uint16_t getMaxTimerValue(void) {return tInfo->timerMax;}
 TimerType_t getTimerType(void) {return tInfo->type;}
 protected: //Methods
 void setInfo(TimerInfo_t* info) {tInfo = info;}
   

}; //PwmIf

#endif //__PWMIF_H__
