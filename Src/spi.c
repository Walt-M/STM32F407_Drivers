#include "spi.h"

void SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Config){
    SPIx->CR1 &= (0x0000);

    SPIx->CR1 |= SPI_ENABLE;
    SPIx->CR1 |= SPI_Config->Mode;
    SPIx->CR1 |= SPI_Config->CommunicationType;
    SPIx->CR1 |= SPI_Config->DataFrame;
    SPIx->CR1 |= SPI_Config->SSM;
    SPIx->CR1 |= SPI_Config->SigBitFrame;
    SPIx->CR1 |= SPI_Config->BaudRate;
    SPIx->CR1 |= SPI_Config->ClockPolarity;
    SPIx->CR1 |= SPI_Config->ClockPhase;
}

void SPI_DeInit(SPI_TypeDef *SPIx){
    SPIx->CR1 &= (0x0000);
}

void SPI_Transmit(SPI_TypeDef *SPIx, uint16_t *Data, uint32_t Size){
    while (Size != 0)
    { 
        if (SPIx->CR1 & SPI_DATAFRAME == SPI_DATAFRAME_16BIT)
        {
            /*TODO: Write code here if it is 16 bits*/
        }
        else
        {
            /*TODO: Write code here if it is 8 bits.*/
        }       
    }
}



void SPI_Receive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size){

}