/*
 * adar2001.c
 *
 *  Created on: Apr 21, 2026
 *      Author: justi
 */

// adar2001.c
#include "adar2001.h"

void ADAR2001_WriteReg(SPI_HandleTypeDef *hspi, uint8_t addr, uint16_t data)
{
    uint8_t tx[3];
    tx[0] = addr;
    tx[1] = (data >> 8) & 0xFF;
    tx[2] = data & 0xFF;

    HAL_GPIO_WritePin(NSS_ADAR2001_GPIO_Port, NSS_ADAR2001_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi, tx, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(NSS_ADAR2001_GPIO_Port, NSS_ADAR2001_Pin, GPIO_PIN_SET);
}

void ADAR2001_Init(SPI_HandleTypeDef *hspi)
{
    // Power on and configure transmit up-converter
    ADAR2001_WriteReg(hspi, 0x00, 0x0000); // Reset
    HAL_Delay(10);
    ADAR2001_WriteReg(hspi, 0x01, 0x0001); // Power up
    ADAR2001_WriteReg(hspi, 0x02, 0x0000); // Configure gain
}
