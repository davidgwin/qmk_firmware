#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LPURPLE 1
#define _LGREEN 2

#define _LYELLOW 3
#define _LAZURE 4
#define _LCYAN 5
#define _LSYSL 6

#define LGREEN MO(_LGREEN)
#define LPURPLE MO(_LPURPLE)
#define LYELLOW MO(_LYELLOW)
#define TGCLMK TG(_COLMAK)
#define TYELLOW TG(_LYELLOW)
#define LAZURE MO(_LAZURE)
#define LCYAN MO(_LCYAN)
#define LSYSL MO(_LSYSL)


// #define LG_QUOT LGUI_T(KC_QUOT)
// #define RG_CAPS RGUI_T(KC_CAPS)
#define CTL_ENT LCTL_T(KC_ENT)//
#define CTR_ENT RCTL_T(KC_ENT)//
// #define CTL_SPC LCTL_T(KC_SPC)
// #define CTR_SPC RCTL_T(KC_SPC)
#define STL_SPC LSFT_T(KC_SPC)
// #define STR_SPC RSFT_T(KC_SPC)
// #define LVN_ESC LT(_LYELLOW, KC_ESC)
// #define D_AZURE LT(_LAZURE, KC_DEL)
// #define B_AZURE LT(_LAZURE, KC_BSPC)
#define CY_QUOT LT(_LCYAN, KC_QUOT)
// #define FLPURPLE LT(_LPURPLE, KC_F)
#define PRPL_BSP LT(_LPURPLE, KC_BSPC)
#define PRPL_DEL LT(_LPURPLE, KC_DEL)
#define YEL_DEL LT(_LYELLOW, KC_DEL)
#define GRN_BSP LT(_LGREEN, KC_BSPC)
#define GRN_DEL LT(_LGREEN, KC_DEL)
// #define ALT_RGT RALT_T(KC_RGHT)
// #define A_SHFT RSFT_T(KC_A)
// #define CL_SHFT RSFT_T(KC_SCLN)
#define KM_DLEFT LGUI(LCTL(KC_LEFT))
#define KM_DRIGHT LGUI(LCTL(KC_RIGHT))
// #define GUI_L LGUI(KC_L)
// #define GUI_E LGUI(KC_E)
#define GUI_LEFT LGUI(KC_LEFT)
#define GUI_RIGHT LGUI(KC_RIGHT)
// #define GUI_L LGUI(KC_L)
#define CTSHESC C_S_T(KC_ESC)//

#define AZ_CAPS LT(_LAZURE, KC_CAPS)


const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_RED}       // Light 4 LEDs, starting with LED 6
    // {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,1, HSV_BLUE}       // Light 4 LEDs, starting with LED 6
    // {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_BLACK}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,5, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4,4, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5,3, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6,2, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7,1, HSV_SPRINGGREEN}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    my_layer1_layer,    // Overrides caps lock layer
    my_capslock_layer,
    my_numlock_layer,
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,     // Overrides other layers
    my_layer4_layer,    // Overrides other layers
    my_layer5_layer,    // Overrides other layers
    my_layer6_layer   // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

enum custom_keycodes {
    C_UPDAT = SAFE_RANGE,
    C_COMPI,
    C_FLASH
};

// enum combos {
//   DF_COMB,
//   SD_COMB,
//   JK_COMB,
//   KL_COMB,
//   E1_COMB,
//   E2_COMB,
//   E3_COMB,
//   XC_COMB,
//   VC_COMB,
//   MCM_COMB,
//   CMDT_COMB,
//   SYSL_COMB,
//   COMBO_LENGTH
// };
// uint16_t COMBO_LEN = COMBO_LENGTH;
// const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
// // const uint16_t PROGMEM e1_combo[] = {KC_E, KC_1, COMBO_END};
// // const uint16_t PROGMEM e2_combo[] = {KC_E, KC_2, COMBO_END};
// // const uint16_t PROGMEM e3_combo[] = {KC_E, KC_3, COMBO_END};
// const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM mcm_combo[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM sysl_combo[] = {KC_GRAVE, KC_1, KC_2, COMBO_END};

// combo_t key_combos[] = {
//   [DF_COMB] = COMBO(df_combo, LCTL(KC_LALT)),
//   [SD_COMB] = COMBO(sd_combo, LCTL(KC_LSFT)),
//   [JK_COMB] = COMBO(jk_combo, RCTL(KC_RALT)),
//   [KL_COMB] = COMBO(kl_combo, RCTL(KC_RSFT)),
// //   [E1_COMB] = COMBO(e1_combo, EMAIL1),
// //   [E2_COMB] = COMBO(e2_combo, EMAIL2),
// //   [E3_COMB] = COMBO(e3_combo, EMAIL3),
// //   [E3_COMB] = COMBO(e3_combo, EMAIL3),
//   [XC_COMB] = COMBO(xc_combo, LYELLOW),
//   [VC_COMB] = COMBO(cv_combo, LGREEN),
//   [MCM_COMB] = COMBO(mcm_combo, LGREEN),
//   [CMDT_COMB] = COMBO(cmdt_combo, LYELLOW),
//   [SYSL_COMB] = COMBO(sysl_combo, LSYSL),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRAVE, KC_1 , KC_2  , KC_3 , KC_4  , KC_5  ,                                                              KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E , KC_R  , KC_T  ,                                                              KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL ,
 
        AZ_CAPS, KC_A  , KC_S   ,KC_D , KC_F  , KC_G  ,                                                              KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,CY_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C , KC_V  , KC_B  ,                                                              KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
        CTL_ENT,KC_LGUI,KC_LALT,CTSHESC,LAZURE,PRPL_BSP, KC_SPC,KC_LSFT,KC_LCTL,            KC_RCTL  ,KC_RSFT, KC_SPC,PRPL_BSP,LCYAN ,KC_LBRC, KC_RBRC ,KC_BSLS,CTR_ENT,
                                                        LGREEN,LYELLOW,KC_DEL,              KC_ENT,LYELLOW ,LGREEN

    ),
    [_LPURPLE] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                                              KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,_______,_______,KC_LCBR,KC_RCBR,_______,                                                              _______,_______,_______,_______,_______,KC_PIPE,
        _______,_______,_______,KC_LBRC,KC_RBRC,_______,                                                              _______,_______,_______,_______,_______,KC_BSLS,
        _______,_______,_______,KC_LPRN,KC_RPRN,_______,                                                              _______,KM_DLEFT,_______,KM_DRIGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,_______,              _______,_______,_______
    ),
    [_LGREEN] = LAYOUT_6x6(
        RGB_TOG,RGB_HUI,_______,_______,_______,RESET  ,                                                              RESET  ,_______,_______,_______,_______,_______,
        RGB_MOD,RGB_SAI,_______,KC_UP  ,_______,_______,                                                              _______, _______,_______,_______,_______,_______,
        RGB_VAI,RGB_VAD,KC_LEFT,KC_DOWN,KC_RGHT,_______,                                                              KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,KC_MSTP,KC_MPLY,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,
                                                        _______,_______,_______,              _______,_______,_______

    ),
    [_LYELLOW] = LAYOUT_6x6(
        DM_RSTP,DM_PLY1,DM_PLY2,_______,_______,_______,                                                              KC_SCRL,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS ,_______,
        _______,DM_REC1,DM_REC2,KC_UP  ,_______,_______,                                                              _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,                                                              _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,_______,_______,_______,                                                              _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,KC_P0  ,KC_P0  ,KC_DOT ,KC_ENT ,_______,
                                                        _______,_______,_______,              _______,_______,_______
    ),
    [_LAZURE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                              _______,C_UPDAT,_______,_______,KC_PSCR,KC_PIPE,
        _______,_______,_______,_______,C_FLASH,_______,                                                              KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,KC_BSLS,
        _______,_______,_______,C_COMPI,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______, _______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,_______,              _______,_______,_______
    ),
    [_LCYAN] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_EXEC,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_SLCT,KC_FIND,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,KC_UNDO,KC_CUT,KC_COPY,KC_PSTE,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,_______,              _______,_______,_______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
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
                SEND_STRING("qmk compile -kb handwired/dactyl_promicro_72 -km default");
            } else {
                // when keycode QMKBEST is released
            }
            break;

         case C_FLASH:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(" qmk flash -kb handwired/dactyl_promicro_72 -km default");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        // case BDSPSW:
        //     if (record->event.pressed) {
        //         // when keycode QMKBEST is pressed
        //         SEND_STRING("");
        //     } else {
        //         // when keycode QMKBEST is released
        //     }
        //     break;

        // case CURBDS:
        //     if (record->event.pressed) {
        //         // when keycode QMKBEST is pressed
        //         SEND_STRING("");
        //     } else {
        //         // when keycode QMKBEST is released
        //     }
        //     break;

    }
    return true;
};

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.num_lock); 
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    rgblight_set_layer_state(3, layer_state_cmp(state, _LPURPLE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LGREEN));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LYELLOW));
    rgblight_set_layer_state(6, layer_state_cmp(state, _LAZURE));
    rgblight_set_layer_state(7, layer_state_cmp(state, _LCYAN));
    return state;
}

// #ifdef OLED_ENABLE

// // static void render_logo(void) {
// //     static const char PROGMEM qmk_logo[] =
// //     {
// //         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C,  0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
// //         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC,  0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
// //         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC,  0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
// //     };

// //     oled_write_P(qmk_logo, false);
// // };
// static short max_wpm = 0, reset = 0;
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

//     for(short i=0; i< digits; i++)
//     {
//         short x = input / mod;
//         input = input - x * mod;
//         // if( begin > 0 )
//         // {

//         //     oled_write_P(PSTR(" "), false);
//         //     --begin;
//         // }
//         // else
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

// bool oled_task_user(void)
// {

//     static const char PROGMEM gwinworld1[] =
//     {
//         0x20,0x94,0x95, 0x96,0x97, 0x98,0x99, 0x9A,0x9B, 0x9C, 0x9D,0x9E, 0x9F,0x20,0x20, 0x00
//     };
//     static const char PROGMEM gwinworld2[] =
//     {
//         0x20,0xA0,0xA1, 0xA2,0xA3, 0xA4,0xA5, 0xA6,0xA7, 0xA8,0xA9, 0xAA, 0xAB,0x20,0x20,
//          0x00
//     };
//     // Host Keyboard Layer Status
//     static const char PROGMEM scroll_lock1[] =
//     {
//        0x80, 0x81, 0x00
//     };
//     static const char PROGMEM scroll_lock2[] =
//     {
//        0x86, 0x87,  0x00
//     };
//     static const char PROGMEM num_lock1[] =
//     {
//         0x82, 0x83, 0x00
//     };
//     static const char PROGMEM num_lock2[] =
//     {
//         0x88, 0x89, 0x00
//     };
//     static const char PROGMEM caps_lock1[] =
//     {
//         0x84, 0x85, 0x00
//     };
//     static const char PROGMEM caps_lock2[] =
//     {
//         0x8A, 0x8B, 0x00
//     };
//     static const char PROGMEM qmk_logo1[] =
//     {
//         0x8C, 0x8D, 0x8E, 0x20, 0x00
//     };

//     static const char PROGMEM qmk_logo2[] =
//     {
//          0x8F,0x90, 0x91, 0x92, 0x00
//      };
//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     bool bigLogo = false;
//     //11 chars go here.
//     if(get_highest_layer(layer_state) == _LSYSL)
//     {
//         bigLogo = true;
//         oled_write_P(gwinworld1, false);
//     }
//     else
//     {

//         oled_write_P(qmk_logo1, false);
//         oled_write_P(PSTR("  Qwerty   "), false);
//     }
//     oled_write_P(led_state.scroll_lock ? scroll_lock1 : PSTR("  "), false);
//     oled_write_P(led_state.num_lock ? num_lock1 : PSTR("  "), false);
//     oled_write_P(led_state.caps_lock ? caps_lock1 : PSTR("  "), false);
//     if(!bigLogo)
//     {
//         oled_write_P(qmk_logo2, false);
//     }


//     //11 chars go here.
//     switch (get_highest_layer(layer_state))
//     {

//         case _LPURPLE:
//             oled_write_P(PSTR("  Purple   "), false);
//             break;
//         case _LGREEN:
//             oled_write_P(PSTR("  Green    "), false);
//             break;
//         case _LYELLOW:
//             oled_write_P(PSTR("  Yellow   "), false);
//             break;
//         case _LAZURE:
//             oled_write_P(PSTR("  Azure    "), false);
//             break;
//         case _LCYAN:
//             oled_write_P(PSTR("  Cyan     "), false);
//             break;
//         case _LSYSL:
//             // oled_write_P(PSTR("  System   "), false);

//             oled_write_P(gwinworld2, false);
//             break;
//         default:

//             oled_write_P(PSTR("           "), false);
//     }


//     oled_write_P(led_state.scroll_lock ? scroll_lock2 : PSTR("  "), false);
//     oled_write_P(led_state.num_lock ? num_lock2 : PSTR("  "), false);
//     oled_write_P(led_state.caps_lock ? caps_lock2 : PSTR("  "), false);

//     static const char PROGMEM bar1[] = {0x01, 0x00};
//     static const char PROGMEM bar2[] = {0x02, 0x00};
//     static const char PROGMEM bar3[] = {0x03, 0x00};
//     static const char PROGMEM bar4[] = {0x04, 0x00};
//     static const char PROGMEM bar5[] = {0x05, 0x00};
//     static const char PROGMEM bar6[] = {0x06, 0x00};
//     static const char PROGMEM bar7[] = {0x07, 0x00};
//     static const char PROGMEM bar8[] = {0x08, 0x00};
//     static const char PROGMEM bar9[] = {0x09, 0x00};
//     static const char PROGMEM bar10[] = {0x0B, 0x00};
//     static const char PROGMEM bar11[] = {0x0C, 0x00};
//     static const char PROGMEM bar12[] = {0x0E, 0x00};
//     static const char PROGMEM bar13[] = {0x0F, 0x00};
//     static const char PROGMEM bar14[] = {0x10, 0x00};
//     static const char PROGMEM bar15[] = {0x11, 0x00};
//     static const char PROGMEM bar16[] = {0x12, 0x00};
//     static const char PROGMEM bar17[] = {0x13, 0x00};
//     static const char PROGMEM bar18[] = {0x14, 0x00};


//     short wpm = get_current_wpm();
//     short ave = 0;
//     if(wpm > max_wpm){
//         max_wpm = wpm;
//     }
//     if(wpm < 1)
//         ++reset;



//     if(reset > 200){
//         reset = 0;
//         max_wpm = 0;
//     }

//     ave = ave/15;
//     float wpmb = wpm;
//     // oled_write_P( num_lock2 , false);
//     // oled_write_P( caps_lock2, false);

//     oled_write_P(PSTR("WPM  Pk: "), false);
//     writeInt(max_wpm);
//     oled_write_ln_P(PSTR(" "), false);
//     writeInt(wpm);

//     // oled_write_ln_P( PSTR(" ") , false);
//     if(wpmb > 168){
//         wpmb -= 168;
//         for (short i=0; i<14; ++i)
//         {
//             if(wpmb > 5) oled_write_P( bar18, false);
//             else if(wpmb == 5) oled_write_P( bar17, false);
//             else if(wpmb == 4) oled_write_P( bar16 , false);
//             else if(wpmb == 3) oled_write_P( bar15, false);
//             else if(wpmb == 2) oled_write_P( bar14, false);
//             else if(wpmb == 1) oled_write_P( bar13, false);
//             else if(wpmb < 1) oled_write_P( bar12, false);
//             wpmb -= 6;
//         }
//     }
//     else if(wpmb > 84){
//         wpmb -= 84;
//         for (short i=0; i<14; ++i)
//         {
//             if(wpmb > 5) oled_write_P( bar12, false);
//             else if(wpmb == 5) oled_write_P( bar11, false);
//             else if(wpmb == 4) oled_write_P( bar10 , false);
//             else if(wpmb == 3) oled_write_P( bar9, false);
//             else if(wpmb == 2) oled_write_P( bar8, false);
//             else if(wpmb == 1) oled_write_P( bar7, false);
//             else if(wpmb < 1) oled_write_P( bar6, false);
//             wpmb -= 6;
//         }
//     }
//     else{
//         for (short i=0; i<14; ++i)
//         {
//             if(wpmb > 5) oled_write_P( bar6, false);
//             else if(wpmb == 5) oled_write_P( bar5 , false);
//             else if(wpmb == 4) oled_write_P( bar4 , false);
//             else if(wpmb == 3) oled_write_P( bar3, false);
//             else if(wpmb == 2) oled_write_P( bar2, false);
//             else if(wpmb == 1) oled_write_P( bar1, false);
//             else if(wpmb < 1) oled_write_P(PSTR(" ") , false);
//             wpmb -= 6;
//         }
//     }
//     // oled_write_P( caps_lock2, false);
//     // oled_write_ln_P(qmk_logo3, false);



//     return false;
// };

// #endif
