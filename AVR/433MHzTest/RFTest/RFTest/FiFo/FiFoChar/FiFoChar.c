/*
 * FIFOCHAR.c
 *
 * Created: 08.03.2016 18:39:39
 *  Author: AP
 */

 #include "FIFOCHAR.h"

/**
 *
 */
#define FIFOCHAR_GET_WRITE_COUNT(bufPtr)     				\
		(bufPtr->counter.write)

/**
 *
 */
#define FIFOCHAR_GET_READ_COUNT(bufPtr)  					\
		(bufPtr->counter.read)

/**
 *
 */
#define FIFOCHAR_GET_BUFFER_SIZE(bufPtr)					\
		(bufPtr->bufferSize)

/**
 *
 */		
#define FIFOCHAR_SET_WRITE_BUFFER(bufPtr,val)			    \
		(bufPtr->counter.write = val)

/**
 *
 */
#define FIFOCHAR_SET_READ_BUFFER(bufPtr,val)				\
		(bufPtr->counter.read = val)

/**
 *
 */
#define FIFOCHAR_GET_BUFFER_CHAR(bufPtr,index)			    \
		(bufPtr->bufferPtr[index])

/**
 *
 */		
#define FIFOCHAR_SET_BUFFER_CHAR(bufPtr,index,pChar)		\
		(bufPtr->bufferPtr[index] = pChar)

/**
 *
 */
#define FIFOCHAR_GET_OVERFLOW_STATUS(bufPtr)                \
        (bufPtr->counter.overflow)
/**
 *
 */
 #define FIFOCHAR_SET_OVERFLOW_STATUS(bufPtr, stat)          \
        (bufPtr->counter.overflow = stat)
/**
 *
 */
#define FIFOCHAR_SET_BUFFER_STATUS(bufPtr, stat)            \
        (bufPtr->status = stat)
/**
 *
 */        
#define FIFOCHAR_GET_BUFFER_STATUS(bufPtr)                      \
        (bufPtr->status)

/**
 *
 */
static void FIFOCHAR_IncrementWriteCounter(FIFOCHAR_Buffer_t* ptr);

/**
 *
 */
static void FIFOCHAR_IncrementReadCounter(FIFOCHAR_Buffer_t* ptr);

/**
 *
 */
static void FIFOCHAR_UpdateBufferStatus(FIFOCHAR_Buffer_t* ptr);


/**************************************************************************************************
 * FUNCTION: void FIOF_InitBuffer(...)
 *************************************************************************************************/
void FIOF_InitBuffer(FIFOCHAR_Buffer_t* ptr,uint8_t* avBuffer,uint8_t avSize)
{
    if(ptr != NULL && avBuffer != NULL)
    {
        ptr->bufferPtr         = avBuffer;
        ptr->bufferSize        = avSize;
        ptr->status            = FIFOCHAR_BUFFER_EMPTY;
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
 * FUNCTION: void FIFOCHAR_Write(...)
 *************************************************************************************************/
void FIFOCHAR_Write(FIFOCHAR_Buffer_t* ptr, char p)
{
	uint8_t i; 
 	
    if(FIFOCHAR_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFOCHAR_GET_WRITE_COUNT(ptr);
	    FIFOCHAR_SET_BUFFER_CHAR(ptr,i,p);
	    FIFOCHAR_IncrementWriteCounter(ptr);
        FIFOCHAR_UpdateBufferStatus(ptr);
    }    
	return;
}

/******************************************************************************
 * FUNCTION: void FIFOCHAR_WriteString(...)
 *****************************************************************************/
FIFOCHAR_Return_t FIFOCHAR_WriteString(FIFOCHAR_Buffer_t* ptr, char* str)
{	
    FIFOCHAR_Return_t ret = FIFOCHAR_OK;
	while(*str)
	{
        if((FIFOCHAR_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
           (FIFOCHAR_IS_BUFFER_FULL(ptr) == TRUE))
        {
            ret = FIFOCHAR_N_OK;
            break;   
        }        
		FIFOCHAR_Write(ptr,*str);
        str++;
	}
	return ret;
}

/******************************************************************************
 * FUNCTION: char FIFOCHAR_Read(...)
 *****************************************************************************/
char FIFOCHAR_Read(FIFOCHAR_Buffer_t* ptr)
{
	char p;
	uint8_t i;
	if(FIFOCHAR_IS_BUFFER_READY(ptr) == TRUE)
    {
	    i = FIFOCHAR_GET_READ_COUNT(ptr);
	    p = FIFOCHAR_GET_BUFFER_CHAR(ptr,i);
        FIFOCHAR_IncrementReadCounter(ptr);
        FIFOCHAR_UpdateBufferStatus(ptr);
    }         
	return p;
}


/******************************************************************************
 * FUNCTION: void FIFOCHAR_ReadString(...)
 *****************************************************************************/
FIFOCHAR_Return_t FIFOCHAR_ReadString(FIFOCHAR_Buffer_t* ptr,char *str, int size)
{
	uint8_t i;
    FIFOCHAR_Return_t ret = FIFOCHAR_OK;
	for(i = 0; i < size; i++)
	{
         if((FIFOCHAR_HAS_BUFFER_ERRORS(ptr) == TRUE) ||
         (FIFOCHAR_IS_BUFFER_FULL(ptr) == TRUE))
         {
             ret = FIFOCHAR_N_OK;
             break;
         }
		str[i] = FIFOCHAR_Read(ptr);
	}
	return ret;
}


/******************************************************************************
 * FUNCTION: void FIFOCHAR_IncrementWriteCounter(...)
 *****************************************************************************/
static void FIFOCHAR_IncrementWriteCounter(FIFOCHAR_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFOCHAR_GET_WRITE_COUNT(ptr) < FIFOCHAR_GET_BUFFER_SIZE(ptr))
	{
		size = FIFOCHAR_GET_WRITE_COUNT(ptr);
        FIFOCHAR_SET_WRITE_BUFFER(ptr,++size);
	}
	else
	{
		FIFOCHAR_SET_WRITE_BUFFER(ptr,0);
        FIFOCHAR_SET_OVERFLOW_STATUS(ptr,TRUE);
	}
	return;
}


/******************************************************************************
 * FUNCTION: void FIFOCHAR_IncrementReadCounter(...)
 *****************************************************************************/
static void FIFOCHAR_IncrementReadCounter(FIFOCHAR_Buffer_t* ptr)
{
	uint8_t size;
	if(FIFOCHAR_GET_READ_COUNT(ptr) < FIFOCHAR_GET_BUFFER_SIZE(ptr))
	{
		size = FIFOCHAR_GET_READ_COUNT(ptr);
        FIFOCHAR_SET_READ_BUFFER(ptr,++size);
	}
	else
	{
		FIFOCHAR_SET_READ_BUFFER(ptr,0);
        FIFOCHAR_SET_OVERFLOW_STATUS(ptr,FALSE);
	}
	return;
}

/******************************************************************************
 * FUNCTION: void FIFOCHAR_UpdateBufferStatus(...)
 *****************************************************************************/
static void FIFOCHAR_UpdateBufferStatus(FIFOCHAR_Buffer_t* ptr)
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
    w = FIFOCHAR_GET_WRITE_COUNT(ptr);
    r = FIFOCHAR_GET_READ_COUNT(ptr);
    o = FIFOCHAR_GET_OVERFLOW_STATUS(ptr);
    
    if(o == FALSE)
    {
        if(w > r)
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr,FIFOCHAR_BUFFER_DATA_AVAILABLE);
        }
        else if (w == r)
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr,FIFOCHAR_BUFFER_EMPTY);
        }   
        else 
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr, FIFOCHAR_UNDEF_ERROR);
        }     
    }
    else 
    {
        
        if(w > r)
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr,FIFOCHAR_WRITE_OVERFLOW_ERROR);
        }
        else if (w == r)
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr,FIFOCHAR_BUFFER_FULL);
        }
        else
        {
            FIFOCHAR_SET_BUFFER_STATUS(ptr,FIFOCHAR_BUFFER_DATA_AVAILABLE);
        }
    }
    return;
}

/******************************************************************************
 * FUNCTION: FIFOCHAR_BufferStatus_t FIFOCHAR_GetBufferStatus(...)
 *****************************************************************************/
FIFOCHAR_BufferStatus_t FIFOCHAR_GetBufferStatus(FIFOCHAR_Buffer_t *ptr)
{
    return FIFOCHAR_GET_BUFFER_STATUS(ptr);
}

