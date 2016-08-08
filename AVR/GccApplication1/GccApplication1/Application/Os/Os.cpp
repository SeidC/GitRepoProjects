/* 
* Os.cpp
*
* Created: 07.08.2016 23:55:51
* Author: AP
*/


#include "Os.h"

// default constructor
Os::Os()
{
   timer = NULL;
   cNumberOfTasks = 0;
   
} //Os

// default destructor
Os::~Os()
{
} //~Os


void Os::setOsTimer(TimerIf *ptr)
{
   if (ptr != NULL && timer != NULL)
   {
      timer = ptr;   
   }
   return;
}



Os::StdReturn_e Os::addNewTask(uint8_t* fncPtr,  uint16_t msTime)
{
   StdReturn_e ret = STD_NOK;
   if(fncPtr != NULL && cNumberOfTasks < OS_NUMBER_OF_TASKS)
   {
      tasks[cNumberOfTasks].callback = (FunctionPtr_f)fncPtr;
      tasks[cNumberOfTasks].execTime = msTime;
      cNumberOfTasks ++;
      ret = STD_OK;
   }
   return ret;  
}



Os::StdReturn_e Os::deleteTask(uint8_t taskIndex)
{
   StdReturn_e ret = STD_NOK;
   if(taskIndex < OS_NUMBER_OF_TASKS && taskIndex < cNumberOfTasks)
   {
      if(tasks[taskIndex].callback != NULL)
      {
         tasks[taskIndex].callback = NULL;
         tasks[taskIndex].execTime = 0;
         ret = STD_OK;
      }
   }
   return ret;
}


Os::StdReturn_e Os::addNewTask(uint8_t index,uint8_t* fncPtr,  uint16_t msTime)
{
   StdReturn_e ret = STD_NOK;
   if(index < OS_NUMBER_OF_TASKS && index < cNumberOfTasks)
   {
      if(tasks[index].callback == NULL  && fncPtr != NULL)
      {
         tasks[index].callback = (FunctionPtr_f)fncPtr;
         tasks[index].execTime = msTime;
         ret = STD_OK;
      }
   }
   return ret;
}

void Os::startOs(void)
{
   timer->toggleTimer(TimerIf::ENABLE);
   return;
}

void Os::run(void)
{
   uint8_t i;
   while(1)
   {
      for(i = 0; i < cNumberOfTasks; i++)
      {
         
      }
   }
}

 Os::StdReturn_e Os::pauseTask(uint8_t taskIndex)
{
    StdReturn_e ret = STD_NOK;
   if(taskIndex < OS_NUMBER_OF_TASKS)
   {
      if(tasks[taskIndex].callback != NULL)
      {
         tasks->pause = false;
         ret = STD_OK;
      }  
   }
   return ret;   
}


Os::StdReturn_e  Os::continueTask(uint8_t taskIndex)
{
     StdReturn_e ret = STD_NOK;
     if(taskIndex < OS_NUMBER_OF_TASKS)
     {
        if(tasks[taskIndex].callback != NULL)
        {
           tasks->pause = true;
           ret = STD_OK;
        }
     }
     return ret;
}