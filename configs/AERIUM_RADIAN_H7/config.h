/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU     STM32H743

#define BOARD_NAME        AERIUM_RADIAN_H7
#define MANUFACTURER_ID   AERM

/* ---------------- Acc / Gyro ---------------- */

#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define GYRO_1_EXTI_PIN             PE15
#define GYRO_1_CS_PIN               PE4
#define GYRO_1_SPI_INSTANCE         SPI2
#define GYRO_1_ALIGN                CW0_DEG

/* ---------------- SD Card (SPI) ---------------- */

#define USE_BARO
#define USE_BARO_SPI_DPS310
#define BARO_SPI_INSTANCE       SPI1
#define BARO_CS_PIN             PC14

#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_INSTANCE     SPI4
#define SDCARD_SPI_CS_PIN       PE3
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD

/* ---------------- Magnetometer (I2C) ---------------- */

#define USE_MAG
#define USE_MAG_LIS3MDL
#define MAG_I2C_INSTANCE     I2CDEV_2
#define MAG_I2C_ADDRESS      30
#define MAG_ALIGN CUSTOM
#define MAG_ALIGN_ROLL CW0_DEG
#define MAG_ALIGN_PITCH CW0_DEG
#define MAG_ALIGN_YAW CW270_DEG
// #define MAG_ALIGN            CW270_DEG
// #define MAG_ALIGN_YAW        2700

/* ---------------- I2C Pins ---------------- */

#define I2C2_SCL_PIN    PB10
#define I2C4_SCL_PIN    PB8

#define I2C2_SDA_PIN    PB11
#define I2C4_SDA_PIN    PB7

/* ---------------- SPI Pins ---------------- */

#define SPI1_SCK_PIN    PB3
#define SPI1_SDI_PIN    PB4
#define SPI1_SDO_PIN    PD7

#define SPI2_SCK_PIN    PB13
#define SPI2_SDI_PIN    PB14
#define SPI2_SDO_PIN    PB15   

#define SPI4_SCK_PIN    PE2
#define SPI4_SDI_PIN    PE13
#define SPI4_SDO_PIN    PE14

/* ---------------- UART Pins ---------------- */

#define UART2_TX_PIN                  PD5
#define UART2_RX_PIN                  PD6
#define SERIALRX_UART                 SERIAL_PORT_USART2

#define UART3_TX_PIN                  PD8   // GPS1 (ArduPilot)
#define UART3_RX_PIN                  PD9
#define GPS_UART                      SERIAL_PORT_USART3

#define UART4_TX_PIN                  PC10  // GPS2 (ArduPilot)
#define UART4_RX_PIN                  PC11

#define UART5_TX_PIN                  PC12  // Spare / GPS in concept
#define UART5_RX_PIN                  PD2

#define UART7_TX_PIN                  PE8
#define UART7_RX_PIN                  PE7

#define UART8_TX_PIN                  PE1
#define UART8_RX_PIN                  PE0

/* ---------------- IO / Misc ---------------- */

#define BEEPER_PIN           PA8

#define RX_PPM_PIN           PA15

/* ---------------- Motors (TIM5: PA0-PA3, TIM4: PD12-PD15) ---------------- */

#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PD12
#define MOTOR6_PIN           PD13
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15

#define TIMER_PIN_MAPPING \
    /* idx  pin       occ  dma */ \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 2,  0 ) /* PA0  -> TIM5_CH1 (DMA1-0) */ \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 2,  1 ) /* PA1  -> TIM5_CH2 (DMA1-1) */ \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 2,  2 ) /* PA2  -> TIM5_CH3 (DMA1-2) */ \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 2,  3 ) /* PA3  -> TIM5_CH4 (DMA1-3) */ \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 1,  6 ) /* PD12 -> TIM4_CH1 (DMA1-6) */ \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 1,  7 ) /* PD13 -> TIM4_CH2 (DMA1-7) */ \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 1,  4 ) /* PD14 -> TIM4_CH3 (DMA1-4) */ \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 1, -1 ) /* PD15 -> TIM4_CH4 (DMA1-3) */ \
    TIMER_PIN_MAP( 8, RX_PPM_PIN, 1, -1 ) /* PA15 -> TIM2_CH1, no DMA */

/* ---------------- ADC / Power ---------------- */

#define ADC_VBAT_PIN            PC0
#define ADC_CURR_PIN            PC1
#define ADC_EXTERNAL1_PIN       PC4
#define ADC_EXTERNAL2_PIN       PC5

// #define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
// #define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     19
#define DEFAULT_VOLTAGE_METER_DIVIDER   1
#define DEFAULT_CURRENT_METER_SCALE     0

#define ADC1_DMA_OPT                    8
#define ADC2_DMA_OPT                    9
#define ADC3_DMA_OPT                    10

#define LED0_PIN                      PA4
#define LED1_PIN                      PB1
#define LED0_INVERTED
#define LED1_INVERTED
