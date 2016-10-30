/*
 * FIFOCHAR.h
 *
 * Created: 08.03.2016 18:39:52
 *  Author: AP
 */


#ifndef FIFOCHAR_H_
#define FIFOCHAR_H_

#include <stdio.h>
#include "PR_DEF.h"


typedef uint8_t FIFOCHAR_Return_t;

#define FIFOCHAR_N_OK                        0
#define FIFOCHAR_OK                          1


/**
 *
 */ 
 #define FIFOCHAR_IS_BUFFER_READY(bufPtr)                            \
          ((bufPtr->status == FIFOCHAR_BUFFER_EMPTY) ||              \
           (bufPtr->status == FIFOCHAR_BUFFER_DATA_AVAILABLE))     
/**
 *
 */            
#define FIFOCHAR_HAS_BUFFER_ERRORS(bufPtr)                           \
        ((bufPtr->status == FIFOCHAR_WRITE_OVERFLOW_ERROR) ||        \
         (bufPtr->status == FIFOCHAR_UNDEF_ERROR))
/**
 *
 */ 
#define FIFOCHAR_IS_BUFFER_FULL(bufPtr)                             \
        (bufPtr->status == FIFOCHAR_BUFFER_FULL)

/**
 *
 */
#define FIFOCHAR_IS_BUFFER_EMPTY(bufPtr)                            \
        (bufPtr->status == FIFOCHAR_BUFFER_EMPTY)
        
typedef enum
{
    FIFOCHAR_BUFFER_EMPTY               = 0x00,
    FIFOCHAR_BUFFER_DATA_AVAILABLE            ,    
    FIFOCHAR_BUFFER_FULL                      ,
    FIFOCHAR_WRITE_OVERFLOW_ERROR             ,
    FIFOCHAR_UNDEF_ERROR
}FIFOCHAR_BufferStatus_t;


/**
 *
 */
typedef struct
{
	uint8_t read;
	uint8_t write;
   bool_t overflow;
}FIFOCHAR_Counter_t;

/**
 *
 */
typedef struct 
{
	uint8_t *bufferPtr;
	uint8_t bufferSize;
    FIFOCHAR_BufferStatus_t status; 
	FIFOCHAR_Counter_t counter;		
}FIFOCHAR_Buffer_t;


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
void FIOF_InitBuffer(FIFOCHAR_Buffer_t* ptr,uint8_t* avBuffer,uint8_t avSize);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] p Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void FIFOCHAR_Write(FIFOCHAR_Buffer_t* ptr, char p);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
char FIFOCHAR_Read(FIFOCHAR_Buffer_t* ptr);

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
FIFOCHAR_Return_t FIFOCHAR_ReadString(FIFOCHAR_Buffer_t* ptr,char *str, int size);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @param [in] str Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFOCHAR_Return_t FIFOCHAR_WriteString(FIFOCHAR_Buffer_t* ptr, char* str);

/**
 *  @brief Brief
 *  
 *  @param [in] ptr Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
FIFOCHAR_BufferStatus_t FIFOCHAR_GetBufferStatus(FIFOCHAR_Buffer_t *ptr);




#endif /* FIFOCHAR_H_ */
