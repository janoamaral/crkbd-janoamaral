/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "keymap_spanish.h"
#include "sendstring_spanish.h"

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_O LCTL_T(KC_O)
#define HOME_E LALT_T(KC_E)
#define HOME_U LGUI_T(KC_U)

// Right-hand home row mods
#define HOME_R LGUI_T(KC_R)
#define HOME_T LALT_T(KC_T)
#define HOME_N LCTL_T(KC_N)
#define HOME_S LSFT_T(KC_S)


//////////////////// Combo key definitions
const uint16_t PROGMEM test_combo1[] = {HOME_U, HOME_E, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {HOME_R, HOME_T, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(leader_combo, KC_F9),
};
//////////////////// end of combo key definitions







//////////////////// Macros definitions
enum custom_keycodes {
    COPY = SAFE_RANGE,
    CUT,
    PASTE,
    UNDO,
    REDO,
    SELECT_ALL,
    BOOST,
};

// Process macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COPY: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("c"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case CUT:
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("x"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case PASTE:
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("v"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case UNDO:
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("z"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case REDO:
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("y"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case SELECT_ALL:
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_LCTL("a"));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    case BOOST:
      if (record->event.pressed){
        SEND_STRING(SS_TAP(X_F5)SS_TAP(X_R));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
  }
  return true;
};
//////////////////// end of leader key sequences




//////////////////// Leader key definitions
// Process leader key sequences
void leader_end_user(void) {

    // Leader M => Alt+F4
    if (leader_sequence_one_key(KC_M)) {
        tap_code16(LALT(KC_F4));
    // Leader A => =>
    // } else if (leader_sequence_one_key(DV_LCBR)) {
    //     SEND_STRING("/**"SS_TAP(X_ENTER));
    // Leader S => ()<left>
    } else if (leader_sequence_one_key(KC_A)) {
        SEND_STRING("map"SS_TAP(X_ENTER));
    // Leader D => []<left>
    } else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING("for"SS_TAP(X_ENTER));
    // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_D)) {
        SEND_STRING("function"SS_TAP(X_ENTER));
     // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("if"SS_TAP(X_ENTER));
     // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_G)) {
        SEND_STRING("te"SS_TAP(X_ENTER));
        // Leader F => {}<left>
    // } else if (leader_sequence_one_key(DV_LPRN)) {
    //     SEND_STRING("cr"SS_TAP(X_ENTER));
        // Leader Tab => if
    } else if (leader_sequence_one_key(KC_DEL)) {
        SEND_STRING("ce"SS_TAP(X_ENTER));
        // Leader Tab => if
    } else if (leader_sequence_one_key(KC_BSPC)) {
        SEND_STRING("cl"SS_TAP(X_ENTER));
         // Leader Tab => if
    } else if (leader_sequence_one_key(KC_TAB)) {
        SEND_STRING("cv"SS_TAP(X_ENTER));
    }
}
//////////////////// end of leader key definitions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         TG(8),  KC_DOT,KC_COMMA, ES_NTIL,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_H,   KC_L,  ES_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_VOLU,  HOME_A,  HOME_O,  HOME_E,  HOME_U,    KC_I,                         KC_D,  HOME_R,  HOME_T,  HOME_N,HOME_S,  ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_VOLD, ES_MINS,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,   KC_Z, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                           LT(5,KC_DEL), LT(3,KC_BSPC),LT(4,KC_TAB),   LT(2,KC_MPLY),LT(1,KC_SPC), LT(6,KC_ENT)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( // NUMERIC
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, ES_PLUS,    KC_7,    KC_8,    KC_9, ES_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, ES_MINS,    KC_4,    KC_5,    KC_6,  ES_EQL,                      XXXXXXX, KC_LGUI, KC_RALT, KC_LCTL, KC_LSFT, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, ES_ASTR,    KC_1,    KC_2,    KC_3, KC_BACKSLASH,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ES_PLUS, KC_0, ES_MINS,       XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3( // FUNCTION
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F21, KC_F18,   KC_F7,   KC_F8,   KC_F9, KC_F15,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F20, KC_F17,   KC_F4,   KC_F5,   KC_F6, KC_F14,                         XXXXXXX, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F19, KC_F16,   KC_F1,   KC_F2,   KC_F3, KC_F13,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_F10, KC_F11, KC_F12,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3( // MOVEMENT
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS,KC_HOME, KC_PGDN,  KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

      [4] = LAYOUT_split_3x6_3( // MULTIMEDIA
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WBAK, KC_WREF, KC_WSCH, KC_WFWD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,SELECT_ALL,   PASTE,     CUT,    COPY, XXXXXXX,                      XXXXXXX, KC_MNXT, KC_VOLD, KC_VOLU,KC_MPRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, KC_MUTE
          //`--------------------------'  `--------------------------'
  ),
      [5] = LAYOUT_split_3x6_3( // MOUSE
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,    UNDO,     CUT,    COPY,   PASTE,    REDO,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN3, KC_BTN2, KC_BTN1
                                      //`--------------------------'  `--------------------------'
  ),
      [6] = LAYOUT_split_3x6_3( // SYMBOLS 1
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, ES_PERC, ES_IQUE, ES_QUES, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_TILD,  ES_EQL, ES_SLSH, ES_LABK, ES_RABK, ES_QUOT,                       ES_DLR, ES_LCBR, ES_RCBR, ES_ASTR, LT(7,ES_SCLN), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, ES_LBRC, ES_RBRC, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            ES_AT, ES_SCLN, ES_AMPR,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
      [7] = LAYOUT_split_3x6_3( // SYMBOLS 2
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, ES_IEXL, ES_EXLM, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_HASH, ES_BSLS, ES_LPRN, ES_RPRN, ES_DQUO,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, ES_PIPE, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
      [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______,    KC_Q,    KC_W,   KC_E,     KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  ES_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,   KC_D,     KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,KC_SCLN, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,   KC_C,     KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_F5,   KC_SPC,  BOOST,     KC_F12,  KC_SPC,   KC_ENT
                                      //`--------------------------'  `--------------------------'

  )
};

