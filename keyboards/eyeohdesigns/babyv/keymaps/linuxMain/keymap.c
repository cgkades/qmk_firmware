/* Copyright 2020 Eye Oh! Designs
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _LINUX,
    _FUNCTN,
    _NUMBRS,
    _SYMBOL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_LINUX] = LAYOUT_2u(
        KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,       KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,      KC_F,       KC_G,    KC_H,    KC_J,    KC_K,      KC_L,     KC_SCLN, KC_QUOT, 
        KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,       KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH, SFT_T(KC_ENT),
        KC_LCTL,                   KC_LALT,      LT(_NUMBRS, KC_BSPC), LT(_SYMBOL, KC_SPC),   MO(_FUNCTN),       KC_LGUI
    ),
   [_FUNCTN] = LAYOUT_2u(
        KC_TILD,  KC_UP,    KC_UP, RGB_TOG,    BL_STEP,    KC_T,    KC_Y,    KC_U,       KC_PGUP,    RGB_MOD,  RGB_RMOD, KC_DEL,
        KC_ESC, KC_LEFT, KC_DOWN, KC_RIGHT,   KC_U,       KC_MINS, KC_EQL,  KC_HOME,    KC_PGDN,    KC_RIGHT, KC_QUOT,  KC_BSLS,
        KC_LSFT, RGB_HUI, RGB_HUD, RGB_SAI,    RGB_SAD,    KC_LBRC, KC_RBRC, RGB_VAI,    RGB_VAD,    KC_LBRC,  KC_RBRC,  KC_RSFT,
        KC_LCTL,                    KC_TRNS,      KC_TRNS,              KC_SPC,      KC_TRNS,                            RESET
    ),
    [_NUMBRS] = LAYOUT_2u(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,      KC_F6,         KC_F7,   KC_F8,   KC_F9,     KC_F10,   KC_F11,  KC_F12,
        KC_MUTE, KC_1,    KC_2,    KC_3,      KC_4,       KC_5,          KC_6,    KC_7,    KC_8,      KC_9,     KC_0,    KC_PIPE,
        KC_CAPS, KC_EXLM, KC_AT,   KC_HASH,   KC_LBRC,    KC_RBRC,       KC_LCBR, KC_RCBR, KC_ASTR,   KC_LPRN,  KC_RPRN, KC_RSFT,
        KC_LCTL,                   KC_TRNS,         KC_TRNS,                 KC_SPC,       KC_TRNS,                      KC_LGUI
    ),
    [_SYMBOL] = LAYOUT_2u(
        KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_UNDS, XXXXXXX,
        XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,      KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
        XXXXXXX,                   XXXXXXX,      XXXXXXX,               XXXXXXX,     XXXXXXX,                   KC_LGUI
    ),
};