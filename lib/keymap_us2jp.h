#pragma once

enum custom_keycodes_us2jp {
    UJ_2 = SAFE_RANGE,
    UJ_6,
    UJ_7,
    UJ_8,
    UJ_9,
    UJ_0,
    UJ_MINS,
    UJ_EQL,
    UJ_SCLN,
    UJ_QUOT,
    UJ_GRV,
    NEW_SAFE_RANGE,
};

bool us2jp(uint16_t keycode, keyrecord_t *record);
