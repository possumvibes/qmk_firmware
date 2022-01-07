// Copyright 2022 crides (@crides)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "fissure.h"
#include "action_layer.h"

// Layers
#define _BASE  0
#define _LOWER 1
#define _RAISE 2
#define _STENO 3
#define _MOUSE 4

#define DEL MT(MOD_LGUI, KC_DEL)
#define TAB MT(MOD_LCTL, KC_TAB)
#define ESC LT(_RAISE, KC_ESC)
#define ENT LT(_LOWER, KC_ENT)
#define SPC MT(MOD_LSFT, KC_SPC)
#define BKSP MT(MOD_LALT, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,        KC_I,       KC_O,        KC_P, KC_3,
        KC_2, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,        KC_K,       KC_L,     KC_SCLN, KC_4,
              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,     KC_DOT,     KC_SLSH,
               DEL,      TAB,      ESC,      ENT,      SPC,     BKSP),


    [_LOWER] = LAYOUT(
        XXXXXXX, G(KC_1),  G(KC_2),  G(KC_3),  G(KC_4),  G(KC_5),   G(KC_6),  G(KC_7),  G(KC_8),  KC_F11,  KC_F12, XXXXXXX,
        XXXXXXX,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,    KC_9,    KC_0, XXXXXXX,
                   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,   KC_F9,  KC_F10,
                 _______,  _______,  _______,  _______,  _______,  _______),

    [_RAISE] = LAYOUT(
        XXXXXXX, KC_BRID,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_BRIU,     KC_HOME,     KC_PGDN,   KC_PGUP,       KC_END,  KC_PSCR, XXXXXXX,
        XXXXXXX, XXXXXXX,  TG(_STENO),  TG(_MOUSE),  XXXXXXX,  XXXXXXX,     KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,  XXXXXXX, XXXXXXX,
                 XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  C(KC_LEFT),  C(KC_DOWN),  C(KC_UP),  C(KC_RIGHT),  XXXXXXX,
                 _______,  _______,  _______,  _______,  _______,    _______),

    [_MOUSE] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, MO(_RAISE), XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, XXXXXXX, KC_BTN5, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 TG(_MOUSE),  _______,  _______,  _______,  _______,    _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    if(record->event.pressed)
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
