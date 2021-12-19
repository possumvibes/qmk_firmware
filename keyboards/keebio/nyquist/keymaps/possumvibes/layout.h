#pragma once

#include "wrappers.h"

/* This is a wrapper for the LAYOUT function to allow passing cleaner or modified arguments. */
#define LAYOUT_wrapper(...)         LAYOUT(__VA_ARGS__)
#define LAYOUT_possum( \
        L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, \
        L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, \
        L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, \
                   L44, L45, R40, R41 \
	) \
    LAYOUT_wrapper( \
        XXXXXXX, ________________GAME_NAV_L0________________, ________________GAME_NAV_R0________________, XXXXXXX, \
        XXXXXXX, L11,     L12,     L13,     L14,     L15,     R10,     R11,     R12,     R13,     R14,     KC_DEL, \
        KC_CAPS, L21,     L22,     L23,     L24,     L25,     R20,     R21,     R22,     R23,     R24,     PANIC, \
        XXXXXXX, L31,     L32,     L33,     L34,     L35,     R30,     R31,     R32,     R33,     R34,     XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L44,     L45,     R40,     R41,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	)
#define LAYOUT_possum_wrapper(...)  LAYOUT_possum(__VA_ARGS__)
