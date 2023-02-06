#include "spi.h"

void SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Config){
    SPIx->CR1 |= SPI_Config->Mode;
    SPIx->CR1 |= SPI_Config->CRCEnable;
    SPIx->CR1 |= SPI_Config->DataFrame;
    SPIx->CR1 |= SPI_Config->SoftwareSlaveManagement;
    SPIx->CR1 |= SPI_Config->SigBitFrame;
    SPIx->CR1 |= SPI_Config->SPIEnable;
    SPIx->CR1 |= SPI_Config->BaudRate;
    SPIx->CR1 |= SPI_Config->MasterSelect;
    SPIx->CR1 |= SPI_Config->ClockPolarity;
    SPIx->CR1 |= SPI_Config->ClockPhase;
}

void SPI_DeInit(SPI_TypeDef *SPIx){
    SPIx->CR1 &= (0U);
}

void SPI_Transmit(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size){

}

void SPI_Receive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size){

}