/*
 * SPI.c
 *
 * Created: 19.04.2016 20:37:28
 *  Author: AP02
 */ 

#include "SPI.h"
#include "avr/interrupt.h"

/*--- Internal Defines --------------------------------------------------------------------------*/

#define SPI_DDR_OFFSET                              (1u)


#define SPI_PIN_OFFSET                              (2u)

/*--- Internal Function Prototypes --------------------------------------------------------------*/

static void SPI_SetupChipSelectMaster(void);

static void SPI_SetupChipSelectSlave(void);

#if (SPI_USE_INTERRUPTS_CFG == TRUE) 

/*--- Interrupt depended Parameter --------------------------------------------------------------*/
#include "FIFO.h"

/**
 * @brief
 */
uint8_t SPI_txBuffer[SPI_TX_FIFO_SIZE];
/**
 * @brief
 */
uint8_t SPI_rxBuffer[SPI_RX_FIFO_SIZE];
/**
 * @brief
 */
FIFO_Buffer_t SPI_txFifo = 
    {
        .bufferPtr  = SPI_txBuffer;
        .bufferSize = SPI_TX_FIFO_SIZE;
        .status  = FIFO_BUFFER_EMPTY;
        .counter = {
                        .overflow = FALSE;
                        .read     = 0u;
                        .write    = 0u;
                   }         
    };
/**
 * @brief
 */
FIFO_Buffer_t SPI_rxFifo =
    {
        .bufferPtr  = SPI_rxBuffer;
        .bufferSize = SPI_RX_FIFO_SIZE;
        .status  = FIFO_BUFFER_EMPTY;
        .counter = {
                        .overflow = FALSE;
                        .read     = 0u;
                        .write    = 0u;
                   }
    };

/*--- Interrupt Callback Functions --------------------------------------------------------------*/
/**
 * @brief SPI Transfer Complete Callback
 *
 */
void SPI_TransferCompleteCallback(void);


/************************************************************************
 * ISR(SPI_INTERRUPT_VECTOR)
 ************************************************************************/
ISR(SPI_INTERRUPT_VECTOR)
{
    SPI_TransferCompleteCallback();
}

/************************************************************************
 * void SPI_TransferCompleteCallback(...)
 ************************************************************************/
void SPI_TransferCompleteCallback(void)
{
    
    /* ------------------------- Tbd ----------------------------------------*/
    /* --- Currently not implemented because Transmit and Receive will be 
       --- done cycle. If needed activate Interrupts and add  FIFO - Buffer 
       --- for Transmit. Read Sequence has also be done here. 
       ---                                                                   */
}

#endif

/*--- Internal Used Parameter -------------------------------------------------------------------*/

/**
 * @brief Chip Select Port/Pin Configuration
 *
 */
static SPI_ChipSelect_t SPI_chipSelects[SPI_NUMBER_OF_CHIP_SELECT_CFG] =  SPI_CHIP_SELECT_CFG;

/**
 * @brief Chip Select Configuration
 *
 */
static SPI_ChipSelectConfig_t SPI_chipSelectConfig = 
        {
            SPI_chipSelects,
            SPI_NUMBER_OF_CHIP_SELECT_CFG,
        };



/*--- Local Functions ---------------------------------------------------------------------------*/

static void SPI_SetupChipSelectMaster(void)
{
    uint8_t i,pin,size;
    volatile uint8_t *ddr, *port;
    
    size = SPI_chipSelectConfig.numberOfChipSelect;
    for(i = 0; i < size; i++)
    {
        port = SPI_chipSelectConfig.chipSelect[i].port;
        pin  = SPI_chipSelectConfig.chipSelect[i].pin;
        ddr  = &GET_DDR_REGISTER_BY_PORT(port);
        SET_REGISTER_BIT(*ddr,pin);
        SET_REGISTER_BIT(*port,pin);
    }
    return;
}

static void SPI_SetupChipSelectSlave(void)
{
    volatile uint8_t* ddrSpi;
    ddrSpi = &GET_DDR_REGISTER_BY_PORT(SPI_PORT);
    RESET_REGISTER_BIT(*ddrSpi,SPI_SS_PIN);
    
    return;
}


/*--- Global Functions --------------------------------------------------------------------------*/

/**************************************************************************************************
 * void SPI_Init
 *************************************************************************************************/
void SPI_Init(void)
{
    SPI_SetDataOrder(SPI_DATA_ORDER_CFG);
    SPI_SetSckSettings(SPI_SCK_SETTING_CFG);
    SPI_SetFrequenceFactor(SPI_FREQUENCE_CFG);
    SPI_SetSpiMode(SPI_MODE_CFG);
    
    if(SPI_MODE_CFG == SPI_MASTER_MODE)
    {
        SPI_SetupChipSelect(SPI_MASTER_MODE);
        SPI_SetupSpiPort(SPI_MASTER_MODE);
    }    
    else
    {
        SPI_SetupChipSelect(SPI_SLAVE_MODE);
        SPI_SetupSpiPort(SPI_SLAVE_MODE);
    }
    return;
}

/**************************************************************************************************
 * void SPI_SetSckSettings
 *************************************************************************************************/
void SPI_SetSckSettings(SPI_SckSettings_t setting)
{
     switch(setting)
     {
         
         case SPI_SCK_IDLE_LOW_LEADING_EDGE:
         /*--- CPOL = 0 And CPHA = 0 -----------------------------*/
         break;
         case SPI_SCK_IDLE_HIGH_LEADING_EDGE:
         /*--- CPOL = 1 And CPHA = 0 -----------------------------*/
         SET_REGISTER_BIT(SPI_CONTROL_REGISTER,CPOL);
         break;
         case SPI_SCK_IDLE_LOW_TRAILING_EDGE:
         /*--- CPOL = 0 And CPHA = 1 -----------------------------*/
         SET_REGISTER_BIT(SPI_CONTROL_REGISTER,CPHA);
         break;
         case SPI_SCK_IDLE_HIGH_TRALING_EDGE:
         /*--- CPOL = 1 And CPHA = 1 -----------------------------*/
         SET_REGISTER_BIT(SPI_CONTROL_REGISTER,CPOL);
         SET_REGISTER_BIT(SPI_CONTROL_REGISTER,CPHA);
         break;
         default:
         
         break;
     }
     return;
}

/**************************************************************************************************
 * void SPI_SetDataOrder
 *************************************************************************************************/
void SPI_SetDataOrder(SPI_DataOrder_t order)
{
     if(SPI_DATA_ORDER_CFG == SPI_LSB_TRANSMIT_FIRST)
     {
        SET_REGISTER_BIT(SPI_CONTROL_REGISTER,DORD);
     }
     else
     {
        RESET_REGISTER_BIT(SPI_CONTROL_REGISTER,DORD); 
     }
     return;    
}

/**************************************************************************************************
 * void SPI_SetFrequenzFactor
 *************************************************************************************************/
void SPI_SetFrequenceFactor(SPI_FrequenceFactor_t factor)
{
    switch(factor)
    {
        case SPI_FREQUENCE_FAC_4:
            /*--- Do Nothing - Default: SPI2X=0 SPR1=0 SPR0=0 ---*/
        break;
        case SPI_FREQUENCE_FAC_16:
            /*--- SPI2X=0 SPR1=0 SPR0=1 -------------------------*/
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR0);
        break;
        case SPI_FREQUENCE_FAC_64:
            /*--- SPI2X=0 SPR1=1 SPR0=0 -------------------------*/
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR1);
        break;
        case SPI_FREQUENCE_FAC_128:
            /*--- SPI2X=0 SPR1=1 SPR0=1 -------------------------*/
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR0);
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR1);        
        break;
        case SPI_FREQUENCE_FAC_2:
            /*--- SPI2X=1 SPR1=0 SPR0=10-------------------------*/
            SET_REGISTER_BIT(SPI_STATUS_REGISTER,SPI2X);
        break;
        case SPI_FREQUENCE_FAC_8:
            /*--- SPI2X=1 SPR1=0 SPR0=1 -------------------------*/
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR0);
            SET_REGISTER_BIT(SPI_STATUS_REGISTER,SPI2X);
        break;
        case SPI_FREQUENCE_FAC_32:
            /*--- SPI2X=1 SPR1=1 SPR0=0 -------------------------*/        
            SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPR1);
            SET_REGISTER_BIT(SPI_STATUS_REGISTER,SPI2X);
        default:
        break;
    }
    return;
}

/**************************************************************************************************
 * void SPI_Status
 *************************************************************************************************/
void SPI_Status(SPI_Enable_t status)
{
    if(status == SPI_ENABLE)
    {
        SET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPIE);
    }
    else
    {
        RESET_REGISTER_BIT(SPI_CONTROL_REGISTER,SPIE);
    }
    return;
}

/**************************************************************************************************
 * void SPI_SetupChipSelect
 *************************************************************************************************/
void SPI_SetupChipSelect(SPI_Mode_t mode)
{
    if (mode == SPI_MASTER_MODE)
    {
        SPI_SetupChipSelectMaster();
    }
    else 
    {
       SPI_SetupChipSelectSlave();
    }
    return;
}

/**************************************************************************************************
 * void SPI_SetSpiMode(...)
 *************************************************************************************************/
void SPI_SetSpiMode(SPI_Mode_t mode)
{
    if(mode == SPI_MASTER_MODE)
    {
        SET_REGISTER_BIT(SPI_CONTROL_REGISTER,MSTR);
    }
    else
    {
        RESET_REGISTER_BIT(SPI_CONTROL_REGISTER,MSTR);    
    }    
    return;
}


/*=== SPI Master API ============================================================================*/
/**************************************************************************************************
 * void SPI_MasterSelectSlave(...)
 *************************************************************************************************/
void SPI_MasterSelectSlave(SPI_SelectSlaveHandle_t handle, uint8_t status)
{
    uint8_t pin;
    volatile uint8_t *port;
    
    if(handle < SPI_chipSelectConfig.numberOfChipSelect)
    {
        pin  = SPI_chipSelectConfig.chipSelect[(uint8_t)handle].pin;
        port = SPI_chipSelectConfig.chipSelect[(uint8_t)handle].port;
        
        if(status == SPI_SET_SLAVE)
        {
            /*Set Slave by set pin to LOW (Active LOW)*/
            RESET_REGISTER_BIT(*port,pin);
        }
        else 
        {
            /*Release Slave by set pin HIGH (Active LOW)*/
            SET_REGISTER_BIT(*port,pin);
        }        
    }
    return;
}

/**************************************************************************************************
 * void SPI_SetupSpiPort(...)
 *************************************************************************************************/
void SPI_SetupSpiPort(SPI_Mode_t mode)
{
    volatile uint8_t *spiDDR;    
    
    spiDDR = &GET_DDR_REGISTER_BY_PORT(SPI_PORT);
    if(mode == SPI_MASTER_MODE)
    {
        SET_REGISTER_BIT(*spiDDR,SPI_MOSI_PIN);
        SET_REGISTER_BIT(*spiDDR,SPI_SCK_PIN);
    }
    else 
    {
       SET_REGISTER_BIT(*spiDDR,SPI_MISO_PIN); 
    }    
    return;
} 


/**************************************************************************************************
 * void SPI_MasterTransmitChar(...)
 *************************************************************************************************/
void SPI_MasterTransmitChar(uint8_t p)
{
    /* Start transmission */
    SPI_TX_DATA_REGISTER = p;
    /* Wait for transmission complete */
    while (!GET_REGISTER_BIT(SPI_STATUS_REGISTER,SPIF))
    ;
    return;
}
/**************************************************************************************************
 * void SPI_MasterTransmitData(...)
 *************************************************************************************************/
void SPI_MasterTransmitData(uint8_t *data)
{
    while (*data)
    {
        SPI_MasterTransmitChar(*data);
        data++;
    }
    return;
}   
/**************************************************************************************************
 * void SPI_MasterReceiveChar(...)
 *************************************************************************************************/
uint8_t SPI_MasterReceiveChar(void)
{
     /* Start transmission */
     SPI_TX_DATA_REGISTER = SPI_RECEIVE_TX_CHARACTER_CFG;
     /* Wait for transmission complete */
      while (!GET_REGISTER_BIT(SPI_STATUS_REGISTER,SPIF))
     ;
     return SPI_RX_DATA_REGISTER;
}
/**************************************************************************************************
 * void SPI_MasterReceiveData(...)
 *************************************************************************************************/
SPI_Return_t SPI_MasterReceiveData(uint8_t *buffer, uint8_t size)
{
    SPI_Return_t ret = SPI_NO_DATA; 
    uint8_t i; 
    for (i = 0; i < size; i++)
    {
        buffer[i] = SPI_MasterReceiveChar();
        if(buffer[i] == SPI_RECEIVE_TX_CHARACTER_CFG)
        {
            ret = SPI_DATA_OK;
        }
    }
    return ret;
}

/**************************************************************************************************
 * SPI_Return_t SPI_SlaveTransmitChar(...)
 *************************************************************************************************/
SPI_Return_t SPI_SlaveTransmitChar(uint8_t p)
{
     volatile uint8_t *spiPIN;
     SPI_Return_t ret = SPI_NO_DATA_REQUEST;
     spiPIN = &GET_PIN_REGISTER_BY_PORT(SPI_PORT);
     
     if(GET_REGISTER_BIT(*spiPIN,SPI_SS_PIN))
     {
         ret = SPI_DATA_OK;
         /* Start transmission */
         SPI_TX_DATA_REGISTER = p;
         /* Wait for transmission complete */
         while (!GET_REGISTER_BIT(SPI_STATUS_REGISTER,SPIF))
         ;
     }
     return ret;
}

/**************************************************************************************************
 * void SPI_SlaveTransmitData(...)
 *************************************************************************************************/
void SPI_SlaveTransmitData(uint8_t *data)
{
    SPI_Return_t txRet;
    /*Run through the whole data array. As long as the data pointer is not NULL, this loop will
      be executed.*/
    while(*data)
    {
        /*Try to transmit a data byte*/
        txRet = SPI_SlaveTransmitChar(*data);
        /*Check the return value whether transmit was successful or no data request available*/
        if(txRet == SPI_DATA_OK)
        {
            /*In case of data transmit available, stay in while loop and increment data pointer to 
              transmit the next data byte*/
            data++;   
        }
        else 
        {
            /*This is needed to avoid a endless loop. If no data request available, exit while loop
              without any changes. On enter this function again, the same transmit will be started 
              again.*/
            break;
        }
    }
    return;
}


uint8_t SPI_SlaveReceiveChar(void)
{
    volatile uint8_t *spiPIN;
    uint8_t p;

    spiPIN = &GET_PIN_REGISTER_BY_PORT(SPI_PORT);
    
    if(GET_REGISTER_BIT(*spiPIN,SPI_SS_PIN))
    {
        /* Start transmission */
        p = SPI_TX_DATA_REGISTER;
        /* Wait for transmission complete */
        while (!GET_REGISTER_BIT(SPI_STATUS_REGISTER,SPIF))
        ;
    } 
    return p;
}

/**************************************************************************************************
 * void SPI_SlaveReceiveData(...)
 *************************************************************************************************/
SPI_Return_t SPI_SlaveReceiveData(uint8_t *buffer, uint8_t size)
{
     SPI_Return_t ret = SPI_DATA_OK;
     uint8_t i;
    
    for(i = 0; i < size; i++)
    {
        /*Try to transmit a data byte*/
        buffer[i] = SPI_SlaveReceiveChar();
        /*Check the return value whether transmit was successful or no data request available*/
        if(buffer[i] != SPI_RECEIVE_TX_CHARACTER_CFG && i == 0)
        { 
            /*This is needed to avoid a lont loop. If no data request available, exit while loop
              without any changes. On enter this function again, the same transmit will be started 
              again.*/
            ret = SPI_NO_DATA;
            break;
        }
        else
        {
            /*--- Do Nothing ---*/
        }
    }   
    return ret;   
}

