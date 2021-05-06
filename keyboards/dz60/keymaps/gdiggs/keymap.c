#include QMK_KEYBOARD_H

enum layer_names {
  BASE, // default layer
  _FN,  // function layer
  _FN2, // 2nd function layer
};

#define CAPS_CTL MT(MOD_LCTL, KC_CAPS)
#define FN_SPACE LT(_FN, KC_SPACE)
#define SH_ESC LSFT(KC_ESC)

enum custom_keycodes {
  TR_TICK = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TR_TICK:
      if (record->event.pressed) {
        SEND_STRING("```");
      } else {
        // when released
      }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_60_ansi(
		KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
	  CAPS_CTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL,   KC_LGUI, KC_LALT,                   FN_SPACE,                  KC_RALT, KC_LGUI, KC_RCTL, MO(1)
  ),

  [_FN] = LAYOUT_60_ansi(
		KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
		KC_TILD,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
		MO(2),     _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
		_______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,   _______, _______,                   _______,                   _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_60_ansi(
		SH_ESC,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,   _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
		_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,   _______, _______,                   _______,                   _______, _______, _______, _______
  ),
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 16, HSV_AZURE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;

}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}
