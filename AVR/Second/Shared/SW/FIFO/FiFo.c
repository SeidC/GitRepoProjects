/*
 * FIFO.c
 *
 * Created: 08.03.2016 18:39:39
 *  Author: AP
 */

 #include "FIFO.h"

/**
 *
 */
#define FIFO_GET_WRITE_COUNT(bufPtr)     				\
		(bufPtr->counter.write)

/**
 *
 */
#define FIFO_GET_READ_COUNT(bufPtr)  					\
		(bufPtr->counter.read)

/**
 *
 */
#define FIFO_GET_BUFFER_SIZE(bufPtr)					\
		(bufPtr->bufferSize)

/**
 *
 */		
#define FIFO_SET_WRITE_BUFFER(bufPtr,val)			    \
		(bufPtr->counter.write = val)

/**
 *
 */
#define FIFO_SET_READ_BUFFER(bufPtr,val)				\
		(bufPtr->counter.read = val)

/**
 *
 */
#define FIFO_GET_BUFFER_CHAR(bufPtr,index)			    \
		(bufPtr->bufferPtr[index])

/**
 *
 */		
#define FIFO_SET_BUFFER_CHAR(bufPtr,index,pChar)		\
		(bufPtr->bufferPtr[index] = pChar)

/**
 *
 */
#define FIFO_GET_OVERFLOW_STATUS(bufPtr)                \
        (bufPtr->counter.overflow)
/**
 *
 */
 #define FIFO_SET_OVERFLOW_STATUS(bufPtr, stat)          \
        (bufPtr->counter.overflow = stat)
/**
 *
 */
#define FIFO_SET_BUFFER_STATUS(bufPtr, stat)            \
        (bufPtr->status = stat)
/**
 *
 */        
#define FIFO_GET_BUFFER_STATUS(bufPtr)                      \
        (bufPtr->status)

/**
 *
 */
static void FIFO_IncrementWriteCounter(FIFO_Buffer_t* ptr);

/**
 *
 */
static void FIFO_IncrementReadCounter(FIFO_Buffer_t* ptr);

/**
 *
 */
static void FIFO_UpdateBufferStatus(FIFO_Buffer_t* ptr);


/**************************************************************************************************
 * FUNCTION: void FIOF_InitBuffer(...)
 *************************************************************************************************/
void FIFO_InitBuffer(FIFO_Buffer_t* ptr,uint8_t* avBuffer,uint8_t avSize)
{
    if(ptr != NULL && avBuffer != NULL)
    {
        ptr->bufferPtr         = avBuffer;
        ptr->bufferSize        = avSize;
        ptr->status            = FIFO_BUFFER_EMPTY;
        ptr->counter.overflow  = FALSE;
        ptr->counter.read      = 0u;
        ptr->counter.write     = 0u;
    }
    else
    {
        ptr = NULL;
    }
    return;
}

/**************************************************************************************************
 * FUNCTION: void FIFO_Write(...)
 *************************************************************************************************/
void FIFO_Write(FIFO_Buffer_t* ptr, char p)
{
	uint8_t i; 
 	
    if(FIFO_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO_GET_WRITE_COUNT(ptr);
	    FIFO_SET_BUFFER_CHAR(ptr,i,p);
	    FIFO_IncrementWriteCounter(ptr);
        FIFO_UpdateBufferStatus(ptr);
    }    
	return;
}

/**************************************************************************************************
 * FUNCTION: void FIFO_WriteString(...)
 *************************************************************************************************/
FIFO_Return_t FIFO_WriteString(FIFO_Buffer_t* ptr, char* str)
{	
    FIFO_Return_t ret = FIFO_OK;
	while(*str)
	{
        if((FIFO_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
           (FIFO_IS_BUFFER_FULL(ptr) == TRUE))
        {
            ret = FIFO_N_OK;
            break;   
        }        
		FIFO_Write(ptr,*str);
        str++;
	}
	return ret;
}

/**************************************************************************************************
 * FUNCTION: char FIFO_Read(...)
 *************************************************************************************************/
char FIFO_Read(FIFO_Buffer_t* ptr)
{
	char p;
	uint8_t i;
	if(FIFO_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO_GET_READ_COUNT(ptr);
	    p = FIFO_GET_BUFFER_CHAR(ptr,i);
        FIFO_IncrementReadCounter(ptr);
        FIFO_UpdateBufferStatus(ptr);
    }         
	return p;
}


/**************************************************************************************************
 * FUNCTION: void FIFO_ReadString(...)
 *************************************************************************************************/
FIFO_Return_t FIFO_ReadString(FIFO_Buffer_t* ptr,char *str, int size)
{
	uint8_t i;
    FIFO_Return_t ret = FIFO_OK;
	for(i = 0; i < size; i++)
	{
         if((FIFO_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
         (FIFO_IS_BUFFER_FULL(ptr) == TRUE))
         {
             ret = FIFO_N_OK;
             break;
         }
		str[i] = FIFO_Read(ptr);
	}
	return ret;
}


/**************************************************************************************************
 * FUNCTION: void FIFO_IncrementWriteCounter(...)
 *************************************************************************************************/
static void FIFO_IncrementWriteCounter(FIFO_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO_GET_WRITE_COUNT(ptr) < FIFO_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO_GET_WRITE_COUNT(ptr);
        FIFO_SET_WRITE_BUFFER(ptr,++size);
	}
	else
	{
		FIFO_SET_WRITE_BUFFER(ptr,0);
        FIFO_SET_OVERFLOW_STATUS(ptr,TRUE);
	}
	return;
}


/**************************************************************************************************
 * FUNCTION: void FIFO_IncrementReadCounter(...)
 *************************************************************************************************/
static void FIFO_IncrementReadCounter(FIFO_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO_GET_READ_COUNT(ptr) < FIFO_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO_GET_READ_COUNT(ptr);
        FIFO_SET_READ_BUFFER(ptr,++size);
	}
	else
	{
		FIFO_SET_READ_BUFFER(ptr,0);
        FIFO_SET_OVERFLOW_STATUS(ptr,FALSE);
	}
	return;
}

/**************************************************************************************************
 * FUNCTION: void FIFO_UpdateBufferStatus(...)
 *************************************************************************************************/
static void FIFO_UpdateBufferStatus(FIFO_Buffer_t* ptr)
{
 /************************************************************************ 
  *
  *     Overflow = FALSE
  * |--------------------------------------------------------|   
  *                   ^                        ^
  *                   a                        b 
  *                   
  *                   b > a --- OK Daten Verfügbar
  *                   b = a --- OK Keine Daten verfübar
  *                   b < a --- kein error muss abgesichert werden
  * 
  *     Overflow = TRUE                  
  *  |--------------------------------------------------------|
  *              ^                        ^
  *              b                        a
  *
  *
  *              b < a --- OK 
  *               b = a --- Buffer voll
  *              b > a --- Error Write Overflow
  *                                                                  
 ************************************************************************/
    
    uint8_t w,r,o;
    w = FIFO_GET_WRITE_COUNT(ptr);
    r = FIFO_GET_READ_COUNT(ptr);
    o = FIFO_GET_OVERFLOW_STATUS(ptr);
    
    if(o == FALSE)
    {
        if(w > r)
        {
            FIFO_SET_BUFFER_STATUS(ptr,FIFO_BUFFER_DATA_AVAILABLE);
        }
        else if (w == r)
        {
            FIFO_SET_BUFFER_STATUS(ptr,FIFO_BUFFER_EMPTY);
        }   
        else 
        {
            FIFO_SET_BUFFER_STATUS(ptr, FIFO_UNDEF_ERROR);
        }     
    }
    else 
    {
        
        if(w > r)
        {
            FIFO_SET_BUFFER_STATUS(ptr,FIFO_WRITE_OVERFLOW_ERROR);
        }
        else if (w == r)
        {
            FIFO_SET_BUFFER_STATUS(ptr,FIFO_BUFFER_FULL);
        }
        else
        {
            FIFO_SET_BUFFER_STATUS(ptr,FIFO_BUFFER_DATA_AVAILABLE);
        }
    }
    return;
}

/**************************************************************************************************
 * FUNCTION: FIFO_BufferStatus_t FIFO_GetBufferStatus(...)
 *************************************************************************************************/
FIFO_BufferStatus_t FIFO_GetBufferStatus(FIFO_Buffer_t *ptr)
{
    return FIFO_GET_BUFFER_STATUS(ptr);
}

/**************************************************************************************************
 * FUNCTION: uint16_t FIFO_GetFreeBufferSpace(...)
 *************************************************************************************************/
uint16_t FIFO_GetFreeBufferSpace(FIFO_Buffer_t *ptr)
{
    uint8_t w,r,o;
    uint16_t space = 0;
    w = FIFO_GET_WRITE_COUNT(ptr);
    r = FIFO_GET_READ_COUNT(ptr);
    o = FIFO_GET_OVERFLOW_STATUS(ptr);
    
    if(o == TRUE)
    {
        space = FIFO_GET_BUFFER_SIZE(ptr) - (r - w ); 
    }
    else
    {
        space = FIFO_GET_BUFFER_SIZE(ptr) - (w - r ); 
    }
    return space;
}