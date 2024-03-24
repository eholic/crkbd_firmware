#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "keymap_us2jp.h"

uint8_t mod_state;
void tap_cs(uint16_t kc, uint16_t kc_shift) {
    mod_state = get_mods();

    if (mod_state & MOD_MASK_SHIFT) {
      del_mods(MOD_MASK_SHIFT);
      tap_code16(kc);
      set_mods(mod_state);
    } else {
      tap_code16(kc_shift);
    }
}

bool us2jp(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UJ_2:
      if (record->event.pressed) {
        tap_cs(JP_AT, KC_2);
      }
      return false; // Skip all further processing of this key
    case UJ_6:
      if (record->event.pressed) {
        tap_cs(JP_CIRC, KC_6);
      }
      return false; // Skip all further processing of this key
    case UJ_7:
      if (record->event.pressed) {
        tap_cs(JP_AMPR, KC_7);
      }
      return false; // Skip all further processing of this key
    case UJ_8:
      if (record->event.pressed) {
        tap_cs(JP_ASTR, KC_8);
      }
      return false; // Skip all further processing of this key
    case UJ_9:
      if (record->event.pressed) {
        tap_cs(JP_LPRN, KC_9);
      }
      return false; // Skip all further processing of this key
    case UJ_0:
      if (record->event.pressed) {
        tap_cs(JP_RPRN, KC_0);
      }
      return false; // Skip all further processing of this key
    case UJ_MINS:
      if (record->event.pressed) {
        tap_cs(JP_UNDS, JP_MINS);
      }
      return false; // Skip all further processing of this key
    case UJ_EQL:
      if (record->event.pressed) {
        tap_cs(JP_PLUS, JP_EQL);
      }
      return false; // Skip all further processing of this key
    case UJ_SCLN:
      if (record->event.pressed) {
        tap_cs(JP_COLN, JP_SCLN);
      }
      return false; // Skip all further processing of this key
    case UJ_QUOT:
      if (record->event.pressed) {
        tap_cs(JP_DQUO, JP_QUOT);
      }
      return false; // Skip all further processing of this key
    case UJ_GRV:
      if (record->event.pressed) {
        tap_cs(JP_TILD, JP_GRV);
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
