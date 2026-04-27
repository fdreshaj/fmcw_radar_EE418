/*
 * adar2001.h
 *
 *  Created on: Apr 21, 2026
 *      Author: justi
 */

#ifndef INC_ADAR2001_H_
#define INC_ADAR2001_H_

#include "stm32f1xx_hal.h"

/* Pin Values*/
#define NSS_ADAR2001_GPIO_PORT		GPIOA
#define NSS_ADAR2001_PIN			GPIO_PIN_3


/* SPI Transaction Parameters */
#define ADAR2001_WRITE          0x0000  // Write bit
#define ADAR2001_READ           0x8000  // Read bit

/* Register Addresses */
#define ADAR2001_REG_CONFIG     0x000   // Configuration register
#define ADAR2001_REG_MULT1      0x011   // Multiplier bias 1
#define ADAR2001_REG_MULT2      0x012   // Multiplier bias 2
#define ADAR2001_REG_INBUF      0x013   // Input buffer bias
#define ADAR2001_REG_SPLITTER   0x014   // Splitter bias
#define ADAR2001_REG_MULT_EN    0x070   // Multiplier enable mode 0
#define ADAR2001_REG_MULT_PASS  0x071   // Multiplier pass mode 0
#define ADAR2001_REG_TX_EN1     0x050   // TX enable channels 1 and 2
#define ADAR2001_REG_TX_EN2     0x051   // TX enable channels 3 and 4
#define ADAR2001_REG_LPF        0x080   // Low pass notch filter control

/* Multiplier Band Settings for 7-8 GHz input (High Band) */
/* From Table 7: High band active, mid and low bands ready, BPF high */
#define ADAR2001_MULT_HIGHBAND  0xCE

/* Low Pass Notch Filter - disabled for >16 GHz output */
#define ADAR2001_LPF_DISABLE    0x00

/* TX Enable - all 4 channels active */
#define ADAR2001_TX_EN_ALL      0xFF

/* Function Prototypes */
void ADAR2001_Init(SPI_HandleTypeDef *hspi);
void ADAR2001_WriteReg(SPI_HandleTypeDef *hspi, uint16_t addr, uint8_t data);
uint8_t ADAR2001_ReadReg(SPI_HandleTypeDef *hspi, uint16_t addr);
void ADAR2001_EnableAllChannels(SPI_HandleTypeDef *hspi);
void ADAR2001_SetMultiplierBand(SPI_HandleTypeDef *hspi, uint8_t band_setting);

#endif /* INC_ADAR2001_H_ */
