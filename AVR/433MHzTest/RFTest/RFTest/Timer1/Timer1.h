/*
 * Timer1.h
 *
 * Created: 12.10.2016 23:12:38
 *  Author: AP02
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "Timer1_Cfg.h"

#define TIMER1_CONTROL_A_REGISTER                             \
       ((TIMER1_COMPARE_OUTPUT_MODE_A_CFG << COM1A0)     |    \
        (TIMER1_COMPARE_OUTPUT_MODE_B_CFG << COM1B0)     |    \
        ((TIMER1_WAVE_FORM_GENERATION_CFG & 0x03) << WGM10))  

  
#define TIMER1_CONTROL_B_REGISTER                              \
        (((TIMER1_WAVE_FORM_GENERATION_CFG & 0x0C) << WGM12) | \ 
         (TIMER1_PRESCALER_CFG << CS10))

void Timer1_Init(void);

#endif /* TIMER1_H_ */