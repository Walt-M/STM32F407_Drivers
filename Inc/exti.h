//To do: 
// 1) Finish the config struct.
// 2) Make headers for functions
// 3) In functions, SYSCONFIG needs to be manipulated aswell.


#include "stm32f407xx.h"

typedef struct
{
    uint32_t Mode; /*Sets the event type to be Interrupt or Event*/
    uint32_t Trigger; /*Sets the method for which the interrupt is triggered*/
    
}EXTI_Config;
