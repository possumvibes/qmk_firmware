#pragma once

#include "keycodes.h"

/*
   Wrappers approach is from users/drashna.
   By defining row sections in blocks like this,
   they are easily reusable in very different keyboard layouts.
*/

// Primary thumbs. isn't this illuminating?
// Thumb Keys
#define THM_LH0     NAVMODE
#define THM_LH1     OSR_SFT
#define __ALPHATHUMB_L__        THM_LH0, THM_LH1

#define THM_RH0     KC_SPC
#define THM_RH1     XXXXXXX
#define __ALPHATHUMB_R__        THM_RH1, THM_RH0

// fun fact: i literally do not remember qwerty anymore
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KY_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KY_A,    KY_S,    KY_D,    KY_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KY_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KY_J,    KY_K,    KY_L,    KY_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX

// all the cool kids reference combos from an alpha layout they don't remember anymore
#define ________________COMBOREF_L1________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ________________COMBOREF_L2________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________COMBOREF_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COMBOREF_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ________________COMBOREF_R2________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ________________COMBOREF_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  XXXXXXX

// APTHD2!
#define ________________APTHD2_L1__________________       XXXXXXX, KC_F,    KH_G,    KC_D,    KC_B
#define ________________APTHD2_L2__________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ________________APTHD2_L3__________________       KC_X,    KC_C,    KC_Y,    KC_P,    KC_V
#define _APTHD2_THUMB_L_                                  NAVMODE, OSR_SFT

#define ________________APTHD2_R1__________________       KC_J,    KC_L,    KH_U,    KC_O,    XXXXXXX 
#define ________________APTHD2_R2__________________       KC_W,    KH_N,    KH_E,    KH_A,    KH_I
#define ________________APTHD2_R3__________________       XXXXXXX, KC_M,    KC_COMM, KC_DOT,  XXXXXXX
#define _APTHD2_THUMB_R_                                  KC_QUOT, KC_SPC

// HDLIKE apt variant
#define ________________HDLIKE_L1__________________       KC_X,    KC_C,    KH_D,    KC_L,    KC_K
#define ________________HDLIKE_L2__________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_J
#define ________________HDLIKE_L3__________________       KC_X,    KC_G,    KC_B,    KC_M,    KC_V
#define _HDLIKE_THUMB_L_                                  NAVMODE, OSR_SFT

#define ________________HDLIKE_R1__________________       KC_W,    KC_Y,    KH_U,    KC_O,    XXXXXXX 
#define ________________HDLIKE_R2__________________       KC_P,    KH_N,    KH_E,    KH_A,    KH_I
#define ________________HDLIKE_R3__________________       XXXXXXX, KC_F,    KC_COMM, KC_DOT,  XXXXXXX
#define _HDLIKE_THUMB_R_                                  KC_QUOT, KC_SPC

// APTv3. Daily driver. 
#define __________________APTv3_L1_________________       KC_W,    KC_G,    KH_D,    KC_F,    KC_B
#define __________________APTv3_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTv3_L3_________________       KC_X,    KC_C,    KC_M,    KC_P,    KC_V

#define __________________APTv3_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_Y
#define __________________APTv3_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTv3_R3_________________       XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX

// Functions and Window management. Funcs are organized by number except for the debuggin' ones
#define __________________FUNC_L1__________________       OS_LALT, WKSP_9,  LSTDESK, LSTNODE, WKSP_10
#define __________________FUNC_L2__________________       OS_LCTL, WKSP_1,  WKSP_2,  WKSP_3,  WKSP_4
#define __________________FUNC_L3__________________       XXXXXXX, WKSP_5,  WKSP_6,  WKSP_7,  WKSP_8

#define __________________FUNC_R1__________________       KC_F5,   KC_F6,   KC_F7,   KC_F8,   OS_LGUI
#define __________________FUNC_R2__________________       KC_F9,   F11_TH,  KC_F10,  F6_TH,   OS_LCTL
#define __________________FUNC_R3__________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX

// Numpad left, mods, some punc, and jkG right.
#define _________________NUMPADL_L1________________       KC_W,    KC_7,    KY_8,    KC_9,    KC_PERC
#define _________________NUMPADL_L2________________       KC_V,    KY_4,    KY_5,    KY_6,    KC_DLR
#define _________________NUMPADL_L3________________       KC_X,    KC_1,    KC_2,    KC_3,    XXXXXXX
#define ____NUMPAD_LT___                                  _______, KC_0


#define _________________NUMPADL_R1________________       KC_EQL,  KC_PLUS, XXXXXXX, PANIC,   XXXXXXX
#define _________________NUMPADL_R2________________       S(KC_G), KC_J,    KC_K,    KC_COLN, XXXXXXX
#define _________________NUMPADL_R3________________       XXXXXXX, _______, _______, _______, XXXXXXX
#define ____NUMPAD_RT___                                  _______, _______

// Macro layer: it's got macros
#define _________________MACRO_L1__________________       _______, KY_V1,   KY_V2,   KY_V3,   _______
#define _________________MACRO_L2__________________       XXXXXXX, VI_AW,   VI_IW,   XXXXXXX, XXXXXXX
#define _________________MACRO_L3__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ____MACRO_LT____                                  _______, OSR_SFT

#define _________________MACRO_R1__________________       XXXXXXX, KC_W,    VI_YIW,  VI_YAW,  XXXXXXX
#define _________________MACRO_R2__________________       XXXXXXX, KC_Y,    VI_IW,   VI_AW,   XXXXXXX
#define _________________MACRO_R3__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ____MACRO_RT____                                  OSR_SFT, _______

// Sym layer: There are four symbols.
#define ___________________SYM_L1__________________       _______, _______, OS_LGUI, _______, _______
#define ___________________SYM_L2__________________       _______, OS_LALT, OS_LCTL, OS_LSFT, _______
#define ___________________SYM_L3__________________       _______, _______, OS_LALT, _______, _______
#define _____SYM_LT_____                                  _______, OSR_SFT

#define ___________________SYM_R1__________________       MD_CODE, KC_EQL,  KC_PIPE, ANGLEBR, _______
#define ___________________SYM_R2__________________       LMBD_FN, KC_PLUS, KC_AMPR, MD_LINK, _______
#define ___________________SYM_R3__________________       XXXXXXX, KC_CIRC, RPR_SCL, GET_SET, XXXXXXX
#define _____SYM_RT_____                                  OSR_SFT, _______

// Nav layer: We Got Mods
#define ___________________NAV_L1__________________       XXXXXXX, KC_BACK, OS_LGUI, KC_FWD,  OS_LGLC
#define ___________________NAV_L2__________________       XXXXXXX, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX
#define ___________________NAV_L3__________________       XXXXXXX, XXXXXXX, F12_TH,  TS_LCTL, XXXXXXX

#define ___________________NAV_R1__________________       OS_LGLC, KC_HOME, KC_UP,   KC_END,  XXXXXXX
#define ___________________NAV_R2__________________       F5_TH,   KC_LEFT, KC_DOWN, KC_RGHT, CLEAR
#define ___________________NAV_R3__________________       ML_LGUI, ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI

// SYS layer: helpful macros, system settings, and (for now) some window manager shortcuts.
#define ___________________SYS_L1__________________       _______, _______, _______, _______, _______
#define ___________________SYS_L2__________________       QWERTY,  APT,     _______, _______, _______
#define ___________________SYS_L3__________________       _______, _______, _______, _______, _______

#define ___________________SYS_R1__________________       QK_BOOT, XXXXXXX, ALT_F4,  XXXXXXX, XXXXXXX
#define ___________________SYS_R2__________________       IS_WIN,  QMKCOMP, COMMENT, VI_ZQ,   _______
#define ___________________SYS_R3__________________       XXXXXXX, QMKFLSH, UNCOMNT, VI_ZZ,   _______


/* alt layouts */
// APTHD. APTv3 variant with reduced load on pinkies. Not in use--put too much load on index for me
#define __________________APTHD_L1_________________       KC_W,    KC_C,    KH_Y,    KC_D,    KC_B
#define __________________APTHD_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTHD_L3_________________       KC_X,    KC_F,    KC_G,    KC_P,    KC_V

#define __________________APTHD_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_QUOT
#define __________________APTHD_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTHD_R3_________________       KC_Z,    KC_M,    KC_COMM, KC_DOT, KC_SLSH

// Canary
#define _________________CANARY_L1_________________       KC_W,    KC_L,    KH_Y,    KC_P,    KC_B
#define _________________CANARY_L2_________________       KS_C,    KS_R,    KS_S,    KS_T,    KC_G
#define _________________CANARY_L3_________________       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K

#define _________________CANARY_R1_________________       KC_Z,    KC_F,    KS_O,    KC_U,    KC_QUOT
#define _________________CANARY_R2_________________       KC_M,    KH_N,    KH_E,    KS_I,    KY_A
#define _________________CANARY_R3_________________       KC_X,    KC_H,    KC_SCLN,  KC_COMM, KC_DOT

// APT 3 Meets HD, not presently in use
#define ________________APTv3_HD_L1________________       KC_W,    KC_G,    KH_D,    KC_F,    KC_B
#define ________________APTv3_HD_L2________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ________________APTv3_HD_L3________________       KC_X,    KC_C,    KC_Y,    KC_P,    KC_V

#define ________________APTv3_HD_R1________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_QUOT
#define ________________APTv3_HD_R2________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define ________________APTv3_HD_R3________________       KC_Z,    KC_M,    KC_COMM, KC_DOT, XXXXXXX

// AptMak 
#define ________________APTMAK_L1__________________       KC_Q,    KC_W,    KH_F,    KC_P,    KC_B
#define ________________APTMAK_L2__________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ________________APTMAK_L3__________________       KC_X,    KC_C,    KC_G,    KC_D,    KC_V
#define _APTMAK_THUMB_L_                                  KC_SPC,  NAVMODE

#define ________________APTMAK_R1__________________       KC_Z,    KC_L,    KH_U,    KC_Y,    KC_QUOT
#define ________________APTMAK_R2__________________       KC_J,    KH_N,    KM_A,    KS_I,    KC_O
#define ________________APTMAK_R3__________________       XXXXXXX, KC_M,    KC_COMM, KC_DOT,  XXXXXXX
#define _APTMAK_THUMB_R_                                  OS_LSFT, KC_E

