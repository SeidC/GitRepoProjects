/* 
* Os.h
*
* Created: 07.08.2016 23:55:51
* Author: AP
*/


#ifndef __OS_H__
#define __OS_H__
#include "AVRConfig.h"
#include "Timer8.h"
#include "Timer16.h"


class Os : public BaseTypes
{
private:
   
   struct Task_s
   {
      FunctionPtr_f callback;
      uint16_t startTime;
      uint16_t execTime;
      bool pause;
   };
   
//variables
public:
protected:
private:
   
   
   TimerIf *timer;
   Task_s tasks[OS_NUMBER_OF_TASKS];
   uint8_t cNumberOfTasks;
    
//functions
public:
	Os();
	~Os();
   void setOsTimer(TimerIf *ptr);
   StdReturn_e addNewTask(uint8_t* fncPtr, uint16_t msTime = 0);
   StdReturn_e addNewTask(uint8_t index,uint8_t* fncPtr,  uint16_t msTime);
   StdReturn_e deleteTask(uint8_t taskIndex);
   void startOs (void);
   void run(void);
   StdReturn_e pauseTask(uint8_t taskIndex);
   StdReturn_e continueTask(uint8_t taskIndex);
   
protected:
private:
	Os( const Os &c );
	Os& operator=( const Os &c );

}; //Os

#endif //__OS_H__
