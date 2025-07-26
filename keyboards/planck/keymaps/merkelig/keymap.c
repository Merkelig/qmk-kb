/* Copyright 2015-2023 Jack Humbert
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
#include "keymap_norwegian_m.h"
#include "g/keymap_combo.h"


enum planck_layers { _QWERTY, _DVORAK, _NUMPAD, _LOWER, _RAISE, _ADJUST };

enum planck_keycodes { QWERTY = SAFE_RANGE, DVORAK, NUMPAD };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Lead | GUI  | ALT  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, QK_LEAD, KC_LGUI, KC_LALT, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Lead | GUI  | Alt  |Lower |    Space    |Raise | RCTL | LSFT |  Up  |PGDN |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  NO_QUOT, NO_COMM, NO_DOT,  NO_P,    NO_Y,    NO_F,    NO_G,    NO_C,    NO_R,    NO_L,    KC_BSPC,
    KC_ESC,  NO_A,    NO_O,    NO_E,    NO_U,    NO_I,    NO_D,    NO_H,    NO_T,    NO_N,    NO_S,    NO_SLSH,
    KC_LSFT, NO_SCLN, NO_Q,    NO_J,    NO_K,    NO_X,    NO_B,    NO_M,    NO_W,    NO_V,    NO_Z,    KC_ENT ,
    KC_LCTL, QK_LEAD, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_RCTL, KC_LSFT, KC_RALT,   KC_PGDN
),

/* numpad
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |   ,  |   .  |      |      |      |      |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DVO  |      |      |      |      |      |      |   0  |   4  |   5  |   6  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Lead | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TAB,  _______, KC_COMM, KC_DOT, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_BSPC,
    DVORAK,  _______, _______, _______, _______, _______, _______, KC_0, KC_4, KC_5, KC_6, KC_SLSH,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_ENT,
    KC_LCTL, QK_LEAD, KC_LGUI, KC_LALT, LOWER, KC_RSFT, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    NO_TILD, NO_EXLM, NO_AT,   NO_HASH, NO_DLR,  NO_PERC, NO_CIRC, NO_AMPR,    NO_ASTR,    NO_LPRN, NO_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   NO_UNDS,    NO_PLUS,    NO_LCBR, NO_RCBR, NO_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    NO_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   NO_MINS, NO_EQL,  NO_LBRC, NO_RBRC, NO_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      |      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |Dvorak|QWERTY|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Debug |      |MUSmod|Aud on|Audoff|AGnorm|Left  | Down | Up   | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, DVORAK, QWERTY, KC_DEL ,
    DB_TOGG, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, _______, KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
       case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
    }
    return true;
}

/* Leader key */


void leader_end_user(void) {
    if (leader_sequence_one_key(KC_BSPC)) {
        SEND_STRING(SS_LALT(SS_LSFT("+")));
    } else if (leader_sequence_one_key(KC_SLSH)) {
        SEND_STRING(SS_LALT(SS_LSFT("-")));
    } else if (leader_sequence_one_key(KC_L)) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DELETE))));
    } else if (leader_sequence_one_key(KC_R)) {
        set_single_persistent_default_layer(_NUMPAD);
    }
}
