#include "lib/mylayer.h"
#include "quantum.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state | default_layer_state)) {
    case KM_WIN:
      oled_write_ln_P(PSTR("Windows"), false);
      break;
    case KM_MAC:
      oled_write_ln_P(PSTR("Mac"), false);
      break;
    case KM_NUM:
      oled_write_ln_P(PSTR("Number"), false);
      break;
    case KM_FN:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    case KM_SIG:
      oled_write_ln_P(PSTR("Sign"), false);
      break;
    case KM_ARW:
      oled_write_ln_P(PSTR("Arrow"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Unknown"), false);
      break;
  }
}

void oled_render_logo(void) {
  // clang-format off
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    static const char PROGMEM win_logo[] = {
        0x80, 0x80, 0x95, 0x96, 0x97, 0x98, 0x80, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA0, 0xB5, 0xB6, 0xB7, 0xB8, 0xA0, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC0, 0xD5, 0xD6, 0xD7, 0xD8, 0xC0, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    static const char PROGMEM mac_logo[] = {
        0x80, 0x80, 0x9C, 0x9D, 0x9E, 0x80, 0x80, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA0, 0xBC, 0xBD, 0xBE, 0xA0, 0xA0, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC0, 0xDC, 0xDD, 0xDE, 0xC0, 0xC0, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
  // clang-format on
  switch (get_highest_layer(layer_state | default_layer_state)) {
    case KM_WIN:
      oled_write_P(win_logo, false);
      break;
    case KM_MAC:
      oled_write_P(mac_logo, false);
      break;
    default:
      oled_write_P(crkbd_logo, false);
      break;
  }
}

bool oled_task_kb(void) {
  if (!oled_task_user()) {
    return false;
  }
  if (is_keyboard_master()) {
    oled_render_layer_state();
  } else {
    oled_render_logo();
  }
  return false;
}
#endif  // OLED_ENABLE

// #ifdef RGB_MATRIX_ENABLE
#ifdef LAYOUT_split_3x6_3

// clang-format off
/*
        {  24,  23,  18,  17,  10,   9 },          {  36,  37,  44,  45,  50,   51 },
        {  25,  22,  19,  16,  11,   8 },          {  35,  38,  43,  46,  49,   52 },
        {  26,  21,  20,  15,  12,   7 },          {  34,  39,  42,  47,  48,   53 },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6 }, { 33,  40,  41,  NO_LED, NO_LED, NO_LED }
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
