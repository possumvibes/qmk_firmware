#include "override_keys.h"

bool override_shift( bool is_shifted,
    uint16_t keycode,
    uint16_t shift_override,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            register_code16(shift_override);

            set_mods(mod_state);
        } else {
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

// Send custom keycode on hold for mod tap
// from https://github.com/filterpaper/qmk_userspace/blob/main/filterpaper.c
bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(hold_keycode);
        return false;
    }
    return true;
}

bool send_autopair(
  uint16_t keycode,
  uint16_t pair_keycode,
  keyrecord_t *record  ) {
    if(record->event.pressed) {
		// clear mods before moving left
		uint8_t mod_state = get_mods();
		del_oneshot_mods(MOD_MASK_SHIFT);
		del_mods(MOD_MASK_SHIFT);

      // Tap the base keycode regardless of shift state
      tap_code16(keycode);
      tap_code16(pair_keycode);


		// move left and reset mod state
      tap_code(KC_LEFT);
      set_mods(mod_state);
    }
    return false;
}

bool send_autopair_on_shift(
    bool is_shifted,
    uint16_t left_keycode,
    uint16_t right_keycode,
    uint16_t keycode,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
			send_autopair(left_keycode, right_keycode, record);
            layer_off(_SYM);
        } else {
            tap_code16(keycode);
        }
    }
    return false;
}

bool send_double_on_shift(
	bool is_shifted,
	uint16_t keycode,
	keyrecord_t *record ) {
    if(record ->event.pressed) {
        // If shifted, double these common punctuation marks.
        if(is_shifted){
            uint8_t mod_state = get_mods();

            // clear shift temporarily
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            tap_code16(keycode);
            tap_code16(keycode);

            // restore previous shift state
            set_mods(mod_state);
            return false;
        }
    }
    return true;
}

bool send_string_c_function(
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
bool send_string_markdown_link(
    keyrecord_t *record) {
        if (record->event.pressed) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);

            SEND_STRING("[]()");
            triple_tap(KC_LEFT);

            set_mods(mod_state);
        }
        return false;
}

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}
