#include "gpio.h"

void GPIO_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_Config *Config){
    GPIOx->MODER &= ~(GPIO_MODE << (GPIO_PIN * 2U));
    GPIOx->MODER |= (Config->Mode << (GPIO_PIN * 2U));

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

//Idea from "Mastering Microcontroller and Embeeded Driver Development" vid 111.
#define GPIOx_TO_NUMBER(GPIOx) ((GPIOx == GPIOA) ? 0 :\
                                (GPIOx == GPIOB) ? 1 :\
                                (GPIOx == GPIOC) ? 2 :\
                                (GPIOx == GPIOD) ? 3 :\
                                (GPIOx == GPIOE) ? 4 :\
                                (GPIOx == GPIOF) ? 5 :\
                                (GPIOx == GPIOG) ? 6 :\
                                (GPIOx == GPIOH) ? 7 :\
                                (GPIOx == GPIOI) ? 8 : 0 )

#define GPIO_IRQ_NUM(GPIO_Pin) ((GPIO_Pin == GPIO_PIN_0) ? EXTI0_IRQn :\
                                (GPIO_Pin == GPIO_PIN_1) ? EXTI1_IRQn :\
                                (GPIO_Pin == GPIO_PIN_2) ? EXTI2_IRQn :\
                                (GPIO_Pin == GPIO_PIN_3) ? EXTI3_IRQn :\
                                (GPIO_Pin == GPIO_PIN_4) ? EXTI4_IRQn :\
                                (GPIO_Pin == GPIO_PIN_5) ? EXTI9_5_IRQn :\
                                (GPIO_Pin == GPIO_PIN_6) ? EXTI9_5_IRQn :\
                                (GPIO_Pin == GPIO_PIN_7) ? EXTI9_5_IRQn :\
                                (GPIO_Pin == GPIO_PIN_8) ? EXTI9_5_IRQn :\
                                (GPIO_Pin == GPIO_PIN_9) ? EXTI9_5_IRQn :\
                                (GPIO_Pin == GPIO_PIN_10) ? EXTI15_10_IRQn :\
                                (GPIO_Pin == GPIO_PIN_11) ? EXTI15_10_IRQn :\
                                (GPIO_Pin == GPIO_PIN_12) ? EXTI15_10_IRQn :\
                                (GPIO_Pin == GPIO_PIN_13) ? EXTI15_10_IRQn :\
                                (GPIO_Pin == GPIO_PIN_14) ? EXTI15_10_IRQn :\
                                (GPIO_Pin == GPIO_PIN_15) ? EXTI15_10_IRQn : 0)

// 1) Set SYSCFG to point to required port and pin
// 2) Configure exti for that port and pin. Trigger, Mode, gpoio exc
// 3) Set proper IRQ bit to 1.
// 4) Once IRQ happens, clear bit.
void GPIO_InteruptEnable(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, EXTI_Config *EXTI_Cfg){
    uint8_t index = GPIO_Pin / 4;
    uint8_t offset = GPIO_Pin % 4;
    uint8_t IRQ_Num = GPIO_IRQ_NUM(GPIO_Pin);


    if(EXTI_Cfg->Mode == EXTI_MODE_INTERUPT){
        SYSCFG->EXTICR[index] |= (GPIOx_TO_NUMBER(GPIOx) << offset * 4U);
        EXTI->IMR |= (1 << GPIO_Pin);


        index = IRQ_Num / 32;
        offset = IRQ_Num % 32;
        NVIC->ISER[index] |= (1 << offset);
    }else{
        EXTI->EMR |= (1 << GPIO_Pin);
    }

    if(EXTI_Cfg->Trigger == EXTI_TRIGGER_RISING){
        EXTI->RTSR |= (1 << GPIO_Pin);
    }else{
        EXTI->FTSR |= (1 << GPIO_Pin);
    }
    


};

void GPIO_DeInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
    GPIOx->MODER &= ~(GPIO_MODE << (GPIO_PIN * 2U));

    GPIOx->OTYPER &= ~(GPIO_TYPE << GPIO_PIN);
    
    GPIOx->OSPEEDR &= ~(GPIO_SPEED << (GPIO_PIN * 2U));

    GPIOx->PUPDR &= ~(GPIO_PUPD << GPIO_PIN * 2U);

    GPIOx->LCKR &= ~(GPIO_LOCK << GPIO_PIN);

    if (GPIO_PIN <= GPIO_PIN_7){
        GPIOx->AFR[0] &= ~(GPIO_ALT << (GPIO_PIN * 4U));
    }else{
        GPIOx->AFR[1] &= ~(GPIO_ALT << (GPIO_PIN * 4U));
    }
};

void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState value){
    GPIOx->ODR |= value << GPIO_PIN;
};

void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
    GPIOx->ODR ^= 1 << GPIO_PIN;
};

GPIO_PinState GPIO_GetState(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
    return GPIOx->IDR & (1 << GPIO_PIN);
};

//Bug: An and with the max bits a register can hold does not equal an integer like GPIO_MODE_ALTERNATE
GPIO_PinState GPIO_GetOutput(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN){
    if (((GPIOx->MODER & GPIO_TYPE) == (GPIO_MODE_OUTPUT << GPIO_PIN * 2U)) 
    || ((GPIOx->MODER & GPIO_TYPE) == (GPIO_MODE_ALTERNATE << GPIO_PIN * 2U)))
    {
        return GPIOx->ODR & (1 << GPIO_PIN);
    }
};