#pragma once

#define TAPPING_TERM 200                // Base tapping term
#define QUICK_TAP_TERM TAPPING_TERM / 2 // Quick Tap Term to trigger auto-repeat
// #define TAPPING_TERM_PER_KEY            // Adjust tapping term for finger strength
// #define PERMISSIVE_HOLD

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 15               // Introduces delay between code taps so no keys get eaten.

// Combos!
#define COMBO_TERM 36                   // Gotta combo fast.
#define COMBO_ONLY_FROM_LAYER 1         // compare only with the COMBOREF layer.
#define COMBO_TERM_PER_COMBO            // Adjust combo term for ease of combo.
#define COMBO_STRICT_TIMER              // all keys must be hit within the term from the first keypress.

// SPACE SAVERS FOR ALL BOARDS.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_16BIT

