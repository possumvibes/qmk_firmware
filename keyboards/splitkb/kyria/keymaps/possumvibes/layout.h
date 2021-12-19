#pragma once

#include "wrappers.h"

// This is a wrapper for the kyria LAYOUT function to allow passing cleaner or modified arguments.
#define LAYOUT_kyria_wrapper(...) LAYOUT(__VA_ARGS__)

// This is a macro to wrap the alpha layouts specifically to ensure consistent
// application of home row mods, 6th col keys, and thumb row keys.
#define LAYOUT_kyria_alpha( \
    L01, L02, L03, L04, L05, R06, R07, R08, R09, R10, \
    L13, L14, L15, L16, L17, R18, R19, R20, R21, R22, \
    L25, L26, L27, L28, L29, R34, R35, R36, R37, R38 \
    ) \
    LAYOUT_kyria_wrapper( \
        KC_ESC, L01, L02, L03, L04, L05, R06, R07, R08, R09, R10, KC_DEL, \
        KC_CAPS, L13, L14, L15, L16, L17, R18, R19, R20, R21, R22, PANIC, \
        XXXXXXX, L25, L26, L27, L28, L29, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R34, R35, R36, R37, R38, XXXXXXX, \
        LOCKSCR, XXXXXXX, THM_LH0, THM_LH1, XXXXXXX, XXXXXXX, THM_RH1, THM_RH0, XXXXXXX, KC_MPLY \
    )
#define LAYOUT_kyria_alpha_wrapper(...) LAYOUT_kyria_alpha(__VA_ARGS__)
