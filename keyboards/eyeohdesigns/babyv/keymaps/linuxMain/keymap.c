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
    _QWERTY,
    _GAMES,
    _FUNCTN,
    _NUMBRS,
    _SYMBOL,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMES
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_2u(
        KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,       KC_T,        KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,      KC_F,       KC_G,        KC_H,    KC_J,    KC_K,      KC_L,     KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,       KC_B,        KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH, SFT_T(KC_ENT),
        KC_LGUI,                   KC_LALT,  LT(_NUMBRS, KC_BSPC),     LT(_SYMBOL, KC_SPC), LT(_FUNCTN, KC_ENT),       KC_LCTL
    ),
    [_FUNCTN] = LAYOUT_2u(
        RGB_TOG, BL_STEP,   RGB_MOD,  RGB_RMOD, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        XXXXXXX, XXXXXXX,   XXXXXXX,  RGB_HUI,  RGB_SAI, RGB_VAI,       KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,  KC_PGUP,
        XXXXXXX, KC_QWERTY, KC_GAMES, RGB_HUD,  RGB_SAD, RGB_VAD,       XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,
        CG_TOGG,                      KC_TRNS,        XXXXXXX,              XXXXXXX,      KC_TRNS,                    QK_BOOT
    ),
    [_NUMBRS] = LAYOUT_2u(
        KC_TILD, KC_1,    KC_2,    KC_3,      KC_4,    KC_5,       KC_6,    KC_7,    KC_8,      KC_9,     KC_0,    KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_BTN1, KC_BTN2,    XXXXXXX, KC_MINS, KC_PLUS,   KC_LBRC,  KC_RBRC, KC_PIPE,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX,   KC_WH_U, KC_WH_D,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, KC_RSFT,
        KC_LCTL,                   KC_TRNS,         XXXXXXX,                 KC_ENT,       KC_TRNS,                QK_BOOT
    ),
    [_SYMBOL] = LAYOUT_2u(
        KC_GRV,  KC_EXLM,   KC_AT, KC_HASH, KC_DLR,   KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_HOME,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      XXXXXXX, S(KC_MINS), S(KC_EQL), S(KC_LBRC), S(KC_RBRC), KC_PIPE,
        XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, KC_LBRC,  KC_RBRC,      KC_LCBR, KC_RCBR,    XXXXXXX,   XXXXXXX,    S(KC_SCLN), KC_RSFT,
        KC_LCTL,                   XXXXXXX,      XXXXXXX,               XXXXXXX,     XXXXXXX,                   KC_RALT
    ),
    [_GAMES] = LAYOUT_2u(
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,        KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,        KC_H,    KC_J,    KC_K,      KC_L,     KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,        KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH, SFT_T(KC_ENT),
        KC_LALT,                   MO(_NUMBRS),      KC_SPC,             LT(_SYMBOL, KC_SPC), MO(_FUNCTN),          KC_LCTL
    ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NUMBRS, _SYMBOL, _FUNCTN);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAMES:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMES);
            }
            return false;
    }
    return true;
}
