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

#define PGU_MOR    LT(_MORSE, KC_PGUP)
#define PGD_LOW    LT(_LOWER, KC_PGDN)
#define KC_MORSE   TH(KC_DOT)

#define KC_LOCKS   TH(KC_F24)

bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record);

