/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"



/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define MATRIX_COL_PINS { B5,  B4,  A15,  B13,  B1, B0, B6, B7}
#define MATRIX_ROW_PINS {C13, C14, C15, B15, B14, A0, A1, A2}
#define RGB_DI_PIN B12
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// #define OLED_FONT_H drivers/oled/gwin_font.c
// Length in milliseconds for a combo to be recognized.
// #define COMBO_TERM 40
// #define COMBO_MUST_HOLD_MODS
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
// #ifdef OLED_ENABLEx
// #define OLED_DISPLAY_128X32
// #define I2C1_SCL_PIN        B9
// #define I2C1_SDA_PIN        B8
// #define OLED_BRIGHTNESS 128
// #define OLED_FONT_H "keyboards/crynu/crynu_font.c"
// #define OLED_FADE_OUT
// #define OLED_FADE_OUT_INTERVAL 15
// #define OLED_UPDATE_INTERVAL 100
// #define OLED_TIMEOUT 60000
// #define OLED_DISPLAY_ADDRESS 0x3C
// #endif



// #define I2C2_SCL_PIN        B10
// #define I2C2_SDA_PIN        B3
// #define I2C2_SCL_PIN        B9
// #define I2C2_SDA_PIN        B8
#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_SPI_CS_PIN A4
// #define CIRQUE_PINNACLE_SPI_LSBFIRST true

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
// #define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN A7
// #define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN A6
// #define SPI_MISO_PAL_MODE 5

#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

