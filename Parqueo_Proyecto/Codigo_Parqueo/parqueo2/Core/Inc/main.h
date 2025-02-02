/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define G_Pin GPIO_PIN_7
#define G_GPIO_Port GPIOC
#define F_Pin GPIO_PIN_8
#define F_GPIO_Port GPIOC
#define E_Pin GPIO_PIN_9
#define E_GPIO_Port GPIOC
#define D_Pin GPIO_PIN_8
#define D_GPIO_Port GPIOA
#define C_Pin GPIO_PIN_9
#define C_GPIO_Port GPIOA
#define B_Pin GPIO_PIN_10
#define B_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_11
#define A_GPIO_Port GPIOA
#define LED11_Pin GPIO_PIN_15
#define LED11_GPIO_Port GPIOA
#define PQ5_Pin GPIO_PIN_10
#define PQ5_GPIO_Port GPIOC
#define PQ6_Pin GPIO_PIN_11
#define PQ6_GPIO_Port GPIOC
#define PQ7_Pin GPIO_PIN_3
#define PQ7_GPIO_Port GPIOB
#define PQ8_Pin GPIO_PIN_4
#define PQ8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
