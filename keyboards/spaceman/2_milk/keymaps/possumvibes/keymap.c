#include QMK_KEYBOARD_H

#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        QMKFLSH,  ENT_LWR
    ),
    [_MORSE] = LAYOUT(
        _______, KC_MORSE
    ),
    [_LOWER] = LAYOUT(
        RESET, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case QMKFLSH:
            if(record->event.pressed && record->tap.count){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }
                SEND_STRING("qmk flash");
                tap_code16(KC_ENT);
                return false;
            }
            break;
        case RESET:
            break;
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

