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
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J LGUI_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_SCLN LSFT_T(KC_SCLN)


//////////////////// Combo key definitions
const uint16_t PROGMEM test_combo1[] = {HOME_F, HOME_D, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {HOME_J, HOME_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(leader_combo, QK_LEAD),
};
//////////////////// end of combo key definitions







//////////////////// Macros definitions
enum custom_keycodes {
    COPY = SAFE_RANGE,
    CUT,
    PASTE,
    UNDO,
    REDO,
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
    } else if (leader_sequence_one_key(DV_LCBR)) {
        SEND_STRING("/**");
    // Leader S => ()<left>
    } else if (leader_sequence_one_key(KC_A)) {
        SEND_STRING("af");
    // Leader D => []<left>
    } else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING("tc");
    // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_D)) {
        SEND_STRING("te");
     // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("for");
     // Leader F => {}<left>
    } else if (leader_sequence_one_key(KC_G)) {
        SEND_STRING("function");
        // Leader F => {}<left>
    } else if (leader_sequence_one_key(DV_LPRN)) {
        SEND_STRING("cr");
        // Leader Tab => if
    } else if (leader_sequence_one_key(KC_TAB)) {
        SEND_STRING("if");
        // Leader Tab => if
    } else if (leader_sequence_one_key(KC_DEL)) {
        SEND_STRING("map");
         // Leader Tab => if
    } else if (leader_sequence_one_key(DV_SCLN)) {
        SEND_STRING("cl");
    }
}
//////////////////// end of leader key definitions


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DV_LCBR,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LEFT_BRACKET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DV_LPRN,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,LT(2,KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DV_LBRC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RIGHT_PAREN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                           LT(4,KC_DEL), LT(3,KC_BSPC),LT(5,KC_TAB),   DV_SCLN,LT(1,KC_SPC), MT(MOD_LALT | MOD_RALT,KC_ENT)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DV_RCBR, KC_RBRC,    KC_7,    KC_8,    KC_9, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DV_RPRN, DV_SCLN,    KC_4,    KC_5,    KC_6, KC_RIGHT_PAREN,               XXXXXXX, KC_LGUI, KC_RALT, KC_LCTL, KC_LSFT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DV_RBRC, KC_PAST,    KC_1,    KC_2,    KC_3, KC_AMPERSAND,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          DV_LABK, KC_0, DV_RABK,     XXXXXXX,  XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F21, KC_F18,   KC_F7,   KC_F8,   KC_F9, KC_F15,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F20, KC_F17,   KC_F4,   KC_F5,   KC_F6, KC_F14,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F19, KC_F16,   KC_F1,   KC_F2,   KC_F3, KC_F13,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_F10, KC_F11, KC_F12,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_INS, KC_HOME, KC_PGDN,  KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

      [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WBAK, KC_WREF, KC_WSCH, KC_WFWD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_WSCH, KC_WFWD, KC_WREF, KC_WBAK, XXXXXXX,                      XXXXXXX, KC_MNXT, KC_VOLD, KC_VOLU,KC_MPRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),
       [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,    UNDO,     CUT,    COPY,   PASTE,    REDO,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN3, KC_BTN2, KC_BTN1
                                      //`--------------------------'  `--------------------------'
  )
};

