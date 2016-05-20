/*
 * USART.h
 *
 * Created: 22.02.2016 18:42:48
 *  Author: AP
 */ 


#ifndef USART_H_
#define USART_H_

#include "PR_DEF.h"
#include <avr/io.h>


/*=== FIFO BUFFER SIZE ==========================================================================*/

/**
 *  @brief TX FiFo Buffer Size configuration
 */ 
#define USART_TX_BUFFER_SIZE                                    50u
/**
 *  @brief RX FiFo Buffer Size configuration
 */ 
#define USART_RX_BUFFER_SIZE                                    50u

/*=== BAUD RATE CALCULATION =====================================================================*/

#define USART_BAUDRATE_2400                                     2400UL
#define USART_BAUDRATE_4800                                     4800UL
#define USART_BAUDRATE_9600                                     9600UL
#define USART_BAUDRATE_14400                                    14400UL
#define USART_BAUDRATE_19200                                    19200UL
#define USART_BAUDRATE_28800                                    28800UL
#define USART_BAUDRATE_38400                                    38400UL
#define USART_BAUDRATE_57600                                    57600UL
#define USART_BAUDRATE_76800                                    76800UL
#define USART_BAUDRATE_115200                                   115200UL
#define USART_BAUDRATE_230400                                   230400UL
#define USART_BAUDRATE_250000                                   250000UL
#define USART_BAUDRATE_500000                                   500000UL
#define USART_BAUDRATE_1000000                                  1000000UL

/**
 * @brief Set Baudrate
 *
 * This define allows to calculate the value for the Baudrate Register automatically
 * Use define USART_BAUDRATE as config parameter
 */
#define USART_BAUD_CONFIG                                   USART_BAUDRATE_4800      

/**
 * @brief Calculated Baudrate
 *
 * This is the calculated value which should be used as UBRR value. 
 */
#define USART_BAUDRATE				\
	((F_CPU + USART_BAUD_CONFIG * 8UL)/( USART_BAUD_CONFIG *16UL) -1)

/** 
 * @brief Real Baudrate
 * 
 * This define shows the "real" baudrate. The define "USART_BAUDRATE" is a rounded value
 * This is the real baudrate. The deviation between the Real and Calculated Baudrate shouldn't
 * be more than 1%
 */
#define BAUD_REAL					\
		(F_CPU / (16UL *(USART_BAUDRATE + 1UL)))     
/**
 * @brief Deviation of Baudrate
 */
#define BAUD_ERROR					\
		((BAUD_REAL * 1000UL) / USART_BAUD_CONFIG) 
/*=== Interrupt User Configuration ==============================================================*/


/**
 *  @brief Use Interrupt Config Flag
 *
 *  With this flag, the USART interrupts can be enabled or disabled
 *  Possible Values:        
 *  ------------------
 *      TRUE  [1]  = Interrupts Enabled
 *      FALSE [0]  = INTERRUPTS DISABLED 
 */ 
 #define USART_USE_INTERRUPT                                TRUE
 
 /** 
  * @brief Data Delimiter
  *
  * Delimiter which will added each transmitted string. 
  * @see USART_ADD_DATA_DELIMITER for activation/deactivation of the delimiter
  */
 #define USART_DATA_DELIMITER                               "\r\n"
 
 /**
  * @brief Activate Delimiter
  *
  * This define allows to active or deactivate the Data Delimiter. 
  * Possible Values: 
  *         TRUE  [1]:  Activated - Delimiter will be add at the end of the transmitted string
  *         FALSE [0]:  Deactivated - Delimiter will not be added.
  */
 #define USART_ADD_DATA_DELIMITER                           TRUE
 
 /*=== USART Register Configuration =============================================================*/

/**
 *  @brief Set HW Rx Register
 */
#define USART_HW_RX_BUFFER                                  UDR

/**
 *  @brief Set HW Tx Register
 */
#define USART_HW_TX_BUFFER                                  UDR

/**
 *  @brief Set Status A Register
 */
#define USART_STATUS_A_REG                                  UCSRA
/**
 *  @brief Set Status B Register
 */
#define USART_STATUS_B_REG                                  UCSRB
/**
 *  @brief Set Status C Register
 */
#define USART_STATUS_C_REG                                  UCSRC
/**
 * @brief Set UBRR Low Register
 */
#define USART_BAUDRATE_LOW_REG                              UBRRL
/**
 * @brief Set UBRR High Register
 */
#define USART_BAUDRATE_HIGH_REG                             UBRRH
/**
 * @brief Use Volatile pragma when Interrupts will be used
 */
#if (USART_USE_INTERRUPT == TRUE)
    #define USART_VOLATILE volatile
#else
    #define USART_VOLATILE
#endif
/*=== USART Defines =============================================================================*/

/**
 * @brief Set Inline Macro to improve code optimization
 */
#define USART_INLINE

#define USART_SET_STATUS_C_REGISTER(bit)                                \
        (USART_STATUS_C_REG |= (1 << URSEL) | (1 << bit))
        

#define USART_SET_TWO_STATUS_C_REGISTER(bit1, bit2)                                \
        (USART_STATUS_C_REG |= (1 << URSEL) | (1 << bit1) | (1 << bit2))        
        
#define USART_RESET_STATUS_C_REGISTER(bit)                              \
        (USART_STATUS_C_REG = (USART_STATUS_C_REG | (1 << URSEL)) & ~(1 << bit))
        
/*=== USART Data Types Definiton ================================================================*/

/**
 * @brief 
 */
typedef enum
{
    USART_DISABLE       = 0x00,
    USART_ENABLE        = 0x01,
     
}USART_Enable_t;

/**
 * @brief 
 */
typedef enum 
{
    USART_PARITY_DISABLED        = 0x00,
    USART_EVEN_PARITY            = 0x02,
    USART_ODD_PARITY             = 0x03,   
    
}USART_ParityMode_t;

/**
 * @brief 
 */
typedef enum 
{
    USART_USE_SYNCHRONOUS_MODE                  = 0x00,
    USART_USE_ASYNCHRONOUS_MODE                 = 0x01,
    USART_USE_ASYNCHRONOUS_MODE_W_DOUBLE_SPEED  = 0x00,
}USART_TransmitionMode_t;

/**
 * @brief 
 */
typedef enum 
{
    USART_USE_1_STOP_BIT = 0x00,
    USART_USE_2_STOP_BIT = 0x01
}USART_StopBit_t;

/**
 * @brief 
 */
typedef enum 
{
    USART_5_BIT_DATA_SIZE     = 0x00,
    USART_6_BIT_DATA_SIZE     = 0x01,
    USART_7_BIT_DATA_SIZE     = 0x02,
    USART_8_BIT_DATA_SIZE     = 0x03,
    USART_9_BIT_DATA_SIZE     = 0x07,
}USART_DataSize_t;

/**
 * @brief 
 */
typedef uint16_t USART_Baudrate_t;

/**
 * @brief 
 */
typedef struct
{
    USART_Enable_t          rxEnableConfig;
    USART_Enable_t          txEnableConfig;
    USART_ParityMode_t      parityConfig;
    USART_StopBit_t         stopBitConfig;
    USART_DataSize_t        dataSizeConfig;
    USART_TransmitionMode_t transmitionConfig;
	USART_Baudrate_t		ubrrValueConfig;
}USART_Config_t;


/**
 *  @brief Brief
 *  
 *  @param [in] config Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_Init(const USART_Config_t* config);
/**
 *  @brief Brief
 *  
 *  @param [in] rx Parameter_Description
 *  @param [in] tx Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_SetEnableStatus(USART_Enable_t rx, USART_Enable_t tx );
/**
 *  @brief Brief
 *  
 *  @param [in] parity Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_SetParityMode(USART_ParityMode_t parity);
/**
 *  @brief Brief
 *  
 *  @param [in] stopBit Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_SetStopBit(USART_StopBit_t stopBit);
/**
 *  @brief Brief
 *  
 *  @param [in] size Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_SetDatasize(USART_DataSize_t size);
/**
 *  @brief Brief
 *  
 *  @param [in] baud Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_SetBaudrate(uint16_t baud);
/**
 *  @brief Brief
 *  
 *  @param [in] c Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_TransmitChar(char c);
/**
 *  @brief Brief
 *  
 *  @param [in] str Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_TransmitString(char *str);
/**
 *  @brief Brief
 *  
 *  @param [in] str Parameter_Description
 *  @param [in] size Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_TransmitData(uint8_t* data, uint8_t size);
/**
 *  @brief Brief
 *  
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE char USART_ReceiveChar(void);
/**
 *  @brief Brief
 *  
 *  @param [in] str Parameter_Description
 *  @param [in] size Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_ReceiveString(char *str, uint8_t size);

/**
 *  @brief Brief
 *  
 *  @param [in] str Parameter_Description
 *  @param [in] size Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE void USART_ReceiveData(uint8_t* str, uint8_t size);

/**
 *  @brief Brief
 *  
 *  @return Return_Description
 *  
 *  @details Details
 */
USART_INLINE  boolean USART_IsDataAvailable(void);


/*=== Error Output By Wrong Config ==============================================================*/

/**
 * @brief Baudrate Error System Message
 * 
 * If the used Baudrate has a higher deviation than 1% then this message will be shown.
 */
#if ((BAUD_ERROR < 990UL) || (BAUD_ERROR > 1010UL))
    #error Systematischer Fehler der Baudrate groesser 1% und damit zu hoch!
#endif

/**
 * @brief F_CPU error message
 *
 * This error message will be shown in case of no definition 
 * of F_CPU. F_CPU is required for the Baudrate calculation
 */
#ifndef F_CPU
	#error F_CPU NOT DEFINED. CAN NOT CALCULATE BAUDRATE
#endif

#endif /* USART_H_ */