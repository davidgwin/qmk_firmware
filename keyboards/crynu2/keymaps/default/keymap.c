// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "progmem.h"
#include "crynu_display.h"
#include <stdio.h>
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define CRYNU_DYNAMIC_SIZE 128
#define _QWERTY 0
#define _COLMAK 1
#define _LPURPLE 2
#define _LGREEN 3
#define _LYELLOW 4
#define _LAZURE 5
#define _LCYAN 6
#define _LSYSL 7

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
#define RG_CAPS RGUI_T(KC_CAPS)
#define CTL_ENT LCTL_T(KC_ENT)
#define CTR_ENT RCTL_T(KC_ENT)
#define CTL_SPC LCTL_T(KC_SPC)
#define CTR_SPC RCTL_T(KC_SPC)
#define STL_SPC LSFT_T(KC_SPC)
#define STL_CAP LSFT_T(KC_CAPS)
#define STR_SPC RSFT_T(KC_SPC)
#define LVY_ENT LT(_LYELLOW, KC_ENT)
#define LVP_ENT LT(_LPURPLE, KC_ENT)
#define LVN_ESC LT(_LYELLOW, KC_ESC)
#define D_AZURE LT(_LAZURE, KC_DEL)
#define E_AZURE LT(_LAZURE, KC_ENT)
#define D_CYAN LT(_LCYAN, KC_DEL)
#define B_AZURE LT(_LAZURE, KC_BSPC)
#define K_CYAN LT(_LCYAN, KC_K)
#define FLPURPLE LT(_LPURPLE, KC_F)
#define PRPL_BSP LT(_LPURPLE, KC_BSPC)
#define PL_SPC LT(_LPURPLE, KC_SPC)
#define PRPL_DEL LT(_LPURPLE, KC_DEL)
#define YEL_DEL LT(_LYELLOW, KC_DEL)
#define GRN_BSP LT(_LGREEN, KC_BSPC)
#define GRN_DEL LT(_LGREEN, KC_DEL)
#define GRN_CAP LT(_LGREEN, KC_CAPS)
#define ALT_RGT RALT_T(KC_RGHT)
#define A_SHFT RSFT_T(KC_A)
#define CL_SHFT RSFT_T(KC_SCLN)
#define KM_DLFT LGUI(LCTL(KC_LEFT))
#define KM_DRGT LGUI(LCTL(KC_RIGHT))
#define GUI_L LGUI(KC_L)
#define GUI_E LGUI(KC_E)
#define GUI_LEFT LGUI(KC_LEFT)
#define GUI_RIGHT LGUI(KC_RIGHT)
#define GUI_L LGUI(KC_L)
#define CTSHESC C_S_T(KC_ESC)

#define AZ_CAPS LT(_LAZURE, KC_CAPS)

bool enter = false, squid = false, ball = false, half = false;

enum custom_keycodes {
    C_UPDAT = SAFE_RANGE,
    C_COMPI,
    C_FLASH,
    EMAIL1,
    EMAIL2,
    EMAIL3,
    EMAIL4,
    FIRE,
    SQUID,
    BALL };

// enum combos { FG_COMB, DF_COMB, SD_COMB, JK_COMB, KL_COMB, E1_COMB, E2_COMB, E3_COMB, XC_COMB, VC_COMB, MCM_COMB, CMDT_COMB, SYSL_COMB, COMBO_LENGTH };

// uint16_t               COMBO_LEN    = COMBO_LENGTH;
// const uint16_t PROGMEM sd_combo[]   = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM df_combo[]   = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM fg_combo[]   = {KC_F, KC_G, COMBO_END};
// const uint16_t PROGMEM jk_combo[]   = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM kl_combo[]   = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM e1_combo[]   = {KC_E, KC_F, KC_1, COMBO_END};
// const uint16_t PROGMEM e2_combo[]   = {KC_E, KC_F, KC_2, COMBO_END};
// const uint16_t PROGMEM e3_combo[]   = {KC_E, KC_F, KC_3, COMBO_END};
// const uint16_t PROGMEM xc_combo[]   = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM cv_combo[]   = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM mcm_combo[]  = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM sysl_combo[] = {KC_GRAVE, KC_1, KC_2, COMBO_END};

// combo_t key_combos[] = {
//     [DF_COMB] = COMBO(df_combo, LCTL(KC_LSFT)),
//     [SD_COMB] = COMBO(sd_combo, LCTL(KC_LALT)),
//     [JK_COMB] = COMBO(jk_combo, RCTL(KC_RSFT)),
//     [KL_COMB] = COMBO(kl_combo, RCTL(KC_RALT)),
//     [E1_COMB] = COMBO(e1_combo, EMAIL1),
//     [E2_COMB] = COMBO(e2_combo, EMAIL2),
//     [E3_COMB] = COMBO(e3_combo, EMAIL3),
//     [XC_COMB] = COMBO(xc_combo, LYELLOW),
//     [VC_COMB] = COMBO(cv_combo, LGREEN),
//     [MCM_COMB] = COMBO(mcm_combo, LGREEN),
//     [CMDT_COMB] = COMBO(cmdt_combo, LYELLOW),
//     [SYSL_COMB] = COMBO(sysl_combo, LSYSL),
//     [FG_COMB] = COMBO(fg_combo, KC_GRV), // for some reason KC_GRV is ESC in the combo?
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │   ~   │   1   │   2   │   3   │   4   │   5   │                                                   │   6   │   7   │   8   │   9   │  0    │  -    │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │  tab  │   q   │   w   │   e   │   r   │   t   │                                                   │   y   │   u   │   i   │   o   │   p   │  =    │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                              a                     ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ caps  │   a   │   s   │   d   │   f   │   g   │                                                   │   h   │   j   │   k   │   l   │   ;   │  '    │
 *     │ azure │       │       │       │       │       │                                                   │       │       │       │       │       │ cyan  │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ shift │   z   │   x   │   c   │   v   │   b   │                                                   │   n   │   m   │   ,   │   .   │   /   │ shift │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼──────┬──────╮                       ╭──────┬──────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │ ctrl  │  win  │  alt  │yellow │ yellow│  del  │ enter│ esc  │                       │ azure│ space│ bkspc │purple │  [    │   ]   │   \   │ ctrl  │
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
        KC_LCTL,KC_LGUI,KC_LALT,LCYAN,LYELLOW,KC_DEL, LVP_ENT, CTSHESC,                    LAZURE,PL_SPC,KC_BSPC,LPURPLE,KC_LBRC,KC_RBRC,KC_BSLS,KC_RCTL,
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
 *     │       │       │       │       │       │       │       │       │                   │       │       │       │       │       │       │       │       │
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
        _______,_______, _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,_______,_______,
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
        _______,_______,_______,_______,TAZURE ,_______,_______,_______,                    _______,_______,_______,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                  ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │R STOP │R1 PLAY│R2 PLAY│       │       │       │                                                  │SCL LCK│NUM LCK│   +   │   *   │   -   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │R1 REC │R2 REC │  UP   │       │       │                                                  │INSERT │    7  │    8  │    9  │   +   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │ LEFT  │  UP   │ RIGHT │       │                                                  │       │    4  │    5  │    6  │   .   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                  ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │ DOWN  │       │       │                                                  │       │    1  │    2  │    3  │   =   │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                  ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │       │       │                  │       │       │       │    0  │    0  │   .   │ ENTER │       │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                  ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                  │       │       │   
 *                                                     ╰───────┴───────╯                  ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LYELLOW] = LAYOUT(
        DM_RSTP,DM_PLY1,DM_PLY2,_______,_______,_______,                                                    KC_SCRL,KC_NUM ,KC_PSLS,KC_PAST,KC_PMNS,_______,
        _______,DM_REC1,DM_REC2,KC_UP  ,_______,_______,                                                    KC_INS ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,KC_LEFT,KC_UP  ,KC_RGHT,_______,                                                    _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,KC_DOWN,_______,_______,                                                    _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,KC_P0  ,KC_P0  ,KC_PDOT,KC_PENT,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                   ╭───────┬───────┬───────┬───────┬───────┬───────╮
 *     │       │       │       │       │       │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   W   │   E   │       │                                                   │       │       │  INS  │       │PRNTSCN│       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │   A   │   W   │   D   │       │                                                   │ HOME  │ PG DN | PG UP │  END  │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┤                                                   ├───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │   S   │       │       │                                                   │       │       │       │       │       │       │
 *     ├───────┼───────┼───────┼───────┼───────┼───────┼───────┬───────╮                   ╭───────┬───────┼───────┼───────┼───────┼───────┼───────┼───────┤
 *     │       │       │       │       │       │       │       │       │                   │       │       │       │       │       │       │       │ LSYSL │
 *     ╰───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┤                   ├───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────╯ 
 *                                                     │       │       │                   │       │       │   
 *                                                     ╰───────┴───────╯                   ╰───────┴───────╯
 *     
 ************************************************************************************************************************************************************/
    [_LAZURE]  = LAYOUT(
        _______,_______,_______,_______,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_W   ,KC_E   ,_______,                                                    _______,_______, KC_INS,_______,KC_PSCR,_______,
        _______,_______,KC_A   ,KC_W   ,KC_D   ,_______,                                                    KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,
        _______,_______,_______,KC_S   ,_______,_______,                                                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,KC_SPC ,_______,_______,                    _______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,                    _______,_______
    ),
/**
 *     ╭───────┬───────┬───────┬───────┬───────┬───────╮                                                  ╭───────┬───────┬───────┬───────┬───────┬───────╮
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
        LSYSL  ,_______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,_______,_______,
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
    }

    return true;
};

#ifdef OLED_ENABLE


    static const short end = 128;



bool oled_task_user(void) {


    char rawbuf[128];
    led_t led_state = host_keyboard_led_state();


    for(short i=0; i<4; ++i)
    {

        oled_set_cursor(0,i);
        

        switch (get_highest_layer(layer_state)) {
            case _LPURPLE:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_purple[i][j];
                }
                break;
            case _LGREEN:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_green[i][j];
                }
                break;
            case _LYELLOW:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_yellow[i][j];
                }
                break;
            case _LAZURE:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_azure[i][j];
                }
                break;
            case _LCYAN:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_cyan[i][j];
                }
                break;
            case _LSYSL:
                for(short j=0; j< end; ++j)
                {
                    rawbuf[j] = raw_lsysl[i][j];
                }
                break;
            default:
                if (layer_state & 2) {
                    // colmak
                    for(short j=0; j< end; ++j)
                    {
                        rawbuf[j] = raw_colmak[i][j];
                    }
                } else {
                    // qwerty
                    for(short j=0; j< end; ++j)
                    {
                        rawbuf[j] = raw_qwerty[i][j];
                    }
                }
        }

        short index = 96;

        if(i<2)
        {


            if(led_state.num_lock)
            {
                for(short j=0; j<16; ++j)
                {
                    rawbuf[index] = raw_num_lock[i][j];
                    ++index;
                }
            }
            index = 112;
            if(led_state.caps_lock)
            {
                for(short j=0; j<16; ++j)
                {
                    rawbuf[index] = raw_caps_lock[i][j];
                    ++index;
                }
            }
        }
        else
        {
            
            index = 112;
            if(led_state.scroll_lock)
            {
                for(short j=0; j<16; ++j)
                {
                    rawbuf[index] = raw_scroll_lock[i-2][j];
                    ++index;
                }
            }
            
            index = 94;
            char dyn_str[8];
            char dis_str[18];
        
            if(i == 2 )
            {
                if(crynu_rec)
                {
                    dyn_str[0] = 'R';
                    dyn_str[1] = 'E';
                    dyn_str[2] = 'C';
                }
                else 
                {
                    dyn_str[0] = ' ';
                    dyn_str[1] = ' ';
                    dyn_str[2] = ' ';
                }
                for(int h=0; h<3; ++h)
                {
                    for(int j = 0; j<6; ++j)
                    {
                        dis_str[j + h*6] = font[(dyn_str[h] * 6 )+j];
                    }
                }
                for(short j=0; j<18; ++j)
                {
                    rawbuf[index] = dis_str[j];
                    ++index;
                }
            }
        
            if(i == 3)
            {
                sprintf(dyn_str, "%3d", dynamic_current);
                for(int h=0; h<3; ++h)
                {
                    for(int j = 0; j<6; ++j)
                    {
                        dis_str[j + h*6] = font[(dyn_str[h] * 6 )+j];
                    }
                }
                for(short j=0; j<18; ++j)
                {
                    rawbuf[index] = dis_str[j];
                    ++index;
                }
            }
            

        }



        oled_write_raw_P(rawbuf, sizeof(rawbuf));
    }

    return false;
};

#endif
