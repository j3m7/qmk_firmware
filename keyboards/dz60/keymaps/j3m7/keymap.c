#include QMK_KEYBOARD_H

#define LF_DIE LALT(KC_F4)   // Linux close window 
#define LF_DOIT LALT(KC_F2)  // Linux run command

#define MF_PSCR  LALT(LSFT(KC_4)) // MacOS print screen
#define MF_DOIT LALT(KC_SPC) // MacOS find program
#define MF_DIE LCMD(KC_W)    // MacOS close window


/* Required improvements from MacOS map
   Make LCTRL switch to LALT after being pressed for long enough.
 */

enum layers {
	     _LB = 0,    // Linux base OS
	     _MB,        // MacOS base layer
	     _CT,        // Control layer
	     _LF,        // Linux function 
	     _MF,        // MacOS function 
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
   /*  LAYER 0 (LINUX BASE)
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BKS│ ` │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ BKSP│
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │ CTRL │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ SHIFT│PSC│
    * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴───┤
    * │CTRL│LYR1│ ALT│           SPACE        │ ALT│LYR2│MENU│CTRL│
    * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
   
   [_LB] = LAYOUT(
	  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,
	  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	  KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PSCR,
	  KC_LCTL, MO(_LF), KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(_CT), KC_NO,   KC_RCMD, KC_RCTL),

   // Linux function
   [_LF] LAYOUT(
	  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_PAUS,
 	  KC_TAB,  LF_DIE,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,   KC_NO,             KC_NO,
	  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_PGUP, LF_DOIT,
	  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   UC(241), KC_NO,   KC_NO,   KC_END,  KC_PGDN, KC_UP,   KC_CAPS,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_LEFT, KC_NO,   KC_DOWN, KC_RGHT),
   
   // Mouse layer, keyboard control
   [_CT] = LAYOUT(
	  DF(_LB), DF(_MB), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, TERM_ON,  TERM_OFF,
	  KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             RESET,
	  KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	  KC_ASTG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),
   
   // MacOS
   [_MB] = LAYOUT(
	  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_GRV,
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,
	  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	  KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MF_PSCR,
	  KC_LCTL, MO(_MF), KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, MO(_CT), KC_NO,   KC_RCMD, KC_RCTL),
   
   /*  LAYER N (MACOS BASE)
    *  MACOS KEYBOARD SETTINGS
    *  CAPS LOCK KEY: CAPS LOCK
    *  CONTROL KEY: Control
    *  OPTION KEY: Command
    *  COMMAND KEY: Option
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BKS│ ` │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ BKSP│
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │ CTRL │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ SHIFT│PSC│
    * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴───┤
    * │CTRL│LYR1│ ALT│           SPACE        │ ALT│LYR2│MENU│CTRL│
    * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
    */
   [_MF] = LAYOUT(
	  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_PAUS,
 	  KC_TRNS, MF_DIE,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,   KC_NO,             RESET,
	  KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_PGUP, MF_DOIT,
	  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   UC(241), KC_NO,   KC_NO,   KC_END,  KC_PGDN, KC_UP,   KC_CAPS,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_LEFT, KC_NO,   KC_DOWN, KC_RGHT),
  };
