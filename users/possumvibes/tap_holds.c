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
        // Pinky
        case KS_C:
        case KH_R:
        case KY_A:
        case KH_I:
        case KY_QUOT:
            return TAPPING_TERM;

        // Ring
        case KS_R:
        case KY_S: // also KH_S
        case KS_I:
        case KH_A:
        case KY_L:
        case KY_4:
            return TAPPING_TERM + 5;

        // Middle
        case KS_S:
        case KH_T:
        case KY_D:
        case KH_E:
        case KM_A:
        case KY_K:
        case KY_5:
            return TAPPING_TERM - 10;

        // Index
        case KS_T:
        case KH_H:
        case KY_F:
        case KS_D:
        case KH_N:
        case KY_J:
        case KY_6:
            return TAPPING_TERM - 16;

        // Upper Middle
        case KS_H:
        case KH_D:
        case KH_F:
        case KH_G:
        case KH_Y:
        case KY_E:
        case KS_O:
        case KH_U:
        case KY_I:
        case KY_8:
            return TAPPING_TERM + 5;

        // Thumbs I Guess
        case NAV_E:
        case NAV_SPC:
            return TAPPING_TERM - 10;

        default:
            return TAPPING_TERM;
    }
}
