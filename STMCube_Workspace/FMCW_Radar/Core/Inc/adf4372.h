/*
 * adf4372.h
 *
 *  Created on: Apr 21, 2026
 *      Author: justi
 */

#ifndef INC_ADF4372_H_
#define INC_ADF4372_H_

#include "stm32f1xx_hal.h"

/* PIN Values*/
#define NSS_ADF4372_GPIO_PORT		GPIOA
#define NSS_ADF4372_PIN				GPIO_PIN_4



/* SPI Transaction Parameters */
#define ADF4372_WRITE               0x00    // Write bit (R/W = 0)
#define ADF4372_READ                0x80    // Read bit (R/W = 1)

/* Register Addresses */
#define ADF4372_REG_CONFIG          0x00    // SPI configuration
#define ADF4372_REG_CHIP_ID         0x04    // Chip ID register
#define ADF4372_REG_POWER_DOWN      0x05    // Power down control
#define ADF4372_REG_REF_DIV         0x07    // Reference divider R
#define ADF4372_REG_INT_LOW         0x10    // INT word bits [7:0]
#define ADF4372_REG_INT_HIGH        0x11    // INT word bits [15:8]
#define ADF4372_REG_FRAC1_LOW       0x12    // FRAC1 bits [7:0]
#define ADF4372_REG_FRAC1_MID       0x13    // FRAC1 bits [15:8]
#define ADF4372_REG_FRAC1_HIGH      0x14    // FRAC1 bits [23:16]
#define ADF4372_REG_FRAC2_LOW       0x15    // FRAC2 bits [7:0]
#define ADF4372_REG_FRAC2_HIGH      0x16    // FRAC2 bits [13:8]
#define ADF4372_REG_MOD2_LOW        0x17    // MOD2 bits [7:0]
#define ADF4372_REG_MOD2_HIGH       0x18    // MOD2 bits [13:8]
#define ADF4372_REG_PHASE_LOW       0x1A    // Phase word bits [7:0]
#define ADF4372_REG_PHASE_HIGH      0x1B    // Phase word bits [15:8]
#define ADF4372_REG_REF_CTRL        0x20    // Reference control (doubler/divider)
#define ADF4372_REG_VCO_CTRL        0x2A    // VCO control
#define ADF4372_REG_CP_CTRL         0x1E    // Charge pump control
#define ADF4372_REG_OUTPUT_CTRL     0x2C    // Output stage control
#define ADF4372_REG_RF8_CTRL        0x2D    // RF8x output control
#define ADF4372_REG_AUTOCAL         0x35    // Autocalibration control
#define ADF4372_REG_LOCK_DETECT     0x3B    // Lock detect control

/* Reference Configuration */
/* 100 MHz reference, R=1, no doubler, fPFD = 100 MHz */
#define ADF4372_R_DIVIDER           0x01    // R = 1
#define ADF4372_REF_DOUBLER_OFF     0x00    // Doubler disabled
#define ADF4372_REF_DIV2_OFF        0x00    // Reference divide by 2 disabled

/* Frequency Configuration for 7-8 GHz sweep */
/* fVCO = fPFD x INT = 100 MHz x 70 = 7000 MHz (start) */
/* fVCO = fPFD x INT = 100 MHz x 80 = 8000 MHz (end)   */
#define ADF4372_INT_7GHZ            70      // INT value for 7 GHz
#define ADF4372_INT_8GHZ            80      // INT value for 8 GHz
#define ADF4372_INT_START           ADF4372_INT_7GHZ

/* Output Stage Settings */
/* RF8x output enabled, maximum power (+5 dBm) */
#define ADF4372_RF8_ENABLE          0x01    // Enable RF8P and RF8N
#define ADF4372_RF8_POWER_MAX       0x03    // Maximum output power

/* Power Down */
#define ADF4372_POWER_UP            0x00    // Normal operation
#define ADF4372_POWER_DOWN          0x01    // Power down

/* Autocalibration */
#define ADF4372_AUTOCAL_EN          0x01    // Enable VCO autocalibration
#define ADF4372_AUTOCAL_DIS         0x00    // Disable autocalibration

/* Function Prototypes */
void ADF4372_Init(SPI_HandleTypeDef *hspi);
void ADF4372_WriteReg(SPI_HandleTypeDef *hspi, uint8_t addr, uint8_t data);
uint8_t ADF4372_ReadReg(SPI_HandleTypeDef *hspi, uint8_t addr);
void ADF4372_SetFrequency(SPI_HandleTypeDef *hspi, uint16_t int_val);
void ADF4372_PowerDown(SPI_HandleTypeDef *hspi);
void ADF4372_PowerUp(SPI_HandleTypeDef *hspi);

#endif /* INC_ADF4372_H_ */
