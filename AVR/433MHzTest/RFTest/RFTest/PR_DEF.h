/*
* PR_DEF.h
*
* Created: 22.02.2016 18:44:19
*  Author: AP
*/


#ifndef PR_DEF_H_
#define PR_DEF_H_

#include <avr/io.h>
#include <stdio.h>


#define MEGA                              \
        ((uint32_t)1.000.000)

/**
 * @brief
 *
 *
 */
typedef uint8_t bool_t;        

#define TRUE                     ((1u)) 
   
#define FALSE                    ((0u))

/**
 * @brief
 *
 *
 */
#define SET_REGISTER_BIT(reg,bit)				\
        (reg |= (1<<bit))

/**
 * @brief
 *
 *
 */
#define GET_REGISTER_BIT(reg,bit)				\
        (reg & (1<<bit))

/**
 * @brief
 *
 *
 */
#define SET_REGISTER_BITS(reg,bitmask)			\
		(reg |= ((uint8_t)bitmask))
   
/**
 * @brief
 *
 *
 */     
#define RESET_REGISTER_BIT(reg,bit)				\
        (reg &= ~(1<<bit))

/**
 * @brief
 *
 *
 */
#define GET_PIN_REG_PTR_BY_PORT(port)          \
        ( (volatile uint8_t*) (port - 2) )

/**
 * @brief
 *
 *
 */
#define GET_DDR_REG_PTR_BY_PORT(port)           \
        ( (volatile uint8_t*) (port - 1) )


#define InterruptRoutine(isrVector)                \
        ISR(isrVector)
#endif /* PR_DEF_H_ */