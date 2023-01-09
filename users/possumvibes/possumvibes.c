#include "possumvibes.h"

bool process_custom_key( bool is_shifted,
    uint16_t tap_keycode,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            register_code16(shift_override);

            set_mods(mod_state);
        } else {
            // regular: /
            register_code16(tap_keycode);
        }
        return false;
    }
    else {
        unregister_code16(shift_override);
        unregister_code16(tap_keycode);
    }

    return true;
}

bool override_shift( bool is_shifted,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            register_code16(shift_override);

            set_mods(mod_state);
        } else {
            // regular: /
            register_code16(keycode);
        }
        return false;
    }
    else {
        unregister_code16(shift_override);
        unregister_code16(keycode);
    }

    return true;
}

bool override_bracket_pair(
    bool is_shifted,
    uint16_t left_keycode,
    uint16_t right_keycode,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_oneshot_mods(MOD_MASK_SHIFT);
            del_mods(MOD_MASK_SHIFT);

            tap_code16(left_keycode);
            tap_code16(right_keycode);
            tap_code(KC_LEFT);

            set_mods(mod_state);
            layer_off(_SYM);
        } else {
            tap_code16(keycode);
        }
    }
    return false;
}

// TODO POSSUM all of these methods can get combined into a smarter def/dict based shift override
// just need to figure out how to manage the strings for these
// todo check ericgebhart and getreuer code, they've both got stuff for this specifically
bool send_function_bracket_string(
    bool is_shifted,
    uint16_t keycode,
    keyrecord_t *record) {
    if (is_shifted){
        if (record->event.pressed) {
            uint8_t mod_state = get_mods();
            del_oneshot_mods(MOD_MASK_SHIFT);
            del_mods(MOD_MASK_SHIFT);

            SEND_STRING("(){");

            set_mods(mod_state);
        }
        return false;
    }
    return true;
}
bool send_link_bracket_string(
    bool is_shifted,
    uint16_t keycode,
    keyrecord_t *record) {
    if (is_shifted){
        if (record->event.pressed) {
            uint8_t mod_state = get_mods();
            del_oneshot_mods(MOD_MASK_SHIFT);
            del_mods(MOD_MASK_SHIFT);

            SEND_STRING("[]()");
            triple_tap(KC_LEFT);

            set_mods(mod_state);
        }
        return false;
    }
    return true;
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
