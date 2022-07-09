#pragma once

#include "quantum.h"
#include "wrappers.h"

/* This overrides the base LAYOUT function to allow
 * consistent use of existing keymap blocks as defined
 * in users/possumvibes/wrappers.h
 * This function assigns the board's pins.
 */


/* This is a wrapper for the LAYOUT function to allow passing cleaner or modified arguments. */
#define LAYOUT_wrapper(...)  LAYOUT(__VA_ARGS__)

/*Layout Template with consistent thumbs (e.g., for alpha layers)*/
#define LAYOUT_alpha( \
        L10, L11, L12, L13, L14,                 R10, R11, R12, R13, R14, \
        L20, L21, L22, L23, L24,                 R20, R21, R22, R23, R24, \
        L30, L31, L32, L33, L34,                 R30, R31, R32, R33, R34 \
    ) \
    LAYOUT_wrapper( \
        OS_LGLC, L10, L11, L12, L13, L14,                 R10, R11, R12, R13, R14, KC_DEL, \
        KC_CAPS, L20, L21, L22, L23, L24,                 R20, R21, R22, R23, R24, R34, \
                 L30, L31, L32, L33, L34,                 R30, R31, R32, R33, R34, \
                    CTL_GUI, __ALPHATHUMB_L__, __ALPHATHUMB_R__, XXXXXXX \
    )
/* Wrapper for new alpha macro */
#define LAYOUT_alpha_wrapper(...)       LAYOUT_alpha(__VA_ARGS__)

