#include QMK_KEYBOARD_H

// Interfaces
bool process_custom_key(bool is_shifted,
    uint16_t tap_keycode,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record);

bool override_shift(bool is_shifted,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record);

bool override_bracket_pair(
    bool is_shifted,
    uint16_t left_keycode,
    uint16_t right_keycode,
    uint16_t keycode,
    keyrecord_t *record );

bool send_function_bracket_string(
    bool is_shifted,
    uint16_t keycode,
    keyrecord_t *record);

bool send_link_bracket_string(
    bool is_shifted,
    uint16_t keycode,
    keyrecord_t *record);

bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record);

void triple_tap(uint16_t keycode);
