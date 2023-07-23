#include "override_keys.h"

bool override_shift( bool is_shifted,
    uint16_t keycode,
    uint16_t shift_override,
    keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            clear_shift(is_shifted);

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
		clear_shift(true);

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

            clear_shift(is_shifted);

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
			clear_shift(is_shifted);
            SEND_STRING("(){");

            set_mods(mod_state);
        }
        return false;
    }
    return true;
}

bool send_string_version(
    bool is_shifted,
    uint8_t number_keycode,
    keyrecord_t *record) {
    if(record->event.pressed){
        // Tap V in whatever shift format is present
        tap_code(KC_V);

        // Remove shift before pressing the number
        if(is_shifted){
            del_oneshot_mods(MOD_MASK_SHIFT);
            del_mods(MOD_MASK_SHIFT);
        }

        tap_code(number_keycode);
    }
    return false;
}

bool send_string_vi_yiw(
	bool is_shifted,
	bool is_yank,
	uint8_t movement,
	bool is_word,
	keyrecord_t *record) {
  	if (record->event.pressed){
		ensure_lowercase(is_shifted);

		// when yanking, add the y
    	if(is_yank){
      		tap_code(KC_Y);
    	}

		// Movement is either a or i
    	tap_code(movement);

		// and if there's a word, add the w or W.
    	if(is_word)
    	{
	  		uint16_t word_code = is_shifted ? S(KC_W) : KC_W;
	    	tap_code16(word_code);
    	}
	}
	return false;
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

void clear_caps(void) {
	if(host_keyboard_led_state().caps_lock){
  		tap_code(KC_CAPS);
	}
}
void clear_shift(bool is_shifted) {
	if(is_shifted) {
    	del_oneshot_mods(MOD_MASK_SHIFT);
    	del_mods(MOD_MASK_SHIFT);
	}
}
void ensure_lowercase(bool is_shifted) {
    clear_caps();
    clear_shift(is_shifted);
}
