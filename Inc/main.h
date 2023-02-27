/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

#define BOARD_USER_B1_Pin GPIO_PIN_0
#define BOARD_B1_Port GPIOA
#define BOARD_GREEN_LED_Pin GPIO_PIN_12
#define BOARD_ORANGE_LED_Pin GPIO_PIN_13
#define BOARD_RED_LED_Pin GPIO_PIN_14
#define BOARD_BLUE_LED_Pin GPIO_PIN_15
#define BOARD_LED_Port GPIOD
#define BOARD_ACCELEROMETER_PORT GPIOA
#define BOARD_ACCELEROMETER_SPI_SCK GPIO_PIN_5
#define BOARD_ACCELEROMETER_SPI_MISO GPIO_PIN_6
#define BOARD_ACCELEROMETER_SPI_MOSI GPIO_PIN_7
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
