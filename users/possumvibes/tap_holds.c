#include QMK_KEYBOARD_H
#include "keycodes.h"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KY_A:
        case KH_A:
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case KY_A:
        case KY_QUOT:
            // Pinky
            return TAPPING_TERM + 15;

        case KY_S:
        case KY_L:
        // case KH_S: //KY_S and KH_S are both aliases for LALT_T(KC_S)
        case KH_A:
            // Ring
            return TAPPING_TERM + 15;
        case KY_E:
        case KY_I:
        case KH_D:
        case KH_U:
            // Upper Middle
            return TAPPING_TERM + 15;
        case KY_D:
        case KY_K:
        case KH_T:
        case KH_E:
            // Middle
            return TAPPING_TERM - 10;
        case KY_F:
        case KY_J:
        case KH_L:
        case KH_N:
            // Index
            return TAPPING_TERM -15;
        default:
            return TAPPING_TERM;
    }
}
