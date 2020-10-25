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

LEADER_EXTERNS();

enum preonic_layers {
  _QWERTY,
  _EMPTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
};


#define MT_SHFT MT(MOD_RSFT, KC_ENT)   // TAP ENTER, HOLD SHIFT
#define MT_CTRL MT(MOD_RCTL, KC_QUOT)  // TAP QUOTE, HODL LCTL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_preonic_1x2uC( \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT_CTRL, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT_SHFT, \
        KC_LEAD, KC_LGUI, KC_LALT, KC_ESC,  LOWER,      KC_SPC,        RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
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
        _______, KC_RGUI, KC_RALT, KC_ESC,  _______,     KC_P0,        _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [_RAISE] = LAYOUT_preonic_1x2uC( \
        KC_GRV,  _______, _______, KC_STOP, _______, KC_F1,   KC_F2,   KC_F3,   KC_LCBR, KC_RCBR, KC_VOLD, KC_VOLU, \
        _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_RBRC, KC_MPLY, KC_DEL,  \
        KC_RCTL, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_LCBR, KC_RCBR, _______, KC_PIPE, \
        KC_RSFT, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_MNXT, KC_PGUP, KC_EXEC, \
        _______, KC_RGUI, KC_RALT, KC_RGUI, _______,     _______,      _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [_ADJUST] = LAYOUT_preonic_1x2uC( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
        _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, \
        _______, EEP_RST, MU_MOD,  _______, _______, _______, _______, _______, MU_ON,   MU_OFF,  _______, _______, \
        _______, CK_RST,  _______, _______, _______, _______, _______, _______, MI_ON,   MI_OFF,  _______, _______, \
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______  \
    )
};

void print_manual(void) {
    SEND_STRING("quick help for " QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_VERSION "\n");
    SEND_STRING("\nLeader key: (L=Code):\n");
    SEND_STRING("L + h -> Print quickhelp\n");
    SEND_STRING("L + p -> PrintScreen\n");
    SEND_STRING("L + c -> CapsLock\n");
    SEND_STRING("L + i -> Insert\n");
    SEND_STRING("L + LAlt + (0-8) -> Ctrl + Alt + F#\n");
    SEND_STRING("L + Any Number/+/- -> F#\n");
    SEND_STRING("L + LAlt + BSPC -> Ctrl + Alt + Del\n");
    SEND_STRING("L + c -> Caps\n");
    SEND_STRING("L + v -> Print version/build info\n");

    SEND_STRING("\nMod Tap: (Tap : Hold)\n");
    SEND_STRING("Enter : RShift\n");
    SEND_STRING("Quote(') : RCtrl\n");

    SEND_STRING("\nAdjust Layer: Prefix with (Lower + Raise)\n");
    SEND_STRING("Q -> RESET\n");
    SEND_STRING("A -> RESET EEPROM\n");
    SEND_STRING("Any Number, '+', '-' -> F#\n");

    SEND_STRING("\nMouse Keys: Prefix with Lower\n");
    SEND_STRING("W,A,S,D -> U,D,L,R\n");
    SEND_STRING("Q,E - Left, right click\n");
    SEND_STRING("R,F - Up, Down wheel scroll\n");

}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_C) tap_code(KC_CAPS);
    SEQ_ONE_KEY(KC_I) tap_code(KC_INSERT);
    SEQ_ONE_KEY(KC_P) tap_code(KC_PSCR);

    SEQ_ONE_KEY(KC_V) {
        SEND_STRING("QMK version " QMK_VERSION " running on " QMK_KEYBOARD ":" QMK_KEYMAP ", built " QMK_BUILDDATE);
    }

    SEQ_ONE_KEY(KC_H) {
        print_manual();
    }

    // Emulate Ctrl+Alt+F# for console switching
    SEQ_TWO_KEYS(KC_LALT, KC_1) tap_code16(C(A(KC_F1)));
    SEQ_TWO_KEYS(KC_LALT, KC_2) tap_code16(C(A(KC_F2)));
    SEQ_TWO_KEYS(KC_LALT, KC_3) tap_code16(C(A(KC_F3)));
    SEQ_TWO_KEYS(KC_LALT, KC_4) tap_code16(C(A(KC_F4)));
    SEQ_TWO_KEYS(KC_LALT, KC_5) tap_code16(C(A(KC_F5)));
    SEQ_TWO_KEYS(KC_LALT, KC_6) tap_code16(C(A(KC_F6)));
    SEQ_TWO_KEYS(KC_LALT, KC_7) tap_code16(C(A(KC_F7)));
    SEQ_TWO_KEYS(KC_LALT, KC_8) tap_code16(C(A(KC_F8)));

    // Emulate the 3 finger salute.
    SEQ_TWO_KEYS(KC_LALT, KC_BSPC) tap_code16(C(A(KC_DEL)));

    // Function keys
    SEQ_ONE_KEY(KC_1) tap_code(KC_F1);
    SEQ_ONE_KEY(KC_2) tap_code(KC_F2);
    SEQ_ONE_KEY(KC_3) tap_code(KC_F3);
    SEQ_ONE_KEY(KC_4) tap_code(KC_F4);
    SEQ_ONE_KEY(KC_5) tap_code(KC_F5);
    SEQ_ONE_KEY(KC_6) tap_code(KC_F6);
    SEQ_ONE_KEY(KC_7) tap_code(KC_F7);
    SEQ_ONE_KEY(KC_8) tap_code(KC_F8);
    SEQ_ONE_KEY(KC_9) tap_code(KC_F9);
    SEQ_ONE_KEY(KC_0) tap_code(KC_F10);
    SEQ_ONE_KEY(KC_MINS) tap_code(KC_F11);
    SEQ_ONE_KEY(KC_EQL) tap_code(KC_F12);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
  }
  return true;
};


