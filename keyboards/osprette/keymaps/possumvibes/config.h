#pragma once

#define IS_PINKY_CLUSTER
#define VERTICAL_THUMB_COMBO

#define COMBO_ONLY_FROM_LAYER 1     // compare only with the COMBOREF layer.
#define IGNORE_MOD_TAP_INTERRUPT    // Lets you roll mod-tap keys
#define TAPPING_FORCE_HOLD          // Allows mod use immediately after tap use
#define TAPPING_FORCE_HOLD_PER_KEY  // BUT NOT EVERYWHERE.
#define TAPPING_TERM 200            // Base tapping term
#define TAPPING_TERM_PER_KEY        // Adjust tapping term for finger strength

// Let's lock some one-shots
#define TAPPING_TOGGLE 2            // Locks Tap Toggles after two taps.
#define ONESHOT_TAP_TOGGLE 2        // Locks Oneshot Toggles after two taps.
#define ONESHOT_TIMEOUT 5000        // How long a oneshot stays active.

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 15           // Introduces delay between code taps so no keys get eaten.

// Combos!
#define COMBO_TERM 38               // Gotta combo fast.
#define COMBO_MUST_TAP_PER_COMBO    // Set whether combos can be held to repeat.
#define COMBO_MUST_HOLD_PER_COMBO   // Set whether combos have to be held to function. probably don't need both of these.
#define COMBO_TERM_PER_COMBO        // Adjust combo term for ease of combo.

#ifdef LEADER_ENABLE
// The Leader key allows to flexibly assign macros to key sequences.
#define LEADER_TIMEOUT 250          // Enable Leader key.
#define LEADER_PER_KEY_TIMING       // Per-key timing for leader sequences.
#define LEADER_NO_TIMEOUT           // no timeout between leader and first sequence key.
#endif

// Space-savers when not debugging-- comment if debugging
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_16BIT
