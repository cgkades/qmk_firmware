/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

enum layer_names {
    _QWERTY,
    _GAMES,
    _LOWER,
    _RAISE,
    _ADJUST,    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_1,    KC_LGUI,   KC_LALT, LT(_LOWER, KC_BSPC), KC_CAPS,                     KC_NUM, LT(_RAISE, KC_SPC),   LT(_ADJUST, KC_ENT), KC_RCTL, KC_4
                                      //`--------------------------'  `--------------------------'

  ),

  [_GAMES] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_LGUI,   KC_LALT, LT(_LOWER, KC_SPC), KC_CAPS,                     KC_NUM, LT(_RAISE, KC_BSPC),   LT(_ADJUST, KC_ENT), KC_RCTL, KC_4
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,                               XXXXXXX, KC_MINUS, KC_EQUAL,   KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRV, KC_EQL,  KC_PLUS, KC_LCBR, KC_RCBR,                                KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                 KC_ESC,  KC_LGUI, _______,  KC_SPC, KC_CAPS,                     KC_NUM,     KC_ENT,   MO(3), KC_RALT, KC_4
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX,  LSFT(KC_MINUS), LSFT(KC_EQUAL),   LSFT(KC_LBRC), LSFT(KC_RBRC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TILD, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_COLN, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_ESC,  KC_LGUI,   MO(_ADJUST),  KC_SPC, KC_CAPS,      KC_NUM, KC_ENT, _______, KC_RALT, KC_4
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_PIPE, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(_QWERTY), TO(_GAMES), XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_1,  KC_LGUI,   MO(_ADJUST),  KC_SPC, KC_CAPS,      KC_NUM, KC_ENT, _______, KC_RALT, KC_4
                                      //`--------------------------'  `--------------------------'
  )
};
