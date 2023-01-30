#include "stm32f407xx.h"
#include "exti.h"

typedef struct
{
    uint32_t Mode;
    uint32_t Type;
    uint32_t Speed;
    uint32_t PUPD;
    uint32_t LOCK;
    uint32_t ALT;
}GPIO_Config;

//Mode
#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT 1
#define GPIO_MODE_ALTERNATE 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE 3

//Type
#define GPIO_TYPE_PP 0
#define GPIO_TYPE_OD 1
#define GPIO_TYPE 1

//Speed
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_HIGH 2
#define GPIO_SPEED_VERY_HIGH 3
#define GPIO_SPEED 3

//Pull-up, Pull-down
#define GPIO_PUPD_NONE 0
#define GPIO_PUPD_PU 1
#define GPIO_PUPD_PD 2
#define GPIO_PUPD 2

//GPIO locking
#define GPIO_LOCK_OFF 0
#define GPIO_LOCK_ON 1
#define GPIO_LOCK 1

//Alterante funtion
#define GPIO_ALT_AF0 0
#define GPIO_ALT_AF1 1
#define GPIO_ALT_AF2 2
#define GPIO_ALT_AF3 3
#define GPIO_ALT_AF4 4
#define GPIO_ALT_AF5 5
#define GPIO_ALT_AF6 6
#define GPIO_ALT_AF7 7
#define GPIO_ALT_AF8 8
#define GPIO_ALT_AF9 9
#define GPIO_ALT_AF10 10
#define GPIO_ALT_AF11 11
#define GPIO_ALT_AF12 12
#define GPIO_ALT_AF13 13
#define GPIO_ALT_AF14 14
#define GPIO_ALT_AF15 15
#define GPIO_ALT 15


//Copied mostly from stm32f4xx_hal_gpio.h
#define GPIO_PIN_0                 0  /* Pin 0 selected    */
#define GPIO_PIN_1                 1  /* Pin 1 selected    */
#define GPIO_PIN_2                 2  /* Pin 2 selected    */
#define GPIO_PIN_3                 3  /* Pin 3 selected    */
#define GPIO_PIN_4                 4  /* Pin 4 selected    */
#define GPIO_PIN_5                 5  /* Pin 5 selected    */
#define GPIO_PIN_6                 6  /* Pin 6 selected    */
#define GPIO_PIN_7                 7  /* Pin 7 selected    */
#define GPIO_PIN_8                 8  /* Pin 8 selected    */
#define GPIO_PIN_9                 9  /* Pin 9 selected    */
#define GPIO_PIN_10                10  /* Pin 10 selected   */
#define GPIO_PIN_11                11  /* Pin 11 selected   */
#define GPIO_PIN_12                12  /* Pin 12 selected   */
#define GPIO_PIN_13                13  /* Pin 13 selected   */
#define GPIO_PIN_14                14  /* Pin 14 selected   */
#define GPIO_PIN_15                15  /* Pin 15 selected   */

#define GPIO_PORT_A                 0  /* PORT A selected    */
#define GPIO_PORT_B                 1  /* PORT B selected    */
#define GPIO_PORT_C                 2  /* PORT C selected    */
#define GPIO_PORT_D                 3  /* PORT D selected    */
#define GPIO_PORT_E                 4  /* PORT E selected    */
#define GPIO_PORT_F                 5  /* PORT F selected    */
#define GPIO_PORT_G                 6  /* PORT G selected    */
#define GPIO_PORT_H                 7  /* PORT H selected    */
#define GPIO_PORT_I                 8  /* PORT I selected    */

//Copied mostly from stm32f4xx_hal_gpio.h
typedef enum
{
    GPIO_PIN_OFF = 0,
    GPIO_PIN_ON
}GPIO_PinState;

void GPIO_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_Config *Config);
void GPIO_DeInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);

void GPIO_InteruptEnable(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, EXTI_Config *EXTI_Cfg);


void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, GPIO_PinState value);
void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);

GPIO_PinState GPIO_GetState(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);
GPIO_PinState GPIO_GetOutput(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);
