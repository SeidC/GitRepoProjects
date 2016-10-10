
/*
 * SPI.h
 *
 * Created: 19.04.2016 20:37:42
 *  Author: AP02
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "PR_DEF.h"

/*--- SPI Register Definition --------------------------------------------------------------------*/
/**
 * @brief SPI Control Register
 *
 */
#define SPI_CONTROL_REGISTER                            SPCR
/**
 * @brief SPI Status Register
 *
 */
#define SPI_STATUS_REGISTER                             SPSR
/**
 * @brief SPI Data Register
 *
 */
#define SPI_DATA_REGISTER                               SPDR

/**
 * @brief SPI Tx Data Register
 */
#define SPI_TX_DATA_REGISTER                            SPI_DATA_REGISTER

/**
 * @brief SPI Rx Data Register
 */
#define SPI_RX_DATA_REGISTER                            SPI_DATA_REGISTER

/**
 * @brief SPI Interrupt Vector
 *
 */
#define SPI_INTERRUPT_VECTOR                            SPI_STC_vect

#define SPI_PORT                                        PORTB

#define SPI_MOSI_PIN                                    PB5 

#define SPI_MISO_PIN                                    PB6

#define SPI_SCK_PIN                                     PB7

#define SPI_SS_PIN                                      PB4
/*--- SPI Constants -----------------------------------------------------------------------------*/

/**
 * @brief Set Slave Constant
 */
#define SPI_SET_SLAVE                                              1
/**
 * @brief Release Slave Constant
 */
#define SPI_RELEASE_SLAVE                                          0

/*--- Type Definition of the SPI ----------------------------------------------------------------*/
/**
 * @brief Enable Type
 *
 * Type to Enable or Disable the SPI.
 */
typedef enum
{
    SPI_DISABLE = 0x00,
    SPI_ENABLE        ,    
    
}SPI_Enable_t;

/**
 * @brief Data Order Type
 *
 * Data Type to choose whether the MSB will be transmitted first or 
 * the LSB will transmitted first.
 */
typedef enum
{
    SPI_MSB_TRANSMIT_FIRST = 0x00,
    SPI_LSB_TRANSMIT_FIRST       ,
    
}SPI_DataOrder_t;

/**
 * @brief Mode Type
 *
 * This type specifies the Mode of the SPI.
 * SPI can be used as Master or as Slave
 */
typedef enum 
{
    SPI_SLAVE_MODE  = 0x00,
    SPI_MASTER_MODE       ,
    
}SPI_Mode_t;

/**
 * @brief SCK Settings Type
 *
 * This type defines the SCK Settings. This means
 * in which case the SPI shall be IDLE (HIGH/LOW) and 
 * which edge will be used to transmit a data byte (LEADING EDGE/TRAILING EDGE)
 */
typedef enum 
{
    SPI_SCK_IDLE_LOW_LEADING_EDGE   = 0x00,
    SPI_SCK_IDLE_HIGH_LEADING_EDGE        ,
    SPI_SCK_IDLE_LOW_TRAILING_EDGE        ,
    SPI_SCK_IDLE_HIGH_TRALING_EDGE        ,    
}SPI_SckSettings_t;

/**
 * @brief Frequency Factor Type
 *
 * Type to choose the SPI Frequency.
 * Calculation of the Frequency: F_CPU / FAC_X = SPI Frequency
 */
typedef enum
{
    SPI_FREQUENCE_FAC_4               = 0x00,
    SPI_FREQUENCE_FAC_16                    ,
    SPI_FREQUENCE_FAC_64                    ,
    SPI_FREQUENCE_FAC_128                   ,
    SPI_FREQUENCE_FAC_2                     ,
    SPI_FREQUENCE_FAC_8                     ,
    SPI_FREQUENCE_FAC_32                    ,

}SPI_FrequenceFactor_t;

/**
 * @brief Select Slave Handle Type
 *
 * Handle Type which will be used as index for choosing a 
 * chip select of the chip select config type.
 */
typedef enum 
{
    SPI_SS_HANDLE_0                     = 0x00,
    SPI_SS_HANDLE_1                           ,
    SPI_SS_HANDLE_2                           ,
    SPI_SS_HANDLE_3                           ,
    SPI_SS_HANDLE_4                           ,
    SPI_SS_HANDLE_5                           ,
    SPI_SS_HANDLE_6                           ,
    SPI_SS_HANDLE_7                           ,
    SPI_SS_HANDLE_8                           ,
    SPI_SS_HANDLE_9                           
   
}SPI_SelectSlaveHandle_t;

/**
 * @brief Chip Select Type
 *
 * Configuration for a chip select
 */
typedef struct  
{
    volatile uint8_t *port;
    uint8_t pin;
    
}SPI_ChipSelect_t;

/**
 * @brief Chip Select Config Type
 *
 * Configuration type for all available chip selects
 */
typedef struct  
{
    SPI_ChipSelect_t *chipSelect;
    uint8_t numberOfChipSelect;

}SPI_ChipSelectConfig_t;

/**
 * @brief SPI Return Type
 *
 * Standard return type of the SPI.
 * The following return types are defined: 
 */
typedef uint8_t SPI_Return_t;

/*--- SPI Return Types Definition ---------------------------------------------------------------*/

/**
 * @brief SPI No Data
 * 
 * Return type which indicates that no data is available
 */
#define SPI_NO_DATA                                             0x00
/**
 * @brief SPI Data Ok
 *
 * Return type which indicates that data is available
 */
#define SPI_DATA_OK                                             0x01
/**
 *
 */
#define SPI_NO_DATA_REQUEST                                     0x02

/*--- SPI Configuration Settings ----------------------------------------------------------------*/

/**
 *  @brief SPI Interrupt usage Configuration
 *
 * FALSE [0]: Don't use Interrupts
 * TRUE  [1]: Use Interrupts
 */
#define SPI_USE_INTERRUPTS_CFG                                      FALSE

 /**
 *  @brief SPI Enable
 * 
 * Specifies whether the SPI is enabled or not
 * @see SPI_Enable_t
 *
 * SPI_ENABLE  [1]:  SPI is Enabled
 * SPI_DISABLE [0] : SPI is Disabled
 */
#define SPI_ENABLE_CFG                                              SPI_ENABLE

/**
 * @brief Data Direction Configuration
 *
 * Specifies the Data Direction of the SPI
 * 
 * SPI_MSB_TRANSMIT_FIRST [0]: Transmit MSB First
 * SPI_LSB_TRANSMIT_FIRST [1]: Transmit LSB First
 */
#define SPI_DATA_ORDER_CFG                                          SPI_MSB_TRANSMIT_FIRST

/**
 *  @brief Frequency Configuration
 *
 * ----- Value ----------------- SPI2X|SPR1|SPR0| SCK Frequency
 * SPI_FREQUENCE_FAC_4    		   0  | 0  | 0  | F_CPU/4
 * SPI_FREQUENCE_FAC_16   		   0  | 0  | 1  | F_CPU/16
 * SPI_FREQUENCE_FAC_64   		   0  | 1  | 0  | F_CPU/64
 * SPI_FREQUENCE_FAC_128  		   0  | 1  | 1  | F_CPU/128
 * SPI_FREQUENCE_FAC_2    		   1  | 0  | 0  | F_CPU/2
 * SPI_FREQUENCE_FAC_8    		   1  | 0  | 1  | F_CPU/8
 * SPI_FREQUENCE_FAC_32		       1  | 1  | 0  | F_CPU/32
 *      -----                      1  | 1  | 1  | F_CPU/64		//Twice available, therefore not used
 */
#define SPI_FREQUENCE_CFG                                         SPI_FREQUENCE_FAC_4


/**
 * @brief Clock Configuration
 *
 *
 * SPI_SCK_IDLE_LOW_LEADING_EDGE:       SCK is LOW in IDLE, Transmit start at LEADING EDGE --> Leading Switch LOW - HIGH
 * SPI_SCK_IDLE_HIGH_LEADING_EDGE:      SCK is HIGH in IDLE, Transmit start at LEADING EDGE --> Leading Switch HIGH -LOW 
 * SPI_SCK_IDLE_LOW_TRAILING_EDGE:      SCK is LOW in IDLE, Transmit start at Trailing EDGE --> Leading Switch HIGH - LOW
 * SPI_SCK_IDLE_HIGH_TRALING_EDGE:      SCK is HIGH in IDLE, Transmit start at LEADING EDGE --> Leading Switch LOW -HIGH
 */
#define SPI_SCK_SETTING_CFG                                     SPI_SCK_IDLE_LOW_LEADING_EDGE

/**
 * @brief Mode Configuration 
 * 
 * SPI_SLAVE_MODE [0]:    Use SPI as Slave
 * SPI_MASTER_MODE [1]    Use SPI as Master
 *
 */
#define SPI_MODE_CFG                                            SPI_MASTER_MODE

/**
 * @brief Chip Select Configuration
 *
 * This define allows to configure one or more chip select/select slave ports.
 * The current configuration is the default configuration for the standard 
 * chip select pin. 
 *
 * HINT: If this SPI will be used as Slave, this configuration will not be used
 */                                                             /*---- PORT --|--- PIN ---------*/
#define SPI_CHIP_SELECT_CFG                                     {                               \
                                                                    {&SPI_PORT,SPI_SS_PIN},     \
                                                                }                               \

/**
 * @brief Number of Chip Selects
 */
#define SPI_NUMBER_OF_CHIP_SELECT_CFG                                       1u

/**
 * @brief SPI Receive Tx Character
 *
 * Char which will be used to receive a data byte.
 * To receive a byte, a default byte has to be transmitted
 * over the SPI. This define specifies the char which will be 
 * transmitted
 */
#define SPI_RECEIVE_TX_CHARACTER_CFG                                        0xFFu


#if (SPI_USE_INTERRUPTS_CFG == TRUE) 

/**
 * @brief Rx Fifo Buffer Size
 */
#define SPI_RX_FIFO_SIZE                                                    20u
/**
 * @brief Tx Fifo Buffer Size
 */
#define SPI_TX_FIFO_SIZE                                                    20u

#endif

/*--- Function Prototypes of the SPI Module -----------------------------------------------------*/


/**
 *  @brief Brief
 *  
 *  @return Return_Description
 *  
 *  @details Details
 */
void SPI_Init(void);
/**
 *  @brief Brief
 *  
 *  @param [in] setting Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void SPI_SetSckSettings(SPI_SckSettings_t setting);
/**
 *  @brief Brief
 *  
 *  @param [in] order Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void SPI_SetDataOrder(SPI_DataOrder_t order);
/**
 *  @brief Brief
 *  
 *  @param [in] factor Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
void SPI_SetFrequenceFactor(SPI_FrequenceFactor_t factor);
/**
 *  @brief Set Status
 *  
 *  @param [in] status Parameter to enable or disable the SPI
 *  @return Return_Description
 *  
 *  @details Details
 */
void SPI_Status(SPI_Enable_t status);
/**
 *  @brief Setup Chip Select
 *  
 *  @param [in] None
 *  @return None
 *  
 *  @details This function setups the configured chip select. 
 *  To configure the chip selects, 
 *          @see SPI_CHIP_SELECT_CFG 
 *          @see SPI_NUMBER_OF_CHIP_SELECT_CFG
 *
 * Normally only one SS was configured. If more SS are needed add
 * some Port and Pins. Don't forget the number of chip selects.
 */
void SPI_SetupChipSelect(SPI_Mode_t mode);
/**
 *  @brief Set SPI Mode
 *  
 *  @param [in] mode: which the SPI shall have
 *  
 *  @return None
 *  
 *  @details Function to set the mode of the SPI.
 *           Use the following parameter:
 *                SPI_SLAVE_MODE: Use SPI as Slave
 *                SPI_MASTER_MODE: Use SPI as Master
 */
void SPI_SetSpiMode(SPI_Mode_t mode);


void SPI_SetupSpiPort(SPI_Mode_t mode);

/*--- SPI Master Function -----------------------------------------------------------------------*/

/**
 *  @brief Select Slave (Master)
 *  
 *  @param [in] handle: Slave which shall be used. Defined over enumerate SPI_SelectSlaveHandle_t
 *  @param [in] status: Status to set or release the slave.
 *
 *  @return None
 *  
 *  @details Function to set or release a slave. 
 *           Use the following parameter: 
 *                 SPI_SET_SLAVE:      Set this slave as used Slave
 *                 SPI_RELEASE_SLAVE:  Release this slave.
 *  This function depends on the chip select configuration.
 */
void SPI_MasterSelectSlave(SPI_SelectSlaveHandle_t handle, uint8_t status);

void SPI_MasterTransmitChar(uint8_t p);

void SPI_MasterTransmitData(uint8_t *data);

uint8_t SPI_MasterReceiveChar(void);

SPI_Return_t SPI_MasterReceiveData(uint8_t *buffer, uint8_t size);

/*--- SPI Slave Function ------------------------------------------------------------------------*/

SPI_Return_t SPI_SlaveTransmitChar(uint8_t p);

void SPI_SlaveTransmitData(uint8_t *data);

SPI_Return_t SPI_SlaveReceiveData(uint8_t *buffer, uint8_t size);


#endif /* SPI_H_ */