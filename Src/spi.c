#include "spi.h"

void SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Config)
{
    SPIx->CR1 &= (0x0000);

    SPIx->CR1 |= SPI_ENABLE;
    SPIx->CR1 |= SPI_Config->SSM;
    SPIx->CR1 |= SPI_Config->Mode;
    SPIx->CR1 |= SPI_Config->CommunicationType;
    SPIx->CR1 |= SPI_Config->DataFrame;
    SPIx->CR1 |= SPI_Config->SigBitFrame;
    SPIx->CR1 |= SPI_Config->BaudRate;
    SPIx->CR1 |= SPI_Config->ClockPolarity;
    SPIx->CR1 |= SPI_Config->ClockPhase;
}

void SPI_DeInit(SPI_TypeDef *SPIx)
{
    SPIx->CR1 &= (0x0000);
}

void SPI_Transmit(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size)
{
    volatile uint16_t data_temp;

    while (Size > 0)
    { 
        data_temp = 0x0000;

        while ((SPIx->SR & SPI_STATUS_TX) == SPI_STATUS_TX_NOTEMPTY)
        {
            //Do nothing until the TX status register is in empty state
        }

        //Get the data that needs to be sent
        data_temp = *Data;
        Size--;
        Data++;

        //If SPI is set to 16 bit mode, get the second byte to transmit.
        if ((SPIx->CR1 & SPI_DATAFRAME) == SPI_DATAFRAME_16BIT)
        {
            data_temp |= ((uint16_t)*Data << 8);
            Size--;
            Data++;
        }

        //Writting to DR envokes the SPI transmitting protocol.
        SPIx->DR = data_temp;
    }
}



void SPI_Receive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t Size)
{
    uint16_t data_temp;

    while (Size > 0)
    { 
        data_temp = 0x0000;
        while ((SPIx->SR & SPI_STATUS_RX) == SPI_STATUS_RX_NOTEMPTY)
        {
            //Do nothing until the TX status register is in empty state
        }

        //Reading from DR invokes a SPI receive protocol
        data_temp = SPIx->DR;
        
        //Fill first byte with data
        *Data = data_temp;
        Size--;
        Data++;

        //If SPI is set to 16 bit, set the second byte.
        if ((SPIx->CR1 & SPI_DATAFRAME) == SPI_DATAFRAME_16BIT)
        {
            *Data = (data_temp >> 8);
            Size --;
            Data ++;
        }
    }
}