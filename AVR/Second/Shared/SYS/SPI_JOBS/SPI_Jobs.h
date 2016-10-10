/*
 * SPI_Jobs.h
 *
 * Created: 26.04.2016 22:39:31
 *  Author: AP02
 */ 


#ifndef SPI_JOBS_H_
#define SPI_JOBS_H_

#include "PR_DEF.h"


/*--- SPI Job Defines ---------------------------------------------------------------------------*/

#define SPI_MAX_DATA_SIZE                                           10u

/*--- SPI Commandos -----------------------------------------------------------------------------*/


/*--- SPI Job Type Definitions ------------------------------------------------------------------*/
/**
 * @brief Job Type definition
 */
typedef enum
{
    SPI_COMMANDO         = 0x00,
    SPI_DATA_TX                ,
    SPI_DATA_RX        
    
}SPI_JobType_t;


/**
 * @brief Job structure
 *
 */
typedef struct
{
    SPI_JobType_t type;
    uint8_t infoOrCmd;
    uint8_t *data;    
}SPI_Job_t;


/**
 * @brief Job list of the SPI interface
 *
 */
typedef struct 
{
    SPI_Job_t *jobs;
    uint8_t numberOfJobs;
}SPI_JobList_t;



#endif /* SPI_JOBS_H_ */