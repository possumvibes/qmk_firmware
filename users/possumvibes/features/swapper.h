#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    bool     active;
    uint16_t mod;
    uint16_t forward;
    uint16_t reverse;
    uint16_t forward_trigger;
    uint16_t reverse_trigger;
} swapper_state_t;
extern swapper_state_t swapper_states[];
extern uint8_t         NUM_SWAPPER_STATES;

void process_swappers(uint16_t keycode, keyrecord_t *record);
