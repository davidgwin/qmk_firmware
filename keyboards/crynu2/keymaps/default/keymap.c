// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "progmem.h"
#include "crynu_display.h"
#include <stdio.h>

#define CRYNU_DYNAMIC_SIZE 128
#define _QWERTY 0
#define _COLMAK 1  // 2
#define _LPURPLE 2 // 4
#define _LGREEN 3  // 8
#define _LYELLOW 4 // 16
#define _LAZURE 5  // 32
#define _LCYAN 6   // 64
#define _LSYSL 7   // 128
#define LGREEN MO(_LGREEN)
#define LPURPLE MO(_LPURPLE)
#define LYELLOW MO(_LYELLOW)
#define TGCLMK TG(_COLMAK)
#define TYELLOW TG(_LYELLOW)
#define LAZURE MO(_LAZURE)
#define TAZURE TG(_LAZURE)
#define LCYAN MO(_LCYAN)
#define LSYSL MO(_LSYSL)

#define CY_QUOT LT(_LCYAN, KC_QUOT)
#define RSG_BKT RSG_T(KC_LBRC)
#define PRPL_BSP LT(_LPURPLE, KC_BSPC)
#define PRPL_DEL LT(_LPURPLE, KC_DEL)
#define KM_DLFT LGUI(LCTL(KC_LEFT))
#define KM_DRGT LGUI(LCTL(KC_RIGHT))
#define CTSHESC C_S_T(KC_ESC)
#define SFTALT LSFT(KC_LALT)
#define AZ_CAPS LT(_LAZURE, KC_CAPS)

bool show_alternate = false;

enum custom_keycodes {
    C_UPDAT = SAFE_RANGE,
    C_COMPI,
    C_FLASH,
    EMAIL1,
    EMAIL2,
    EMAIL3,
    EMAIL4
     };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │   ~   │   1   │   2   │   3   │   4   │   5   │                                                   │   6   │   7   │   8   │   9   │  0    │  -    │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │  tab  │   q   │   w   │   e   │   r   │   t   │                                                   │   y   │   u   │   i   │   o   │   p   │  =    │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ caps  │   a   │   s   │   d   │   f   │   g   │                                                   │   h   │   j   │   k   │   l   │   ;   │  '    │
 *     │ azure │       │       │       │       │       │                                                   │       │       │       │       │       │ cyan  │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ shift │   z   │   x   │   c   │   v   │   b   │                                                   │   n   │   m   │   ,   │   .   │   /   │ shift │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼──────┬──────╮                       ╭──────┬──────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ ctrl  │  win  │  alt  │ cyan  │ yellow│  del  │ enter│ esc  │                       │ azure│ space│ bkspc │purple │  [    │   ]   │   \   │ ctrl  │
 *     │       │       │       │       │       │       │purple│ c_s  │                       │      │      │       │       │       │       │       │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼──────┼──────┤                       ├──────┼──────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │ green│  esc │                       │yellow│ green│   
 *                                                     ╰──────┴──────╯                       ╰──────┴──────╯
 *     
 ************************************************************************************************************************************************************/
    [_QWERTY]  = LAYOUT(/* qwerty */
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                        KC_6,    KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                        KC_Y,    KC_U,  KC_I,   KC_O,   KC_P,   KC_EQL ,
        AZ_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                        KC_H,    KC_J,  KC_K,   KC_L,   KC_SCLN,CY_QUOT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                                        KC_N,    KC_M,  KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,LCYAN,LYELLOW,PRPL_DEL,KC_ENT, CTSHESC,                    LAZURE,KC_SPC,PRPL_BSP,  SFTALT,RSG_BKT,KC_RBRC,KC_BSLS,  KC_RCTL,
                                                           LGREEN,KC_SPC,                   LYELLOW,LGREEN
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │       │       │       │       │       │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │    F  │   P   │   G   │                                                   │   J   │   L   │   U   │   Y   │  ;    │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │    R  │    S  │   T   │   D   │                                                   │   H   │   N   │   E   │   I   │  O    │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                   │   K   │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼──────┬──────╮                       ╭──────┬──────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │      │      │                       │      │BK SPC│ SPACE │       │       │       │       │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼──────┼──────┤                       ├──────┼──────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │      │      │                       │      │      │   
 *                                                     ╰──────┴──────╯                       ╰──────┴──────╯
 *    
 ************************************************************************************************************************************************************/

    [_COLMAK]  = LAYOUT(
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_F   ,KC_P   ,KC_G   ,                                                    KC_J   ,KC_L   ,KC_U  ,KC_Y   ,KC_SCLN ,_______,
        _______,_______,KC_R   ,KC_S   ,KC_T   ,KC_D   ,                                                    KC_H   ,KC_N   ,KC_E   , KC_I, KC_O    ,_______,
        _______,_______,_______,_______,_______,_______,                                                    KC_K   ,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                    _______,KC_BSPC,KC_SPC ,_______,_______,_______,_______,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │  F12  │   F1  │   F2  │   F3  │   F4  │   F5  │                                                   │   F6  │   F7  │   F8  │   F9  │   F10 │   F11 │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   {   │   }   │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   [   │   ]   │       │                                                   │  LEFT │  DOWN │  UP   │ RIGHT │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   (   │   )   │       │                                                   │       │ WS <  │       │  WS > │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                   ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │  MENU │       │       │       │       │       │       │                   │       │       │       │       │       │       │       │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                   ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                   │       │       │   
 *                                                     ╰───────┴───────╯                   ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LPURPLE] = LAYOUT(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3   ,KC_F4  ,KC_F5  ,                                                   KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,_______,_______,KC_LCBR ,KC_RCBR,_______,                                                   _______,_______,_______,_______,_______,KC_PIPE,
        _______,_______,_______,KC_LBRC ,KC_RBRC,_______,                                                   KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
        _______,_______,_______,KC_LPRN ,KC_RPRN,_______,                                                   _______,KM_DLFT,_______,KM_DRGT,_______,_______,
        _______,KC_APP , _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,_______,_______,
                                                         _______,_______,                   _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                  ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │  F24  │  F13  │  F14  │  F15  │  F16  │  F17  │                                                  │  F18  │  F19  │  F20  │  F21  │  F22  │  F23  │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │  LEFT │  DOWN │   UP  │ RIGHT │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │       │  STOP │  PLAY │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                  ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │TG AZUR│       │       │       │                  │       │       │       │  PREV │ VOLUP │ VOLDN │  NEXT │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                  │       │       │   
 *                                                     ╰───────┴───────╯                  ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LGREEN]  = LAYOUT(
        KC_F24 ,KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,                                                    KC_F18 ,KC_F19 ,KC_F20 ,KC_F21 ,KC_F22 ,KC_F23 ,
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                    KC_LEFT,KC_DOWN,KC_UP ,KC_RIGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,KC_MSTP,KC_MPLY,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                  ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │R STOP │R1 PLAY│R2 PLAY│       │       │       │                                                  │SCL LCK│NUM LCK│   +   │   *   │   -   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │R1 REC │R2 REC │       │       │       │                                                  │INSERT │    7  │    8  │    9  │   +   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │    4  │    5  │    6  │   .   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │    1  │    2  │    3  │   =   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                  ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │       │       │                  │       │       │       │    0  │    0  │   .   │ ENTER │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                  │       │       │   
 *                                                     ╰───────┴───────╯                  ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LYELLOW] = LAYOUT(
        DM_RSTP,DM_PLY1,DM_PLY2,_______,_______,_______,                                                    KC_SCRL,KC_NUM ,KC_PSLS,KC_PAST,KC_PMNS,_______,
        _______,DM_REC1,DM_REC2,_______,_______,_______,                                                    KC_INS ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,KC_P0  ,KC_P0  ,KC_PDOT,KC_PENT,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │       │       │       │       │       │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   W   │   E   │       │                                                   │       │       │  INS  │       │PRNTSCN│       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │   G   │   A   │   S   │   D   │  F    │                                                   │ HOME  │ PG DN | PG UP │  END  │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                   ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │       │       │                   │       │       │       │       │       │       │       │ LSYSL │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                   ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                   │       │       │   
 *                                                     ╰───────┴───────╯                   ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LAZURE]  = LAYOUT(
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,KC_E   ,KC_W   ,_______,_______,                                                    _______,_______, KC_INS,_______,KC_PSCR,_______,
        _______,KC_F   ,KC_A   ,KC_S   ,KC_D   ,_______,                                                    KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,KC_SPC ,_______,_______,                    _______,_______,_______,_______,_______,_______,_______,_______,
                                                        KC_L   ,KC_LALT,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │       │EMAIL 1│EMAIL 2│EMAIL 3│EMAIL 4│       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │ UPDATE│       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │FLASH  │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │COMPILE│       │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                  ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ LSYSL │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                  │       │       │   
 *                                                     ╰───────┴───────╯                  ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LCYAN]   = LAYOUT (
        _______,EMAIL1 ,EMAIL2 ,EMAIL3 ,EMAIL4 ,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,C_UPDAT,_______,_______,_______,_______,
        _______,_______,_______,_______,C_FLASH,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,C_COMPI,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        LSYSL  ,_______,_______,_______,_______,_______,_______,_______,                    TAZURE ,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                  ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │       │       │       │       │       │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │ RESET │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │COLEMAK│       │       │                                                  │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                  ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │       │       │                  │       │       │       │       │       │       │       │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                  │       │       │   
 *                                                     ╰───────┴───────╯                  ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LSYSL]   = LAYOUT(
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,QK_BOOT,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,TGCLMK ,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,                    _______,_______
    )
};

// static int8_t crynu_dynamic1 = 0;
// static int8_t crynu_dynamic2 = 0;
static int8_t dynamic_current = 0;
static bool crynu_rec = false;
static int enter_ani = 0;

void dynamic_macro_record_start_user(int8_t direction)
{
    crynu_rec = true;
    dynamic_current = direction;
}


void dynamic_macro_record_end_user(int8_t direction)
{   
    crynu_rec = false;
}


void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record)
{
    
}

// process_record_user is called each time the keyboard matrix is read.
bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) {
        case KC_ENTER:
         // Play a tone when enter is pressed
            if (record->event.pressed) 
            {
                enter_ani = 1;
            }
            return true; // Let QMK send the enter press/release events
        case C_UPDAT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("sudo apt update && sudo apt upgrade");
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case C_COMPI:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("qmk compile -kb crynu2 -km default");
            } else {
                // when keycode QMKBEST is released
            }
            break;

         case C_FLASH:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(" qmk flash -kb crynu2 -km default");
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case EMAIL1:
            if (record->event.pressed) {
                SEND_STRING("david@gwin.world");
            } else {
            }
            break;
        case EMAIL2:
            if (record->event.pressed) {
                SEND_STRING("david.gwin@fleetpride.com");
            } else {
            }
            break;
        case EMAIL3:
            if (record->event.pressed) {
                SEND_STRING("davidgwin123@gmail.com");
            } else {
            }
            break;
        case EMAIL4:
            if (record->event.pressed) {
                SEND_STRING("davidgwin@outlook.com");
            } else {
            }
            break;
        // case M_COLEMAK:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_PURPLE:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_GREEN:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_YELLOW:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_AZURE:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_CYAN:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
        // case M_LSYSL:
        //     if (record->event.pressed) {
                
        //     } else {
        //     }
        //     break;
    }

    return true;
};

#ifdef OLED_ENABLE


    static const short end = 128;

static char gun [] = {
        0x01,0x02,0x03
    };
static char shot [4] = {
        0x06,0x07,0x08,0x09
    };

bool oled_task_user(void) 
{
    char rawbuf[128];
    char *layerText;
    led_t led_state = host_keyboard_led_state();

    switch (get_highest_layer(layer_state)) 
    {
        case _LPURPLE:
            layerText = "Purple";
            break;
        case _LGREEN:
            layerText = "Green";
            break;
        case _LYELLOW:
            layerText = "Yellow";
            break;
        case _LAZURE:
            layerText = "Azure";
            break;
        case _LCYAN:
            layerText = "Cyan";
            break;
        case _LSYSL:
            layerText = "LSYSL";
            break;
        default:
            if (layer_state & 2) {
            layerText = "Colemak";
            } else {
            layerText = "Crynu";
            }
    }
    
    int locks = 0;

    if(led_state.num_lock)
    {
        locks = locks | NUM;
    }
    if(led_state.caps_lock)
    {
        locks = locks | CAPS;
    }
    if(led_state.scroll_lock)
    {
        locks = locks | SCROLL;
    }
    if(crynu_rec)
    {
        locks = locks | REC;
    }
    setLocks(locks);

    if(show_alternate)
    {
        // oled_set_cursor(0,0);
        // oled_write_ln(show_alternate_message_1, false);
        // oled_write_ln(show_alternate_message_2, false);
        // oled_write_ln(show_alternate_message_3, false);
        // oled_write_ln(show_alternate_message_4, false);

    }
    else
    {
        for(short i=0; i<4; ++i)
        {

            oled_set_cursor(0,i);
            if(i < 2)
            {
                largeFont(layerText, i, rawbuf);
            }
            else 
            {
                if(enter_ani && i>2)
                {

                    /**
                     * tank at char 01, 02, 03
                     * projectile at 04 - 9. Locations 4 and 5 are frame 3 and 4. Locations 5-9 are to be incremented through. 
                    */
                
                    int enterIdx = 0;
                    char ani[MAX_SMALL_CHARACTERS];
                    if(enter_ani < 18)
                    {
                        enterIdx = enter_ani/7;                        
                        ani[0] = gun[enterIdx];
                        ani[1] = enterIdx == 2 ? 0x04 : 0x20;

                    }
                    else
                    {
                        enterIdx = (enter_ani-18)/2  ;
                        for(int j=1; j<MAX_SMALL_CHARACTERS; ++j)
                        {
                            if(enterIdx == j)
                            {
                                ani[j] = shot[enterIdx % 4];                                
                            }
                            else ani[j] = 0x20;
                        }
                        ani[0] = gun[2];
                    }
                    
                    smallFont(ani,rawbuf);
                    ++enter_ani;
                    if(enterIdx > MAX_SMALL_CHARACTERS) 
                    {
                        enter_ani = 0;
                    }
                }
                else
                {
                    char layers[10];
                    layers[0] = layer_state & 2   ? 0x07 :' ';
                    layers[1] = layer_state & 4   ? 0x0F :' ';
                    layers[2] = layer_state & 8   ? 0x0e :' ';
                    layers[3] = layer_state & 16  ?  '#' :' ';
                    layers[4] = layer_state & 32  ? 0x10 :' ';
                    layers[5] = layer_state & 64  ? 0x11 :' ';
                    layers[6] = layer_state & 128 ? 0x15 :' ';
                    layers[7] = 0;
                    largeFont(layers, i % 2, rawbuf);
                }


                
                
            }
            getLockStateImage(i,rawbuf);

            oled_write_raw_P(rawbuf, sizeof(rawbuf));
        }    
    }
    return false;
};

#endif
