/*
 * FIFO.h
 *
 * Created: 08.03.2016 18:39:52
 *  Author: AP
 */


#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include "PR_DEF.h"


typedef uint8_t FIFO_Return_t;

#define FIFO_N_OK                        0
#define FIFO_OK                          1


/**
 *
 */ 
 #define FIFO_IS_BUFFER_READY(bufPtr)                            \
          ((bufPtr->status == FIFO_BUFFER_EMPTY) ||              \
           (bufPtr->status == FIFO_BUFFER_DATA_AVAILABLE))     
/**
 *
 */            
#define FIFO_HAS_BUFFER_ERRORS(bufPtr)                           \
        ((bufPtr->status == FIFO_WRITE_OVERFLOW_ERROR) ||        \
         (bufPtr->status == FIFO_UNDEF_ERROR))
/**
 *
 */ 
#define FIFO_IS_BUFFER_FULL(bufPtr)                             \
        (bufPtr->status == FIFO_BUFFER_FULL)

/**
 *
 */
#define FIFO_IS_BUFFER_EMPTY(bufPtr)                            \
        (bufPtr->status == FIFO_BUFFER_EMPTY)

/**
 * @brief Buffer Status
 *
 * Status values which the FIFO can contains.
 */       
typedef enum
{
    FIFO_BUFFER_EMPTY               = 0x00,
    FIFO_BUFFER_DATA_AVAILABLE            ,    
    FIFO_BUFFER_FULL                      ,
    FIFO_WRITE_OVERFLOW_ERROR             ,
    FIFO_UNDEF_ERROR
}FIFO_BufferStatus_t;


/**
 * @brief FiFo Counter 
 *
 * Structure which contains all needed counter parameter to handle the 
 * FIFO Buffer. This counter represents the read/write position. 
 * To calculate the correct position, the overflow parameter is needed.
 */
typedef struct
{
	uint8_t read;
	uint8_t write;
    boolean overflow;
}FIFO_Counter_t;

/**
 * @brief Buffer Structure
 *
 * This struct represents a FIFO Buffer.
 */
typedef struct 
{
	uint8_t *bufferPtr;
	uint8_t bufferSize;
    FIFO_BufferStatus_t status; 
	FIFO_Counter_t counter;	
}FIFO_Buffer_t;


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
void FIFO_InitBuffer(FIFO_Buffer_t* ptr,uint8_t* avBuffer,uint8_t avSize);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] p Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void FIFO_Write(FIFO_Buffer_t* ptr, char p);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
char FIFO_Read(FIFO_Buffer_t* ptr);

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
FIFO_Return_t FIFO_ReadString(FIFO_Buffer_t* ptr,char *str, int size);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] str Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO_Return_t FIFO_WriteString(FIFO_Buffer_t* ptr, char* str);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFO_BufferStatus_t FIFO_GetBufferStatus(FIFO_Buffer_t *ptr);




#endif /* FIFO_H_ */
