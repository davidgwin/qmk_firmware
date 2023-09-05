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
#define TAZURE TG(_LAZURE)
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
#define LP_ENT LT(_LPURPLE, KC_ENT)
// #define D_AZURE LT(_LAZURE, KC_DEL)
// #define B_AZURE LT(_LAZURE, KC_BSPC)
#define CY_QUOT LT(_LCYAN, KC_QUOT)
// #define FLPURPLE LT(_LPURPLE, KC_F)
#define LP_SPC LT(_LPURPLE, KC_SPC)
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
#define CAS_IN MEH_T(KC_INS)

#define AZ_CAPS LT(_LAZURE, KC_CAPS)

/*
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
};*/

enum custom_keycodes {
    C_UPDAT = SAFE_RANGE,
    C_COMPI,
    C_FLASH,
    EMAIL1,
    EMAIL2,
    EMAIL3,
    EMAIL4,
    KEY1,
    KEY2,
    KVMSW
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
        KC_GRAVE, KC_1 , KC_2  , KC_3 , KC_4  , KC_5  ,                                                              KC_6   , KC_7  , KC_8  , KC_9   , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E , KC_R  , KC_T  ,                                                              KC_Y   , KC_U  , KC_I  , KC_O   , KC_P  ,KC_EQL ,
        AZ_CAPS, KC_A  , KC_S   ,KC_D , KC_F  , KC_G  ,                                                              KC_H   , KC_J  , KC_K  , KC_L   ,KC_SCLN,CY_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C , KC_V  , KC_B  ,                                                              KC_N   , KC_M  ,KC_COMM, KC_DOT ,KC_SLSH,KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,A(KC_LCTL),LCYAN,KC_DEL,LP_ENT ,CTSHESC,KC_SCRL,       RCTL(KC_RSFT),KC_RSFT,LP_SPC,KC_BSPC ,LAZURE,KC_LBRC, KC_RBRC,KC_BSLS,KC_RCTL,
                                                          LGREEN,LYELLOW,CAS_IN,            KC_ENT  ,LYELLOW, LGREEN
    ),
    [_LPURPLE] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                                              KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,_______,_______,KC_LCBR,KC_RCBR,_______,                                                              _______,_______,_______,_______,_______,KC_PIPE,
        _______,_______,_______,KC_LBRC,KC_RBRC,_______,                                                              KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,_______,KC_BSLS,
        _______,_______,_______,KC_LPRN,KC_RPRN,_______,                                                              _______,_______,KM_DLEFT,KM_DRIGHT,_______,_______,
        _______,KC_APP ,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,TAZURE ,_______,              _______,_______,_______
    ),
    [_LGREEN] = LAYOUT_6x6(
        KC_F24 ,KC_F13 ,KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,                                                              KC_F18 ,KC_F19 ,KC_F20 ,KC_F21 ,KC_F22 ,KC_F23 ,
        RGB_MOD,RGB_SAI,_______,_______,_______,_______,                                                              _______, _______,_______,_______,_______,_______,
        RGB_VAI,RGB_VAD,_______,_______,_______,_______,                                                              KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,_______,_______,
        RGB_TOG,RGB_HUI,_______,_______,_______,_______,                                                              _______,_______,KC_MSTP,KC_MPLY,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,
                                                        _______,_______,_______,              _______,_______,_______
    ),
    [_LYELLOW] = LAYOUT_6x6(
        DM_RSTP,DM_PLY1,DM_PLY2,_______,_______,_______,                                                              _______,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS ,_______,
        _______,DM_REC1,DM_REC2,KC_UP  ,_______,_______,                                                              _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,KC_LEFT,KC_UP  ,KC_RGHT,_______,                                                              _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,KC_DOWN,_______,_______,                                                              _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,KC_P0  ,KC_P0  ,KC_DOT ,KC_ENT ,_______,
                                                        _______,_______,_______,              _______,_______,_______
    ),
    [_LAZURE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,KC_E   ,KC_W   ,_______,_______,                                                              _______,_______,KC_INS ,_______,KC_PSCR,_______,
        CW_TOGG,KC_F   ,KC_A   ,KC_S   ,KC_D   ,_______,                                                              KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,  KVMSW,
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        QK_BOOT,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______,_______,_______,_______,
                                                        KC_SPC ,_______,TAZURE ,              _______,_______,_______
    ),
    [_LCYAN] = LAYOUT_6x6(
        KEY1   ,EMAIL1 ,EMAIL2 ,EMAIL3 ,EMAIL4 ,KEY2   ,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,KC_WAKE,_______,_______,_______,                                                              _______,C_UPDAT,_______,_______,_______,_______,
        KVMSW  ,_______,KC_SLEP,_______,QK_MAKE,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                                              _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______,_______,_______,QK_BOOT,
                                                        _______,_______,_______,              _______,_______,_______
    )
};

static const char PROGMEM flash_cmd[] = {'q','m','k',' ','f', 'l', 'a','s','h', ' ','-','k','b',' ','h','a','n','d','w','i','r','e','d','/', 'd','a','c','t','y','l','_','p','r','o','m','i','c','r','o','_','7','2',' ','-','k','m',' ','d','e','f','a','u','l','t',0};
static const char PROGMEM update_cmd[] = {'s','u','d','o',' ', 'a', 'p','t',' ', 'u','p','d','a','t','e',' ','&','&', 's','u','d','o',' ', 'a','p','t',' ', 'u','p','g','r','a','d','e',' ', '-','y',0};
static const char PROGMEM email1_str[] = {'d','a','v','i','d','@','g','w','i','n','.','w','o','r','l','d',0};
static const char PROGMEM email2_str[] = {'d','a','v','i','d','.','g','w','i','n','@','f','l','e','e','t','p','r','i','d','e','.','c','o','m',0};
static const char PROGMEM email3_str[] = {'d','a','v','i','d','g','w','i','n','1','2','3','@','g','m','a','i','l','.','c','o','m',0};
static const char PROGMEM email4_str[] = {'d','a','v','i','d','g','w','i','n','@','o','u','t','l','o','o','k','.','c','o','m',0};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {

        case C_UPDAT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                send_string_P(update_cmd);
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case C_FLASH:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                send_string_P(flash_cmd);
            } else {
                // when keycode QMKBEST is released
            }
            break;

   
        case EMAIL1:
            if (record->event.pressed) {
                send_string_P(email1_str);
            } else {
            }
            break;
        case EMAIL2:
            if (record->event.pressed) {
                send_string_P(email2_str);
            } else {
            }
            break;
        case EMAIL3:
            if (record->event.pressed) {
                send_string_P(email3_str);
            } else {
            }
            break;
        case EMAIL4:
            if (record->event.pressed) {
                send_string_P(email4_str);
            } else {
            }
            break;    
        case KVMSW:
            if (record->event.pressed) {
                register_code(KC_SCRL);
                unregister_code(KC_SCRL);
                register_code(KC_SCRL);
                unregister_code(KC_SCRL);
                register_code(KC_ENT);
                unregister_code(KC_ENT);

            } else {
            }
            break;
    }
    return true;
};

bool led_update_user(led_t led_state)
{
    if(led_state.caps_lock)
    {

               rgblight_sethsv_at(HSV_RED, 7);  
               rgblight_sethsv_at(HSV_RED, 8);

    }
    else
    {
               rgblight_sethsv_at(HSV_BLACK, 7);
               rgblight_sethsv_at(HSV_BLACK, 8);
    }
    if(led_state.num_lock)
    {

               rgblight_sethsv_at(HSV_BLUE, 6);
               rgblight_sethsv_at(HSV_BLUE, 9);
    }
    else
    {

               rgblight_sethsv_at(HSV_BLACK, 6);
               rgblight_sethsv_at(HSV_BLACK, 9);
    }
    return true;
}

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
/*
    rgblight_set_layer_state(3, layer_state_cmp(state, _LPURPLE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LGREEN));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LYELLOW));
    rgblight_set_layer_state(6, layer_state_cmp(state, _LAZURE));
    rgblight_set_layer_state(7, layer_state_cmp(state, _LCYAN));*/

    switch (get_highest_layer(state)) {
        case _QWERTY:
            {
               rgblight_sethsv_range(HSV_BLACK, 9, 15);
               rgblight_sethsv_range(HSV_BLACK, 0, 6);
                break;
            }
        case _LPURPLE:
            {
               rgblight_sethsv_range(HSV_PURPLE, 9, 15);
               rgblight_sethsv_range(HSV_PURPLE, 0, 6);
                break;
            }
        case _LGREEN:
            {
                rgblight_sethsv_range(HSV_GREEN, 9, 15);
                rgblight_sethsv_range(HSV_GREEN, 0, 6);
                break;
            }
        case _LYELLOW:
            {
                rgblight_sethsv_range(HSV_YELLOW, 9, 15);
                rgblight_sethsv_range(HSV_YELLOW, 0, 6);
                break;

            }
        case _LAZURE:
            {
                rgblight_sethsv_range(HSV_BLUE, 9, 15);
                rgblight_sethsv_range(HSV_BLUE, 0, 6);
                break;
            }
        case _LCYAN:
            {
                rgblight_sethsv_range(HSV_SPRINGGREEN, 9, 15);
                rgblight_sethsv_range(HSV_SPRINGGREEN, 0, 6);
                break;

            }
        default: //  for any other layers, or the d
            {
                rgblight_sethsv_range(HSV_WHITE, 0, 6);
                break;
            }
    }
    return state;
}

bool led_update_kb(led_t led_state)
{
   bool res =  led_update_user(led_state);
   return res;
}
