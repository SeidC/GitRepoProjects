/*
 * FIFO16.c
 *
 * Created: 08.03.2016 18:39:39
 *  Author: AP
 */

 #include "FIFO16.h"

/**
 *
 */
#define FIFO16_GET_WRITE_COUNT(bufPtr)     				\
		(bufPtr->counter.write)

/**
 *
 */
#define FIFO16_GET_READ_COUNT(bufPtr)  					\
		(bufPtr->counter.read)

/**
 *
 */
#define FIFO16_GET_BUFFER_SIZE(bufPtr)					\
		(bufPtr->bufferSize)

/**
 *
 */		
#define FIFO16_SET_WRITE_BUFFER(bufPtr,val)			    \
		(bufPtr->counter.write = val)

/**
 *
 */
#define FIFO16_SET_READ_BUFFER(bufPtr,val)				\
		(bufPtr->counter.read = val)

/**
 *
 */
#define FIFO16_GET_BUFFER_CHAR(bufPtr,index)			    \
		(bufPtr->bufferPtr[index])

/**
 *
 */		
#define FIFO16_SET_BUFFER_CHAR(bufPtr,index,pChar)		\
		(bufPtr->bufferPtr[index] = pChar)

/**
 *
 */
#define FIFO16_GET_OVERFLOW_STATUS(bufPtr)                \
        (bufPtr->counter.overflow)
/**
 *
 */
 #define FIFO16_SET_OVERFLOW_STATUS(bufPtr, stat)          \
        (bufPtr->counter.overflow = stat)
/**
 *
 */
#define FIFO16_SET_BUFFER_STATUS(bufPtr, stat)            \
        (bufPtr->status = stat)
/**
 *
 */        
#define FIFO16_GET_BUFFER_STATUS(bufPtr)                      \
        (bufPtr->status)

/**
 *
 */
static void FIFO16_IncrementWriteCounter(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr);

/**
 *
 */
static void FIFO16_IncrementReadCounter(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr);

/**
 *
 */
static void FIFO16_UpdateBufferStatus(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr);


/**************************************************************************************************
 * FUNCTION: void FIOF_InitBuffer(...)
 *************************************************************************************************/
void FIFO16_InitBuffer(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr,FIFO16_DATA_TYPE* avBuffer,uint8_t avSize)
{
    if(ptr != NULL && avBuffer != NULL)
    {
        ptr->bufferPtr         = avBuffer;
        ptr->bufferSize        = avSize;
        ptr->status            = FIFO16_BUFFER_EMPTY;
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
 * FUNCTION: void FIFO16_Write(...)
 *************************************************************************************************/
void FIFO16_Write(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr, FIFO16_DATA_TYPE p)
{
	uint8_t i; 
 	
    if(FIFO16_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO16_GET_WRITE_COUNT(ptr);
	    FIFO16_SET_BUFFER_CHAR(ptr,i,p);
	    FIFO16_IncrementWriteCounter(ptr);
        FIFO16_UpdateBufferStatus(ptr);
    }    
	return;
}

/******************************************************************************
 * FUNCTION: void FIFO16_WriteString(...)
 *****************************************************************************/
FIFO16_Return_t FIFO16_WriteString(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr, FIFO16_DATA_TYPE* str)
{	
    FIFO16_Return_t ret = FIFO16_OK;
	while(*str)
	{
        if((FIFO16_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
           (FIFO16_IS_BUFFER_FULL(ptr) == TRUE))
        {
            ret = FIFO16_N_OK;
            break;   
        }        
		FIFO16_Write(ptr,*str);
        str++;
	}
	return ret;
}

/******************************************************************************
 * FUNCTION: char FIFO16_Read(...)
 *****************************************************************************/
FIFO16_DATA_TYPE FIFO16_Read(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr)
{
	FIFO16_DATA_TYPE p = 0;
	uint8_t i;
	if(FIFO16_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFO16_GET_READ_COUNT(ptr);
	    p = FIFO16_GET_BUFFER_CHAR(ptr,i);
        FIFO16_IncrementReadCounter(ptr);
        FIFO16_UpdateBufferStatus(ptr);
    }         
	return p;
}


/******************************************************************************
 * FUNCTION: void FIFO16_ReadString(...)
 *****************************************************************************/
FIFO16_Return_t FIFO16_ReadString(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr,FIFO16_DATA_TYPE *str, uint8_t size)
{
	uint8_t i;
    FIFO16_Return_t ret = FIFO16_OK;
	for(i = 0; i < size; i++)
	{
         if((FIFO16_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
         (FIFO16_IS_BUFFER_FULL(ptr) == TRUE))
         {
             ret = FIFO16_N_OK;
             break;
         }
		str[i] = FIFO16_Read(ptr);
	}
	return ret;
}


/******************************************************************************
 * FUNCTION: void FIFO16_IncrementWriteCounter(...)
 *****************************************************************************/
static void FIFO16_IncrementWriteCounter(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO16_GET_WRITE_COUNT(ptr) < FIFO16_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO16_GET_WRITE_COUNT(ptr);
        FIFO16_SET_WRITE_BUFFER(ptr,++size);
	}
	else
	{
		FIFO16_SET_WRITE_BUFFER(ptr,0);
        FIFO16_SET_OVERFLOW_STATUS(ptr,TRUE);
	}
	return;
}


/******************************************************************************
 * FUNCTION: void FIFO16_IncrementReadCounter(...)
 *****************************************************************************/
static void FIFO16_IncrementReadCounter(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFO16_GET_READ_COUNT(ptr) < FIFO16_GET_BUFFER_SIZE(ptr))
	{
		size = FIFO16_GET_READ_COUNT(ptr);
        FIFO16_SET_READ_BUFFER(ptr,++size);
	}
	else
	{
		FIFO16_SET_READ_BUFFER(ptr,0);
        FIFO16_SET_OVERFLOW_STATUS(ptr,FALSE);
	}
	return;
}

/******************************************************************************
 * FUNCTION: void FIFO16_UpdateBufferStatus(...)
 *****************************************************************************/
static void FIFO16_UpdateBufferStatus(FIFO16_BUFFER_EXT FIFO16_Buffer_t* ptr)
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
    w = FIFO16_GET_WRITE_COUNT(ptr);
    r = FIFO16_GET_READ_COUNT(ptr);
    o = FIFO16_GET_OVERFLOW_STATUS(ptr);
    
    if(o == FALSE)
    {
        if(w > r)
        {
            FIFO16_SET_BUFFER_STATUS(ptr,FIFO16_BUFFER_DATA_AVAILABLE);
        }
        else if (w == r)
        {
            FIFO16_SET_BUFFER_STATUS(ptr,FIFO16_BUFFER_EMPTY);
        }   
        else 
        {
            FIFO16_SET_BUFFER_STATUS(ptr, FIFO16_UNDEF_ERROR);
        }     
    }
    else 
    {
        
        if(w > r)
        {
            FIFO16_SET_BUFFER_STATUS(ptr,FIFO16_WRITE_OVERFLOW_ERROR);
        }
        else if (w == r)
        {
            FIFO16_SET_BUFFER_STATUS(ptr,FIFO16_BUFFER_FULL);
        }
        else
        {
            FIFO16_SET_BUFFER_STATUS(ptr,FIFO16_BUFFER_DATA_AVAILABLE);
        }
    }
    return;
}

/******************************************************************************
 * FUNCTION: FIFO16_BufferStatus_t FIFO16_GetBufferStatus(...)
 *****************************************************************************/
FIFO16_BufferStatus_t FIFO16_GetBufferStatus(FIFO16_BUFFER_EXT FIFO16_Buffer_t *ptr)
{
    return FIFO16_GET_BUFFER_STATUS(ptr);
}

