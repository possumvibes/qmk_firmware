#include QMK_KEYBOARD_H

#include "keycodes.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        PGU_MOR,
        PGD_LOW
    ),
    [_LOWER] = LAYOUT(
        KC_LOCKS,
        _______
    ),
    [_MORSE] = LAYOUT(
        _______,
        KC_MORSE
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_LOCKS: {
            uint16_t lock_key = record->tap.count ? KC_ESC : KC_L;
            if(record ->event.pressed) {
                tap_code16(G(lock_key));
            }
            return false;
        }
        case KC_MORSE: return override_th_hold(KC_MINS, record);
    }

    return true;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
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

