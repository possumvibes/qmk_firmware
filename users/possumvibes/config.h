#pragma once

#define TAPPING_FORCE_HOLD          // Allows mod use immediately after tap use
#define TAPPING_FORCE_HOLD_PER_KEY  // BUT NOT EVERYWHERE.
#define TAPPING_TERM 200            // Base tapping term
#define TAPPING_TERM_PER_KEY        // Adjust tapping term for finger strength

// Let's lock some one-shots
#define ONESHOT_TIMEOUT 5000        // How long a oneshot stays active.

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 15           // Introduces delay between code taps so no keys get eaten.

// Combos!
#define COMBO_TERM 36               // Gotta combo fast.
#define COMBO_ONLY_FROM_LAYER 1     // compare only with the COMBOREF layer.
#define COMBO_MUST_TAP_PER_COMBO    // Set whether combos can be held to repeat.
#define COMBO_TERM_PER_COMBO        // Adjust combo term for ease of combo.
#define COMBO_STRICT_TIMER          // all keys must be hit within the term from the first keypress.

#ifdef LEADER_ENABLE
// The Leader key allows to flexibly assign macros to key sequences.
#  define LEADER_TIMEOUT 250          // Enable Leader key.
#  define LEADER_PER_KEY_TIMING       // Per-key timing for leader sequences.
#  define LEADER_NO_TIMEOUT           // no timeout between leader and first sequence key.
#endif


// SPACE SAVERS FOR ALL BOARDS.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_16BIT
