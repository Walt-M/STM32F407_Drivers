#include "stm32f407xx.h"
#include "gpio.h"


//typedef struct
//{
//  __IO uint32_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
//  __IO uint32_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
//  __IO uint32_t SR;         /*!< SPI status register,                                Address offset: 0x08 */
//  __IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
//  __IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
//  __IO uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
//  __IO uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
//  __IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
//  __IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
//} SPI_TypeDef;

typedef struct
{
    uint32_t Mode;                      /*Selects device as master or slave*/
                                          
    uint32_t CommunicationType;                 /*Enable CRC Calculation. Todo: Figure out what this register does.*/ 

    uint32_t DataFrame;                 /*Select the transmit and receive data size. 8 bits or 16.*/

    uint32_t SSM;   /*Controls software slave management*/

    uint32_t SigBitFrame;               /*Chooses if the LSB or the MSB is sent first*/

    uint32_t BaudRate;                  /*Changes the clock divisor. lowest divisor is 2*/

    uint32_t ClockPolarity;             /*Set clock as defualt high or low when clock is off*/

    uint32_t ClockPhase;                /*Contros if the data capture edge is first or second.*/

}SPI_Config;


/*Defines various modes that the SPI communication protocol
can be set to*/

#define SPI_DISABLE (0U)
#define SPI_ENABLE (1 << 6)

#define SPI_MODE (1 << 2)
#define SPI_MODE_SLAVE (0U)
#define SPI_MODE_MASTER SPI_MODE 

#define SPI_COMMUNICATIONTYPE_FULLDUPLEX (0U)
#define SPI_COMMUNICATIONTYPE_HALFDUPLEX_RX (1 << 15)
#define SPI_COMMUNICATIONTYPE_SIMPLEX (1 << 10)

#define SPI_DATAFRAME (1 << 11)
#define SPI_DATAFRAME_8BIT (0U)
#define SPI_DATAFRAME_16BIT SPI_DATAFRAME

#define SPI_SSM_DISABLE (0U)
#define SPI_SSM_SOFT_ENABLE (1 << 9)
#define SPI_SSM_ENABLE (3 << 8)

#define SPI_SIGFIGFRAME_MSB (0U)
#define SPI_SIGFIGFRAME_LSB (1 << 7)

#define SPI_BAUDRATE_2 (0U)
#define SPI_BAUDRATE_4 (1 << 3)
#define SPI_BAUDRATE_8 (2 << 3)
#define SPI_BAUDRATE_16 (3 << 3)
#define SPI_BAUDRATE_32 (4 << 3)
#define SPI_BAUDRATE_64 (5 << 3)
#define SPI_BAUDRATE_128 (6 << 3)
#define SPI_BAUDRATE_256 (7 << 3)

#define SPI_CLOCKPOLARITY_Lo (0U)
#define SPI_CLOCKPOLARITY_Hi (1 << 1)

#define SPI_CLOCKPHASE_EDGE1 (0U)
#define SPI_CLOCKPHASE_EDGE2 (1)


/*Defines statuses for the various states that the SPI
Communication line can have.*/

#define SPI_STATUS_RX (1 << 0)
#define SPI_STATUS_RX_EMPTY (0U)
#define SPI_STATUS_RX_NOTEMPTY SPI_STATUS_RX

#define SPI_STATUS_TX (1 << 1)
#define SPI_STATUS_TX_EMPTY (0U)
#define SPI_STATUS_TX_NOTEMPTY SPI_STATUS_TX

#define SPI_STATUS_CHANNEL (1 << 2)
#define SPI_STATUS_CHANNEL_LEFT (0U)
#define SPI_STATUS_CHANNEL_RIGHT SPI_STATUS_CHANNEL

#define SPI_STATUS_UNDERRUN (1 << 3)
#define SPI_STATUS_UNDERRUN_NONE (0U)
#define SPI_STATUS_UNDERRUN_OCCURRED SPI_STATUS_UNDERRUN

#define SPI_STATUS_CRC_ERROR (1 << 4)
#define SPI_STATUS_CRC_ERROR_NONE (0U)
#define SPI_STATUS_CRC_ERROR_OCCURRED SPI_STATUS_CRC_ERROR

#define SPI_STATUS_MODE_FAULT (1 << 5)
#define SPI_STATUS_MODE_FAULT_NONE (0U)
#define SPI_STATUS_MODE_FAULT_OCCURRED SPI_STATUS_MODE_FAULT

#define SPI_STATUS_OVERRUN (1 << 6)
#define SPI_STATUS_OVERRUN_NONE (0U)
#define SPI_STATUS_OVERRUN_OCCURRED SPI_STATUS_OVERRUN

#define SPI_STATUS_NOT_BUSY (0U)
#define SPI_STATUS_BUSY (1 << 7)

#define SPI_STATUS_FRAME_ERROR (1 << 8)
#define SPI_STATUS_FRAME_ERROR_NONE (0U)
#define SPI_STATUS_FRAME_ERROR_OCCURRED SPI_STATUS_FRAME_ERROR



void SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Config);
void SPI_DeInit(SPI_TypeDef *SPIx);

void SPI_Transmit(SPI_TypeDef *SPIx, uint16_t *Data, uint32_t Size);
void SPI_Receive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size);