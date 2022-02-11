#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LPURPLE 1
#define _LGREEN 2
#define _LYELLOW 3 
#define _LORANGE 4 
#define _LCYAN 5 
 
#define LGREEN MO(_LGREEN)
#define LPURPLE MO(_LPURPLE)
#define LYELLOW MO(_LYELLOW) 
#define LORANGE MO(_LORANGE) 
#define LCYAN MO(_LCYAN) 

#define LG_QUOT LGUI_T(KC_QUOT)
#define RG_CAPS RGUI_T(KC_CAPS)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SPC LCTL_T(KC_SPC)
#define CTR_SPC RCTL_T(KC_SPC)
#define LVN_ESC LT(_LYELLOW, KC_ESC) 
#define DLORANGE LT(_LORANGE, KC_D)
#define KLCYAN LT(_LCYAN, KC_K)
#define FLPURPLE LT(_LPURPLE, KC_F)
#define ALT_RGT RALT(KC_RGHT)
#define A_SHFT RSFT_T(KC_A)
#define CL_SHFT RSFT_T(KC_SCLN)

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    THORN_L,
    THORN_U,
    GRINF,
    WINKF,
    GFWINK, 
    GFOPEN,
    GFSLGHT,
    HORNS
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [THORN_L] = 0x00FE, // þ
    [THORN_U] = 0x00DE, // Þ
    [GRINF] = 0x1F600, //Grinning Face
    [GFWINK] = 0x1F609, //Winking Face
    [GFSLGHT] = 0x1F642, //Slightly Smiling Face
    [HORNS] = 0x1F918 //Sign of the Horns
    // []0x1F601 //Grinning Face with Smiling Eyes
//0x1F606 //Smiling Face with Open Mouth and Tightly-Closed Eyes
//0x1F605 //Smiling Face with Open Mouth and Cold Sweat
//0x1F602 //Face with Tears of Joy
//0x1F923 //Rolling On The Floor Laughing
//0x1F60A //Smiling Face with Smiling Eyes
//0x1F604 //Smiling Face with Open Mouth and Smiling Eyes
//0x1F643 //Upside-Down Face
//0x1F607 //Smiling Face with Halo
//0x1F603 //Smiling Face with Open Mouth
//0x1F914 //Thinking Face
//0x1F92D //Smiling Face With Smiling Eyes And Hand Covering Mouth
//0x1F917 //Hugging Face
//0x1F92B //Face With Finger Covering Closed Lips
//0x1F60B //Face Savouring Delicious Food
//0x1F61B //Face with Stuck-Out Tongue
//0x1F61C //Face with Stuck-Out Tongue and Winking Eye
//0x1F92A //Grinning Face With One Large And One Small Eye
//0x1F61D //Face with Stuck-Out Tongue and Tightly-Closed Eyes
//0x1F911 //Money-Mouth Face
//0x1F919 //Call Me Hand
//0x1F91E //Hand with Index and Middle Fingers Crossed
//0x1F91F //I Love You Hand Sign
//0x1F90C //Pinched Fingers
//0x1F90F //Pinching Hand
//0x1F44C //Ok Hand Sign
//0x270C  //Victory Hand
//0x1F91B // Left-Facing Fist
//0x1F91C //Right-Facing Fist
//0x1F44D //Thumbs Up Sign
//0x270A //Raised Fist
//0x1F44A //Fisted Hand Sign
//0x1F44E //Thumbs Down Sign


};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_RED}       // Light 4 LEDs, starting with LED 6
    // {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,0, HSV_CORAL}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_GREEN}
);
// Light LEDs 13 & 14 in green when keyboard layer 4 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_YELLOW}
);
// Light LEDs 13 & 14 in green when keyboard layer 5 is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_ORANGE}
);
// Light LEDs 13 & 14 in green when keyboard layer 5 is active
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,8, HSV_CYAN}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,     // Overrides other layers
    my_layer4_layer,    // Overrides other layersCVV
    my_layer5_layer,    // Overrides other layersCVV
    my_layer6_layer   // Overrides other layersCVV
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRAVE, KC_1 ,KC_2   , KC_3 , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  ,KC_W   , KC_E , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL ,
        KC_CAPS, KC_A  , KC_S   ,KC_D , KC_F , KC_G   ,                                        KC_H   , KC_J  ,KC_K , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C , KC_V  ,KC_B  ,                                         KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_SFTENT,
        KC_LCTL,KC_LGUI,KC_LALT,KC_ESC ,KC_DEL,LPURPLE,KC_LSFT,KC_LCTL,       LORANGE, KC_SPC, LCYAN, KC_LEFT,KC_DOWN, KC_UP , KC_RGHT,  KC_RCTL,                                                                       
                                                        LGREEN ,LYELLOW ,        KC_BSPC, KC_ENT
                                                                            
    ), 
    [_LPURPLE] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_BSLS,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_TILD,
        _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,
                                                        _______,_______,       _______,_______                                             
    ),
    [_LGREEN] = LAYOUT_6x6(
        _______,RGB_HUI,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        RGB_MOD,RGB_SAI,_______,_______,_______,_______,                                       _______,_______,KC_MS_U,_______,_______,_______,
        RGB_VAI  ,RGB_VAD ,KC_BTN3,KC_BTN2,KC_BTN1,_______,                                       _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        RGB_TOG,_______,_______,_______,_______,_______,                                       _______,_______,KC_MSTP,KC_MPLY,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,        KC_WH_L,KC_WH_R, KC_WH_U,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______, 
                                                      _______,_______,        _______,KC_WH_D
                                                                              
    ),
    [_LYELLOW] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
        _______,_______,_______,_______,_______,XP(THORN_L,THORN_U),                            _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,_______,X(GRINF),X(GFSLGHT),X(BL_BRTG),                                _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,X(GFWINK),X(HORNS),_______,                                    _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,KC_P0 ,KC_DOT ,KC_PENT,_______, 
                                                        _______,_______,       _______,_______
                                                                               
    ),
    [_LORANGE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_UP  ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,       _______,_______   
    ),
    [_LCYAN] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,DM_RSTP,DM_PLY1,DM_PLY2,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,DM_RSTP,DM_REC1,DM_REC2,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,_______,
                                                        _______,_______,       _______,_______
                                                                               
    )                                          
};


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _LPURPLE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LGREEN));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LYELLOW));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LORANGE));
    rgblight_set_layer_state(6, layer_state_cmp(state, _LCYAN));
    return state;
}
