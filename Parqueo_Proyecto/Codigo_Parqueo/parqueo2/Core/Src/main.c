/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "neo_pixel.h"



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ESP32_ADDRESS 0x10
#define NUMBER_OF_LEDS 8



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim3;
DMA_HandleTypeDef hdma_tim3_ch1_trig;

UART_HandleTypeDef huart5;

/* USER CODE BEGIN PV */
uint8_t option[1];
uint8_t tx_buffer[20];

neopixel_led leds[NUMBER_OF_LEDS + 1];
neopixel_led circular_pattern_led[2 * NUMBER_OF_LEDS + 1];
rgb_color led_pattern[NUMBER_OF_LEDS];

int dis = 0;
int m1 = 1;
int m2 = 1;
int m3 = 1;
int m4 = 1;
int m5 = 1;
int m6 = 1;
int m7 = 1;
int m8 = 1;
int conteo = 0; //son los valores que se reciben del I2C



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM3_Init(void);
static void MX_UART5_Init(void);
/* USER CODE BEGIN PFP */

void send_i2c_command(char* command);

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

  /* USER CODE BEGIN 1 */

	neopixel_led temp_neo_pixel;
	rgb_color red_color = {255, 0, 0};
	rgb_color green_color = {0, 255, 0};
	rgb_color blue_color = {0, 0, 255};
	rgb_color black_color = {0, 0, 0};
	uint16_t led_pos_counter = 0;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM3_Init();
  MX_UART5_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart5, option, 1);  // EMPEZAR RECEPCIÓN

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(PQ5_GPIO_Port, PQ5_Pin) == 1){
		  HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_SET);
		  m5 = 1;
		  send_i2c_command("A");
		  transmit_uart5("e");


		  reset_specific_led(leds, 0);
		  set_specific_led(leds, 0, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs


		  HAL_Delay(50);

	  }else{
		  m5 = 0;
		  HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_RESET);
		  send_i2c_command("a");
		  transmit_uart5("E");

		  reset_specific_led(leds, 0);
		  set_specific_led(leds, 0, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

		  HAL_Delay(50);
	  };
	  if(HAL_GPIO_ReadPin(PQ6_GPIO_Port, PQ6_Pin) == 1){
		  m6 = 1;
		  send_i2c_command("B");
		  transmit_uart5("f");

		  reset_specific_led(leds, 1);
		  set_specific_led(leds, 1, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs


		  HAL_Delay(50);
	  }else{
		  m6 = 0;
		  send_i2c_command("b");
		  transmit_uart5("F");


		  reset_specific_led(leds, 1);
		  set_specific_led(leds, 1, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

		  HAL_Delay(50);
	  };
	  if(HAL_GPIO_ReadPin(PQ7_GPIO_Port, PQ7_Pin) == 1){
		  m7 = 1;
		  send_i2c_command("C");
		  transmit_uart5("g");


		  reset_specific_led(leds, 2);
		  set_specific_led(leds, 2, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs



		  HAL_Delay(50);
	  }else{
		  m7 = 0;
		  send_i2c_command("c");
		  transmit_uart5("G");


		  reset_specific_led(leds, 2);
		  set_specific_led(leds, 2, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs


		  HAL_Delay(50);
	  };
	  if(HAL_GPIO_ReadPin(PQ8_GPIO_Port, PQ8_Pin) == 1){
		  m8 = 1;
		  send_i2c_command("D");
		  transmit_uart5("h");


		  reset_specific_led(leds, 3);
		  set_specific_led(leds, 3, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs



		  HAL_Delay(50);
	  }else{
		  m8 = 0;
		  send_i2c_command("d");
		  transmit_uart5("H");


		  reset_specific_led(leds, 3);
		  set_specific_led(leds, 3, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs


		  HAL_Delay(50);
	  };

	  if(m1 == 1){


		  reset_specific_led(leds, 4);
		  set_specific_led(leds, 4, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  }else{
		  reset_specific_led(leds, 4);
		  set_specific_led(leds, 4, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  };

	  if(m2 == 1){


		  reset_specific_led(leds, 5);
		  set_specific_led(leds, 5, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  }else{
		  reset_specific_led(leds, 5);
		  set_specific_led(leds, 5, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  };

	  if(m3 == 1){


		  reset_specific_led(leds, 6);
		  set_specific_led(leds, 6, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  }else{
		  reset_specific_led(leds, 6);
		  set_specific_led(leds, 6, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  };

	  if(m4 == 1){


		  reset_specific_led(leds, 7);
		  set_specific_led(leds, 7, &green_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  }else{
		  reset_specific_led(leds, 7);
		  set_specific_led(leds, 7, &red_color); // Establecer el primer LED en rojo
		  HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)leds, NUMBER_OF_LEDS * 24 + 24); // Enviar datos a los LEDs

	  };

	  dis = m5 + m6 + m7 + m8 + m1 + m2 + m3 + m4;

	  switch(dis){
	  	  case 0:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
		  break;
	  	case 1:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
	  	  break;
	  	case 2:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  	  break;
	  	case 3:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  			  break;
	  	case 4:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
	   		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
	   		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  			  break;
	  	case 5:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  			  break;
	  	case 6:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  			  break;
	  	case 7:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
	  		  	  break;
	  	case 8:
	  		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	  			  break;
	  };
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_ENABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 3;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 24;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, G_Pin|F_Pin|E_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D_Pin|C_Pin|B_Pin|A_Pin
                          |LED11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : G_Pin F_Pin E_Pin */
  GPIO_InitStruct.Pin = G_Pin|F_Pin|E_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : D_Pin C_Pin B_Pin A_Pin
                           LED11_Pin */
  GPIO_InitStruct.Pin = D_Pin|C_Pin|B_Pin|A_Pin
                          |LED11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PQ5_Pin PQ6_Pin */
  GPIO_InitStruct.Pin = PQ5_Pin|PQ6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PQ7_Pin PQ8_Pin */
  GPIO_InitStruct.Pin = PQ7_Pin|PQ8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// Función para enviar un comando I2C
void send_i2c_command(char* command) {
    HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)(ESP32_ADDRESS << 1), (uint8_t*)command, strlen(command), HAL_MAX_DELAY);
}

void transmit_uart5(char *message){
	HAL_UART_Transmit(&huart5, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	  if(huart->Instance == UART5){

	    		  switch (option[0]){

	    		  case 'A':
	    			  m1 = 1;  //aca pones I2C a es e, b es f, c es g, d es h
	    			  send_i2c_command("E");

	    			  //HAL_Delay(50);
	    			  break;
	    		  case 'a':
	    			  m1 = 0;
	    			  send_i2c_command("e");
	    			  //HAL_Delay(50);
	    			  break;
	    		  case 'B':
	    		 	  m2 = 1;
	    		 	 send_i2c_command("F");
	    		 	 //HAL_Delay(50);
	    		 	  break;
	    		  case 'b':
	    		 	  m2 = 0;
	    		 	  send_i2c_command("f");
	    		 	//HAL_Delay(50);
	    		 	  break;
	    		  case 'C':
	    		  	  m3 = 1;
	    		  	  send_i2c_command("G");
	    		  	//HAL_Delay(50);
	    		  	  break;
	    		  case 'c':
	    		  	  m3 = 0;
	    		  	  send_i2c_command("g");
	    		  	//HAL_Delay(50);
	    		  	  break;
	    		  case 'D':
	    		  	  m4 = 1;
	    		  	  send_i2c_command("H");
	    		  	//HAL_Delay(50);
	    		  	  break;
	    		  case 'd':
	    		  	  m4 = 0;
	    		  	  send_i2c_command("h");
	    		  	//HAL_Delay(50);
	    		  	  break;
	    		  default:
	    			  break;
	    		  }

	    		  HAL_UART_Transmit(&huart5, tx_buffer, strlen(tx_buffer), 10);
	    	  	  HAL_UART_Receive_IT(&huart5, option, 1);


	    	  }
}

/*************Interrupcion para NeoPixel***************/
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)	{
	HAL_TIM_PWM_Stop_DMA(&htim3, TIM_CHANNEL_1);
	htim3.Instance->CCR1 = 0;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
