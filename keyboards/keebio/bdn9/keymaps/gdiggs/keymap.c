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
#define DISCORD_PTT LGUI(LSFT(KC_B))
#define SCREENSHOT LGUI(LSFT(KC_4))

enum encoder_names {
  _LEFT,
  _RIGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |            | Knob 2: Page Dn/Up |
        | Press: Mute       | Space      | Press: Home        |
        | Previous          | Play/Pause | Next               |
        | Layer 1           | Screenshot | Discord PTT        |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_SPACE, KC_HOME,
        KC_MPRV, KC_MPLY  , KC_MNXT,
        TT(1), SCREENSHOT, DISCORD_PTT
    ),
    /*
        | N/A   | Uo      | N/A     |
        | Left  | Down    | Right   |
        | N/A   | Tilde   | Win     |
     */
    [1] = LAYOUT(
        _______, KC_UP, _______,
        KC_LEFT, KC_DOWN, KC_RIGHT,
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
      if (IS_LAYER_ON(1)) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
      } else {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
      }
    }
}
