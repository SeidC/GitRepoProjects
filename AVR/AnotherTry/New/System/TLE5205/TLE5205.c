/*
 * TLE5205.c
 *
 * Created: 15.09.2016 21:32:58
 *  Author: AP02
 */ 

#include "TLE5202.h"


TLE5202_IoConfig_t TLE5202_config[TLE5205_NUMBER_OF_DEVICES] = 
            {
               {
                  .input1    = {IO_PORT_C,IO_PIN_0},
                  .input2    = {IO_PORT_C,IO_PIN_1},
                  .errorFlag = {IO_PORT_D,IO_PIN_2},
                  .channel   = PWM_CHANNEL_0
               },
               
               {
                  .input1    = {IO_PORT_C,IO_PIN_6},
                  .input2    = {IO_PORT_C,IO_PIN_7},
                  .errorFlag = {IO_PORT_D,IO_PIN_3},
                  .channel   = PWM_CHANNEL_2
               },               
            };            