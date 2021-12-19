#include "possumvibes.h"

bool override_shift( bool is_shifted,
    uint16_t tap_keycode,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            tap_code16(shift_override);

            set_mods(mod_state);
        } else {
            // regular: /
            tap_code16(tap_keycode);
        }
    }
    return false;
}

bool override_th_bracket_pair(
    uint16_t left_keycode,
    uint16_t right_keycode,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (record->tap.count) {
            tap_code16(left_keycode);
        } else {
            tap_code16(left_keycode);
            tap_code16(right_keycode);
            tap_code(KC_LEFT);

            layer_off(_SYM);
        }
    }
    return false;
}

// Send custom keycode on hold for mod tap
// from https://github.com/filterpaper/qmk_userspace/blob/main/filterpaper.c
bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(hold_keycode);
        return false;
    }
    return true;
}

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}
