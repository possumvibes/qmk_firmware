#pragma once

#include "quantum.h"
#include "wrappers.h"

/* This overrides the base LAYOUT function to allow
 * consistent use of existing keymap blocks as defined
 * in users/possumvibes/wrappers.h
 * This function assigns the board's pins.
 */

/* This is a wrapper for the LAYOUT function to allow passing cleaner or modified arguments. */
// because there is no difference between the sweep layout and the possum one,
// this just aliases LAYOUT to LAYOUT_possum_wrapper
#define LAYOUT_possum_wrapper(...)  LAYOUT(__VA_ARGS__)

/*Layout Template with consistent thumbs (e.g., for alpha layers)*/
/* #define LAYOUT_possum( \ */
/*         L10, L11, L12, L13, L14,      R10, R11, R12, R13, R14, \ */
/*         L20, L21, L22, L23, L24,      R20, R21, R22, R23, R24, \ */
/*         L30, L31, L32, L33, L34,      R30, R31, R32, R33, R34, \ */
/*                        L40, L41,      R40, R41 \ */
/*     ) \ */
/*     LAYOUT_wrapper( \ */
/*         L10, L11, L12, L13, L14,      R10, R11, R12, R13, R14, \ */
/*         L20, L21, L22, L23, L24,      R20, R21, R22, R23, R24, \ */
/*         L30, L31, L32, L33, L34,      R30, R31, R32, R33, R34, \ */
/*                        L40, L41,      R40, R41 \ */
/*     ) */
/* #define LAYOUT_possum_wrapper(...)  LAYOUT_possum(__VA_ARGS__) */
/**/
/**/
