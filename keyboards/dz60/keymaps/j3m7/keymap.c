#include QMK_KEYBOARD_H

#define KC_DIE LALT(KC_F4) 
#define KC_DOIT LALT(KC_F2) 

#define KC_OSX_PSCR  SCMD(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   // Linux
   LAYOUT(
	  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_GRV,
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,
	  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	  KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PSCR,
	  KC_LCTL, MO(1),   KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(2),   KC_NO,   KC_RCMD, KC_RCTL),
   
   LAYOUT(
	  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_PAUS,
 	  KC_TAB,  KC_DIE,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,   KC_NO,             KC_NO,
	  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_PGUP, KC_DOIT,
	  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   UC(241), KC_NO,   KC_NO,   KC_END,  KC_PGDN, KC_UP,   KC_CAPS,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_LEFT, KC_NO,   KC_DOWN, KC_RGHT),
   
   // Mouse layer, keyboard control
   LAYOUT(
	  DF(0),   DF(0),   DF(3),   M(3),    M(4),    M(5),    M(6),    M(7),    M(8),    M(9),    KC_MUTE, KC_VOLD, KC_VOLU, TERM_ON,  TERM_OFF,
	  KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             RESET,
	  KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	  KC_ASTG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),
   
   // MacOS
   LAYOUT(
	  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_GRV,
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,
	  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	  KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_OSX_PSCR,
	  KC_LCTL, KC_LCMD, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(2),   KC_NO,   KC_RCMD, KC_RCTL),
   
   LAYOUT(
	  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_PAUS,
 	  KC_TRNS, KC_DIE,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,           RESET,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_PGUP, KC_DOIT,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC(241), KC_TRNS, KC_TRNS, KC_END,  KC_PGDN, KC_UP,   KC_CAPS,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_LEFT, KC_TRNS, KC_DOWN, KC_RGHT),
  };

