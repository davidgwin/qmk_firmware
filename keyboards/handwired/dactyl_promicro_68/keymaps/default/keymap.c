#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _SALEM 1
#define _MONA 2
#define _LEVAN 3 
 
#define MONA MO(_MONA)
#define SALEM MO(_SALEM)
#define LEVAN MO(_LEVAN) 

#define LG_QUOT LGUI_T(KC_QUOT)
#define RG_CAPS RGUI_T(KC_CAPS)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SPC LCTL_T(KC_SPC)
#define CTR_SPC RCTL_T(KC_SPC)
#define LVN_ESC LT(_LEVAN, KC_ESC)
#define ALT_RGT RALT(KC_RGHT)

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    THORN_L,
    THORN_U,
    

};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [THORN_L] = 0x00FE, // þ
    [THORN_U] = 0x00DE, // Þ
//0x1F600 //Grinning Face
//0x1F609 //Winking Face
//0x1F601 //Grinning Face with Smiling Eyes
//0x1F606 //Smiling Face with Open Mouth and Tightly-Closed Eyes
//0x1F605 //Smiling Face with Open Mouth and Cold Sweat
//0x1F602 //Face with Tears of Joy
//0x1F923 //Rolling On The Floor Laughing
//0x1F60A //Smiling Face with Smiling Eyes
//0x1F642 //Slightly Smiling Face
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
//0x1F918 //Sign of the Horns
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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRAVE, KC_1 ,KC_2   , KC_3 , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  ,KC_W   , KC_E , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL ,
        RG_CAPS, KC_A  ,KC_S   , KC_D , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,LG_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,KC_ESC ,KC_DEL,KC_BSPC,CTL_SPC, MONA ,      KC_ENT , CTR_SPC, KC_TAB, KC_LEFT,KC_DOWN, KC_UP , KC_RGHT,KC_RCTL,                                                                       
                                                        SALEM ,LEVAN ,      KC_RALT ,SALEM  
                                                                            
    ),
    [_SALEM] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,                                       _______,_______,KC_UP  ,_______,_______,_______,
        _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,
                                                        _______,_______,       _______,_______                                             
    ),
,    [_MONA] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,______,_,_______,_______,                                       _______,_______,KC_MS_U,_______,_______,_______,
        _______,_______,KC_BTN3,KC_BTN2,KC_BTN1,_______,                                       _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_MSTP,KC_MPLY,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,      KC_WH_L,KC_WH_R, KC_WH_U,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______, 
                                                        _______,_______,      _______,KC_WH_D
                                                                              
    ),
    [_LEVAN] = LAYOUT_6x6(
        DM_RSTP,DM_PLY1,DM_PLY2,_______,_______,_______,                                       _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
        DM_RSTP,DM_REC1,DM_REC2,_______,_______,_______,                                       _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PCMM,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PEQL,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,_______,_______,KC_P0 ,KC_DOT ,KC_PENT,_______, 
                                                        _______,_______,        _______,_______
                                                                               
    ) 
};
