#pragma once

#include "wrappers.h"

#define XXX     KC_A
#define LT0     THM_LH0
#define LT1     THM_LH1
#define RT0     THM_RH0
#define RT1     THM_RH1

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
        CAPSWRD, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, KC_DEL, \
        KC_CAPS, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, PANIC, \
        XXX,     L25, L26, L27, L28, L29, XXX, XXX, XXX, XXX, R34, R35, R36, R37, R38, XXX, \
             LOCKSCR, XXX, LT0, LT1, XXX, XXX, RT1, RT0, XXX, KC_MPLY \
    )
#define LAYOUT_kyria_alpha_wrapper(...) LAYOUT_kyria_alpha(__VA_ARGS__)

#define LAYOUT_kyria_34( \
    L01, L02, L03, L04, L05, R06, R07, R08, R09, R10, \
    L13, L14, L15, L16, L17, R18, R19, R20, R21, R22, \
    L25, L26, L27, L28, L29, R34, R35, R36, R37, R38, \
    L40, L41, R42, R43 \
    ) \
    LAYOUT_kyria_wrapper( \
        XXX, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, _______, \
        XXX, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, XXX, \
        XXX, L25, L26, L27, L28, L29, XXX, XXX, XXX, XXX, R34, R35, R36, R37, R38, XXX, \
        _______, XXX,  L40, L41, XXX, XXX, R42, R43, XXX, _______ \
    )
#define LAYOUT_kyria_34_wrapper(...) LAYOUT_kyria_34(__VA_ARGS__)
