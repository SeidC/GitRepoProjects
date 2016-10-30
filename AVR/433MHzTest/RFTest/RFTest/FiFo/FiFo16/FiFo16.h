/*
 * FIFO16.h
 *
 * Created: 08.03.2016 18:39:52
 *  Author: AP
 */


#ifndef FIFO16_H_
#define FIFO16_H_

#include <stdio.h>
#include "PR_DEF.h"


typedef uint8_t FIFO16_Return_t;

#define FIFO16_N_OK                        0
#define FIFO16_OK                          1


/**
 *
 */ 
 #define FIFO16_IS_BUFFER_READY(bufPtr)                            \
          ((bufPtr->status == FIFO16_BUFFER_EMPTY) ||              \
           (bufPtr->status == FIFO16_BUFFER_DATA_AVAILABLE))     
/**
 *
 */            
#define FIFO16_HAS_BUFFER_ERRORS(bufPtr)                           \
        ((bufPtr->status == FIFO16_WRITE_OVERFLOW_ERROR) ||        \
         (bufPtr->status == FIFO16_UNDEF_ERROR))
/**
 *
 */ 
#define FIFO16_IS_BUFFER_FULL(bufPtr)                             \
        (bufPtr->status == FIFO16_BUFFER_FULL)

/**
 *
 */
#define FIFO16_IS_BUFFER_EMPTY(bufPtr)                            \
        (bufPtr->status == FIFO16_BUFFER_EMPTY)
        
typedef enum
{
    FIFO16_BUFFER_EMPTY               = 0x00,
    FIFO16_BUFFER_DATA_AVAILABLE            ,    
    FIFO16_BUFFER_FULL                      ,
    FIFO16_WRITE_OVERFLOW_ERROR             ,
    FIFO16_UNDEF_ERROR
}FIFO16_BufferStatus_t;


/**
 *
 */
typedef struct
{
	uint8_t read;
	uint8_t write;
    bool_t overflow;
}FIFO16_Counter_t;

/**
 *
 */
typedef struct 
{
	uint16_t *bufferPtr;
	uint8_t bufferSize;
    FIFO16_BufferStatus_t status; 
	FIFO16_Counter_t counter;		
}FIFO16_Buffer_t;


/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] avBuffer Parameter_Description
 *  @param [in] avSize Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void FIFO16_InitBuffer(FIFO16_Buffer_t* ptr,uint16_t* avBuffer,uint8_t avSize);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] p Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void FIFO16_Write(FIFO16_Buffer_t* ptr, uint16_t p);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint16_t FIFO16_Read(FIFO16_Buffer_t* ptr);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] str Parameter_Description
 *  @param [in] size Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO16_Return_t FIFO16_ReadString(FIFO16_Buffer_t* ptr,uint16_t *str, uint8_t size);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] str Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO16_Return_t FIFO16_WriteString(FIFO16_Buffer_t* ptr, uint16_t* str);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO16_BufferStatus_t FIFO16_GetBufferStatus(FIFO16_Buffer_t *ptr);




#endif /* FIFO16_H_ */
