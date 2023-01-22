#include "stm32f407xx.h"

#define __GPIOA_CLK_ENABLE RCC->AHB1ENR |= 1 << 0
#define __GPIOB_CLK_ENABLE RCC->AHB1ENR |= 1 << 1
#define __GPIOC_CLK_ENABLE RCC->AHB1ENR |= 1 << 2
#define __GPIOD_CLK_ENABLE RCC->AHB1ENR |= 1 << 3
#define __GPIOE_CLK_ENABLE RCC->AHB1ENR |= 1 << 4
#define __GPIOF_CLK_ENABLE RCC->AHB1ENR |= 1 << 5
#define __GPIOG_CLK_ENABLE RCC->AHB1ENR |= 1 << 6
#define __GPIOH_CLK_ENABLE RCC->AHB1ENR |= 1 << 7
#define __GPIOI_CLK_ENABLE RCC->AHB1ENR |= 1 << 8


#define __GPIOA_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 0)
#define __GPIOB_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 1)
#define __GPIOC_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 2)
#define __GPIOD_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 3)
#define __GPIOE_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 4)
#define __GPIOF_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 5)
#define __GPIOG_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 6)
#define __GPIOH_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 7)
#define __GPIOI_CLK_DISABLE RCC->AHB1ENR &= ~(1 << 8)
