#pragma once

#include "keycodes.h"

/*
   Wrappers approach is from users/drashna.
   By defining row sections in blocks like this,
   they are easily reusable in very different keyboard layouts.
*/

// Primary thumbs. isn't this illuminating?
#define __ALPHATHUMB_L__        THM_LH0, THM_LH1
#define __ALPHATHUMB_R__        THM_RH1, THM_RH0

// fun fact: i literally do not remember qwerty anymore
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KY_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KY_A,    KY_S,    KY_D,    KY_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KY_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KY_J,    KY_K,    KY_L,    KY_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    COM_EXC, DOT_QUE, KC_SLSH

// all the cool kids reference combos from an alpha layout they don't remember anymore
#define ________________COMBOREF_L1________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ________________COMBOREF_L2________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________COMBOREF_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COMBOREF_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ________________COMBOREF_R2________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ________________COMBOREF_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// APT 3 Meets HD, not presently in use
#define ________________APTv3_HD_L1________________       KC_W,    KC_G,    KH_D,    KC_F,    KC_B
#define ________________APTv3_HD_L2________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ________________APTv3_HD_L3________________       KC_X,    KC_C,    KC_Y,    KC_P,    KC_V

#define ________________APTv3_HD_R1________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_QUOT
#define ________________APTv3_HD_R2________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define ________________APTv3_HD_R3________________       KC_Z,    KC_M,    COM_EXC, DOT_QUE, KC_SLSH

// APTv3. Daily Driver.
#define __________________APTv3_L1_________________       KC_W,    KC_G,    KH_D,    KC_F,    KC_B
#define __________________APTv3_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTv3_L3_________________       KC_X,    KC_C,    KC_M,    KC_P,    KC_V

#define __________________APTv3_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_Y
#define __________________APTv3_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTv3_R3_________________       KC_Z,    KC_QUOT, COM_EXC, DOT_QUE, KC_SLSH

// Functions and Window management. Funcs are organized by number except for the debuggin' ones
#define __________________FUNC_L1__________________       OS_LALT, WKSP_9,  LSTDESK, LSTNODE, WKSP_10
#define __________________FUNC_L2__________________       OS_LCTL, WKSP_1,  WKSP_2,  WKSP_3,  WKSP_4
#define __________________FUNC_L3__________________       OS_LGUI, WKSP_5,  WKSP_6,  WKSP_7,  WKSP_8

#define __________________FUNC_R1__________________       KC_F5,   KC_F6,   KC_F7,   KC_F8,   OS_LALT
#define __________________FUNC_R2__________________       KC_F9,   F11_TH,  KC_F10,  F6_TH,   OS_LCTL
#define __________________FUNC_R3__________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   OS_LGUI

// Numpad left, mods, some punc, and jkG right.
#define _________________NUMPADL_L1________________       OS_LALT, KC_7,    KY_8,    KC_9,    KC_PERC
#define _________________NUMPADL_L2________________       OS_LCTL, KY_4,    KY_5,    KY_6,    KC_DLR
#define _________________NUMPADL_L3________________       KC_EQL,  KC_1,    KC_2,    KC_3,    KC_0

#define _________________NUMPADL_R1________________       S(KC_G), KC_J,    KC_K,    KC_HASH, OS_LALT
#define _________________NUMPADL_R2________________       KC_PLUS, KC_C,    PANIC,   KC_X,    OS_LCTL
#define _________________NUMPADL_R3________________       XXXXXXX, _______, _______, _______, _______

// Macro layer: so i can put the v2 macros somewhere shiftable
#define _________________MACRO_L1__________________       OS_LALT, KY_V1,   KY_V2,   KY_V3,   XXXXXXX
#define _________________MACRO_L2__________________       OS_LCTL, MD_LINK, LMBD_FN, GET_SET, XXXXXXX
#define _________________MACRO_L3__________________       OS_LGUI, XXXXXXX, ANGLEBR, RPR_SCL, XXXXXXX

#define _________________MACRO_R1__________________       XXXXXXX, _______, _______, _______, XXXXXXX
#define _________________MACRO_R2__________________       XXXXXXX, _______, KC_PERC, KC_DLR,  XXXXXXX
#define _________________MACRO_R3__________________       XXXXXXX, _______, _______, _______, XXXXXXX

#define ___________________SYM_L1__________________       _______, _______, OS_LGUI, _______, _______
#define ___________________SYM_L2__________________       _______, OS_LALT, OS_LCTL, OS_LSFT, _______
#define ___________________SYM_L3__________________       _______, _______, _______, _______, _______

#define ___________________SYM_R1__________________       KC_EXLM, KC_PLUS, KC_AMPR, KC_PIPE, KC_QUES
#define ___________________SYM_R2__________________       KC_BSLS, KC_EQL,  KC_AT,   KC_GRV,  XXXXXXX
#define ___________________SYM_R3__________________       XXXXXXX, KC_CIRC, KC_LABK, KC_RABK, XXXXXXX


// Nav layer: We Got Mods
#define ___________________NAV_L1__________________       XXXXXXX, KC_BACK, OS_LGUI, KC_FWD,  XXXXXXX
#define ___________________NAV_L2__________________       XXXXXXX, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX
#define ___________________NAV_L3__________________       XXXXXXX, XXXXXXX, F12_TH,  TS_LCTL, XXXXXXX

#define ___________________NAV_R1__________________       CTL_U,   KC_HOME, KC_UP,   KC_END,  KC_DEL
#define ___________________NAV_R2__________________       F5_TH,   KC_LEFT, KC_DOWN, KC_RGHT, CLEAR
#define ___________________NAV_R3__________________       XXXXXXX, ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI


// SYS layer: helpful macros, system settings, and (for now) some window manager shortcuts.
#define ___________________SYS_L1__________________       APTHD,   LOGOUT,  KC_VOLU, CONFIG,  XXXXXXX
#define ___________________SYS_L2__________________       APT,     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX
#define ___________________SYS_L3__________________       QWERTY,  _______, KC_VOLD, KC_MUTE, XXXXXXX

#define ___________________SYS_R1__________________       QK_BOOT, SCREEN,  ALT_F4,  XXXXXXX, XXXXXXX
#define ___________________SYS_R2__________________       IS_WIN,  QMKCOMP, COMMENT, VI_ZQ,   _______
#define ___________________SYS_R3__________________       XXXXXXX, QMKFLSH, UNCOMNT, VI_ZZ,   _______


/* ------ Gaming Layers ------ */
// QWERTY with Home Row Mods and no layer toggles
#define ________________GAME_NAV_L0_________________________       KC_ESC,  SYS_OSL, PANIC,   XXXXXXX, NETHACK, GAMENAV

#define _______________GAMENAV_QWE_L1______________       KC_Q,    KC_W,    KY_E,    KC_R,    KC_T
#define _______________GAMENAV_QWE_L2______________       KY_A,    KY_S,    KY_D,    KY_F,    KC_G
#define _______________GAMENAV_QWE_L3______________       KC_Z,    KC_X,    KC_C,    KY_V,    KC_B

#define _______________GAMENAV_QWE_R1______________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _______________GAMENAV_QWE_R2______________       KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define _______________GAMENAV_QWE_R3______________       KC_N,    KC_M,    COM_EXC, DOT_QUE, KC_UP
#define _______________GAMENAV_QWE_R4_______________________      KC_BSPC, KC_SPC,  KC_SCLN, KC_LEFT, KC_DOWN, KC_TAB


#define _______________NETHACK_NUM_R1_______________________       KC_7,    KC_8,    KC_9,    KC_COMM, KC_SCLN, KC_Y
#define _______________NETHACK_NUM_R2_______________________       KC_4,    KC_5,    KC_6,    KC_0,    KC_SLSH, KC_QUOT
#define _______________NETHACK_NUM_R3_______________________       KC_1,    KC_2,    KC_3,    KC_DOT,  KC_UP,   KC_N
#define _______________NETHACK_NUM_R4_______________________       KC_BSPC, KC_SPC,  OS_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT


/* alt layouts */
// APTHD. APTv3 variant with reduced load on pinkies. Not in use--put too much load on index for me
#define __________________APTHD_L1_________________       KC_W,    KC_C,    KH_Y,    KC_D,    KC_B
#define __________________APTHD_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTHD_L3_________________       KC_X,    KC_F,    KC_G,    KC_P,    KC_V

#define __________________APTHD_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_QUOT
#define __________________APTHD_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTHD_R3_________________       KC_Z,    KC_M,    COM_EXC, DOT_QUE, KC_SLSH

// Canary
#define _________________CANARY_L1_________________       KC_W,    KC_L,    KH_Y,    KC_P,    KC_B
#define _________________CANARY_L2_________________       KS_C,    KS_R,    KS_S,    KS_T,    KC_G
#define _________________CANARY_L3_________________       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K

#define _________________CANARY_R1_________________       KC_Z,    KC_F,    KS_O,    KC_U,    KC_QUOT
#define _________________CANARY_R2_________________       KC_M,    KH_N,    KH_E,    KS_I,    KY_A
#define _________________CANARY_R3_________________       KC_X,    KC_H,    KC_SCLN,  COM_EXC, DOT_QUE
