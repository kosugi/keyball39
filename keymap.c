/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "alias.h"

#define _MOD_S (LALT_T(KC_S))
#define _MOD_D (LSFT_T(KC_D))
#define _MOD_F (LCTL_T(KC_F))

#define _MOD_J (RCTL_T(KC_J))
#define _MOD_K (RSFT_T(KC_K))
#define _MOD_L (RALT_T(KC_L))

//#define _LT1_m (LT(1,KC_MINS))

#define _MOD_F6 (LALT_T(KC_F6))
#define _MOD_F7 (LSFT_T(KC_F7))
#define _MOD_F8 (LCTL_T(KC_F8))

#define _MOD_LEFT (RCTL_T(KC_LEFT))
#define _MOD_DOWN (RSFT_T(KC_DOWN))
#define _MOD_RGHT (RALT_T(KC_RGHT))

#define _LT1 (LT(2,KC_TAB))
#define _LT2 (SFT_T(KC_SPC))
#define _LT3 (LT(3,KC_LNG1))
#define _RT1 (LT(1,KC_ENT))
#define _RT2 (CTL_T(KC_SPC))
#define _RT3 (_______)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , _MOD_S   , _MOD_D   , _MOD_F   , KC_G     ,                            KC_H     , _MOD_J   , _MOD_K   , _MOD_L   , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , KC_BTN2  , KC_BTN1  , _LT1     , _LT2     , _LT3     ,      _RT1     , _RT2     , _RT3     , _______  , _______  , KC_LWIN
  ),

  [1] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    _S_SLSH  , KC_GRV   , KC_QUOT  , _S_QUOT  , XXXXXXX  ,                            KC_BSPC  , _S_EQL   , KC_LBRC  , KC_RBRC  , _______  ,
    XXXXXXX  , _S_7     , _S_BSLS  , XXXXXXX  , XXXXXXX  ,                            KC_EQL   , _S_8     , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _S_1     , _S_2     , _S_3     , _S_4     , _S_5     ,                            _S_6     , _S_GRV   , _S_9     , _S_0     , KC_BSLS  ,
    _S_SLSH  , KC_GRV   , KC_QUOT  , _S_QUOT  , XXXXXXX  ,                            KC_BSPC  , _S_EQL   , KC_LBRC  , KC_RBRC  , KC_SCLN  ,
    XXXXXXX  , _S_7     , _S_BSLS  , XXXXXXX  , XXXXXXX  ,                            KC_EQL   , _S_8     , _S_LBRC  , _S_RBRC  , _S_SCLN  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , XXXXXXX  ,                            KC_HOME  , KC_PGUP  , KC_UP    , KC_PGDN  , KC_END   ,
    KC_F5    , _MOD_F6  , _MOD_F7  , _MOD_F8  , XXXXXXX  ,                            KC_BSPC  , _MOD_LEFT, _MOD_DOWN, _MOD_RGHT, KC_DEL   ,
    KC_F9    , KC_F10   , KC_F11   , KC_F12   , XXXXXXX  ,                            XXXXXXX  , KC_ENT   , XXXXXXX  , XXXXXXX  , KC_INS   ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  )
};
// clang-format on

//#include "frames.c"
//#include "cat.c"
#include "combo.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

uint8_t get_current_layer_index(void) {
  for (uint8_t i = 1; i < 10; i++) {
    if (layer_state_is(i)) return i;
  }
  return 0;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {

  static uint8_t counter = 0;

  oled_write_ln_P(PSTR(" "), false);
  oled_write_ln_P(PSTR(" "), false);
  oled_write_ln_P(PSTR(" "), false);
  oled_write_ln_P(PSTR(" "), false);
  oled_write_ln_P(PSTR(" "), false);
  oled_write_ln_P(PSTR(" "), false);

  counter = (1 + counter) % NUM_FRAMES;
  switch (counter) {
  case 0: oled_write_raw_P(parrot_0, sizeof parrot_0); break;
  case 1: oled_write_raw_P(parrot_1, sizeof parrot_1); break;
  case 2: oled_write_raw_P(parrot_2, sizeof parrot_2); break;
  case 3: oled_write_raw_P(parrot_3, sizeof parrot_3); break;
  case 4: oled_write_raw_P(parrot_4, sizeof parrot_4); break;
  case 5: oled_write_raw_P(parrot_5, sizeof parrot_5); break;
  case 6: oled_write_raw_P(parrot_6, sizeof parrot_6); break;
  case 7: oled_write_raw_P(parrot_7, sizeof parrot_7); break;
  case 8: oled_write_raw_P(parrot_8, sizeof parrot_8); break;
  case 9: oled_write_raw_P(parrot_9, sizeof parrot_9); break;
  }
}

void oledkit_render_logo_user(void) {

  //static uint8_t counter = 0;

  // layer
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("LAY:"), false);
  oled_write_char(get_current_layer_index() + '0', false);
  oled_write_P(PSTR("-----"), false);

  uint8_t mods = get_mods();
  oled_write_P((mods & MOD_MASK_SHIFT)? PSTR("[SFT]"): PSTR("[   ]"), false);
  oled_write_P((mods & MOD_MASK_CTRL)?  PSTR("[CTL]"): PSTR("[   ]"), false);
  oled_write_P((mods & MOD_MASK_ALT)?   PSTR("[ALT]"): PSTR("[   ]"), false);
  oled_write_P((mods & MOD_MASK_GUI)?   PSTR("[WIN]"): PSTR("[   ]"), false);
  oled_write_P(PSTR("-----"), false);
  //oled_write_char((++counter % 10) + '0', false);
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        oledkit_render_info_user();
    } else {
        oledkit_render_logo_user();
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
  //return !is_keyboard_master() ? rotation: OLED_ROTATION_270;
}
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}

#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _MOD_S:
    case _MOD_D:
    case _MOD_F:
    case _MOD_J:
    case _MOD_K:
    case _MOD_L:
      return 400;
    default:
      return TAPPING_TERM;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_T(KC_SPC):
    case CTL_T(KC_SPC):
      return true;
    default:
      return false;
  }
}

#ifdef BACKLIGHT_ENABLE
void backlight_effects(void) {
    backlight_set(get_current_layer_index());
}
#endif

void keyboard_post_init_user() {
#ifdef RGBLIGHT_ENABLE
    // Force RGB lights to show test animation without writing EEPROM.
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
#endif
}
