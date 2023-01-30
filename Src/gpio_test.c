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


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  GPIO_Config *board_LED_Config = malloc(sizeof(GPIO_Config));
  GPIO_Config *board_Button_Config = malloc(sizeof(GPIO_Config));
  EXTI_Config *board_Button_EXTI = malloc(sizeof(EXTI_Config));

  __GPIOD_CLK_ENABLE;
  __GPIOA_CLK_ENABLE;
  __SYSCFG_CLK_ENABLE;

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

  board_Button_EXTI->Mode = EXTI_MODE_INTERUPT;
  board_Button_EXTI->Trigger = EXTI_TRIGGER_FALLING;

  GPIO_Init(BOARD_LED_Port, BOARD_GREEN_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_ORANGE_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_RED_LED_Pin, board_LED_Config);
  GPIO_Init(BOARD_LED_Port, BOARD_BLUE_LED_Pin, board_LED_Config);

  GPIO_Init(BOARD_B1_Port, BOARD_USER_B1_Pin, board_Button_Config);
  GPIO_InteruptEnable(BOARD_B1_Port, BOARD_USER_B1_Pin, board_Button_EXTI);


  while (1)
  {
    int sum = 1 + 1;
  }
}

void EXTI0_IRQHandler(void)
{
  
  GPIO_Toggle(BOARD_LED_Port, BOARD_GREEN_LED_Pin);
  for(int i = 0; i < 100000; i++);
  GPIO_Toggle(BOARD_LED_Port, BOARD_ORANGE_LED_Pin);
  for(int i = 0; i < 100000; i++);
  GPIO_Toggle(BOARD_LED_Port, BOARD_RED_LED_Pin);
  for(int i = 0; i < 100000; i++);
  GPIO_Toggle(BOARD_LED_Port, BOARD_BLUE_LED_Pin);
  for(int i = 0; i < 100000; i++);
  EXTI->PR |= (1 << 0);
}
