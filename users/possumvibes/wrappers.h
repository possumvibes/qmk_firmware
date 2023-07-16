#pragma once

#include "keycodes.h"

/*
   Wrappers approach is from users/drashna.
   By defining row sections in blocks like this,
   they are reusable across differently sized boards.
*/

// Primary thumbs. isn't this illuminating?
// Thumb Keys
#define THM_LH0     NAVMODE
#define THM_LH1     OSR_SFT

#define THM_RH0     KC_SPC
#define THM_RH1     KC_SPC

// APTv3. Daily driver. 
#define LAYER_APTv3 \
    KC_W,    KC_G,    KC_D,    KC_F,    KC_B,    KC_Q,    KC_L,    KC_U,    KC_O,    KC_Y,    \
    KC_R,    KC_S,    KC_T,    KC_H,    KC_K,    KC_J,    KC_N,    KC_E,    KC_A,    KC_I,    \
    KC_X,    KC_C,    KC_M,    KC_P,    KC_V,    XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX, \
                               THM_LH0, THM_LH1, THM_RH1, THM_RH0

// fun fact: i literally do not remember qwerty anymore
#define LAYER_QWERTY \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX, \
                               THM_LH0, THM_LH1, THM_RH1, THM_RH0

// all the cool kids reference combos from an alpha layout they don't remember anymore
#define LAYER_COMBOREF \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX, \
                               KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC

// Functions and Window management. Funcs are organized by number except for the debuggin' ones
#define LAYER_FUNC \
    OS_LALT, WKSP_9,  LSTDESK, LSTNODE, WKSP_10, KC_F5,  KC_F6,   KC_F7,   KC_F8,   OS_LGUI, \
    OS_LCTL, WKSP_1,  WKSP_2,  WKSP_3,  WKSP_4,  KC_F9,  F11_TH,  KC_F10,  F6_TH,   OS_LCTL, \
    XXXXXXX, WKSP_5,  WKSP_6,  WKSP_7,  WKSP_8,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   XXXXXXX, \
                               _______, _______, _______, _______

// Numpad left, mods, some punc, and jkG right.
#define LAYER_NUM \
    KC_W,    KC_7,    KC_8,    KC_9,    KC_PERC, KC_EQL,  KC_PLUS, KC_G,    KC_LSFT, XXXXXXX, \
    KC_V,    KC_4,    KC_5,    KC_6,    KC_DLR,  S(KC_G), KC_J,    KC_K,    KC_L,    XXXXXXX, \
    KC_X,    KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, \
                               _______, KC_0,    _______, _______

// Macro layer: it's got macros
#define LAYER_MACRO \
    _______, KY_V1,   KY_V2,   KY_V3,   _______, XXXXXXX, KC_W,    VI_YIW,  VI_YAW,  XXXXXXX, \
    XXXXXXX, VI_AW,   VI_IW,   XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    VI_IW,   VI_AW,   XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               _______, _______, OSR_SFT, _______

// Sym layer: There are four symbols.
#define LAYER_SYM \
    _______, _______, OS_LGUI, _______, _______, MD_CODE, KC_EQL,  KC_PIPE, ANGLEBR, _______, \
    _______, OS_LALT, OS_LCTL, OS_LSFT, _______, LMBD_FN, KC_PLUS, KC_PIPE, MD_LINK, _______, \
    _______, _______, OS_LALT, _______, _______, XXXXXXX, KC_PIPE, RPR_SCL, GET_SET, XXXXXXX, \
                               _______, _______, OSR_SFT, _______

// Nav layer: We Got Mods
#define LAYER_NAV \
    XXXXXXX, S_BACK,  OS_LGUI, S_FWD,   OS_LGLC, OS_LGLC, KC_HOME, KC_UP,   KC_END,  XXXXXXX,  \
    XXXXXXX, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX, F5_TH,   KC_LEFT, KC_DOWN, KC_RGHT, CLEAR,    \
    XXXXXXX, XXXXXXX, F12_TH,  TS_LCTL, XXXXXXX, ML_LGUI, ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI,  \
                               _______, _______, _______, _______

// SYS layer: helpful macros, system settings, and (for now) some window manager shortcuts.
#define LAYER_SYSTEM \
    _______, _______, _______, _______, _______, QK_BOOT, XXXXXXX, ALT_F4,  S_SAVE,  XXXXXXX, \
    QWERTY,  APT,     _______, _______, _______, IS_WIN,  QMKCOMP, COMMENT, VI_ZQ,   _______, \
    _______, _______, _______, _______, _______, XXXXXXX, QMKFLSH, UNCOMNT, VI_ZZ,   _______, \
                               _______, _______, _______, _______


// LAYOUT wrappers for default 34-key layout mapping
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)

// Macros to add inverted-T GACS mods
#define URM_L(k1) LGUI_T(k1)
#define URM_R(k1) RGUI_T(k1)
#define HRM_L(k0, k1, k2, k3) k0,LALT_T(k1),LCTL_T(k2),LSFT_T(k3)
#define HRM_R(k0, k1, k2, k3) RSFT_T(k0),RCTL_T(k1),RALT_T(k2),k3

#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
      l01, l02, l03, l04, l05,  r01, r02, r03, r04, r05, \
      l06, l07, l08, l09, l10,  r06, r07, r08, r09, r10, \
      l11, l12, l13, l14, l15,  r11, r12, r13, r14, r15, \
                     l16, l17, r16, r17 \
)\
      l01, l02, URM_L(l03),l04, l05,  r01, r02, URM_R(r03), r04, r05, \
      HRM_L(l06, l07, l08, l09),l10,  r06, HRM_R(r07, r08, r09, r10), \
      l11,       l12, l13, l14, l15,  r11,       r12, r13, r14,  r15, \
                          l16, l17,   r16, r17 
