#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    bool          locking;
    uint16_t      mod;
    uint16_t      trigger;
} mod_lock_state_t;

extern mod_lock_state_t mod_lock_states[];
extern uint8_t          NUM_MODLOCK_STATES;

// Custom mod-locking functionality that registers the mod and
// keeps it registered until the trigger key is tapped again
// or until a specified cancel key is tapped.
void process_mod_lock(uint16_t keycode, keyrecord_t *record);

bool is_mod_lock_cancel_key(uint16_t keycode);
