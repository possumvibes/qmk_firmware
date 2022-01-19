#include "nshot_mod.h"
#include "keycodes.h"

nshot_state_t  nshot_states[] = {
    {OS_LSFT, KC_LSFT, 1, os_up_unqueued, 0},
    {OS_LCTL, KC_LCTL, 1, os_up_unqueued, 0},
    {OS_LALT, KC_LALT, 1, os_up_unqueued, 0},
    {OS_LGUI, KC_LGUI, 1, os_up_unqueued, 0},
    {TS_LCTL, KC_LCTL, 2, os_up_unqueued, 0}
};
uint8_t        NUM_NSHOT_STATES = sizeof(nshot_states) / sizeof(nshot_state_t);

void process_nshot_state(uint16_t keycode, keyrecord_t *record) {
    nshot_state_t *curr_state = NULL;

    for (int i = 0; i < NUM_NSHOT_STATES; ++i) {
        curr_state = &nshot_states[i];

        if (keycode == curr_state->trigger) {
            if (record->event.pressed) {
                // Trigger keydown
                if (curr_state->state == os_up_unqueued) {
                    register_code(curr_state->mod);
                }
                curr_state->state = os_down_unused;
                curr_state->count = 0;
            } else {
                // Trigger keyup
                switch (curr_state->state) {
                    case os_down_unused:
                        // If we didn't use the mod while trigger was held, queue it.
                        curr_state->state = os_up_queued;
                        break;
                    case os_down_used:
                        // If we did use the mod while trigger was held, unregister it.
                        curr_state->state = os_up_unqueued;
                        unregister_code(curr_state->mod);
                        break;
                    default:
                        break;
                }
            }
        } else {
            if (record->event.pressed) {
                if (is_nshot_cancel_key(keycode) && curr_state->state != os_up_unqueued) {
                    // Cancel oneshot on designated cancel keydown.
                    curr_state->state = os_up_unqueued;
                    curr_state->count = 0;
                    unregister_code(curr_state->mod);
                }
            } else {
                if (!is_nshot_ignored_key(keycode)) {
                    // On non-ignored keyup, consider the oneshot used.
                    switch (curr_state->state) {
                        case os_down_unused:
                            // The mod key is being held as a normal mod.
                            curr_state->state = os_down_used;
                            break;
                        case os_up_queued:
                            // The mod key is being used as an n-shot.
                            // Increment the keys-used count.
                            curr_state->count = curr_state->count + 1;

                            // If the n-shot max has been reached, complete the n-shot.
                            if (curr_state->count == curr_state->max_count) {
                                curr_state->state = os_up_unqueued;
                                curr_state->count = 0;
                                unregister_code(curr_state->mod);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}

bool is_nshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case PANIC:
        case CLEAR:
        case THM_LH0:
        case THM_LH1:
        case THM_RH0:
        case THM_RH1:
            return true;
        default:
            return false;
    }
}

bool is_nshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case THM_LH0:
        case THM_LH1:
        case THM_RH0:
        case THM_RH1:
        case SYM_OSL:
        case SYM_TG:
        case NAV_TG:
        case NUM_OSL:
        case NUM_TO:
        case FUN_OSL:
        case ALPHA:
        case NUMMODE:
        case FUNMODE:
            return true;
        default:
            return false;
    }
}