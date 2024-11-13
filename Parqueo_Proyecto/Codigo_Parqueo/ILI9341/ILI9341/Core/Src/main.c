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
#include "ili9341.h"
#include "bitmap.h"
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
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;
DMA_HandleTypeDef hdma_tim3_ch1_trig;

UART_HandleTypeDef huart5;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
extern uint8_t fondo[];

uint8_t option[1];
uint8_t tx_buffer[20];

int p1 = 1;
int p2 = 1;
int p3 = 1;
int p4 = 1;
int p5 = 1;
int p6 = 1;
int p7 = 1;
int p8 = 1;
int count = 0;
int m1 = 0;
int m12 = 0;
int m2 = 0;
int m22 = 0;
int m3 = 0;
int m32 = 0;
int m4 = 0;
int m42 = 0;
int m5 = 0;
int m52 = 0;
int m6 = 0;
int m62 = 0;
int m7 = 0;
int m72 = 0;
int m8 = 0;
int m82 = 0;

int PQ5 = 0;
int PQ6 = 0;
int PQ7 = 0;
int PQ8 = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_UART5_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void parqueo1(){
		LCD_Sprite(15,230,37,6,car37X6,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,220,37,16,car37X16,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,210,37,26,car37X26,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,200,37,36,car37X36,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,190,37,46,car37X46,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,180,37,56,car37X56,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,170,37,65,car37X65,1,0,1,0);
		HAL_Delay(50);
		LCD_Sprite(15,160,37,75,car37X75,1,0,1,0);
		HAL_Delay(50);


};
void parq1(){
		LCD_Sprite(15,170,37,65,car37X65,1,0,1,0);
		FillRect(15, 160, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,180,37,56,car37X56,1,0,1,0);
		FillRect(15, 170, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,190,37,46,car37X46,1,0,1,0);
		FillRect(15, 180, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,200,37,36,car37X36,1,0,1,0);
		FillRect(15, 190, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,210,37,26,car37X26,1,0,1,0);
		FillRect(15, 200, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,220,37,16,car37X16,1,0,1,0);
		FillRect(15, 210, 37, 10, 0x0000);
		HAL_Delay(50);
		LCD_Sprite(15,230,37,6,car37X6,1,0,1,0);
		FillRect(15, 220, 37, 10, 0x0000);
		HAL_Delay(50);
		FillRect(15, 230, 37, 10, 0x0000);
};
void parqueo2(){
		LCD_Bitmap(70, 230, 38,5, car38x5);
		HAL_Delay(50);
		LCD_Bitmap(70,220,38,15,car38x15);
		HAL_Delay(50);
		LCD_Bitmap(70,210,38,25,car38x25);
		HAL_Delay(50);
		LCD_Bitmap(70,200,38,35,car38x35);
		HAL_Delay(50);
		LCD_Bitmap(70,190,38,45,car38x45);
		HAL_Delay(50);
		LCD_Bitmap(70,180,38,55,car38x55);
		HAL_Delay(50);
		LCD_Bitmap(70,170,38,65,car38x65);
		HAL_Delay(50);
		LCD_Bitmap(70,160,38,75,car38x75);
		HAL_Delay(50);


};
void parq2(){
		LCD_Bitmap(70,170,38,65,car38x65);
		FillRect(70, 160, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,180,38,56,car38x55);
		FillRect(70, 170, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,190,38,45,car38x45);
		FillRect(70, 180, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,200,38,35,car38x35);
		FillRect(70, 190, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,210,38,25,car38x25);
		FillRect(70, 200, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,220,38,15,car38x15);
		FillRect(70, 210, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(70,230,38,5,car38x5);
		FillRect(70, 220, 38, 10, 0x0000);
		HAL_Delay(50);
		FillRect(70, 230, 38, 10, 0x0000);
};
void parqueo3(){
		LCD_Bitmap(123, 230, 36,5, car36x5);
		HAL_Delay(50);
		LCD_Bitmap(123,220,36,15,car36x15);
		HAL_Delay(50);
		LCD_Bitmap(123,210,36,25,car36x25);
		HAL_Delay(50);
		LCD_Bitmap(123,200,36,35,car36x35);
		HAL_Delay(50);
		LCD_Bitmap(123,190,36,45,car36x45);
		HAL_Delay(50);
		LCD_Bitmap(123,180,36,55,car36x55);
		HAL_Delay(50);
		LCD_Bitmap(123,170,36,65,car36x65);
		HAL_Delay(50);
		LCD_Bitmap(123,160,36,75,car36x75);
		HAL_Delay(50);


};
void parq3(){
		LCD_Bitmap(123,170,36,65,car36x65);
		FillRect(123, 160, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,180,36,56,car36x55);
		FillRect(123, 170, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,190,36,45,car36x45);
		FillRect(123, 180, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,200,36,35,car36x35);
		FillRect(123, 190, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,210,36,25,car36x25);
		FillRect(123, 200, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,220,36,15,car36x15);
		FillRect(123, 210, 36, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(123,230,36,5,car36x5);
		FillRect(123, 220, 36, 10, 0x0000);
		HAL_Delay(50);
		FillRect(123, 230, 36, 10, 0x0000);
};
void parqueo4(){
		LCD_Bitmap(180, 230, 38,5, caro38x5);
		HAL_Delay(50);
		LCD_Bitmap(180,220,38,15,caro38x15);
		HAL_Delay(50);
		LCD_Bitmap(180,210,38,25,caro38x25);
		HAL_Delay(50);
		LCD_Bitmap(180,200,38,35,caro38x35);
		HAL_Delay(50);
		LCD_Bitmap(180,190,38,45,caro38x45);
		HAL_Delay(50);
		LCD_Bitmap(180,180,38,55,caro38x55);
		HAL_Delay(50);
		LCD_Bitmap(180,170,38,65,caro38x65);
		HAL_Delay(50);
		LCD_Bitmap(180,160,38,75,caro38x75);
		HAL_Delay(50);


};
void parq4(){
		LCD_Bitmap(180,170,38,65,caro38x65);
		FillRect(180, 160, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,180,38,56,caro38x55);
		FillRect(180, 170, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,190,38,45,caro38x45);
		FillRect(180, 180, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,200,38,35,caro38x35);
		FillRect(180, 190, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,210,38,25,caro38x25);
		FillRect(180, 200, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,220,38,15,caro38x15);
		FillRect(180, 210, 38, 10, 0x0000);
		HAL_Delay(50);
		LCD_Bitmap(180,230,38,5,caro38x5);
		FillRect(180, 220, 38, 10, 0x0000);
		HAL_Delay(50);
		FillRect(180, 230, 38, 10, 0x0000);
};
void parqueo5(){
		LCD_Bitmap(15, 5, 35,5, car35x5);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,15,car35x15);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,25,car35x25);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,35,car35x35);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,45,car35x45);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,55,car35x55);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,65,car35x65);
		HAL_Delay(50);
		LCD_Bitmap(15,5,35,75,car35x75);
		HAL_Delay(50);


};
void parq5(){
		FillRect(15, 70, 35, 10, 0x0000);
		LCD_Bitmap(15, 5,35,65,car35x65);
		HAL_Delay(50);
		FillRect(15, 60, 35, 10, 0x0000);
		LCD_Bitmap(15,5,35,56,car35x55);
		HAL_Delay(50);
		FillRect(15, 49, 35, 12, 0x0000);
		LCD_Bitmap(15,5,35,45,car35x45);
		HAL_Delay(50);
		FillRect(15,40, 35, 10, 0x0000);
		LCD_Bitmap(15,5,35,35,car35x35);
		HAL_Delay(50);
		FillRect(15, 30, 35, 10, 0x0000);
		LCD_Bitmap(15,5,35,25,car35x25);
		HAL_Delay(50);
		FillRect(15, 20, 35, 10, 0x0000);
		LCD_Bitmap(15,5,35,15,car35x15);
		HAL_Delay(50);
		FillRect(15, 10, 35, 10, 0x0000);
		LCD_Bitmap(15,5,35,5,car35x5);
		HAL_Delay(50);
		FillRect(15, 5, 35, 10, 0x0000);

};
void parqueo6(){
		LCD_Bitmap(70, 5, 38,5, cars38x5);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,15,cars38x15);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,25,cars38x25);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,35,cars38x35);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,45,cars38x45);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,55,cars38x55);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,65,cars38x65);
		HAL_Delay(50);
		LCD_Bitmap(70,5,38,75,cars38x75);
		HAL_Delay(50);


};
void parq6(){
		FillRect(70, 70, 38, 10, 0x0000);
		LCD_Bitmap(70, 5,38,65,cars38x65);
		HAL_Delay(50);
		FillRect(70, 60, 38, 10, 0x0000);
		LCD_Bitmap(70,5,38,56,cars38x55);
		HAL_Delay(50);
		FillRect(70, 49, 38, 12, 0x0000);
		LCD_Bitmap(70,5,38,45,cars38x45);
		HAL_Delay(50);
		FillRect(70,40, 38, 10, 0x0000);
		LCD_Bitmap(70,5,38,35,cars38x35);
		HAL_Delay(50);
		FillRect(70, 30, 38, 10, 0x0000);
		LCD_Bitmap(70,5,38,25,cars38x25);
		HAL_Delay(50);
		FillRect(70, 20, 38, 10, 0x0000);
		LCD_Bitmap(70,5,38,15,cars38x15);
		HAL_Delay(50);
		FillRect(70, 10, 38, 10, 0x0000);
		LCD_Bitmap(70,5,38,5,cars38x5);
		HAL_Delay(50);
		FillRect(70, 5, 38, 10, 0x0000);

};
void parqueo7(){
		LCD_Bitmap(123, 5, 37,5, cars37x5);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,15,cars37x15);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,25,cars37x25);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,35,cars37x35);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,45,cars37x45);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,55,cars37x55);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,65,cars37x65);
		HAL_Delay(50);
		LCD_Bitmap(123,5,37,75,cars37x75);
		HAL_Delay(50);


};
void parq7(){
		FillRect(123, 70, 37, 10, 0x0000);
		LCD_Bitmap(123, 5,37,65,cars37x65);
		HAL_Delay(50);
		FillRect(123, 60, 37, 10, 0x0000);
		LCD_Bitmap(123,5,37,56,cars37x55);
		HAL_Delay(50);
		FillRect(123, 49, 37, 12, 0x0000);
		LCD_Bitmap(123,5,37,45,cars37x45);
		HAL_Delay(50);
		FillRect(123,40, 37, 10, 0x0000);
		LCD_Bitmap(123,5,37,35,cars37x35);
		HAL_Delay(50);
		FillRect(123, 30, 37, 10, 0x0000);
		LCD_Bitmap(123,5,37,25,cars37x25);
		HAL_Delay(50);
		FillRect(123, 20, 37, 10, 0x0000);
		LCD_Bitmap(123,5,37,15,cars37x15);
		HAL_Delay(50);
		FillRect(123, 10, 37, 10, 0x0000);
		LCD_Bitmap(123,5,37,5,cars37x5);
		HAL_Delay(50);
		FillRect(123, 5, 37, 10, 0x0000);

};
void parqueo8(){
		LCD_Bitmap(180, 5, 38,5, caros38x5);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,15,caros38x15);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,25,caros38x25);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,35,caros38x35);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,45,caros38x45);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,55,caros38x55);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,65,caros38x65);
		HAL_Delay(50);
		LCD_Bitmap(180,5,38,75,caros38x75);
		HAL_Delay(50);


};
void parq8(){
		FillRect(180, 70, 38, 10, 0x0000);
		LCD_Bitmap(180, 5,38,65,caros38x65);
		HAL_Delay(50);
		FillRect(180, 60, 38, 10, 0x0000);
		LCD_Bitmap(180,5,38,56,caros38x55);
		HAL_Delay(50);
		FillRect(180, 49, 38, 12, 0x0000);
		LCD_Bitmap(180,5,38,45,caros38x45);
		HAL_Delay(50);
		FillRect(180,40, 38, 10, 0x0000);
		LCD_Bitmap(180,5,38,35,caros38x35);
		HAL_Delay(50);
		FillRect(180, 30, 38, 10, 0x0000);
		LCD_Bitmap(180,5,38,25,caros38x25);
		HAL_Delay(50);
		FillRect(180, 20, 38, 10, 0x0000);
		LCD_Bitmap(180,5,38,15,caros38x15);
		HAL_Delay(50);
		FillRect(180, 10, 38, 10, 0x0000);
		LCD_Bitmap(180,5,38,5,caros38x5);
		HAL_Delay(50);
		FillRect(180, 5, 38, 10, 0x0000);

};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

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
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_UART5_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart5, option, 1);  // EMPEZAR RECEPCIÓN
	LCD_Init();

	LCD_Clear(0x00);

	FillRect(5, 86, 225, 5, 0xFFFF);
	FillRect(5, 154, 225, 5, 0xFFFF);

	FillRect(5, 6, 5, 80, 0xFFFF);
	FillRect(5, 154, 5, 80, 0xFFFF);

	FillRect(60, 6, 5, 80, 0xFFFF);
	FillRect(60, 154, 5, 80, 0xFFFF);

	FillRect(113, 6, 5, 80, 0xFFFF);
	FillRect(113, 154, 5, 80, 0xFFFF);

	FillRect(170, 6, 5, 80, 0xFFFF);
	FillRect(170, 154, 5, 80, 0xFFFF);

	FillRect(225, 6, 5, 80, 0xFFFF);
	FillRect(225, 154, 5, 80, 0xFFFF);

	LCD_Bitmap(240,20,70,70,parqueo70x70);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


		LCD_Sprite(10,96,50,21,barra50x21,2,p5,1,0);
		LCD_Sprite(10,127,50,21,barra50x21,2,p1,1,0);
		LCD_Sprite(65,96,50,21,barra50x21,2,p6,1,0);
		LCD_Sprite(65,127,50,21,barra50x21,2,p2,1,0);
		LCD_Sprite(120,96,50,21,barra50x21,2,p7,1,0);
		LCD_Sprite(120,127,50,21,barra50x21,2,p3,1,0);
		LCD_Sprite(175,96,50,21,barra50x21,2,p8,1,0);
		LCD_Sprite(175,127,50,21,barra50x21,2,p4,1,0);


		LCD_Sprite(245,120,64,80,num64x80,9,count,0,0);

		if(HAL_GPIO_ReadPin(PQ1_GPIO_Port, PQ1_Pin) == 0){
			p1 = 0;
			transmit_uart5("a");
			HAL_Delay(50);
			if(m1 == 0){
				parqueo1();
				m1 = 1;
				m12 = 0;
			};
		}else{
			p1 = 1;
			transmit_uart5("A");
			HAL_Delay(50);
			if(m12 == 0){
				parq1();
				m12 = 1;
				m1 = 0;
			};
		};

		if(HAL_GPIO_ReadPin(PQ1_GPIO_Port, PQ2_Pin) == 0){
			p2 = 0;
			transmit_uart5("b");
			HAL_Delay(50);
			if(m2 == 0){
				parqueo2();
				m2 = 1;
				m22 = 0;
			};
		}else{
			p2 = 1;
			transmit_uart5("B");
			HAL_Delay(50);
			if(m22 == 0){
				parq2();
				m22 = 1;
				m2 = 0;
			};
		};
		if(HAL_GPIO_ReadPin(PQ3_GPIO_Port, PQ3_Pin) == 0){
			p3 = 0;
			transmit_uart5("c");
			HAL_Delay(50);
			if(m3 == 0){
				parqueo3();
				m3 = 1;
				m32 = 0;
			};
		}else{
			p3 = 1;
			transmit_uart5("C");
			HAL_Delay(50);
			if(m32 == 0){
				parq3();
				m32 = 1;
				m3 = 0;
			};
		};
		if(HAL_GPIO_ReadPin(PQ4_GPIO_Port, PQ4_Pin) == 0){
				p4 = 0;
				transmit_uart5("d");
				HAL_Delay(50);
				if(m4 == 0){
					parqueo4();
					m4 = 1;
					m42 = 0;
				};
			}else{
				p4 = 1;
				transmit_uart5("D");
				HAL_Delay(50);
				if(m42 == 0){
					parq4();
					m42 = 1;
					m4 = 0;
				};
			};
		if(PQ5 == 1){
				p5 = 0;
				if(m5 == 0){
					parqueo5();
					m5 = 1;
					m52 = 0;
				};
			}else{
				p5 = 1;
				if(m52 == 0){
					parq5();
					m52 = 1;
					m5 = 0;
				};
			};

		if(PQ6 == 1){
				p6 = 0;
				if(m6 == 0){
					parqueo6();
					m6 = 1;
					m62 = 0;
					};
			}else{
				p6 = 1;
				if(m62 == 0){
					parq6();
					m62 = 1;
					m6 = 0;
				};
			};
		if(PQ7 == 1){
				p7 = 0;
				if(m7 == 0){
					parqueo7();
					m7 = 1;
					m72 = 0;
				};
			}else{
				p7 = 1;
				if(m72 == 0){
					parq7();
					m72 = 1;
					m7 = 0;
				};
			};
		if(PQ8 == 1){
					p8 = 0;
					if(m8 == 0){
						parqueo8();
						m8 = 1;
						m82 = 0;
					};
				}else{
					p8 = 1;
					if(m82 == 0){
						parq8();
						m82 = 1;
						m8 = 0;
					};
				};

		count = p1+p2+p3+p4+p5+p6+p7+p8;

		//parqueo1();
		//parq1();


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
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

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
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LCD_RST_Pin|LCD_D1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_RD_Pin|LCD_WR_Pin|LCD_RS_Pin|LCD_D7_Pin
                          |LCD_D0_Pin|LCD_D2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_CS_Pin|LCD_D6_Pin|LCD_D3_Pin|LCD_D5_Pin
                          |LCD_D4_Pin|SD_SS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LCD_RST_Pin LCD_D1_Pin */
  GPIO_InitStruct.Pin = LCD_RST_Pin|LCD_D1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_RD_Pin LCD_WR_Pin LCD_RS_Pin LCD_D7_Pin
                           LCD_D0_Pin LCD_D2_Pin */
  GPIO_InitStruct.Pin = LCD_RD_Pin|LCD_WR_Pin|LCD_RS_Pin|LCD_D7_Pin
                          |LCD_D0_Pin|LCD_D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_CS_Pin LCD_D6_Pin LCD_D3_Pin LCD_D5_Pin
                           LCD_D4_Pin SD_SS_Pin */
  GPIO_InitStruct.Pin = LCD_CS_Pin|LCD_D6_Pin|LCD_D3_Pin|LCD_D5_Pin
                          |LCD_D4_Pin|SD_SS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PQ4_Pin PQ3_Pin */
  GPIO_InitStruct.Pin = PQ4_Pin|PQ3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PQ2_Pin PQ1_Pin */
  GPIO_InitStruct.Pin = PQ2_Pin|PQ1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void transmit_uart5(char *message){
	HAL_UART_Transmit(&huart5, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	  if(huart->Instance == UART5){

	    		  switch (option[0]){

	    		  case 'E':
	    			  PQ5 = 1;
	    			  break;
	    		  case 'e':
	    			  PQ5 = 0;
	    			  break;
	    		  case 'F':
	    			  PQ6 = 1;
	    		 	  break;
	    		  case 'f':
	    		 	  PQ6 = 0;
	    		 	  break;
	    		  case 'G':
	    		  	  PQ7 = 1;
	    		  	  break;
	    		  case 'g':
	    		  	  PQ7 = 0;
	    		  	  break;
	    		  case 'H':
	    		  	  PQ8 = 1;
	    		  	  break;
	    		  case 'h':
	    		  	  PQ8 = 0;
	    		  	  break;
	    		  default:
	    			  break;
	    		  }

	    		  HAL_UART_Transmit(&huart5, tx_buffer, strlen(tx_buffer), 10);
	    	  	  HAL_UART_Receive_IT(&huart5, option, 1);


	    	  }
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
	while (1) {
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
