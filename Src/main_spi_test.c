#include "main.h"
#include "stm32f407xx.h"
#include "rcc.h"
#include "spi.h"
#include "gpio.h"
#include <stdlib.h>

int main(void)
{   
    uint8_t test_value = 1;
    GPIO_Config *accel_gpio_setup = malloc(sizeof(GPIO_Config));

    //Parameters in order to setup SPI for accelerometer
    accel_gpio_setup->Mode = GPIO_MODE_ALTERNATE;
    accel_gpio_setup->Type = GPIO_TYPE_PP;
    accel_gpio_setup->Speed = GPIO_SPEED_HIGH;
    accel_gpio_setup->PUPD = GPIO_PUPD_NONE;
    accel_gpio_setup->ALT = GPIO_ALT_AF5;

    __GPIOA_CLK_ENABLE;
    __SPI2_CLK_ENABLE;
    GPIO_Init(BOARD_ACCELEROMETER_PORT, BOARD_ACCELEROMETER_SPI_SCK, accel_gpio_setup);
    GPIO_Init(BOARD_ACCELEROMETER_PORT, BOARD_ACCELEROMETER_SPI_MISO, accel_gpio_setup);
    GPIO_Init(BOARD_ACCELEROMETER_PORT, BOARD_ACCELEROMETER_SPI_MOSI, accel_gpio_setup);

    SPI_Config *accel_spi_setup = malloc(sizeof(SPI_Config));

    /*
    Setup for the SPI communication for accelerometer. Sets MCU as the master,
    full duplex mode, sending and receving 16 bits of data, sends MSB first,
    baurdrate set to meet the specifications of 100 MHz maximum on the accel,
    clock is normally high, and the data is sent on the second pulse.  
    */
    accel_spi_setup->Mode = SPI_MODE_MASTER;
    accel_spi_setup->CommunicationType = SPI_COMMUNICATIONTYPE_FULLDUPLEX;
    accel_spi_setup->DataFrame = SPI_DATAFRAME_8BIT;
    accel_spi_setup->SSM = SPI_SSM_ENABLE;
    accel_spi_setup->SigBitFrame = SPI_SIGFIGFRAME_MSB;
    accel_spi_setup->BaudRate = SPI_BAUDRATE_256;
    accel_spi_setup->ClockPolarity = SPI_CLOCKPOLARITY_HI;
    accel_spi_setup->ClockPhase = SPI_CLOCKPHASE_EDGE2;

    SPI_Init(SPI2, accel_spi_setup);

    for(;;)
    {
        if (test_value <= (sizeof(test_value - 1)))
        {
            test_value++;
            SPI_Transmit(SPI2, &test_value, 1);
        }
        else
        {
            test_value = 0;
        }
    }
}