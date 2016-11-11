/*
 * Easy_Cfg.c
 *
 * Created: 03.11.2016 23:53:46
 *  Author: AP
 */ 
#include "Easy_Types.h"
#include "Easy_Cfg.h"

#ifdef RELEASE 
Easy_Config_t Easy_config =
{
	.rxPosOffset         = EASY_CONVERT_TIME(20),
	.rxEdgeTime          = EASY_CONVERT_TIME(250),
	.rxNegOffset         = EASY_CONVERT_TIME(20),
	 
   .startMinTimeOffset  = EASY_CONVERT_TIME(20),
	.startTime           = EASY_CONVERT_TIME(300),
   .startMaxTimeOfset   = EASY_CONVERT_TIME(20),
   
   .txBaudrate          = EASY_CONVERT_TIME(250),
};
#warning "Release Easy Config used!!"
#endif


#ifdef DEBUG
Easy_Config_t Easy_config =
{
   .rxPosOffset         = EASY_CONVERT_TIME(25),
   .rxEdgeTime          = EASY_CONVERT_TIME(313),
   .rxNegOffset         = EASY_CONVERT_TIME(25),
   
   .startMinTimeOffset  = EASY_CONVERT_TIME(25),
   .startTime           = EASY_CONVERT_TIME(375),
   .startMaxTimeOfset   = EASY_CONVERT_TIME(25),
   
   .txBaudrate          = EASY_CONVERT_TIME(313),
};
  #warning "Debug Easy Config used!!"
#endif