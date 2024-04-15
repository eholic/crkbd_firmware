#include QMK_KEYBOARD_H

#include "keymap_japanese.h"
#include "lib/keymap_us2jp.h"
#include "lib/mylayer.h"
#include "lib/ledmap.h"

enum custom_keycodes {
  CS_ESC = NEW_SAFE_RANGE,
};

// clang-format off
#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KM_WIN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
LGUI_T(KC_TAB),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_WH_L,    KC_WH_R,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_CPNL,    KC_PSCR,    KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                   KC_LALT, LT(KM_SIG, JP_MHEN), LT(KM_NUM, KC_SPC),  LT(KM_NUM, KC_SPC), LT(KM_ARW, JP_HENK), CS_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_MAC] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_WH_L,    KC_WH_R,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LPAD,    KC_MCTL,    KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                  KC_LGUI, LT(KM_SIG,  KC_LNG2), LT(KM_NUM, KC_SPC),  LT(KM_NUM, KC_SPC), LT(KM_ARW,  KC_LNG1), CS_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    _______, _______,  JP_EQL, JP_UNDS, JP_MINS, JP_PLUS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,MO(KM_FN), MO(KM_FN), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_FN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_SIG] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       JP_GRV, _______, _______, _______, _______, _______, _______,    _______, _______, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      JP_TILD, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC, _______,    _______, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  JP_YEN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [KM_ARW] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, KC_WBAK, KC_PGDN, KC_PGUP, KC_WFWD, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, _______,    _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, TG(KM_MAC)
                                      //`--------------------------'  `--------------------------'
  )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [KM_WIN] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_R, KC_WH_L), },
  [KM_MAC] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_R, KC_WH_L), },
  [KM_NUM] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_R, KC_WH_L), },
  [KM_FN]  = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_R, KC_WH_L), },
  [KM_SIG] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_R, KC_WH_L), },
  [KM_ARW] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};

#else

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KM_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LGUI_T(KC_TAB),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                   KC_LALT, LT(KM_SIG, JP_MHEN), LT(KM_NUM, KC_SPC),  LT(KM_NUM, KC_SPC), LT(KM_ARW, JP_HENK), CS_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [KM_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, UJ_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, UJ_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                  KC_LGUI, LT(KM_SIG,  KC_LNG2), LT(KM_NUM, KC_SPC),  LT(KM_NUM, KC_SPC), LT(KM_ARW,  KC_LNG1), CS_ESC
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
#endif
// clang-format on

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

#ifdef RGB_MATRIX_ENABLE

// clang-format off
/*
        {  24,  23,  18,  17,  10,   9 },          {  36,  37,  44,  45,  50,   51 },
        {  25,  22,  19,  16,  11,   8 },          {  35,  38,  43,  46,  49,   52 },
        {  26,  21,  20,  15,  12,   7 },          {  34,  39,  42,  47,  48,   53 },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6 }, { 33,  40,  41,  NO_LED, NO_LED, NO_LED }

        {  18,  17,  12,  11,   4,   3,  21},  {44,   26,  27,  34,  35,  40,   41 },
        {  19,  16,  13,  10,   5,   2,  22},  {45,   25,  28,  33,  36,  39,   42 },
        {  20,  15,  14,   9,   6,   1 },          {  24,  29,  32,  37,  38,   43 },
    { NO_LED, NO_LED, NO_LED,   8,   7,   0 }, { 23,  30,  31,  NO_LED, NO_LED, NO_LED }
*/
// clang-format on

void set_color(int index, uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue) {
  HSV hsv = (HSV){hsvred, hsvgreen, hsvblue};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

void set_color_all(uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue) {
  HSV hsv = (HSV){hsvred, hsvgreen, hsvblue};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

// #ifdef   LAYOUT_split_3x6_3
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (rgb_matrix_get_mode() != 1) {
    return false;
  }

  rgb_matrix_set_color_all(RGB_OFF);

  switch (get_highest_layer(layer_state | default_layer_state)) {
    case KM_NUM:
      if (is_keyboard_left()) {
        // left
        set_color(LD_A, HSV_YELLOW);
        set_color(LD_S, HSV_YELLOW);
        set_color(LD_D, HSV_YELLOW);
        set_color(LD_F, HSV_YELLOW);
        set_color(LD_G, HSV_YELLOW);
      } else {
        // right
        set_color(LD_H, HSV_YELLOW);
        set_color(LD_J, HSV_YELLOW);
        set_color(LD_K, HSV_YELLOW);
        set_color(LD_L, HSV_YELLOW);
        set_color(LD_SCLN, HSV_YELLOW);
        set_color(LD_U, HSV_BLUE);
        set_color(LD_I, HSV_BLUE);
        set_color(LD_O, HSV_BLUE);
        set_color(LD_P, HSV_BLUE);

        set_color(LD_BSPC, HSV_RED);
      }
      break;
    case KM_SIG:
      if (is_keyboard_left()) {
        // left
        set_color(LD_A, HSV_BLUE);
        set_color(LD_S, HSV_BLUE);
        set_color(LD_D, HSV_BLUE);
        set_color(LD_F, HSV_BLUE);
        set_color(LD_G, HSV_BLUE);
        set_color(LD_Q, HSV_BLUE);
      } else {
        // right
        set_color(LD_H, HSV_BLUE);
        set_color(LD_J, HSV_BLUE);
        set_color(LD_K, HSV_BLUE);
        set_color(LD_L, HSV_BLUE);
        set_color(LD_SCLN, HSV_BLUE);
        set_color(LD_QUOT, HSV_BLUE);

        set_color(LD_U, HSV_BLUE);
        set_color(LD_I, HSV_BLUE);
        set_color(LD_O, HSV_BLUE);
        set_color(LD_P, HSV_BLUE);

        set_color(LD_BSPC, HSV_RED);
      }
      break;
    case KM_FN:
      if (is_keyboard_left()) {
        // left
        set_color(LD_LCTL, HSV_GOLDENROD);
        set_color(LD_A, HSV_GOLDENROD);
        set_color(LD_S, HSV_GOLDENROD);
        set_color(LD_D, HSV_GOLDENROD);
        set_color(LD_F, HSV_GOLDENROD);
        set_color(LD_G, HSV_GOLDENROD);
      } else {
        // right
        set_color(LD_H, HSV_GOLDENROD);
        set_color(LD_J, HSV_GOLDENROD);
        set_color(LD_K, HSV_GOLDENROD);
        set_color(LD_L, HSV_GOLDENROD);
        set_color(LD_SCLN, HSV_GOLDENROD);
        set_color(LD_QUOT, HSV_GOLDENROD);
      }
      break;
    case KM_ARW:
#ifdef LAYOUT_split_3x6_3_ex2
      // show win/mac
      if (IS_LAYER_ON_STATE(layer_state, KM_MAC)) {
        set_color_all(HSV_CORAL);
      } else {
        set_color_all(HSV_BLUE);
      }
#else
      if (is_keyboard_left()) {
        // left
        set_color(LD_A, HSV_MAGENTA);
        set_color(LD_S, HSV_MAGENTA);
        set_color(LD_D, HSV_MAGENTA);
        set_color(LD_F, HSV_MAGENTA);

        set_color(LD_Z, HSV_MAGENTA);
        set_color(LD_X, HSV_MAGENTA);
        set_color(LD_C, HSV_MAGENTA);
        set_color(LD_V, HSV_MAGENTA);
      } else {
        // right
        set_color(LD_H, HSV_GREEN);
        set_color(LD_J, HSV_GREEN);
        set_color(LD_K, HSV_GREEN);
        set_color(LD_L, HSV_GREEN);

        set_color(LD_Y, HSV_ORANGE);
        set_color(LD_U, HSV_BLUE);
        set_color(LD_I, HSV_BLUE);
        set_color(LD_O, HSV_ORANGE);

        // show win/mac
        if (IS_LAYER_ON_STATE(layer_state, KM_MAC)) {
          set_color(LD_MM, HSV_CORAL);
        } else {
          set_color(LD_MM, HSV_BLUE);
        }
      }
#endif
      break;
    default:
      break;
  }
  return false;
}

// #endif  // LAYOUT_split_3x6_3

#endif  // RGB_MATRIX_ENABLE
