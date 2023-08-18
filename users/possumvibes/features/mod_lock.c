#include "mod_lock.h"
#include "keycodes.h"

mod_lock_state_t modlock_states[] = {
    {false, KC_LSFT, ML_LSFT},
    {false, KC_LCTL, ML_LCTL},
    {false, KC_LALT, ML_LALT},
    {false, KC_LGUI, ML_LGUI}
};
uint8_t        NUM_MODLOCK_STATES = sizeof(modlock_states) / sizeof(mod_lock_state_t);

void process_mod_lock(uint16_t keycode, keyrecord_t *record) {
    mod_lock_state_t *curr_state = NULL;

    for (int i = 0; i < NUM_MODLOCK_STATES; ++i) {
        curr_state = &modlock_states[i];

        if (keycode == curr_state->trigger) {
            if (record->event.pressed) {
                if (curr_state->locking) {
                    unregister_code(curr_state->mod);
                } else {
                    register_code(curr_state->mod);
                }

                curr_state->locking = !curr_state->locking;
            }
        } else {
            // check for cancel condition on keydown and keyup
            if (curr_state->locking && is_mod_lock_cancel_key(keycode)) {
                unregister_code(curr_state->mod);
                curr_state->locking = false;
            }
        }
    }
}

bool is_mod_lock_cancel_key(uint16_t keycode) {
    // Mod locks are exclusively used on the nav layer.
    // any key besides nav keys should cancel the lock.
    switch (keycode) {
        case KC_LEFT:
        case KC_RGHT:
        case KC_UP:
        case KC_DOWN:
        case KC_HOME:
        case KC_END:
        case ML_LALT:
        case ML_LCTL:
        case ML_LGUI:
        case ML_LSFT:
        case LCLICK:
        case RCLICK:
            return false;
        default:
            return true;
    }
}
