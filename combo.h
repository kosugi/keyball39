
const uint16_t PROGMEM cb_mb1[] = {         _MOD_D,  _MOD_F,  COMBO_END};
const uint16_t PROGMEM cb_mb2[] = {_MOD_S,  _MOD_D,           COMBO_END};
const uint16_t PROGMEM cb_mb3[] = {_MOD_S,  _MOD_D,  _MOD_F,  COMBO_END};
const uint16_t PROGMEM cb_mb4[] = {KC_W,    KC_E,             COMBO_END};
const uint16_t PROGMEM cb_mb5[] = {         KC_E,    KC_R,    COMBO_END};

const uint16_t PROGMEM cb_z1 [] = {         _MOD_F7, _MOD_F8, COMBO_END};
const uint16_t PROGMEM cb_z2 [] = {_MOD_F6, _MOD_F7,          COMBO_END};
const uint16_t PROGMEM cb_z3 [] = {_MOD_F6, _MOD_F7, _MOD_F8, COMBO_END};
const uint16_t PROGMEM cb_z4 [] = {KC_F2,   KC_F3,            COMBO_END};
const uint16_t PROGMEM cb_z5 [] = {         KC_F3,   KC_F4,   COMBO_END};

const uint16_t PROGMEM cb_mid[] = {KC_BTN1, KC_BTN2,          COMBO_END};

const uint16_t PROGMEM cb_esc[] = {KC_Q,    KC_W,             COMBO_END};
const uint16_t PROGMEM cb_tab[] = {KC_A,    _MOD_S,           COMBO_END};

combo_t key_combos[] = {
    COMBO(cb_mb1, KC_BTN1),
    COMBO(cb_mb2, KC_BTN2),
    COMBO(cb_mb3, KC_BTN3),
    COMBO(cb_mb4, KC_BTN4),
    COMBO(cb_mb5, KC_BTN5),
    COMBO(cb_z1,  KC_BTN1),
    COMBO(cb_z2,  KC_BTN2),
    COMBO(cb_z3,  KC_BTN3),
    COMBO(cb_z4,  KC_BTN4),
    COMBO(cb_z5,  KC_BTN5),
    COMBO(cb_esc, KC_ESC),
    COMBO(cb_tab, KC_TAB),
    COMBO(cb_mid, KC_BTN3),
};
