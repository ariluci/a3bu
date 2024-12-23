/**
 * \file
 *
 * \brief XMEGA-A3BU-XPLAINED board header file.
 *
 * This file contains definitions and services related to the features of the
 * XMEGA-A3BU Xplained board.
 *
 * To use this board define BOARD=XMEGA_A3BU_XPLAINED.
 *
 * Copyright (c) 2011 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an Atmel
 *    AVR product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
#ifndef _XMEGA_A3BU_XPLAINED_H_
#define _XMEGA_A3BU_XPLAINED_H_

#include <compiler.h>

/**
 * \defgroup xmega_a3bu_xplained_group XMEGA-A3BU Xplained board
 * @{
 */

/**
 * \defgroup xmega_a3bu_xplained_feature_group Feature definitions
 * @{
 */

//! \name Miscellaneous data
//@{
//! Validate board support for the common sensor service.
#define COMMON_SENSOR_PLATFORM
//@}

/**
 * \name LEDs
 *
 * LED0 and LED1 are single yellow LEDs that are active low..
 * LED2 and LED3 are inside one package (Led red and green close
 * to USB connector) but can be controlled individually.
 * LED2 has a red color and is active low. This LED can be
 * used for general purposes.
 * LED3 has a green color and is active high. By default this
 * LED is on since it shall indicate that power is applied to the
 * board. By pulling the gate of a N-FET low it is possible to
 * turn off the LED if needed.
 */
//@{
#define LED0_GPIO                       IOPORT_CREATE_PIN(PORTR, 0)
#define LED1_GPIO                       IOPORT_CREATE_PIN(PORTR, 1)
#define LED2_GPIO                       IOPORT_CREATE_PIN(PORTD, 4)
#define LED3_GPIO                       IOPORT_CREATE_PIN(PORTD, 5)
#define LED0                            LED0_GPIO
#define LED1                            LED1_GPIO
#define LED2                            LED2_GPIO
#define LED3                            LED3_GPIO
//! Number of LEDs.
#define LED_COUNT                       4
//@}

//! \name Push buttons
//@{
#define GPIO_PUSH_BUTTON_0              IOPORT_CREATE_PIN(PORTE, 5)
#define GPIO_PUSH_BUTTON_1              IOPORT_CREATE_PIN(PORTF, 1)
#define GPIO_PUSH_BUTTON_2              IOPORT_CREATE_PIN(PORTF, 2)
//@}

//! \name QTouch button
//@{
#define QTOUCH_BUTTON_SNS               IOPORT_CREATE_PIN(PORTF, 6)
#define QTOUCH_BUTTON_SNSK              IOPORT_CREATE_PIN(PORTF, 7)
//@}

//! \name Light sensor
//@{
#define LIGHT_SENSOR_ADC_MODULE         ADCA
#define LIGHT_SENSOR_ADC_INPUT          ADCCH_POS_PIN0
#define LIGHT_SENSOR_SIGNAL_PIN         IOPORT_CREATE_PIN(PORTA, 0)
//@}

//! \name Temperature sensor (NTC)
//@{
#define TEMPERATURE_SENSOR_ADC_MODULE   ADCA
#define TEMPERATURE_SENSOR_ADC_INPUT    ADCCH_POS_PIN1
#define TEMPERATURE_SENSOR_SIGNAL_PIN   IOPORT_CREATE_PIN(PORTA, 1)
//@}

//! \name Analog filter (lowpass RC @ 159 Hz)
//@{
#define FILTER_INPUT_SIGNAL_PIN         IOPORT_CREATE_PIN(PORTF, 0)
#define FILTER_OUTPUT_ADC_MODULE        ADCA
#define FILTER_OUTPUT_ADC_INPUT         ADCCH_POS_PIN2
#define FILTER_OUTPUT_SIGNAL_PIN        IOPORT_CREATE_PIN(PORTA, 2)
//@}

//! \name LCD backlight
//@{
#define LCD_BACKLIGHT_ENABLE_PIN        IOPORT_CREATE_PIN(PORTE, 4)
#define LCD_BACKLIGHT_ENABLE_LEVEL      true
//@}

//! \name LCD controller (NHD-C12832A1Z-FSW-FBW-3V3)
//@{
#define NHD_C12832A1Z_SPI               &USARTD0
#define NHD_C12832A1Z_SPI_SCK	        IOPORT_CREATE_PIN(PORTD, 1)
#define NHD_C12832A1Z_SPI_MOSI          IOPORT_CREATE_PIN(PORTD, 3)
#define NHD_C12832A1Z_CSN               IOPORT_CREATE_PIN(PORTF, 3)
//! If this signal is set high display data is sent otherwise commands
#define NHD_C12832A1Z_REGISTER_SELECT   IOPORT_CREATE_PIN(PORTD, 0)
#define NHD_C12832A1Z_RESETN            IOPORT_CREATE_PIN(PORTA, 3)
//! The backlight is active high
#define NHD_C12832A1Z_BACKLIGHT         IOPORT_CREATE_PIN(PORTE, 4)
//@}

//! \name LCD dimensions
//@{
#define LCD_WIDTH_PIXELS                (128)
#define LCD_HEIGHT_PIXELS               (32)
//@}

//! \name DataFlash memory (AT45DBX)
//@{
#define AT45DBX_SPI                     &USARTD0
#define AT45DBX_CS                      IOPORT_CREATE_PIN(PORTF, 4)
//! SCK pin
#define AT45DBX_MASTER_SCK              IOPORT_CREATE_PIN(PORTD, 1)
//! MOSI pin
#define AT45DBX_MASTER_MOSI             IOPORT_CREATE_PIN(PORTD, 3)
//! MISO pin
#define AT45DBX_MASTER_MISO		IOPORT_CREATE_PIN(PORTD, 2)
//@}

/**
 * \name External oscillator
 *
 * \todo Need to measure the actual startup time on the hardware.
 */
//@{
#define BOARD_XOSC_HZ                   32768
#define BOARD_XOSC_TYPE                 XOSC_TYPE_32KHZ
#define BOARD_XOSC_STARTUP_US           1000000
//@}

//! \name Communication interfaces on header J1
//@{
#define TWIC_SDA                        IOPORT_CREATE_PIN(PORTC, 0)
#define TWIC_SCL                        IOPORT_CREATE_PIN(PORTC, 1)
#define USARTC0_RXD                     IOPORT_CREATE_PIN(PORTC, 2)
#define USARTC0_TXD                     IOPORT_CREATE_PIN(PORTC, 3)
#define SPIC_SS                         IOPORT_CREATE_PIN(PORTC, 4)
#define SPIC_MOSI                       IOPORT_CREATE_PIN(PORTC, 5)
#define SPIC_MISO                       IOPORT_CREATE_PIN(PORTC, 6)
#define SPIC_SCK                        IOPORT_CREATE_PIN(PORTC, 7)
//@}

/**
 * \name Pin connections on header J1
 *
 * The whole port C is directly connected to J1.
 *
 * \note For the TWI lines there are footprints for pull up resistors, which
 * are by default not mounted on the board.
 */
//@{
#define J1_PIN0                        IOPORT_CREATE_PIN(PORTC, 0)
#define J1_PIN1                        IOPORT_CREATE_PIN(PORTC, 1)
#define J1_PIN2                        IOPORT_CREATE_PIN(PORTC, 2)
#define J1_PIN3                        IOPORT_CREATE_PIN(PORTC, 3)
#define J1_PIN4                        IOPORT_CREATE_PIN(PORTC, 4)
#define J1_PIN5                        IOPORT_CREATE_PIN(PORTC, 5)
#define J1_PIN6                        IOPORT_CREATE_PIN(PORTC, 6)
#define J1_PIN7                        IOPORT_CREATE_PIN(PORTC, 7)
//@}

/**
 * \name Pin connections on header J2
 *
 * The upper half of port A is connected to the lower pins of J2 while the
 * lower half of port B is connected to the upper pins of J2.
 *
 * The port pins are connected directly to this header and are not shared with
 * any on-board functionality.
 */
//@{
#define J2_PIN0                        IOPORT_CREATE_PIN(PORTA, 4)
#define J2_PIN1                        IOPORT_CREATE_PIN(PORTA, 5)
#define J2_PIN2                        IOPORT_CREATE_PIN(PORTA, 6)
#define J2_PIN3                        IOPORT_CREATE_PIN(PORTA, 7)
#define J2_PIN4                        IOPORT_CREATE_PIN(PORTB, 0)
#define J2_PIN5                        IOPORT_CREATE_PIN(PORTB, 1)
#define J2_PIN6                        IOPORT_CREATE_PIN(PORTB, 2)
#define J2_PIN7                        IOPORT_CREATE_PIN(PORTB, 3)
//@}

/**
 * \name Pin connections on header J3
 *
 * The lower half of port A is connected to the lower pins of J3 and the upper
 * half of port B is connected to the upper pins of J3.
 *
 * Follwing pins are shared with on-board functionality:
 *  - J3_PIN0 Light sensor output (can be disconnected via scratch pad)
 *  - J3_PIN1 NTC sensor output (can be disconnected via scratch pad)
 *  - J3_PIN2 Filter ouptput (can be disconnected via scratch pad)
 *  - J3_PIN3 Display reset input (can't be used when display is in use)
 *  - J3_PIN4 JTAG TMS (pin can't be used while JTAG device connected)
 *  - J3_PIN5 JTAG TDI (pin can't be used while JTAG device connected)
 *  - J3_PIN6 JTAG TCK (pin can't be used while JTAG device connected)
 *  - J3_PIN7 JTAG TDO & PID DATA (pin can't be used while JTAG/PDI device is
 *            connected)
 */
//@{
#define J3_PIN0                        IOPORT_CREATE_PIN(PORTA, 0)
#define J3_PIN1                        IOPORT_CREATE_PIN(PORTA, 1)
#define J3_PIN2                        IOPORT_CREATE_PIN(PORTA, 2)
#define J3_PIN3                        IOPORT_CREATE_PIN(PORTA, 3)
#define J3_PIN4                        IOPORT_CREATE_PIN(PORTB, 4)
#define J3_PIN5                        IOPORT_CREATE_PIN(PORTB, 5)
#define J3_PIN6                        IOPORT_CREATE_PIN(PORTB, 6)
#define J3_PIN7                        IOPORT_CREATE_PIN(PORTB, 7)
//@}

/**
 * \name Pin connections on header J4
 *
 * The lower half of port E is connected to the lower pins of J4 and the upper
 * half of port B is connected to the upper pins of J3.
 */
//@{
#define J4_PIN0                        IOPORT_CREATE_PIN(PORTE, 0)
#define J4_PIN1                        IOPORT_CREATE_PIN(PORTE, 1)
#define J4_PIN2                        IOPORT_CREATE_PIN(PORTE, 2)
#define J4_PIN3                        IOPORT_CREATE_PIN(PORTE, 3)
#define J4_PIN4                        IOPORT_CREATE_PIN(PORTC, 4)
#define J4_PIN5                        IOPORT_CREATE_PIN(PORTC, 5)
#define J4_PIN6                        IOPORT_CREATE_PIN(PORTC, 6)
#define J4_PIN7                        IOPORT_CREATE_PIN(PORTC, 7)
//@}

/**
 * @}
 */

/**
 * \defgroup xmega_a3bu_xplained_config_group Configuration options
 * @{
 */

#if defined(__DOXYGEN__)

/**
 * \name Initialization
 * \note Define these symbols in \ref conf_board.h to enable the corresponding
 * features.
 */
//@{

/**
 * \def CONF_BOARD_C12832A1Z
 * \brief Initialize SPI and control pins for C12832A1Z LCD controller
 */
#  if !defined(CONF_BOARD_C12832A1Z)
#    define CONF_BOARD_C12832A1Z
#  endif

/**
 * \def CONF_BOARD_AT45DBX
 * \brief Initialize SPI pins for AT45DBX DataFlash
 */
#  if !defined(CONF_BOARD_AT45DBX)
#    define CONF_BOARD_AT45DBX
#  endif

/**
 * \def CONF_BOARD_ENABLE_AC_PINS
 * \brief Initialize IO pins for Analog Comparator
 *
 * \note This initializes pins PA0, PA2 and PB1 as inputs.
 */
#  if !defined(CONF_BOARD_ENABLE_AC_PINS)
#    define CONF_BOARD_ENABLE_AC_PINS
#  endif

/**
 * \def CONF_BOARD_ENABLE_USARTC0
 * \brief Initialize IO pins for USART 0 on port C
 */
#  if !defined(CONF_BOARD_ENABLE_USARTC0)
#    define CONF_BOARD_ENABLE_USARTC0
#  endif

/**
 * \def CONF_BOARD_ENABLE_USARTD0
 * \brief Initialize IO pins for USART 0 on port D
 */
#  if !defined(CONF_BOARD_ENABLE_USARTD0)
#    define CONF_BOARD_ENABLE_USARTD0
#  endif

//@}

#endif // __DOXYGEN__

/**
 * @}
 */

/**
 * @}
 */

#endif /* _XMEGA_A3BU_XPLAINED_H_ */
