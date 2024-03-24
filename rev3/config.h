#pragma once

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#ifdef RGB_MATRIX_ENABLE
#  define SPLIT_TRANSPORT_MIRROR
#  define SPLIT_LAYER_STATE_ENABLE

#  define RGB_DISABLE_WHEN_USB_SUSPENDED
#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#  define RGB_MATRIX_KEYPRESSES
#endif
