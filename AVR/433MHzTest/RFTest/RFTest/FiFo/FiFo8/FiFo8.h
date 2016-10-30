/*
 * FIFO8.h
 *
 * Created: 08.03.2016 18:39:52
 *  Author: AP
 */


#ifndef FIFO8_H_
#define FIFO8_H_

#include <stdio.h>
#include "PR_DEF.h"


typedef uint8_t FIFO8_Return_t;

#define FIFO8_N_OK                        0
#define FIFO8_OK                          1


/**
 *
 */ 
 #define FIFO8_IS_BUFFER_READY(bufPtr)                            \
          ((bufPtr->status == FIFO8_BUFFER_EMPTY) ||              \
           (bufPtr->status == FIFO8_BUFFER_DATA_AVAILABLE))     
/**
 *
 */            
#define FIFO8_HAS_BUFFER_ERRORS(bufPtr)                           \
        ((bufPtr->status == FIFO8_WRITE_OVERFLOW_ERROR) ||        \
         (bufPtr->status == FIFO8_UNDEF_ERROR))
/**
 *
 */ 
#define FIFO8_IS_BUFFER_FULL(bufPtr)                             \
        (bufPtr->status == FIFO8_BUFFER_FULL)

/**
 *
 */
#define FIFO8_IS_BUFFER_EMPTY(bufPtr)                            \
        (bufPtr->status == FIFO8_BUFFER_EMPTY)
        
typedef enum
{
    FIFO8_BUFFER_EMPTY               = 0x00,
    FIFO8_BUFFER_DATA_AVAILABLE            ,    
    FIFO8_BUFFER_FULL                      ,
    FIFO8_WRITE_OVERFLOW_ERROR             ,
    FIFO8_UNDEF_ERROR
}FIFO8_BufferStatus_t;


/**
 *
 */
typedef struct
{
	uint8_t read;
	uint8_t write;
    bool_t overflow;
}FIFO8_Counter_t;

/**
 *
 */
typedef struct 
{
	uint8_t *bufferPtr;
	uint8_t bufferSize;
    FIFO8_BufferStatus_t status; 
	FIFO8_Counter_t counter;		
}FIFO8_Buffer_t;


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
void FIFO8_InitBuffer(FIFO8_Buffer_t* ptr,uint8_t* avBuffer,uint8_t avSize);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] p Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void FIFO8_Write(FIFO8_Buffer_t* ptr, uint8_t p);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
uint8_t FIFO8_Read(FIFO8_Buffer_t* ptr);

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
FIFO8_Return_t FIFO8_ReadString(FIFO8_Buffer_t* ptr,uint8_t *str, uint8_t size);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] str Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO8_Return_t FIFO8_WriteString(FIFO8_Buffer_t* ptr, uint8_t* str);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO8_BufferStatus_t FIFO8_GetBufferStatus(FIFO8_Buffer_t *ptr);




#endif /* FIFO8_H_ */
