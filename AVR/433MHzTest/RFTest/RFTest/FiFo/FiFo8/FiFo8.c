/*
 * FIFO8.c
 *
 * Created: 08.03.2016 18:39:39
 *  Author: AP
 */

 #include "FIFO8.h"

/**
 *
 */
#define FIFO8_GET_WRITE_COUNT(bufPtr)     				\
		(bufPtr->counter.write)

/**
 *
 */
#define FIFO8_GET_READ_COUNT(bufPtr)  					\
		(bufPtr->counter.read)

/**
 *
 */
#define FIFO8_GET_BUFFER_SIZE(bufPtr)					\
		(bufPtr->bufferSize)

/**
 *
 */		
#define FIFO8_SET_WRITE_BUFFER(bufPtr,val)			    \
		(bufPtr->counter.write = val)

/**
 *
 */
#define FIFO8_SET_READ_BUFFER(bufPtr,val)				\
		(bufPtr->counter.read = val)

/**
 *
 */
#define FIFO8_GET_BUFFER_CHAR(bufPtr,index)			    \
		(bufPtr->bufferPtr[index])

/**
 *
 */		
#define FIFO8_SET_BUFFER_CHAR(bufPtr,index,pChar)		\
		(bufPtr->bufferPtr[index] = pChar)

/**
 *
 */
#define FIFO8_GET_OVERFLOW_STATUS(bufPtr)                \
        (bufPtr->counter.overflow)
/**
 *
 */
 #define FIFO8_SET_OVERFLOW_STATUS(bufPtr, stat)          \
        (bufPtr->counter.overflow = stat)
/**
 *
 */
#define FIFO8_SET_BUFFER_STATUS(bufPtr, stat)            \
        (bufPtr->status = stat)
/**
 *
 */        
#define FIFO8_GET_BUFFER_STATUS(bufPtr)                      \
        (bufPtr->status)

/**
 *
 */
static void FIFO8_IncrementWriteCounter(FIFO8_BUFFER_EXT  FIFO8_Buffer_t* ptr);

/**
 *
 */
static void FIFO8_IncrementReadCounter(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr);

/**
 *
 */
static void FIFO8_UpdateBufferStatus(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr);


/**************************************************************************************************
 * FUNCTION: void FIOF_InitBuffer(...)
 *************************************************************************************************/
void FIFO8_InitBuffer(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr,FIFO8_DATA_TYPE* avBuffer,uint8_t avSize)
{
    if(ptr != NULL && avBuffer != NULL)
    {
        ptr->bufferPtr         = avBuffer;
        ptr->bufferSize        = avSize;
        ptr->status            = FIFO8_BUFFER_EMPTY;
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
 * FUNCTION: void FIFO8_Write(...)
 *************************************************************************************************/
void FIFO8_Write(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr, FIFO8_DATA_TYPE p)
{
	uint8_t i; 
 	
    if(FIFO8_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO8_GET_WRITE_COUNT(ptr);
	    FIFO8_SET_BUFFER_CHAR(ptr,i,p);
	    FIFO8_IncrementWriteCounter(ptr);
        FIFO8_UpdateBufferStatus(ptr);
    }    
	return;
}

/******************************************************************************
 * FUNCTION: void FIFO8_WriteString(...)
 *****************************************************************************/
FIFO8_Return_t FIFO8_WriteString(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr, FIFO8_DATA_TYPE* str)
{	
    FIFO8_Return_t ret = FIFO8_OK;
	while(*str)
	{
        if((FIFO8_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
           (FIFO8_IS_BUFFER_FULL(ptr) == TRUE))
        {
            ret = FIFO8_N_OK;
            break;   
        }        
		FIFO8_Write(ptr,*str);
        str++;
	}
	return ret;
}

/******************************************************************************
 * FUNCTION: char FIFO8_Read(...)
 *****************************************************************************/
FIFO8_DATA_TYPE FIFO8_Read(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr)
{
	FIFO8_DATA_TYPE p;
	uint8_t i;
	if(FIFO8_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO8_GET_READ_COUNT(ptr);
	    p = FIFO8_GET_BUFFER_CHAR(ptr,i);
        FIFO8_IncrementReadCounter(ptr);
        FIFO8_UpdateBufferStatus(ptr);
    }         
	return p;
}


/******************************************************************************
 * FUNCTION: void FIFO8_ReadString(...)
 *****************************************************************************/
FIFO8_Return_t FIFO8_ReadString(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr,FIFO8_DATA_TYPE *str, uint8_t size)
{
	uint8_t i;
    FIFO8_Return_t ret = FIFO8_OK;
	for(i = 0; i < size; i++)
	{
         if((FIFO8_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
         (FIFO8_IS_BUFFER_FULL(ptr) == TRUE))
         {
             ret = FIFO8_N_OK;
             break;
         }
		str[i] = FIFO8_Read(ptr);
	}
	return ret;
}


/******************************************************************************
 * FUNCTION: void FIFO8_IncrementWriteCounter(...)
 *****************************************************************************/
static void FIFO8_IncrementWriteCounter(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO8_GET_WRITE_COUNT(ptr) < FIFO8_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO8_GET_WRITE_COUNT(ptr);
        FIFO8_SET_WRITE_BUFFER(ptr,++size);
	}
	else
	{
		FIFO8_SET_WRITE_BUFFER(ptr,0);
        FIFO8_SET_OVERFLOW_STATUS(ptr,TRUE);
	}
	return;
}


/******************************************************************************
 * FUNCTION: void FIFO8_IncrementReadCounter(...)
 *****************************************************************************/
static void FIFO8_IncrementReadCounter(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO8_GET_READ_COUNT(ptr) < FIFO8_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO8_GET_READ_COUNT(ptr);
        FIFO8_SET_READ_BUFFER(ptr,++size);
	}
	else
	{
		FIFO8_SET_READ_BUFFER(ptr,0);
        FIFO8_SET_OVERFLOW_STATUS(ptr,FALSE);
	}
	return;
}

/******************************************************************************
 * FUNCTION: void FIFO8_UpdateBufferStatus(...)
 *****************************************************************************/
static void FIFO8_UpdateBufferStatus(FIFO8_BUFFER_EXT FIFO8_Buffer_t* ptr)
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
    w = FIFO8_GET_WRITE_COUNT(ptr);
    r = FIFO8_GET_READ_COUNT(ptr);
    o = FIFO8_GET_OVERFLOW_STATUS(ptr);
    
    if(o == FALSE)
    {
        if(w > r)
        {
            FIFO8_SET_BUFFER_STATUS(ptr,FIFO8_BUFFER_DATA_AVAILABLE);
        }
        else if (w == r)
        {
            FIFO8_SET_BUFFER_STATUS(ptr,FIFO8_BUFFER_EMPTY);
        }   
        else 
        {
            FIFO8_SET_BUFFER_STATUS(ptr, FIFO8_UNDEF_ERROR);
        }     
    }
    else 
    {
        
        if(w > r)
        {
            FIFO8_SET_BUFFER_STATUS(ptr,FIFO8_WRITE_OVERFLOW_ERROR);
        }
        else if (w == r)
        {
            FIFO8_SET_BUFFER_STATUS(ptr,FIFO8_BUFFER_FULL);
        }
        else
        {
            FIFO8_SET_BUFFER_STATUS(ptr,FIFO8_BUFFER_DATA_AVAILABLE);
        }
    }
    return;
}

/******************************************************************************
 * FUNCTION: FIFO8_BufferStatus_t FIFO8_GetBufferStatus(...)
 *****************************************************************************/
FIFO8_BufferStatus_t FIFO8_GetBufferStatus(FIFO8_BUFFER_EXT FIFO8_Buffer_t *ptr)
{
    return FIFO8_GET_BUFFER_STATUS(ptr);
}

