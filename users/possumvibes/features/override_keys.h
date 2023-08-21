#pragma once
#include QMK_KEYBOARD_H

// Methods for fancy behavior overrides


// Overrides a key's shift to a different uint16_t keycode
bool override_shift(bool is_shifted,
    uint16_t keycode,
    uint16_t shift_override,
    keyrecord_t *record);

// tap-hold equivalent to override_shift
bool override_th_hold(uint16_t hold_keycode, keyrecord_t *record);

// Sends an auto-closed keycode pair.
bool send_autopair(
  uint16_t left_keycode,
  uint16_t right_keycode,
  keyrecord_t *record );

// Sends an auto-closed keycode pair on shift.
bool send_autopair_on_shift(
    bool is_shifted,
    uint16_t left_keycode,
    uint16_t right_keycode,
    uint16_t keycode,
    keyrecord_t *record );

bool send_double_on_shift(
	bool is_shifted,
	uint16_t keycode,
	keyrecord_t *record );

// Sends (){
bool send_string_c_function(
    bool is_shifted,
    uint16_t keycode,
    keyrecord_t *record);

bool send_string_version(
    bool is_shifted,
    uint8_t number_keycode,
    keyrecord_t *record);

// Send (y){i,a}{w,W}
bool send_string_vi_yiw(
	bool is_shifted,
	bool is_yank,
	uint8_t movement,
	bool is_word,
	keyrecord_t *record);

// Sends a markdown link []()
bool send_string_markdown_link(
    keyrecord_t *record);

// What it says on the tin
void triple_tap(uint16_t keycode);

// lowercase helper methods
void clear_caps(void); 
void clear_shift(bool is_shifted); 
void ensure_lowercase(bool is_shifted); 
