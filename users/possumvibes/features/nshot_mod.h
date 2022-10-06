#pragma once

#include QMK_KEYBOARD_H

// Represents the four states an n-shot key can be in (from users/callum)
typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

typedef struct {
    uint16_t      trigger;
    uint8_t       modbit;
    uint8_t       max_count;
    bool          active_on_rolls;
    oneshot_state state;
    uint8_t       count;
    bool          had_keydown;
} nshot_state_t;

extern nshot_state_t nshot_states[];
extern uint8_t             NUM_NSHOT_STATES;

// Custom one-or-more-shot implementation that does not rely on timers
// and persists across layer changes. Based on the users/callum implementation
// at https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
void process_nshot_state(uint16_t keycode, keyrecord_t *record);

// Keys that should cancel the n-shot mod if tapped
bool is_nshot_cancel_key(uint16_t keycode);

// Keys that should not count towards n-shot usage (e.g., layer toggles)
bool is_nshot_ignored_key(uint16_t keycode);
