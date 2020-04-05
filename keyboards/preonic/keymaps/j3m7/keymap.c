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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  MC_HELP,
  MC_FREK
};

#define MT_SHFT MT(MOD_RSFT, KC_ENT)   // TAP ENTER, HOLD SHIFT 

#define LF_DIE LALT(KC_F4)   // Linux close window
#define LF_DOIT LALT(KC_F2)  // Linux run command

#define TD_CLES TD(TD_CONTROL_ESCAPE)
#define TD_T1LD TD(TD_1_TILDE)
#define TD_QBSH TD(TD_QUOTE_BACKSLASH)
#define TD_PARN TD(TD_PAIR_PARN)
#define TD_BRAC TD(TD_PAIR_BRAC)
#define TD_CBRC TD(TD_PAIR_CBRC)

enum {
      TD_CONTROL_ESCAPE = 0,
      TD_1_TILDE,
      TD_QUOTE_BACKSLASH,
      TD_PAIR_PARN,
      TD_PAIR_BRAC,
      TD_PAIR_CBRC,
};

qk_tap_dance_action_t tap_dance_actions[] =
  {
   [TD_CONTROL_ESCAPE] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_ESC),
   [TD_1_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_GRV),
   [TD_QUOTE_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_BSLS),
   [TD_PAIR_PARN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
   [TD_PAIR_BRAC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
   [TD_PAIR_CBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
  TD_T1LD, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  TD_CLES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD_QBSH, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT_SHFT, \
  KC_LCTL, KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
),

[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, _______, _______, LF_DIE,  _______, KC_NLCK, KC_PSLS, KC_PAST, TD_PARN, KC_RPRN, KC_VOLD, KC_VOLU, \
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_P7,   KC_P8,   KC_P9,   TD_BRAC, KC_RBRC, KC_MPLY, KC_DEL, \
  KC_RCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_P4,   KC_P5,   KC_P6,   TD_CBRC, KC_RCBR, _______, KC_BSLS, \
  KC_RSFT, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_MPRV, KC_MNXT, KC_PGUP, LF_DOIT, \
  KC_ESC,  _______, KC_RALT, KC_RGUI, _______, KC_P0,   KC_P0,   _______, _______, KC_HOME, KC_PGDN, KC_END   \
),

[_RAISE] = LAYOUT_preonic_grid(						\
  KC_GRV,  _______, _______, LF_DIE,  _______, KC_F1,   KC_F2,   KC_F3,   TD_PARN, KC_RPRN, KC_VOLD, KC_VOLU, \
  _______, LF_DIE,  _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   TD_BRAC, KC_RBRC, KC_MPLY, KC_DEL, \
  KC_RCTL, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   TD_CBRC, KC_RCBR, _______, KC_PIPE, \
  KC_RSFT, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_MNXT, KC_PGUP, LF_DOIT, \
  KC_RCTL, _______, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END \
),

[_ADJUST] = LAYOUT_preonic_grid(					\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______, \
  KC_CAPS, EEP_RST, MU_MOD,  AU_ON,   AU_OFF,  _______, MC_HELP, MC_FREK, _______, _______, _______, _______, \
  KC_INS,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, CK_UP,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_DOWN, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case LOWER:
	  if (record->event.pressed) {
	    layer_on(_LOWER);
	    update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
	    layer_off(_LOWER);
	    update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  return false;
	  break;
	  
	case RAISE:
	  if (record->event.pressed) {
	    layer_on(_RAISE);
	    update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
	    layer_off(_RAISE);
	    update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  return false;
	  break;
  }
  return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
	muse_offset++;
      } else {
	muse_offset--;
      }
    } else {
      if (clockwise) {
	muse_tempo+=1;
      } else {
	muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
	case 0:
	    if (active) {
		layer_on(_ADJUST);
	    } else {
		layer_off(_ADJUST);
	    }
	    break;
	case 1:
	    if (active) {
		muse_mode = true;
	    } else {
		muse_mode = false;
	    }
    }
}


void matrix_scan_user(void) {

#ifdef AUDIO_ENABLE
    if (muse_mode) {
	if (muse_counter == 0) {
	    uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
	    if (muse_note != last_muse_note) {
		stop_note(compute_freq_for_midi_note(last_muse_note));
		play_note(compute_freq_for_midi_note(muse_note), 0xF);
		last_muse_note = muse_note;
	    }
	}
	muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
	if (muse_counter) {
	    stop_all_notes();
	    muse_counter = 0;
	}
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
