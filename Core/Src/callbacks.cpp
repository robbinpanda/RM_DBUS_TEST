//
// Created by RobbinPanda on 24-10-11.
//
#include "gpio.h"
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <remote.h>

extern uint8_t rxBuffer[36u];
extern uint8_t rx[15];
extern uint8_t rxData[36u];

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM6) {
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    /*if (huart->Instance == USART1) {*/
    if (huart == &huart1) {

        /*HAL_TIM_Base_Start_IT(&htim6);*/

        memcpy(rxData, rxBuffer, sizeof(rxBuffer));
        receive();
        HAL_UART_Receive_DMA(&huart1, rxBuffer, 18u);
}