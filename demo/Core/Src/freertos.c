/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LED1 */
osThreadId_t LED1Handle;
const osThreadAttr_t LED1_attributes = {
  .name = "LED1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for LED2 */
osThreadId_t LED2Handle;
const osThreadAttr_t LED2_attributes = {
  .name = "LED2",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LED1_Task(void *argument);
void LED2_Task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LED1 */
  LED1Handle = osThreadNew(LED1_Task, NULL, &LED1_attributes);

  /* creation of LED2 */
  LED2Handle = osThreadNew(LED2_Task, NULL, &LED2_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_LED1_Task */
/**
  * @brief  Function implementing the LED1 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LED1_Task */
void LED1_Task(void *argument)
{
  /* USER CODE BEGIN LED1_Task */
  /* Infinite loop */
  for(;;)
  {
      xTaskCreate();
    osDelay(1);
  }
  /* USER CODE END LED1_Task */
}

/* USER CODE BEGIN Header_LED2_Task */
/**
* @brief Function implementing the LED2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LED2_Task */
void LED2_Task(void *argument)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
  /* USER CODE BEGIN LED2_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
      vTaskDelayUntil(&xLastWakeTime,500);
  }
  /* USER CODE END LED2_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

