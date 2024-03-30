#pragma once

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define QUICK_TAP_TERM 0

#ifdef RGB_MATRIX_ENABLE
#  define SPLIT_TRANSPORT_MIRROR
#  define SPLIT_LAYER_STATE_ENABLE

#  define RGB_MATRIX_SLEEP
#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#  define RGB_MATRIX_KEYPRESSES
#endif
