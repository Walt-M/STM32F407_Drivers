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
    uint32_t Mode;                      /*Two line mode has uni-directional pins,
                                          One line mode has bi-directional pins.*/
                                          
    uint32_t CRCEnable;                 /*Enable CRC Calculation. Todo: Figure out what this register does.*/ 

    uint32_t DataFrame;                 /*Select the transmit and receive data size. 8 bits or 16.*/

    uint32_t SoftwareSlaveManagement;   /*Controls software slave management*/

    uint32_t SigBitFrame;               /*Chooses if the LSB or the MSB is sent first*/

    uint32_t SPIEnable;                 /*Enable or disable SPI peripheral.*/

    uint32_t BaudRate;                  /*Changes the clock divisor. lowest divisor is 2*/

    uint32_t MasterSelect;              /*Configure device as a master or slave*/

    uint32_t ClockPolarity;             /*Set clock as defualt high or low when clock is off*/

    uint32_t ClockPhase;                /*Contros if the data capture edge is first or second.*/

}SPI_Config;

#define SPI_Mode_2Line = (0U)
#define SPI_Mode_2Line_RxOnly = (1 << 10)
#define SPI_Mode_1Line_Rx = (1 << 15)
#define SPI_Mode_1Line_Tx = (3 << 14)

#define SPI_CRC_Di = 0U
#define SPI_CRC_En = (1 << 13)

#define SPI_CRCNext_Data = (0U)
#define SPI_CRCNext_CRC = (1 << 12)

#define SPI_DataFrame_8bit = (0U)
#define SPI_DataFrame_16bit = (1 << 11)

#define SPI_SSM_Di = (0U)
#define SPI_SSM_En = (3 << 9)

#define SPI_SigFigFrame_MSB = (0U)
#define SPI_SigFigFrame_LSB = (1 << 7)

#define SPI_Di = (0U)
#define SPI_En = (1 << 6)

#define SPI_BaudRate_2 = (0U)
#define SPI_BaudRate_4 = (1 << 3)
#define SPI_BaudRate_8 = (2 << 3)
#define SPI_BaudRate_16 = (3 << 3)
#define SPI_BaudRate_32 = (4 << 3)
#define SPI_BaudRate_64 = (5 << 3)
#define SPI_BaudRate_128 = (6 << 3)
#define SPI_BaudRate_256 = (7 << 3)

#define SPI_MasterSelect_Di = (0U)
#define SPI_MasterSelect_En = (1 << 2)

#define SPI_ClockPolarity_Lo = (0U)
#define SPI_ClockPolarity_Hi = (1 << 1)

#define SPI_ClockPhase_1Edge = (0U)
#define SPI_ClockPhase_2Edge = (1)

void SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Config);
void SPI_DeInit(SPI_TypeDef *SPIx);

void SPI_Transmit(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size);
void SPI_Receive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size);