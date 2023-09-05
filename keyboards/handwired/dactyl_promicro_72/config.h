/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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



/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { F6, F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION COL2ROW

/* USB Device descriptor parameter */

//#define MANUFACTURER    tshort

/* mouse config *//*
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0*/

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* ws2812 RGB LED */

#define RGBLIGHT_LAYERS
#define WS2812_DI_PIN  D3
#define RGBLED_NUM 16    // Number of LEDs
#define RGBLED_SPLIT {8,8}
#define RGBLIGHT_SPLIT
// #define SPLIT_LAYER_STATE_ENABLE
// if this pin is high it is the left low is the right.
#define SPLIT_HAND_PIN F5
#define RGBLIGHT_SLEEP
#define SPLIT_TRANSPORT_MIRROR
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


#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// #define MASTER_RIGHT

