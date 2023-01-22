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
  __GPIOD_CLK_ENABLE;
  GPIO_Config *board_LED_Config = malloc(sizeof(GPIO_Config));

  board_LED_Config->Mode = GPIO_MODE_OUTPUT;
  board_LED_Config->Type = GPIO_TYPE_PP;
  board_LED_Config->Speed = GPIO_SPEED_LOW;
  board_LED_Config->PUPD = GPIO_PUPD_NONE;
  board_LED_Config->LOCK = GPIO_LOCK_OFF;
  board_LED_Config->ALT = GPIO_ALT_AF0;
  
  GPIO_Init(BOARD_LED_Port, GREEN_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, ORANGE_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, RED_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BLUE_LED_Pin, board_LED_Config);

  GPIO_Write(BOARD_LED_Port, GREEN_LED_Pin, GPIO_PIN_ON);
  GPIO_Write(BOARD_LED_Port, ORANGE_LED_Pin, GPIO_PIN_ON);
  GPIO_Write(BOARD_LED_Port, RED_LED_Pin, GPIO_PIN_ON);
  GPIO_Write(BOARD_LED_Port, BLUE_LED_Pin, GPIO_PIN_ON);

  while (1)
  {

  }
  /* USER CODE END 3 */
}
