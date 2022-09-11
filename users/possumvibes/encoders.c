#include "keycodes.h"

// Scrolling with PageUp and PgDn.
void encoder_scroll_page(bool clockwise){
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
}

// Scrolling vertically with arrows.
void encoder_scroll_y(bool clockwise){
    if (clockwise) {
        tap_code(KC_DOWN);
    } else {
        tap_code(KC_UP);
    }
}

// Scrolling horizontally with arrows.
void encoder_scroll_x(bool clockwise){
    if (clockwise) {
        tap_code(KC_RGHT);
    } else {
        tap_code(KC_LEFT);
    }
}

// Volume control.
void encoder_volume(bool clockwise){
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

// ENCODER TIME >:)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Left Hand
        switch (biton32(layer_state)) {
            default:
                encoder_scroll_y(clockwise);
                break;
        }
    } else if (index == 1) {
        // Right Hand
        switch (biton32(layer_state)) {
            case _NAV:
                encoder_volume(clockwise);
                break;
            // case _SYM: // homerow activated
            //     encoder_scroll_x(clockwise);
            //     break;
            default:
                encoder_scroll_page(clockwise);
                break;
        }
    }
    return false;
}
