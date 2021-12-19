#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _MORSE,
};

enum custom_keycodes {
    QMKFLSH = SAFE_RANGE
};

#define TH(k)   LT(0, k)

#define QMKFLSH    LT(_MORSE, KC_DOT)
#define ENT_LWR    LT(_LOWER, KC_ENT)
#define KC_MORSE   TH(KC_DOT)

bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record);

