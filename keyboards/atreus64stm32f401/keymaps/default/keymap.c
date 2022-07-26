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
		CTL_ENT,KC_LGUI,KC_LALT,LVN_ESC,LGREEN, PRPL_BSP, STL_SPC, D_CYAN, LAZURE, KC_SPC, PRPL_BSP,LGREEN,KC_LBRC,KC_RBRC,KC_BSLS,CTR_ENT
		),
	
        [_COLMAK]  = LAYOUT(
		_______,_______,_______,_______,_______,_______,				                    _______,_______,_______,_______,_______,_______,
		_______,_______,_______,KC_F   ,KC_P   ,KC_G   ,			                    	KC_J   ,KC_L   ,KC_U  ,KC_Y   ,KC_SCLN ,_______,
        _______,_______,KC_R   ,KC_S   ,KC_T   ,KC_D   ,                                    KC_H   ,KC_N   ,KC_E   , KC_I, KC_O    ,_______,
        _______,_______,_______,_______,_______,_______,                                    KC_K   ,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,_______
		),

        [_LPURPLE] = LAYOUT(
		KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  , 			     		            KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , 
		_______,_______,_______,KC_LCBR,KC_RCBR,_______,            				        _______,_______,_______,_______,_______,KC_PIPE,
	    _______,_______,_______,KC_LBRC, KC_RBRC, _______,			            	        KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,_______,_______,
		_______, _______, _______,KC_LPRN, KC_RPRN, _______,				                _______,KM_DLEFT,_______,KM_DRIGHT,_______,_______, 
		_______,_______, _______,_______,_______,_______,_______,_______,   _______,_______,_______, KC_HOME, KC_PGDN, KC_PGUP,KC_END, _______
		),
	
	[_LGREEN]  = LAYOUT(
		GE_NORM,NOVELTY, BDSPSW, CURBDS,_______,_______, 			                    _______,_______,_______,_______,_______,_______, 
		_______,_______,_______,_______,_______,_______, 			    	            _______,_______,KC_UP  ,_______,KC_MPLY,_______, 
		_______,_______,SQUID  ,_______,FIRE   ,_______, 				                _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_MSTP,_______,
		_______,_______,_______,_______,_______,BALL   ,			                  	_______,_______,_______,_______,_______,CMB_TOG, 
		_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,KC_MPRV,KC_VOLD, KC_VOLU, KC_MNXT, _______
		),
	
	[_LYELLOW] = LAYOUT(
		_______, _______, _______, _______, _______, _______, 				KC_SCRL, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, _______, 
		_______, _______, _______, _______, _______, _______, 				_______, KC_P7, KC_P8, KC_P9, KC_PPLS, _______,
		_______, _______, KC_LEFT, KC_UP, KC_RGHT, _______, 				_______, KC_P4, KC_P5, KC_P6, KC_PCMM, _______,
		_______, _______, _______, KC_DOWN, _______, _______,				 _______, KC_P1, KC_P2, KC_P3, KC_PEQL, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PENT, _______
		),

	[_LAZURE]  = LAYOUT(
		_______, _______, _______, _______, _______, _______,			 	_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, 				_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, 				_______, KC_RSFT, KC_RCTL, KC_RALT, _______, _______, 
		_______, _______, _______, _______, _______, _______,				 _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
		),

	[_LCYAN]   = LAYOUT(
		_______, _______, _______, _______, _______, _______, 				_______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______,				 _______, _______, _______, _______, _______, _______, 
		_______, _______, KC_LALT, KC_LCTL, KC_LSFT, _______, 				_______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______,				 _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
		),

	[_LSYSL]   = LAYOUT(
		_______, _______, _______, _______, _______, _______,				 _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, RESET, _______,				 _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, 				_______, _______, _______, _______, _______, _______, 
		_______, _______, _______, TGCLMK, _______, _______, 				_______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

#ifdef OLED_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] =
//     {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C,  0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC,  0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC,  0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// };
static short max_wpm = 0, reset = 0, count = 0, count2 = 0;
static short average[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char strbuf[10];
// short writeInt(short input)
// {
//     static const char PROGMEM zero[] = {0x30, 0x00};
//     static const char PROGMEM one[] = {0x31, 0x00};
//     static const char PROGMEM two[] = {0x32, 0x00};
//     static const char PROGMEM three[] = {0x33, 0x00};
//     static const char PROGMEM four[] = {0x34, 0x00};
//     static const char PROGMEM five[] = {0x35, 0x00};
//     static const char PROGMEM six[] = {0x36, 0x00};
//     static const char PROGMEM seven[] = {0x37, 0x00};
//     static const char PROGMEM eight[] = {0x38, 0x00};
//     static const char PROGMEM nine[] = {0x39, 0x00};

//     short mod = 1;
//     short digits = 0, md = 0;
//     short begin = 3;
//     if(input > md) do {
//         md =( md * 10) + 9;
//         ++digits;
//         mod *=  10;
//     } while(input > md);

//     begin = begin - digits;
//     digits = 3;
//     for(short i=0; i< digits; i++)
//     {
//         short x = input / mod;
//         input = input - x * mod;
//         if( begin > 0 )
//         {
//             oled_write_P(PSTR(" "), false);
//             --begin;
//         }
//         else
//         switch (x)
//         {
//             case 0:
//                 oled_write_P( zero, false);
//                 break;

//             case 1:
//                 oled_write_P( one, false);
//                 break;

//             case 2:
//                 oled_write_P(two, false) ;
//                 break;

//             case 3:
//                 oled_write_P(three, false);
//                 break;

//             case 4:
//                 oled_write_P(four, false) ;
//                 break;

//             case 5:
//                 oled_write_P(five, false) ;
//                 break;

//             case 6:
//                 oled_write_P(six, false) ;
//                 break;

//             case 7:
//                 oled_write_P(seven, false);
//                 break;

//             case 8:
//                 oled_write_P(eight, false);
//                 break;

//             case 9:
//                 oled_write_P(nine, false);
//                 break;

//         }

//             mod = mod / 10;

//     }
//     return digits;
// }

bool oled_task_user(void) {
    const short SCREEN = 19;
    static const char PROGMEM gwinworld1[] = {0x20, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x20, 0x20, 0x00};
    static const char PROGMEM gwinworld2[] = {0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0x20, 0x20, 0x00};
    // Host Keyboard Layer Status
    static const char PROGMEM scroll_lock1[] = {0x80, 0x81, 0x00};
    static const char PROGMEM scroll_lock2[] = {0x86, 0x87, 0x00};
    static const char PROGMEM num_lock1[]    = {0x82, 0x83, 0x00};
    static const char PROGMEM num_lock2[]    = {0x88, 0x89, 0x00};
    static const char PROGMEM caps_lock1[]   = {0x84, 0x85, 0x00};
    static const char PROGMEM caps_lock2[]   = {0x8A, 0x8B, 0x00};
    static const char PROGMEM qmk_logo1[]    = {0x8C, 0x8D, 0x8E, 0x20, 0x00};

    static const char PROGMEM qmk_logo2[] = {0x8F, 0x90, 0x91, 0x92, 0x00};
    // Host Keyboard LED Status
    char  lineBuff[20];
    led_t led_state = host_keyboard_led_state();
    bool  bigLogo   = false;
    // 11 chars go here.
    if (get_highest_layer(layer_state) == _LSYSL) {
        bigLogo = true;
        oled_write_P(gwinworld1, false);
    } else if (layer_state & 2) {
        oled_write_P(qmk_logo1, false);
        oled_write_P(PSTR("  Colmak   "), false);
    } else {
        oled_write_P(qmk_logo1, false);
        oled_write_P(PSTR("  Qwerty   "), false);
    }
    oled_write_P(led_state.scroll_lock ? scroll_lock1 : PSTR("  "), false);
    oled_write_P(led_state.num_lock ? num_lock1 : PSTR("  "), false);
    oled_write_P(led_state.caps_lock ? caps_lock1 : PSTR("  "), false);
    if (!bigLogo) {
        oled_write_P(qmk_logo2, false);
    }

    // 11 chars go here.
    switch (get_highest_layer(layer_state)) {
        case _LPURPLE:
            oled_write_P(PSTR("  Purple   "), false);
            break;
        case _LGREEN:
            oled_write_P(PSTR("  Green    "), false);
            break;
        case _LYELLOW:
            oled_write_P(PSTR("  Yellow   "), false);
            break;
        case _LAZURE:
            oled_write_P(PSTR("  Azure    "), false);
            break;
        case _LCYAN:
            oled_write_P(PSTR("  Cyan     "), false);
            break;
        case _LSYSL:
            // oled_write_P(PSTR("  System   "), false);

            oled_write_P(gwinworld2, false);
            break;
        default:

            oled_write_P(PSTR("           "), false);
    }

    oled_write_P(led_state.scroll_lock ? scroll_lock2 : PSTR("  "), false);
    oled_write_P(led_state.num_lock ? num_lock2 : PSTR("  "), false);
    oled_write_P(led_state.caps_lock ? caps_lock2 : PSTR("  "), false);

    // static const char PROGMEM bar1[]  = {0x01, 0x00};
    // static const char PROGMEM bar2[]  = {0x02, 0x00};
    // static const char PROGMEM bar3[]  = {0x03, 0x00};
    // static const char PROGMEM bar4[]  = {0x04, 0x00};
    // static const char PROGMEM bar5[]  = {0x05, 0x00};
    // static const char PROGMEM bar6[]  = {0x06, 0x00};
    // static const char PROGMEM bar7[]  = {0x07, 0x00};
    // static const char PROGMEM bar8[]  = {0x08, 0x00};
    // static const char PROGMEM bar9[]  = {0x09, 0x00};
    // static const char PROGMEM bar10[] = {0x0B, 0x00};
    // static const char PROGMEM bar11[] = {0x0C, 0x00};
    // static const char PROGMEM bar12[] = {0x0E, 0x00};,m.m.m.,m/.,m/.mkjjkjkjkjkj
    // static const char PROGMEM bar13[] = {0x0F, 0x00};
    // static const char PROGMEM bar14[] = {0x10, 0x00};
    // static const char PROGMEM bar15[] = {0x11, 0x00};
    // static const char PROGMEM bar16[] = {0x12, 0x00};
    // static const char PROGMEM bar17[] = {0x13, 0x00};
    // static const char PROGMEM bar18[] = {0x14, 0x00};

    short wpm = get_current_wpm();
    short ave = 0;
    if (wpm > max_wpm) {
        max_wpm = wpm;
    }
    if (wpm < 1) ++reset;

    if (count % 5 == 0) {
        for (short i = 0; i < 15; ++i) {
            ave += average[i];
        }
        average[count % 15] = wpm;
        ++count;
    }
    if (reset > 200) {
        reset   = 0;
        max_wpm = 0;
    }

    ave        = ave / 15;
    float wpmb = wpm;
    // oled_write_P( num_lock2 , false);
    // oled_write_P( caps_lock2, false);

    oled_write_P(PSTR("WPM Av: "), false);
    // writeInt(ave);
    sprintf(strbuf, "%3d", ave);
    oled_write_P(PSTR(strbuf), false);
    oled_write_P(PSTR(" Pk: "), false);
    // writeInt(max_wpm);
    sprintf(strbuf, "%3d\n", max_wpm);
    oled_write_P(PSTR(strbuf), false);
    if (enter) {
        if (count3 == 20) {
            enter = false;
        }
        short iEnt = 1, baton = count3 % 4;

        // char lineBuff[20];
        lineBuff[0] = 0x1A;
        while (iEnt < count3 && iEnt < SCREEN) {
            lineBuff[iEnt] = 0x20;
            ++iEnt;
        }
        if (iEnt < SCREEN) {
            if (baton == 0) lineBuff[iEnt] = 0x15;
            if (baton == 1) lineBuff[iEnt] = 0x16;
            if (baton == 2) lineBuff[iEnt] = 0x17;
            if (baton == 3) lineBuff[iEnt] = 0x18;
            ++iEnt;
        }
        while (iEnt < SCREEN) {
            lineBuff[iEnt] = 0x20;
            ++iEnt;
        }
        lineBuff[iEnt] = 0x00;
        oled_write_P(lineBuff, false);

        ++count3;

    } else if (squid || ball) {
        if (count3 == 20) {
            squid = false;
            ball  = false;
        }
        short iEnt = 0, baton = count3 % 4;

        // char lineBuff[20];
        while (iEnt < count3 && iEnt < SCREEN) {
            lineBuff[iEnt] = 0x20;
            ++iEnt;
        }
        if (iEnt < 22) {
            if (squid && iEnt < SCREEN) {
                if (baton == 0) lineBuff[iEnt] = 0x19;
                if (baton == 1) lineBuff[iEnt] = 0x1B;
                if (baton == 2) lineBuff[iEnt] = 0x1C;
                if (baton == 3) lineBuff[iEnt] = 0x1B;

                if (half) {
                    ++count3;
                    half = false;
                } else {
                    half = true;
                }

                ++iEnt;
            }
            if (ball) {
                if (iEnt > 3) lineBuff[iEnt - 3] = 0x1D;
                if (iEnt > 2 && iEnt < 21) lineBuff[iEnt - 2] = 0x1E;
                if (iEnt > 1 && iEnt < 20) lineBuff[iEnt - 1] = 0x1F;
                if (iEnt < SCREEN) lineBuff[iEnt] = 0xDF;
                ++iEnt;
                ++count3;
            }
        }
        while (iEnt < SCREEN)
            {
            lineBuff[iEnt] = 0x20;
            ++iEnt;
        }
        lineBuff[iEnt] = 0x00;
        oled_write_P(lineBuff, false);

    } else 
    // if (ball) {
    //     if (count3 == 20) {
    //         ball = false;
    //     }
    //     short iEnt = 0, baton = count3 % 4;

    //     while (iEnt < count3 && iEnt < SCREEN) {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     if (iEnt < SCREEN) {
    //         if (baton == 0) lineBuff[iEnt] = 0x1D;
    //         if (baton == 1) lineBuff[iEnt] = 0x1E;
    //         if (baton == 2) lineBuff[iEnt] = 0x1F;
    //         if (baton == 3) lineBuff[iEnt] = 0xDF;
    //         ++iEnt;
    //     }
    //     while (iEnt < SCREEN) {
    //         lineBuff[iEnt] = 0x20;
    //         ++iEnt;
    //     }
    //     lineBuff[iEnt] = 0x00;
    //     oled_write_P(lineBuff, false);

    //     ++count3;

    // } else 
    if (animation) {
        ++count2;
        short wpmc   = wpm;
        short batton = count2 % 4;
        short iAni   = 0;
        // char  lineBuff[20];
        do {
            wpmc -= 6;
            if (batton == 0) {
                lineBuff[iAni] = 0x15;
                count2         = 0;
            }
            if (batton == 1) lineBuff[iAni] = 0x16;
            if (batton == 2) lineBuff[iAni] = 0x17;
            if (batton == 3) lineBuff[iAni] = 0x18;
            ++iAni;
        } while (wpmc > 0 && iAni < SCREEN);
        while (iAni < SCREEN) {
            lineBuff[iAni] = 0x20;
            ++iAni;
        }
        lineBuff[iAni] = 0x00;
        oled_write_P(lineBuff, false);

    } else {
        // writeInt(wpm);
        sprintf(strbuf, "%3d", wpm);
        //oled_write_P(PSTR(strbuf), false);
        // oled_write_ln_P( PSTR(" ") , false);
        short idx = 3;
       if (wpmb > 168) {
            wpmb -= 168;
            for (short i = 0; i < 14; ++i) {
                if (wpmb > 5)
                    strbuf[idx++] = 0x14;
                else if (wpmb == 5)
                    strbuf[idx++] = 0x13;
                else if (wpmb == 4)
                    strbuf[idx++] = 0x12;
                else if (wpmb == 3)
                    strbuf[idx++] = 0x11;
                else if (wpmb == 2)
                    strbuf[idx++] = 0x10;
                else if (wpmb == 1)
                    strbuf[idx++] = 0x0F;
                else if (wpmb < 1)
                    strbuf[idx++] = 0x0E;
                wpmb -= 6;
            }
        } else if (wpmb > 84) {
            wpmb -= 84;
            for (short i = 0; i < 14; ++i) {
                if (wpmb > 5)
                    strbuf[idx++] = 0x0E;
                else if (wpmb == 5)
                    strbuf[idx++] = 0x0C;
                else if (wpmb == 4)
                    strbuf[idx++] = 0x0B;
                else if (wpmb == 3)
                    strbuf[idx++] = 0x09;
                else if (wpmb == 2)
                    strbuf[idx++] = 0x08;
                else if (wpmb == 1)
                    strbuf[idx++] = 0x07;
                else if (wpmb < 1)
                    strbuf[idx++] = 0x06;
                wpmb -= 6;
            }
        } else {
            for (short i = 0; i < 14; ++i) {
                if (wpmb > 5)
                    strbuf[idx++] = 0x06;
                else if (wpmb == 5)
                    strbuf[idx++] = 0x05;
                else if (wpmb == 4)
                    strbuf[idx++] = 0x04;
                else if (wpmb == 3)
                    strbuf[idx++] = 0x03;
                else if (wpmb == 2)
                    strbuf[idx++] = 0x02;
                else if (wpmb == 1)
                    strbuf[idx++] = 0x01;
                else if (wpmb < 1)
                    strbuf[idx++] = ' ';
                wpmb -= 6;
            }
        }
        while(idx < SCREEN)
        {
            strbuf[idx++] = ' ';
        }
        oled_write_P( strbuf, false);
    }

    // oled_write_ln_P(qmk_logo3, false);

    return false;
};

#endif
