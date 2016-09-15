/*
 * TLE5202.h
 *
 * Created: 15.09.2016 21:33:17
 *  Author: AP02
 */ 


#ifndef TLE5202_H_
#define TLE5202_H_
#include "Io.h"

#define TLE5205_NUMBER_OF_DEVICES                  2u


typedef struct 
{
   Io_Config_t input1;
   Io_Config_t input2;
   Io_Config_t errorFlag;
   
}TLE5202_IoConfig_t; 




#endif /* TLE5202_H_ */