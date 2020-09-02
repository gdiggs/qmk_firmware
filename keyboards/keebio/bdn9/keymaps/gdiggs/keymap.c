/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |            | Knob 2: Page Dn/Up |
        | Press: Mute       | Space      | Press: Home        |
        | Previous          | Play/Pause | Next               |
        | Layer 1           | Backtick   | Enter              |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_SPACE, KC_HOME,
        KC_MPRV, KC_MPLY  , KC_MNXT,
        MO(1), KC_GRV, KC_ENTER
    ),
    /*
        | N/A   | N/A     | N/A     |
        | Back  | Refresh | Forward |
        | N/A   | Tilde   | Win     |
     */
    [1] = LAYOUT(
        _______, _______, _______,
        KC_WBAK, KC_WREF, KC_WFWD,
        _______, KC_TILDE, KC_LGUI
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}
