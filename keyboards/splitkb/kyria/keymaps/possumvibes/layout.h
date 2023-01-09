#pragma once

#include "wrappers.h"


/* This overrides the base LAYOUT function to allow
 * consistent use of existing keymap blocks as defined
 * in users/possumvibes/wrappers.h
 * This function assigns the board's pins.
 */
// This is a wrapper for the kyria LAYOUT function to allow passing cleaner or modified arguments.
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

/*Layout Template with consistent thumbs (e.g., for alpha layers)*/
#define LAYOUT_possum( \
        L01, L02, L03, L04, L05,                          R06, R07, R08, R09, R10, \
        L13, L14, L15, L16, L17,                          R18, R19, R20, R21, R22, \
        L25, L26, L27, L28, L29,                          R34, R35, R36, R37, R38 \
    ) \
    LAYOUT_wrapper( \
        NON, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, KC_DEL, \
        L01, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R10, \
        NON, L25, L26, L27, L28, L29, NON, NON, NON, NON, R34, R35, R36, R37, R38, NON, \
              LOCKSCR, NON, TL0, TL1, TL1, TR1, TR1, TR0, NON, KC_MPLY \
    )
/* Wrapper for new alpha macro */
#define LAYOUT_possum_wrapper(...) LAYOUT_possum(__VA_ARGS__)

/* The same, but now with custom thumbs */
#define LAYOUT_possum_thumbs( \
        L01, L02, L03, L04, L05,                          R06, R07, R08, R09, R10, \
        L13, L14, L15, L16, L17,                          R18, R19, R20, R21, R22, \
        L25, L26, L27, L28, L29,                          R34, R35, R36, R37, R38, \
                            L40, L41,                R42, R43 \
    ) \
    LAYOUT_wrapper( \
        NON, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, KC_DEL, \
        L01, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R10, \
        NON, L25, L26, L27, L28, L29, NON, NON, NON, NON, R34, R35, R36, R37, R38, NON, \
        _______, NON,  L40, L41, L41, R42, R42, R43, NON, _______ \
    )
#define LAYOUT_possum_thumbs_wrapper(...) LAYOUT_possum_thumbs(__VA_ARGS__)
