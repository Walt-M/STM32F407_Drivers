/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f407xx.h"
#include "gpio.h"
#include "rcc.h"
#include <stdlib.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  GPIO_Config *board_LED_Config = malloc(sizeof(GPIO_Config));
  GPIO_Config *board_Button_Config = malloc(sizeof(GPIO_Config));

  __GPIOD_CLK_ENABLE;
  __GPIOA_CLK_ENABLE;

  board_LED_Config->Mode = GPIO_MODE_OUTPUT;
  board_LED_Config->Type = GPIO_TYPE_PP;
  board_LED_Config->Speed = GPIO_SPEED_LOW;
  board_LED_Config->PUPD = GPIO_PUPD_NONE;
  board_LED_Config->LOCK = GPIO_LOCK_OFF;
  board_LED_Config->ALT = GPIO_ALT_AF0;

  board_Button_Config->Mode = GPIO_MODE_INPUT;
  board_Button_Config->Type = GPIO_TYPE_PP;
  board_Button_Config->Speed = GPIO_SPEED_LOW;
  board_Button_Config->PUPD = GPIO_PUPD_NONE;
  board_Button_Config->LOCK = GPIO_LOCK_OFF;
  board_Button_Config->ALT = GPIO_ALT_AF0;


  GPIO_Init(BOARD_LED_Port, BOARD_GREEN_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_ORANGE_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_RED_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_BLUE_LED_Pin, board_LED_Config);

  GPIO_Init(BOARD_B1_Port, BOARD_USER_B1_Pin, board_Button_Config);

  while (1)
  {
    if (GPIO_GetState(BOARD_B1_Port, BOARD_USER_B1_Pin) == GPIO_PIN_ON){
      GPIO_Write(BOARD_LED_Port, BOARD_GREEN_LED_Pin, GPIO_PIN_ON);
      GPIO_Write(BOARD_LED_Port, BOARD_ORANGE_LED_Pin, GPIO_PIN_ON);
      GPIO_Write(BOARD_LED_Port, BOARD_RED_LED_Pin, GPIO_PIN_ON);
      GPIO_Write(BOARD_LED_Port, BOARD_BLUE_LED_Pin, GPIO_PIN_ON);
    }
  }
  /* USER CODE END 3 */
}
