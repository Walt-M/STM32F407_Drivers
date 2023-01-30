//To do: 



#include "stm32f407xx.h"

typedef struct
{
    uint32_t Mode; /*Sets the event type to be Interrupt or Event*/
    uint32_t Trigger; /*Sets the method for which the interrupt is triggered*/
}EXTI_Config;

#define EXTI_MODE_INTERUPT 0
#define EXTI_MODE_EVENT 1

#define EXTI_TRIGGER_RISING 0
#define EXTI_TRIGGER_FALLING 1
