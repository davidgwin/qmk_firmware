// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "progmem.h"
#include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

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
#define LCYAN MO(_LCYAN)
#define LSYSL MO(_LSYSL)

#define LG_QUOT LGUI_T(KC_QUOT)
#define RG_CAPS RGUI_T(KC_CAPS)
#define CTL_ENT LCTL_T(KC_ENT)
#define CTR_ENT RCTL_T(KC_ENT)
#define CTL_SPC LCTL_T(KC_SPC)
#define CTR_SPC RCTL_T(KC_SPC)
#define STL_SPC LSFT_T(KC_SPC)
#define STL_CAP LSFT_T(KC_CAPS)
#define STR_SPC RSFT_T(KC_SPC)
#define LVN_ESC LT(_LYELLOW, KC_ESC)
#define D_AZURE LT(_LAZURE, KC_DEL)
#define E_AZURE LT(_LAZURE, KC_ENT)
#define D_CYAN LT(_LCYAN, KC_DEL)
#define B_AZURE LT(_LAZURE, KC_BSPC)
#define K_CYAN LT(_LCYAN, KC_K)
#define FLPURPLE LT(_LPURPLE, KC_F)
#define PRPL_BSP LT(_LPURPLE, KC_BSPC)
#define PRPL_DEL LT(_LPURPLE, KC_DEL)
#define YEL_DEL LT(_LYELLOW, KC_DEL)
#define GRN_BSP LT(_LGREEN, KC_BSPC)
#define GRN_DEL LT(_LGREEN, KC_DEL)
#define GRN_CAP LT(_LGREEN, KC_CAPS)
#define ALT_RGT RALT_T(KC_RGHT)
#define A_SHFT RSFT_T(KC_A)
#define CL_SHFT RSFT_T(KC_SCLN)
#define KM_DLEFT LGUI(LCTL(KC_LEFT))
#define KM_DRIGHT LGUI(LCTL(KC_RIGHT))
#define GUI_L LGUI(KC_L)
#define GUI_E LGUI(KC_E)
#define GUI_LEFT LGUI(KC_LEFT)
#define GUI_RIGHT LGUI(KC_RIGHT)
#define GUI_L LGUI(KC_L)
#define CTSHESC C_S_T(KC_ESC)

#define AZ_CAPS LT(_LAZURE, KC_CAPS)

bool enter = false, squid = false, ball = false, half = false;

enum custom_keycodes { NOVELTY = SAFE_RANGE, BDSPSW, CURBDS, EMAIL1, EMAIL2, EMAIL3, FIRE, SQUID, BALL };

enum combos { FG_COMB, DF_COMB, SD_COMB, JK_COMB, KL_COMB, E1_COMB, E2_COMB, E3_COMB, XC_COMB, VC_COMB, MCM_COMB, CMDT_COMB, SYSL_COMB, COMBO_LENGTH };

uint16_t               COMBO_LEN    = COMBO_LENGTH;
const uint16_t PROGMEM sd_combo[]   = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[]   = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[]   = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM jk_combo[]   = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[]   = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM e1_combo[]   = {KC_E, KC_F, KC_1, COMBO_END};
const uint16_t PROGMEM e2_combo[]   = {KC_E, KC_F, KC_2, COMBO_END};
const uint16_t PROGMEM e3_combo[]   = {KC_E, KC_F, KC_3, COMBO_END};
const uint16_t PROGMEM xc_combo[]   = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcm_combo[]  = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM sysl_combo[] = {KC_GRAVE, KC_1, KC_2, COMBO_END};

combo_t key_combos[] = {
    [DF_COMB] = COMBO(df_combo, LCTL(KC_LSFT)), 
    [SD_COMB] = COMBO(sd_combo, LCTL(KC_LALT)),
    [JK_COMB] = COMBO(jk_combo, RCTL(KC_RSFT)), 
    [KL_COMB] = COMBO(kl_combo, RCTL(KC_RALT)), 
    [E1_COMB] = COMBO(e1_combo, EMAIL1), 
    [E2_COMB] = COMBO(e2_combo, EMAIL2), 
    [E3_COMB] = COMBO(e3_combo, EMAIL3), 
    [XC_COMB] = COMBO(xc_combo, LYELLOW),
    [VC_COMB] = COMBO(cv_combo, LGREEN), 
    [MCM_COMB] = COMBO(mcm_combo, LGREEN), 
    [CMDT_COMB] = COMBO(cmdt_combo, LYELLOW), 
    [SYSL_COMB] = COMBO(sysl_combo, LSYSL),
    [FG_COMB] = COMBO(fg_combo, KC_GRV), // for some reason KC_GRV is ESC in the combo?
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY]  = LAYOUT(/* qwerty */
       	KC_GRV, KC_1,  KC_2,   KC_3,   KC_4,   KC_5,						               KC_6,    KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS, 
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,						               KC_Y,    KC_U,  KC_I,   KC_O,   KC_P,   KC_EQL,
	STL_CAP,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,						               KC_H,    KC_J,  KC_K,   KC_L,   KC_SCLN,KC_QUOT,
	KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, 						               KC_N,    KC_M,  KC_COMM,KC_DOT, KC_SLSH,KC_RSFT, 
	CTL_ENT,KC_LGUI,KC_LALT,LVN_ESC,LGREEN, PRPL_BSP, STL_SPC, D_CYAN,		        LAZURE, KC_SPC, PRPL_BSP,LGREEN,KC_LBRC,KC_RBRC,KC_BSLS,CTR_ENT
	),
	
        [_COLMAK]  = LAYOUT(
	_______,_______,_______,_______,_______,_______,		                                       _______,_______,_______,_______,_______,_______,
	_______,_______,_______,KC_F   ,KC_P   ,KC_G   ,        	                                       KC_J   ,KC_L   ,KC_U  ,KC_Y   ,KC_SCLN ,_______,
        _______,_______,KC_R   ,KC_S   ,KC_T   ,KC_D   ,                                                       KC_H   ,KC_N   ,KC_E   , KC_I, KC_O    ,_______,
        _______,_______,_______,_______,_______,_______,                                                       KC_K   ,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,_______,_______
	),

        [_LPURPLE] = LAYOUT(
	KC_F12 ,KC_F1  ,KC_F2  ,KC_F3   ,KC_F4  ,KC_F5  , 			     		               KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , 
	_______,_______,_______,KC_LCBR ,KC_RCBR,_______,            				               _______,_______,_______,_______,_______,KC_PIPE,
	_______,_______,_______,KC_LBRC ,KC_RBRC,_______,			            	               KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
	_______,_______,_______,KC_LPRN ,KC_RPRN,_______,				                       _______,KM_DLEFT,_______,KM_DRIGHT,_______,_______, 
	_______,_______, _______,_______,_______,_______,_______,_______,                      _______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______
	),
	
	[_LGREEN]  = LAYOUT(
	GE_NORM,NOVELTY, BDSPSW, CURBDS,_______,_______, 			                               _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,_______,_______, 			    	                       _______,_______,KC_UP  ,_______,KC_MPLY,_______, 
	_______,_______,SQUID  ,_______,FIRE   ,_______, 			                               _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_MSTP,_______,
	_______,_______,_______,_______,_______,BALL   ,			                      	       _______,_______,_______,_______,_______,CMB_TOG, 
	_______,_______,_______,_______,_______,_______,_______,_______,                       _______,_______,_______,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______
	),
	
	[_LYELLOW] = LAYOUT(
	_______,_______,_______,_______,_______,_______, 			                               KC_SCRL,KC_NUM ,KC_PSLS,KC_PAST,KC_PMNS,_______, 
	_______,_______,_______,_______,_______,_______, 		                                       _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
	_______,_______,KC_LEFT,KC_UP  ,KC_RGHT,_______, 			                               _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
	_______,_______,_______,KC_DOWN,_______,_______,		                                       _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______, 
        _______,_______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,KC_P0  ,KC_PDOT,KC_PENT,_______
		),

	[_LAZURE]  = LAYOUT(
	_______,_______,_______,_______,_______,_______,			                               _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,         		                               _______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______, 				                       _______,KC_RSFT,KC_RCTL,KC_RALT,_______,_______, 
	_______,_______,_______,_______,_______,_______,		                                       _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,_______,_______
	),

	[_LCYAN]   = LAYOUT (
	_______,_______,_______,_______,_______,_______, 	  	                                       _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,_______,_______,				                       _______,_______,_______,_______,_______,_______, 
	_______,_______,KC_LALT,KC_LCTL,KC_LSFT,_______, 		                                       _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,_______,_______,		                                       _______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,_______,_______
	),

	[_LSYSL]   = LAYOUT(
	_______,_______,_______,_______,_______,_______,			                               _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,RESET  ,_______,			                               _______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______, 		                                       _______,_______,_______,_______,_______,_______, 
 	_______,_______,_______,TGCLMK ,_______,_______, 				                       _______,_______,_______,_______,_______,_______, 
	_______,_______,_______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,_______,_______
	)
};                                        

static short count3 = 0;
static bool animation = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case NOVELTY:
            if (record->event.pressed)
            {
                animation = !animation;
            } else {
            }
            break;

        case BDSPSW:
            if (record->event.pressed) {
                SEND_STRING("");
            }
            break;
        case CURBDS:
            if (record->event.pressed) {
                SEND_STRING("");
            } else {
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
                SEND_STRING("david.gwin@bestdealspring.com");
            } else {
            }
            break;
        case EMAIL3:
            if (record->event.pressed) {
                SEND_STRING("davidgwin123@gmail.com");
            } else {
            }
            break;
        case FIRE:
            if (record->event.pressed) {
                enter  = true;
                count3 = 0;
            } else {
            }
            break;
        case SQUID:
            if (record->event.pressed) {
                squid  = true;
                count3 = 0;
            } else {
            }
            break;
        case BALL:
            if (record->event.pressed) {
                ball   = true;
                count3 = 0;
            } else {
            }
            break;
    }
    return true;
};

// #ifdef OLED_ENABLE

static short logoCount = 0;
// static short max_wpm = 0, reset = 0, count = 0, count2 = 0, logoCount = 0;
// static short average[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



    static const short first = 64;
    static const char PROGMEM raw_purple[2][ 64] = {
        {0,  0,  0,252,252,196,204, 76,124, 56,  0,240,240,  0,  0,  0,240,  0,  0, 16, 16,240,240, 32, 48, 48,  0,240,240, 32, 16, 48,240,192,  0,  2,  2,254,254,  0,  0,  0,  0,224,240,144,144,176,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
        {0,  0,  0, 15, 15,  0,  0,  0,  0,  0,  0,  7, 15, 12,  8,  4, 15,  0,  0,  8,  8, 15, 15,  8,  8,  0,  0,127,127,  4,  8, 12, 15,  3,  0,  8,  8, 15, 15,  8,  8,  0,  0,  7, 15, 12,  8, 12, 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    
    static const char PROGMEM raw_azure[2][ 64] = {
        
        {0,  0,  0,  0,240,124, 12,252,240,  0,  0,  0, 96, 96, 96, 96,224,224, 96,  0,  0,224,224,  0,  0,  0,224,224,  0,  0, 96, 96,224,224, 64, 96, 96,  0,  0,192,192, 96, 32, 96,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
        {0,  0, 16, 31, 15,  3,  3,  3, 15, 31, 16,  0, 24, 28, 22, 19, 17, 16, 16,  0,  0, 15, 31, 24, 24,  8, 31, 31,  0,  0, 24, 24, 31, 31, 16, 16,  0,  0,  0,  7, 15, 25, 25, 25, 25,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };

    static const char PROGMEM raw_cyan[2][ 64] = {
        {0,  0,  0,240,248, 12, 12, 12, 28, 24,  0,  0,224,224,  0,  0,  0,224,224,  0,  0, 64, 96, 96, 32, 96,192,128,  0,  0,224,224, 64, 96, 96,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
        {0,  0,  0,  7, 15, 24, 24, 24, 28, 12,  0,  0,192,195,255,120, 31,  3,  0,  0,  0, 14, 31, 17, 17,  9, 31, 31,  0,  0, 31, 31,  0,  0,  0, 31, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    static const char PROGMEM raw_green[2][ 64] = {
        {0,  0,240,248, 28, 12, 12, 60, 56, 32,  0,  0, 96, 96,224,224,128, 64, 96, 96,  0,  0,128,192, 96, 96, 96,224,192,128,  0,  0,128,192, 96, 96, 96,224,192,128,  0,  0,224,224,128, 96, 96,224,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  },
        {0,  0, 31, 63, 56, 48, 51, 11, 63, 63,  0,  0, 48, 48, 63, 63, 49, 48, 48,  0,  0,  0, 15, 31, 58, 50, 50, 51, 27, 19,  0,  0, 15, 31, 58, 50, 50, 51, 27, 19,  0,  0, 63, 63,  0,  0,  0, 63, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  }
   
        // {0,  0,  0,248,252, 12,140,140,152,144,  0, 16, 16,240,240, 32, 48, 48,  0,224,240,144,144,176,224,192,  0,224,240,144,144,176,224,192,  0,240,240, 32, 16, 48,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},  
        // {0,  0,  0,  7, 15, 12, 12,  4, 15, 15,  0,  8,  8, 15, 15,  8,  8,  0,  0,  7, 15, 12,  8, 12,  6,  0,  0,  7, 15, 12,  8, 12,  6,  0,  0, 15, 15,  0,  0,  0, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    // static const char PROGMEM raw_gwin_world[2][ 80] = {
    //     {0,128,224,112, 24, 12, 12, 12, 12, 12, 12, 12, 24, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4, 12, 12, 28,120,224,128,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,128,224,248, 28, 12, 12,  4,  0,  0,  0,  0,  0,  0,252,  4,  0,  0,  0,  0,  0,  0,  0,252,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
    //     {0,  3, 15, 28, 56, 48, 96, 96, 96, 97,101, 77, 57,103, 70,112, 24,112, 64, 96, 56, 12,  4,  0,125, 64,  0,124,120,  4,  4,124, 64,  1, 15, 62,112, 96,124, 63,  1, 63,124, 96,112,  6, 59,109, 68, 68,108, 60,  0, 68,124,  8,  4, 12,  0,127, 64,  0, 56,124, 68, 68,100, 60,127, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, }
    // };
    
    static const char PROGMEM raw_lsysl[2][ 64] = {
        {0,  0,  0,252,252,  0,  0,  0,  0,  0,  0,  0,120,252,204,204,140,140,  8,  0,  4, 28,124,224,128,224,120, 28,  4,  0,120,252,204,204,140,140,  8,  0,  0,252,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
        {0,  0,  0, 31, 31, 24, 24, 24, 24, 24,  0,  0, 12, 24, 24, 24, 25, 31, 15,  0,  0,  0,  0,  1, 31,  1,  0,  0,  0,  0, 12, 24, 24, 24, 25, 31, 15,  0,  0, 31, 31, 24, 24, 24, 24, 24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    
    static const char PROGMEM raw_yellow[2][ 64] = {
        {0,  0,  4, 28,124,224,128,224,120, 28,  4,  0,192,192, 96, 32, 96,224,192,  0,  0,  6,  6,  6,254,  0,  0,  0,  0,  0,  6,  6,  6,254,  0,  0,  0,  0,  0,192,224, 96, 32, 96,224,192,  0, 96,224,  0,  0,224,  0,  0,224, 96,  0,  0,  0,  0,  0,  0,  0,  0,},
        {0,  0,  0,  0,  0,  1, 31,  1,  0,  0,  0,  0,  7, 15, 25, 25, 25, 25,  9,  0,  0, 24, 24, 24, 31, 16, 16, 16,  0,  0, 24, 24, 24, 31, 16, 16, 16,  0,  0, 15, 31, 24, 16, 24, 31, 15,  0,  0, 31, 16, 31,  1, 31, 16, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    
    static const char PROGMEM raw_qwerty[2][ 64] = {        
        {0,192,248,252, 12, 12, 12,252,248,192,224,224,  0,224, 96,224,  0,224,224,  0,192,224, 96, 96, 96,224,192,  0,  0, 96, 96,224,224,192, 96, 96,  0,  0, 96, 96,252,252, 96, 96, 96, 0, 32,224,224,  0,  0,  0,224,224, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,},  
        {0, 1, 15, 31, 24,120,216,223,207,  1,  1, 31, 16, 31,  0, 31, 16, 31,  0,  0, 15, 15, 25, 25, 25, 25,  9,  0,  0, 24, 24, 31, 31, 24, 24,  0,  0,  0,  0,  0, 31, 31, 24, 24, 24,  0, 0,192,199,255,120, 31,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
    };
    
    static const char PROGMEM raw_colmak[2][ 64] = {
        {0,  0,240,248, 28, 12, 12, 28, 56, 16,  0,  0,128,192, 96, 96, 96,224,192,128,  0,  0, 12, 12, 12,252,252,  0,  0,  0,  0,224,224, 64, 96,224,192, 96,224,224,  0,  0, 64,224, 96, 96, 96,224,192,  0,  0,  0,252,252,  0,128,192,224, 96, 32,  0,  0,  0,  0,}, 
        {0,  0, 15, 31, 56, 48, 48, 56, 28,  8,  0,  0, 31, 31, 48, 48, 48, 63, 31, 15,  0,  0, 48, 48, 48, 63, 63, 48, 48, 48,  0, 63, 63,  0,  0, 63, 63,  0, 63, 63,  0,  0, 28, 62, 50, 50, 18, 31, 63, 48,  0,  0, 63, 63,  7,  7, 15, 60, 56, 32,  0,  0,  0,  0,}
     };
    
    static const char PROGMEM raw_scroll_lock[2][16] = {
       { 0,192,224,252,254, 98, 34,162,162, 34, 98,254,252,224,192,  0, },
       { 0, 63,127,127,127, 76, 89, 89, 89, 65, 99,127,127,127, 63,  0,}

    };
    
    static const char PROGMEM raw_caps_lock[2][16] = {
        {0,192,224,252,254,226,226, 34, 34, 34,226,254,252,224,192,  0,},  
        {0, 63,127,127,127, 79, 64,118,119, 96, 67,127,127,127, 63,  0,}
    };
    
    static const char PROGMEM raw_num_lock[2][16] = {
        {0,192,224,252,254, 34, 34,226,226,226, 34,254,252,224,192,  0,  },
        {0, 63,127,127,127, 64,126,120, 99, 71, 64,127,127,127, 63,  0,}
    };


    static const char PROGMEM raw_hatchet[8][2][16] = {
        {
            {
                0,  0,  0,  0, 16, 40,252,252, 40,124,214,124,  0,  0,  0,  0,  
            
            },{
                0,  0,  0,  0,  0,  0,127,127, 64,  0,  0,  0,  0,  0,  0,  0,
            
            }    
        },
        {
            {
                0,  0,  0,  0,  0,  0,128,216,104, 48,216,104,160,192, 96,  0, 
            
            },{
            
                0,  0, 24, 44,  6,  3,  1,  0,  0,  0,  2,  3,  1,  0,  0,  0,
            }
        },
        {        
            {
                0,192,192,192,192,192,192,192,192,192,224,208,224,192,  0,  0,   
            },
            { 
                0,  1,  0,  0,  0,  0,  0,  0,  4, 14, 11, 14, 11, 14,  4,  0,
            }
        },
        {
            {
                0,  0,  8,  4, 12, 24, 48, 96,192,128,  0,128,128,  0,  0,  0,  
            },
            { 
                0,  0,  0,  0,  0,  0, 12, 24, 52,109, 91,  6, 13,  0,  0,  0,
            }
        },
        {
            {
                0,  0,  0,  0,  0,  0,  0,  2,254,254,  0,  0,  0,  0,  0,  0,   
            },
            { 
                0,  0,  0,  0, 62,107, 62, 20, 63, 63, 20,  8,  0,  0,  0,  0,
            }
        },
        {
            {
                0,  0,  0,128,192, 64,  0,  0,  0,128,192, 96, 52, 24,  0,  0,   
            },
            { 
                0,  6,  3,  5, 22, 27, 12, 22, 27,  1,  0,  0,  0,  0,  0,  0,
            }
        },
        {
            {
                0, 32,112,208,112,208,112, 32,  0,  0,  0,  0,  0,  0,128,  0,   
            },
            {  
                0,  0,  3,  7, 11,  7,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,
            }
        },
        {
            {
                0,  0,  0,176, 96,218,182, 44, 24, 48,  0,  0,  0,  0,  0,  0,   
            },
            { 
                0,  0,  0,  1,  1,  0,  1,  3,  6, 12, 24, 48, 32, 16,  0,  0,
            }
        }
    };
    static const unsigned char PROGMEM skell[2][16] =
        { // stare
            {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
            {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        };
        // { // smile
        //     {0,  0,  0,  0, 30, 31,185,125,111,125,185, 31, 30,  0,  0,  0},  
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { // wink
        //     {0,  0,  0,  0, 30, 31,185,121,175,123,185, 31, 30,  0,  0,  0},  
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { // look right
        //     {0,  0,  0,  0, 30, 31,187,121,175,123,185, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { // look left
        //     {0,  0,  0,  0, 30, 31,185,123,175,121,187, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { // blink
        //     {0,  0,  0,  0, 30, 31,187,123,175,123,187, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { //  left hand pos 1
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0,192, 96,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { //  left hand pos 2
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0, 48, 24, 52,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { //  left hand pos 3
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0, 48, 24, 52,  0,  4, 85, 85,255, 85, 85,  4,  0,248,  0,  0,}
        // },
        // { //  right hand pos 1
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0,248, 96,192}
        // },
        // { //  right hand pos 2
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0, 52, 24, 48,}
        // },
        // { //  right hand pos 3
        //     {0,  0,  0,  0, 30, 31,185,121,175,121,185, 31, 30,  0,  0,  0,}, 
        //     {0,  0,  0,248,  0,  4, 85, 85,255, 85, 85,  4,  0, 22, 12,  6,}
        // },
    // };
bool oled_task_user(void) {
    // const short SCREEN = 19;
    // static const char PROGMEM gwinworld1[] = {0x20, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x20, 0x20, 0x00};
    // static const char PROGMEM gwinworld2[] = {0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0x20, 0x20, 0x00};
    // // Host Keyboard Layer Status
    // static const char PROGMEM scroll_lock1[] = {0x80, 0x81, 0x00};
    // static const char PROGMEM scroll_lock2[] = {0x86, 0x87, 0x00};
    // static const char PROGMEM num_lock1[]    = {0x82, 0x83, 0x00};
    // static const char PROGMEM num_lock2[]    = {0x88, 0x89, 0x00};
    // static const char PROGMEM caps_lock1[]   = {0x84, 0x85, 0x00};
    // static const char PROGMEM caps_lock2[]   = {0x8A, 0x8B, 0x00};
    // static const char PROGMEM qmk_logo1[]    = {0x8C, 0x8D, 0x8E, 0x20, 0x00};

    // static const char PROGMEM qmk_logo2[] = {0x8F, 0x90, 0x91, 0x92, 0x00};
    // // Host Keyboard LED Status
    // char  lineBuff[20];
    // bool  bigLogo   = false;


    char rawbuf[128];
    led_t led_state = host_keyboard_led_state();

    if(logoCount > 23)
    {
        logoCount = 0;
    }

    for(short i=0; i<2; ++i)
    {

        oled_set_cursor(0,i);
        // if(logoCount < 10)
        // {      
            
            switch (get_highest_layer(layer_state)) {
                case _LPURPLE:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_purple[i][j];
                    }
                    break;
                case _LGREEN:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_green[i][j];
                    }
                    break;
                case _LYELLOW:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_yellow[i][j];
                    }
                    break;
                case _LAZURE:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_azure[i][j];
                    }
                    break;
                case _LCYAN:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_cyan[i][j];
                    }
                    break;
                case _LSYSL:
                    for(short j=0; j< first; ++j)
                    {
                        rawbuf[j] = raw_lsysl[i][j];
                    }
                    break;
                default:
                    if (layer_state & 2) {
                        // colmak
                        for(short j=0; j< first; ++j)
                        {
                            rawbuf[j] = raw_colmak[i][j];
                        }
                    } else {
                        // qwerty
                        for(short j=0; j< first; ++j)
                        {
                            rawbuf[j] = raw_qwerty[i][j];
                        }
                    }
            } 
        // }
        // else
        // {
        //     for(short j=0; j< first; ++j)
        //     {
        //         rawbuf[j] = raw_gwin_world[i][j];
        //     }
        // }

        short index = first;    

        for(short j=0; j<16; ++j)
        { 
            rawbuf[index] = raw_hatchet[logoCount % 8][i][j];
            ++index;
        }

        

        if(led_state.scroll_lock)
        {
            for(short j=0; j<16; ++j)
            { 
                rawbuf[index] = raw_scroll_lock[i][j];
                ++index;
            }
        }
        else {
            
            for(short j=0; j<16; ++j)
            {
                rawbuf[index] = 0;
                ++index;
            }
        }
        if(led_state.num_lock)
        {
            for(short j=0; j<16; ++j)
            {
                rawbuf[index] = raw_num_lock[i][j];
                ++index;
            }
        }
        else {
            for(short j=0; j<16; ++j)
            {
                rawbuf[index] = 0;
                ++index;
            }
        }
        if(led_state.caps_lock)
        {
            for(short j=0; j<16; ++j)
            {
                rawbuf[index] = raw_caps_lock[i][j];
                ++index;
            }
        }
        else {
            for(short j=0; j<16; ++j)
            {
                rawbuf[index] = 0;
                ++index;
            }
        }
        oled_write_raw_P(rawbuf, sizeof(rawbuf));
    }
    
    ++logoCount;

    oled_set_cursor(0,2);


    
    short wpm = get_current_wpm();

    if(wpm > 0)
    {
        short pass = 0;
        {

            short ski = 0;
            for(short i=0; i<128)
            {
                if(i > 31 && i < 65)
                {
                    rawbuf[i] = skell[0][pass][ski++];
                }
                else
                {
                    rawbuf[i] = 0;
                }
            }
            if (wpm < 10)
            {
                ski = logoCount % 6
                if( ski < 3)
                {
                    rawbuf[]
                }
            }
        }while(pass < 2)
        
    }
    // oled_write_P(PSTR("\n"), false);
    // short ave = 0;
    // if (wpm > max_wpm) {
    //     max_wpm = wpm;
    // }
    // if (wpm < 1) ++reset;

    // if (count % 5 == 0) {
    //     for (short i = 0; i < 15; ++i) {
    //         ave += average[i];
    //     }
    //     average[count % 15] = wpm;
    //     ++count;
    // }
    // if (reset > 200) {
    //     reset   = 0;
    //     max_wpm = 0;
    // }

    // ave        = ave / 15;
    // float wpmb = wpm;
    // oled_write_P(PSTR("WPM Av: "), false);
    // sprintf(strbuf, "%3d", ave);
    // oled_write_P(PSTR(strbuf), false);
    // oled_write_P(PSTR(" Pk: "), false);
    // sprintf(strbuf, "%3d\n", max_wpm);
    // oled_write_P(PSTR(strbuf), false);
    // if (enter) {
    //     if (count3 == 20) {
    //         enter = false;
    //     }
    //     short iEnt = 1, baton = count3 % 4;
    //     lineBuff[0] = 0x1A;
    //     while (iEnt < count3 && iEnt < SCREEN) {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     if (iEnt < SCREEN) {
    //         if (baton == 0) lineBuff[iEnt] = 0x15;
    //         if (baton == 1) lineBuff[iEnt] = 0x16;
    //         if (baton == 2) lineBuff[iEnt] = 0x17;
    //         if (baton == 3) lineBuff[iEnt] = 0x18;
    //         ++iEnt;
    //     }
    //     while (iEnt < SCREEN) {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     lineBuff[iEnt] = 0x00;
    //     oled_write_P(lineBuff, false);

    //     ++count3;

    // } else if (squid || ball) {
    //     if (count3 == 20) {
    //         squid = false;
    //         ball  = false;
    //     }
    //     short iEnt = 0, baton = count3 % 4;
    //     while (iEnt < count3 && iEnt < SCREEN) {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     if (iEnt < 22) {
    //         if (squid && iEnt < SCREEN) {
    //             if (baton == 0) lineBuff[iEnt] = 0x19;
    //             if (baton == 1) lineBuff[iEnt] = 0x1B;
    //             if (baton == 2) lineBuff[iEnt] = 0x1C;
    //             if (baton == 3) lineBuff[iEnt] = 0x1B;

    //             if (half) {
    //                 ++count3;
    //                 half = false;
    //             } else {
    //                 half = true;
    //             }

    //             ++iEnt;
    //         }
    //         if (ball) {
    //             if (iEnt > 3) lineBuff[iEnt - 3] = 0x1D;
    //             if (iEnt > 2 && iEnt < 21) lineBuff[iEnt - 2] = 0x1E;
    //             if (iEnt > 1 && iEnt < 20) lineBuff[iEnt - 1] = 0x1F;
    //             if (iEnt < SCREEN) lineBuff[iEnt] = 0xDF;
    //             ++iEnt;
    //             ++count3;
    //         }
    //     }
    //     while (iEnt < SCREEN)
    //         {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     lineBuff[iEnt] = 0x00;
    //     oled_write_P(lineBuff, false);

    // } else 
    
    // if (animation) {
    //     ++count2;
    //     short wpmc   = wpm;
    //     short batton = count2 % 4;
    //     short iAni   = 0;
    //     do {
    //         wpmc -= 6;
    //         if (batton == 0) {
    //             lineBuff[iAni] = 0x15;
    //             count2         = 0;
    //         }
    //         if (batton == 1) lineBuff[iAni] = 0x16;
    //         if (batton == 2) lineBuff[iAni] = 0x17;
    //         if (batton == 3) lineBuff[iAni] = 0x18;
    //         ++iAni;
    //     } while (wpmc > 0 && iAni < SCREEN);
    //     while (iAni < SCREEN) {
    //         lineBuff[iAni] = 0x20;
    //         ++iAni;
    //     }
    //     lineBuff[iAni] = 0x00;
    //     oled_write_P(lineBuff, false);

    // } else {
    //     sprintf(strbuf, "%3d", wpm);
    //     short idx = 3;
    //    if (wpmb > 168) {
    //         wpmb -= 168;
    //         for (short i = 0; i < 14; ++i) {
    //             if (wpmb > 5)
    //                 strbuf[idx++] = 0x14;
    //             else if (wpmb == 5)
    //                 strbuf[idx++] = 0x13;
    //             else if (wpmb == 4)
    //                 strbuf[idx++] = 0x12;
    //             else if (wpmb == 3)
    //                 strbuf[idx++] = 0x11;
    //             else if (wpmb == 2)
    //                 strbuf[idx++] = 0x10;
    //             else if (wpmb == 1)
    //                 strbuf[idx++] = 0x0F;
    //             else if (wpmb < 1)
    //                 strbuf[idx++] = 0x0E;
    //             wpmb -= 6;
    //         }
    //     } else if (wpmb > 84) {
    //         wpmb -= 84;
    //         for (short i = 0; i < 14; ++i) {
    //             if (wpmb > 5)
    //                 strbuf[idx++] = 0x0E;
    //             else if (wpmb == 5)
    //                 strbuf[idx++] = 0x0C;
    //             else if (wpmb == 4)
    //                 strbuf[idx++] = 0x0B;
    //             else if (wpmb == 3)
    //                 strbuf[idx++] = 0x09;
    //             else if (wpmb == 2)
    //                 strbuf[idx++] = 0x08;
    //             else if (wpmb == 1)
    //                 strbuf[idx++] = 0x07;
    //             else if (wpmb < 1)
    //                 strbuf[idx++] = 0x06;
    //             wpmb -= 6;
    //         }
    //     } else {
    //         for (short i = 0; i < 14; ++i) {
    //             if (wpmb > 5)
    //                 strbuf[idx++] = 0x06;
    //             else if (wpmb == 5)
    //                 strbuf[idx++] = 0x05;
    //             else if (wpmb == 4)
    //                 strbuf[idx++] = 0x04;
    //             else if (wpmb == 3)
    //                 strbuf[idx++] = 0x03;
    //             else if (wpmb == 2)
    //                 strbuf[idx++] = 0x02;
    //             else if (wpmb == 1)
    //                 strbuf[idx++] = 0x01;
    //             else if (wpmb < 1)
    //                 strbuf[idx++] = ' ';
    //             wpmb -= 6;
    //         }
    //     }
    //     while(idx < SCREEN)
    //     {
    //         strbuf[idx++] = ' ';
    //     }
    //     oled_write_P( strbuf, false);
    // }



    return false;
};

// #endif
