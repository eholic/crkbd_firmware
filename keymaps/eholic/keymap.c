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
#include <stdio.h>

#include "keymap_japanese.h"
#include "lib/keymap_us2jp.h"
#include "lib/mylayer.h"

enum custom_keycodes {
  CS_ESC = NEW_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KM_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LGUI_T(KC_TAB),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                   KC_LALT, LT(KM_SIG, JP_MHEN), LT(KM_NUM, KC_ENT),  LT(KM_NUM, KC_SPC), LT(KM_ARW, JP_HENK), CS_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [KM_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                  KC_LGUI, LT(KM_SIG,  KC_LNG2), LT(KM_NUM, KC_ENT),  LT(KM_NUM, KC_SPC), LT(KM_ARW,  KC_LNG1), CS_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [KM_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______,  JP_EQL, JP_UNDS, JP_MINS, JP_PLUS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,MO(KM_FN), MO(KM_FN), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_SIG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       JP_GRV, _______, _______, _______, _______, _______,                      _______, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      JP_TILD, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC,                      JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  JP_YEN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_ARW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, TG(KM_MAC)
                                      //`--------------------------'  `--------------------------'
  )
};

/*
        {  24,  23,  18,  17,  10,   9 },          {  36,  37,  44,  45,  50,   51 },
        {  25,  22,  19,  16,  11,   8 },          {  35,  38,  43,  46,  49,   52 },
        {  26,  21,  20,  15,  12,   7 },          {  34,  39,  42,  47,  48,   53 },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6 }, { 33,  40,  41,  NO_LED, NO_LED, NO_LED }
*/
// clang-format on

#ifdef RGB_MATRIX_ENABLE

void set_color(int index, uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue) {
  HSV hsv = (HSV){hsvred, hsvgreen, hsvblue};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (rgb_matrix_get_mode() != 1) {
    return false;
  }

  rgb_matrix_set_color_all(RGB_OFF);

  switch (get_highest_layer(layer_state | default_layer_state)) {
    case KM_NUM:
      if (is_keyboard_left()) {
        // left
        set_color(8, HSV_YELLOW);
        set_color(11, HSV_YELLOW);
        set_color(16, HSV_YELLOW);
        set_color(19, HSV_YELLOW);
        set_color(22, HSV_YELLOW);
      } else {
        // right
        set_color(35, HSV_YELLOW);
        set_color(38, HSV_YELLOW);
        set_color(43, HSV_YELLOW);
        set_color(46, HSV_YELLOW);
        set_color(49, HSV_YELLOW);
        set_color(37, HSV_BLUE);
        set_color(44, HSV_BLUE);
        set_color(45, HSV_BLUE);
        set_color(50, HSV_BLUE);

        set_color(51, HSV_RED);
      }
      break;
    case KM_SIG:
      if (is_keyboard_left()) {
        // left
        set_color(8, HSV_BLUE);
        set_color(11, HSV_BLUE);
        set_color(16, HSV_BLUE);
        set_color(18, HSV_BLUE);
        set_color(19, HSV_BLUE);
        set_color(22, HSV_BLUE);
        set_color(23, HSV_BLUE);
      } else {
        // right
        set_color(35, HSV_BLUE);
        set_color(37, HSV_BLUE);
        set_color(38, HSV_BLUE);
        set_color(43, HSV_BLUE);
        set_color(44, HSV_BLUE);
        set_color(45, HSV_BLUE);
        set_color(46, HSV_BLUE);
        set_color(49, HSV_BLUE);
        set_color(50, HSV_BLUE);
        set_color(52, HSV_BLUE);

        set_color(51, HSV_RED);
      }
      break;
    case KM_FN:
      if (is_keyboard_left()) {
        // left
        set_color(8, HSV_GOLDENROD);
        set_color(11, HSV_GOLDENROD);
        set_color(16, HSV_GOLDENROD);
        set_color(19, HSV_GOLDENROD);
        set_color(22, HSV_GOLDENROD);
        set_color(25, HSV_GOLDENROD);
      } else {
        // right
        set_color(35, HSV_GOLDENROD);
        set_color(38, HSV_GOLDENROD);
        set_color(43, HSV_GOLDENROD);
        set_color(46, HSV_GOLDENROD);
        set_color(49, HSV_GOLDENROD);
        set_color(52, HSV_GOLDENROD);
      }
      break;
    case KM_ARW:
      if (is_keyboard_left()) {
        // left
        set_color(11, HSV_MAGENTA);
        set_color(12, HSV_MAGENTA);
        set_color(15, HSV_MAGENTA);
        set_color(16, HSV_MAGENTA);
        set_color(19, HSV_MAGENTA);
        set_color(20, HSV_MAGENTA);
        set_color(21, HSV_MAGENTA);
        set_color(22, HSV_MAGENTA);
      } else {
        // right
        set_color(35, HSV_GREEN);
        set_color(38, HSV_GREEN);
        set_color(43, HSV_GREEN);
        set_color(46, HSV_GREEN);

        set_color(36, HSV_ORANGE);
        set_color(37, HSV_BLUE);
        set_color(44, HSV_BLUE);
        set_color(45, HSV_ORANGE);

        // show win/mac
        if (IS_LAYER_ON_STATE(layer_state, KM_MAC)) {
          set_color(41, HSV_CORAL);
        } else {
          set_color(41, HSV_BLUE);
        }
      }
      break;
    default:
      break;
  }
  return false;
}

#endif  // RGB_MATRIX_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CS_ESC:
      if (record->event.pressed) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
          case KM_WIN:
            tap_code16(JP_MHEN);
            break;
          case KM_MAC:
            tap_code16(KC_LNG2);
            break;
        }
        tap_code16(KC_ESC);
      }
      return false;  // Skip all further processing of this key
    default:
      break;
  }
  return us2jp(keycode, record);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case KM_WIN:
      set_color(41, HSV_BLUE);
      break;
    case KM_MAC:
      set_color(41, HSV_RED);
      break;
    default:
      break;
  }
  return state;
}
