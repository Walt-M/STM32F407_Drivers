#include "gpio.h"

void GPIO_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_Config *Config){
    GPIOx->MODER &= ~(GPIO_MODE << (uint32_t)(GPIO_PIN * 2U));
    GPIOx->MODER |= (Config->Mode << (uint32_t)(GPIO_PIN * 2U));

    GPIOx->OTYPER &= ~(GPIO_TYPE << GPIO_PIN);
    GPIOx->OTYPER |= (Config->Type << GPIO_PIN);
    
    GPIOx->OSPEEDR &= ~(GPIO_SPEED << (GPIO_PIN * 2U));
    GPIOx->OSPEEDR |= (Config->Speed << (GPIO_PIN * 2U));

    GPIOx->PUPDR &= ~(GPIO_PUPD << GPIO_PIN * 2U);
    GPIOx->PUPDR |= (Config->PUPD << (GPIO_PIN * 2U));

    GPIOx->LCKR &= ~(GPIO_LOCK << GPIO_PIN);
    GPIOx->LCKR |= (Config->LOCK << GPIO_PIN);

    if (GPIO_PIN <= GPIO_PIN_7){
        GPIOx->AFR[0] &= ~(GPIO_ALT << (GPIO_PIN * 4U));
        GPIOx->AFR[0] |= (Config->ALT << (GPIO_PIN * 4U));
    }else{
        GPIOx->AFR[1] &= ~(GPIO_ALT << (GPIO_PIN * 4U));
        GPIOx->AFR[1] |= (Config->ALT << (GPIO_PIN * 4U));
    }
    
    
};

//void GPIO_DeInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);

void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState value){
    GPIOx->ODR |= value << GPIO_PIN;
};