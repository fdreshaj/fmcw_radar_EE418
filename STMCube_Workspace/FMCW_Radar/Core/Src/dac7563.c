/*
 * dac7563.c
 *
 *  Created on: Apr 21, 2026
 *      Author: justi
 */

#include "dac7563.h"
#include "stm32f1xx_hal.h"



void DAC7563_Write(SPI_HandleTypeDef *hspi, uint8_t command, uint16_t value)
{
    uint8_t tx[3];
    uint16_t aligned_value = (value << 4) & 0xFFF0;

    tx[0] = command;
    tx[1] = (aligned_value >> 8) & 0xFF;
    tx[2] = aligned_value & 0xFF;

    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi, tx, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_SET);
    // Output updates automatically on 24th falling SCLK edge in synchronous mode
}

void DAC7563_Init(SPI_HandleTypeDef *hspi)
{
    // Set LDAC permanently LOW for synchronous mode
    HAL_GPIO_WritePin(DAC_LDAC_PORT, DAC_LDAC_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_SET);
    HAL_Delay(1);

    // Enable internal reference gain=2
    uint8_t tx[3];
    tx[0] = DAC_ENABLE_INT_REF;
    tx[1] = 0x00;
    tx[2] = 0x01;
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi, tx, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_SET);
    HAL_Delay(1);

    // Power up DAC-A
    tx[0] = DAC_POWER_UP_A;
    tx[1] = 0x00;
    tx[2] = 0x01;
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi, tx, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(NSS_DAC7563_GPIO_PORT, NSS_DAC7563_PIN, GPIO_PIN_SET);
    HAL_Delay(1);
}
