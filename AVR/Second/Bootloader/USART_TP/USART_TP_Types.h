/*
 * USART_TP_Types.h
 *
 * Created: 14.05.2016 12:16:05
 *  Author: AP02
 */ 


#ifndef USART_TP_TYPES_H_
#define USART_TP_TYPES_H_

#include "TP_Types.h"


#define USART_TP_START_SIGN         0xAA55u

#define USART_TP_DELIMITER "\r\n"

#define USART_NEW_MESSAGE                                           \
TP_NEW_MESSAGE(msgName,msgId,msgLength,msgStart_i,msgDelim_Str)



#endif /* USART_TP_TYPES_H_ */