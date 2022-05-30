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

// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch(keycode) {
//         case KH_H:
//         case KH_N:
//         case KS_T:
//         case KS_D:
//         case KY_F:
//         case KY_J:
//             return true;
//         default:
//             return false;
//     }
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case KY_A:
        case KY_QUOT:
        case KY_6:
        case KY_7:
            // Pinky
            return TAPPING_TERM + 5;

        case KS_R:
        case KY_S:
        case KY_L:
        // case KH_S: //KY_S and KH_S are both aliases for LALT_T(KC_S)
        case KH_A:
            // Ring
            return TAPPING_TERM + 5;
        case KY_E:
        case KY_I:
        case KH_D:
        case KH_U:
        case KS_H:
            // Upper Middle
            return TAPPING_TERM + 5;
        case KY_D:
        case KY_K:
        case KH_T:
        case KH_E:
        case KS_N:
            // Middle
            return TAPPING_TERM - 10;
        case KY_F:
        case KY_J:
        case KH_H:
        case KH_N:
        case KS_T:
        case KS_D:
            // Index
            return TAPPING_TERM - 15;
        default:
            return TAPPING_TERM;
    }
}
