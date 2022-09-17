#pragma once

#include "quantum.h"
#include "wrappers.h"

/* This overrides the base LAYOUT function to allow
 * consistent use of existing keymap blocks as defined
 * in users/possumvibes/wrappers.h
 * This function assigns the board's pins.
 */

 #define LAYOUT_osprette( \
         K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
         K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
         K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                        K30, K31, K32, K33 \
) \
{ \
    { K00,   K01,   K02,   K03, K04, K05, K06, K07,   K08,   K09 }, \
    { K10,   K11,   K12,   K13, K14, K15, K16, K17,   K18,   K19 }, \
    { K20,   K21,   K22,   K23, K24, K25, K26, K27,   K28,   K29 }, \
    { KC_NO, KC_NO, KC_NO, K30, K31, K32, K33, KC_NO, KC_NO, KC_NO } \
}

/* This is a wrapper for the LAYOUT function to allow passing cleaner or modified arguments. */
#define LAYOUT_osprette_wrapper(...)    LAYOUT_osprette(__VA_ARGS__)

// Layout Template with consistent thumbs (e.g., for alpha layers)
#define LAYOUT_osprette_alpha( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29  \
    ) \
    LAYOUT_osprette_wrapper( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  __ALPHATHUMB_L__, __ALPHATHUMB_R__ \
    )
/* Wrapper for new alpha macro */
#define LAYOUT_alpha_wrapper(...)       LAYOUT_osprette_alpha(__VA_ARGS__)
