/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "audio.h"
#include "version.h"

enum preonic_layers {
  _QWERTY,
  _WORKMAN,
  _NUMPAD,
  _EMPTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  QWERTY,
  WORKMAN,
  NUMPAD,
  KC_SDMO,
  KC_VRSN,
  LF_HOME,
};

#define MT_SHFT MT(MOD_RSFT, KC_ENT)   // TAP ENTER, HOLD SHIFT 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_1x2uC( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT_SHFT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  LOWER,      KC_SPC,        RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
),
[_WORKMAN] = LAYOUT_preonic_1x2uC( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_UP,   MT_SHFT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  LOWER,      KC_SPC,        RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
),
[_NUMPAD] = LAYOUT_preonic_1x2uC( \
  KC_ACL0, KC_BTN3, KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
  KC_ACL1, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
  KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
  XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,       XXXXXXX,      RAISE,   KC_P0,   KC_P0,   KC_PDOT, KC_PENT  \
),
[_EMPTY] = LAYOUT_preonic_1x2uC( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,       XXXXXXX,      RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),
[_LOWER] = LAYOUT_preonic_1x2uC( \
  KC_TILD, _______, _______, KC_STOP, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_LPRN, KC_RPRN, KC_VOLD, KC_VOLU, \
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_RBRC, KC_MPLY, KC_DEL,  \
  KC_RCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_P4,   KC_P5,   KC_P6,   KC_LCBR, KC_RCBR, _______, KC_BSLS, \
  KC_RSFT, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_MPRV, KC_MNXT, KC_PGUP, KC_EXEC, \
  KC_ESC,  KC_RGUI, KC_RALT, KC_ESC,  _______,     KC_P0,        _______, LF_HOME, KC_HOME, KC_PGDN, KC_END   \
),
[_RAISE] = LAYOUT_preonic_1x2uC( \
  KC_GRV,  _______, _______, KC_STOP, _______, KC_F1,   KC_F2,   KC_F3,   KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, \
  _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_RBRC, KC_MPLY, KC_DEL,  \
  KC_RCTL, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_LCBR, KC_RCBR, _______, KC_PIPE, \
  KC_RSFT, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_MNXT, KC_PGUP, KC_EXEC, \
  KC_RCTL, KC_RGUI, KC_RALT, KC_RGUI, _______,     _______,      _______, _______, KC_HOME, KC_PGDN, KC_END   \
),
[_ADJUST] = LAYOUT_preonic_1x2uC( \
  DM_REC1, DM_REC2, DM_RSTP, _______, _______, _______, _______, _______, AU_ON,   AU_OFF,  _______, QWERTY,  \
  KC_VRSN, RESET,   DEBUG,   _______, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, WORKMAN, \
  KC_CAPS, EEP_RST, MU_MOD,  _______, _______, _______, _______, _______, MU_ON,   MU_OFF,  _______, NUMPAD,  \
  KC_INS,  CK_RST,  _______, _______, _______, _______, _______, _______, MI_ON,   MI_OFF,  CK_UP,   _______, \
  _______, _______, _______, _______, _______,     _______,      _______, _______, CK_TOGG, CK_DOWN, _______  \
)
};

float end_macro_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
float start_macro_song[][2] = SONG(PLOVER_SOUND);

void dynamic_macro_record_end_user(int8_t direction) {
  if (direction != 0) {
    PLAY_SONG(end_macro_song);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    
  case WORKMAN:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_WORKMAN);
    }
    return false;

  case NUMPAD:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_NUMPAD);
    }
    return false;
    
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;

  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    
  case DM_REC1:
    PLAY_SONG(start_macro_song);
    return false;
    
  case DM_REC2:
    PLAY_SONG(start_macro_song);
    return false;
  
  case KC_VRSN:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    
  case LF_HOME:
    if (record->event.pressed) {
      SEND_STRING ("~/");
    }
    return false;
  }
  
  return true;
};
