#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _MORSE,
};

// enum custom_keycodes {
//     KC_LOCKS = SAFE_RANGE
// };

#define TH(k)   LT(0, k)

#define LCL_MOR    LT(_MORSE, LCLICK)
#define RCL_LOW    LT(_LOWER, RCLICK)
#define KC_MORSE   TH(KC_DOT)

#define KC_LOCKS   TH(KC_F24)
#define LCLICK      KC_BTN1
#define RCLICK      KC_BTN2
#define MCLICK      KC_BTN3

bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record);

