/*
 * Timer1_Cfg.h
 *
 * Created: 12.10.2016 23:14:20
 *  Author: AP02
 */ 


#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

#ifdef  DEBUG
   #define TIMER1_INLINE                     
#endif
#ifdef RELEASE
   #define TIMER1_INLINE  inline
#endif


#define TIMER1_PORT_DISCONNECTED                0x00
#define TIMER1_TOGGLE_ON_COMPARE_MATCH          0x01
#define TIMER1_CLEAR_ON_COMPARE_MATCH           0x02
#define TIMER1_SET_ON_COMPARE_MATCH             0x03


#define TIMER1_NORMAL_MODE                     0x00


#define TIMER1_PRESCALER_1                     0x01
#define TIMER1_PRESCALER_8                     0x02
#define TIMER1_PRESCALER_64                    0x03
#define TIMER1_PRESCALER_256                   0x04
#define TIMER1_PRESCALER_1024                  0x05

/*Config for Timer1 A*/
#define TIMER1_COMPARE_OUTPUT_MODE_A_CFG        TIMER1_PORT_DISCONNECTED
/*Config for Timer 1 B*/
#define TIMER1_COMPARE_OUTPUT_MODE_B_CFG        TIMER1_PORT_DISCONNECTED
/*Config for Wave Form Generation*/
#define TIMER1_WAVE_FORM_GENERATION_CFG         TIMER1_NORMAL_MODE
/*Config for Prescaler*/
#define TIMER1_PRESCALER_CFG                    TIMER1_PRESCALER_1 


/*--- Defines/Types for Interrupt Mask Configuration ----------------------------------*/
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE           (1 << TOIE1)
#define TIMER1_OUTPUT_COMPARE_A_INTERRUPT_ENABLE   (1 << OCIE1A)
#define TIMER1_OUTPUT_COMPARE_B_INTERRUPT_ENABLE   (1 << OCIE1B)
#define TIMER1_INPUT_CAPUTURE_INTERRUPT_ENABLE     (1 << TICIE1)


#define TIMER1_INTERRUPT_MASK_CFG                  TIMER1_OVERFLOW_INTERRUPT_ENABLE


#define TIMER1_CONTROL_A_REGISTER                             \
		((TIMER1_COMPARE_OUTPUT_MODE_A_CFG << COM1A0)     |    \
		(TIMER1_COMPARE_OUTPUT_MODE_B_CFG << COM1B0)     |    \
		((TIMER1_WAVE_FORM_GENERATION_CFG & 0x03) << WGM10))


#define TIMER1_CONTROL_B_REGISTER                              \
		(((TIMER1_WAVE_FORM_GENERATION_CFG & 0x0C) << WGM12) | \
		(TIMER1_PRESCALER_CFG << CS10))


#define TIMER_1_OVERFLOW_INTERRUPT                 TIMER1_OVF_vect


#define TIMER1_WAIT_US_HARD_OFFSET                  10u
#endif /* TIMER1_CFG_H_ */