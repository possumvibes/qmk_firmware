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
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    COM_EXC, DOT_QUE, KC_SCLN

// all the cool kids reference combos from an alpha layout they don't remember anymore
#define ________________COMBOREF_L1________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ________________COMBOREF_L2________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________COMBOREF_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COMBOREF_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ________________COMBOREF_R2________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ________________COMBOREF_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// APTHD. APTv3 variant with reduced load on pinkies. Not in use--put too much load on index for me
#define __________________APTHD_L1_________________       KC_W,    KC_C,    KH_Y,    KC_D,    KC_B
#define __________________APTHD_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTHD_L3_________________       KC_X,    KC_F,    KC_G,    KC_P,    KC_V

// #define __________________APTHD_L1_________________       KC_W,    KC_F,    KH_G,    KC_D,    KC_B
// #define __________________APTHD_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
// #define __________________APTHD_L3_________________       KC_X,    KC_C,    KC_Y,    KC_P,    KC_V

#define __________________APTHD_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_QUOT
#define __________________APTHD_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTHD_R3_________________       KC_Z,    KC_M,    COM_EXC, DOT_QUE, KC_SCLN

// APTv3. Daily Driver.
#define __________________APTv3_L1_________________       KC_W,    KC_G,    KH_D,    KC_F,    KC_B
#define __________________APTv3_L2_________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define __________________APTv3_L3_________________       KC_X,    KC_C,    KC_M,    KC_P,    KC_V

#define __________________APTv3_R1_________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_Y
#define __________________APTv3_R2_________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define __________________APTv3_R3_________________       KC_Z,    KC_QUOT, COM_EXC, DOT_QUE, KC_SCLN

// Functions optimized for Visual Studio debugging. The non-debugging/renaming ones are vaguely organized.
#define __________________FUNC_L1__________________       OS_LALT, WKSP_9,  LSTDESK, LSTNODE, WKSP_10
#define __________________FUNC_L2__________________       OS_LCTL, WKSP_1,  WKSP_2,  WKSP_3,  WKSP_4
#define __________________FUNC_L3__________________       OS_LGUI, WKSP_5,  WKSP_6,  WKSP_7,  WKSP_8

#define __________________FUNC_R1__________________       KC_F1,   KC_F8,   KC_F4,   F5_TH,   OS_LALT
#define __________________FUNC_R2__________________       KC_F7,   F11_TH,  KC_F10,  F6_TH,   OS_LCTL
#define __________________FUNC_R3__________________       KC_F9,   KC_F2,   KC_F3,   F6_TH,   OS_LGUI

// Simple numrow, in case I ever want it
#define _________________NUMROW_L1_________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMROW_R1_________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

// Numpad left, mods, some punc, and jkG right.
#define _________________NUMPADL_L1________________       KC_0,    KC_7,    KC_8,    KC_9,    KC_PERC
#define _________________NUMPADL_L2________________       KC_0,    KC_1,    KC_2,    KC_3,    KC_DLR
#define _________________NUMPADL_L3________________       KC_X,    KC_4,    KC_5,    KC_6,    KC_0

#define _________________NUMPADL_R1________________       KC_K,    XXXXXXX, OS_LGUI, KY_QUOT, _______
#define _________________NUMPADL_R2________________       S(KC_G), OS_LSFT, OS_LCTL, OS_LALT, _______
#define _________________NUMPADL_R3________________       KC_J,    KC_SCLN, COM_EXC, DOT_QUE, KC_QUOT

// Sym layer: A Lesson Was Learned
#define ___________________SYM_L1__________________       OS_LALT, KC_RABK, ANGLEBR, RPR_SCL, KC_QUES
#define ___________________SYM_L2__________________       OS_LCTL, KC_LPRN, KC_RPRN, KC_COLN, KC_RCBR
#define ___________________SYM_L3__________________       OS_LGUI, KC_RBRC, KC_LBRC, KC_LCBR, KC_BSLS

#define ___________________SYM_R1__________________       KC_TILD, GET_SET, LMBD_FN, KC_GRV,  XXXXXXX
#define ___________________SYM_R2__________________       KC_DQUO, KC_EQL,  KC_AMPR, KC_PLUS, XXXXXXX
#define ___________________SYM_R3__________________       KC_LABK, KC_CIRC, KC_PIPE, KC_AT,   XXXXXXX


// Nav layer: We Got Mods
#define ___________________NAV_L1__________________       SW_REV,  KC_PGUP, OS_LGUI, KC_PGDN, KC_WH_U
#define ___________________NAV_L2__________________       SW_WIN,  OS_LALT, OS_LCTL, OS_LSFT, KC_WH_D
#define ___________________NAV_L3__________________       SW_TAB,  SW_REV,  F12_TH,  TS_LCTL, OS_LGLC

#define ___________________NAV_R1__________________       KC_PGDN, KC_HOME, KC_UP,   KC_END,  KC_DEL
#define ___________________NAV_R2__________________       F5_TH,   KC_LEFT, KC_DOWN, KC_RGHT, CLEAR
#define ___________________NAV_R3__________________       CTL_U,   ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI


// SYS layer: helpful macros, system settings, and (for now) some window manager shortcuts.
#define ___________________SYS_L1__________________       APTHD,   LOGOUT,  KC_VOLU, CONFIG,  _______
#define ___________________SYS_L2__________________       APT,     KC_MPRV, KC_MPLY, KC_MNXT, _______
#define ___________________SYS_L3__________________       QWERTY,  _______, KC_VOLD, KC_MUTE, _______

#define ___________________SYS_R1__________________       QK_BOOT, SCREEN,  ALT_F4,  KY_V3,   XXXXXXX
#define ___________________SYS_R2__________________       IS_WIN,  QMKCOMP, COMMENT, KY_V2,   _______
#define ___________________SYS_R3__________________       XXXXXXX, QMKFLSH, UNCOMNT, KY_V1,   _______


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

/* --- Retired rows --- */
//// Numpad on the right, symbols on the left. Not presently in use.
// #define _________________NUMPADR_L1________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
// #define _________________NUMPADR_L2________________       SYM_MO,  KC_COLN, KC_DOT,  KC_COMM, XXXXXXX
// #define _________________NUMPADR_L3________________       KC_X,    KC_QUOT, KC_DQUO, KC_DQUO, XXXXXXX

// #define _________________NUMPADR_R1________________       XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX
// #define _________________NUMPADR_R2________________       XXXXXXX, KC_1,    KC_2,    KC_3,    KY_0
// #define _________________NUMPADR_R3________________       XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX


// Sym layer: theoretically optimized, but man i need a better access point
// #define ___________________SYM_L1__________________       KC_BSLS, KC_LABK, KC_RABK, KC_QUES, KC_DLR
// #define ___________________SYM_L2__________________       KC_COLN, KC_LPRN, KC_RPRN, RPR_SCL, KC_PERC
// #define ___________________SYM_L3__________________       KC_RCBR, KC_LBRC, KC_RBRC, KC_LCBR, KC_SLSH

// #define ___________________SYM_R1__________________       KC_QUOT, GET_SET, KC_AT,   KC_EXLM, KC_GRV
// #define ___________________SYM_R2__________________       KC_DQUO, KC_EQL,  KC_AMPR, KC_PLUS, KC_TILD
// #define ___________________SYM_R3__________________       KC_COMM, KC_CIRC, KC_PIPE, KC_MINS, KC_SLSH

// // Sym layer: YAAAAAAAAAA
// #define ___________________SYM_L1__________________       OS_LALT, KC_AT,   KC_RABK, KC_QUES, KC_GRV
// #define ___________________SYM_L2__________________       OS_LCTL, KC_AMPR, KC_PLUS, KC_EQL,  KC_LABK
// #define ___________________SYM_L3__________________       OS_LGUI, KC_PIPE, KC_LBRC, KC_RBRC, KC_BSLS

// #define ___________________SYM_R1__________________       KC_TILD, LMBD_FN, GET_SET, KY_V2,   KC_RCBR
// #define ___________________SYM_R2__________________       KC_DQUO, KC_COLN, KC_LPRN, RPR_SCL, KC_RPRN
// #define ___________________SYM_R3__________________       KC_QUOT, KC_LCBR, ANGLEBR, KY_V3,   XXXXXXX



/* alt layouts */
// APT 3 Meets HD, not presently in use
#define ___________________APT_L1__________________       KC_W,    KC_C,    KH_G,    KC_D,    KC_V
#define ___________________APT_L2__________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ___________________APT_L3__________________       KC_Z,    KC_F,    KC_M,    KC_P,    KC_B

#define ___________________APT_R1__________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_Y
#define ___________________APT_R2__________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define ___________________APT_R3__________________       KC_QUOT, KC_X,    COM_EXC, DOT_QUE, KC_SCLN

// Canary
#define _________________CANARY_L1_________________       KC_W,    KC_L,    KH_Y,    KC_P,    KC_B
#define _________________CANARY_L2_________________       KS_C,    KS_R,    KS_S,    KS_T,    KC_G
#define _________________CANARY_L3_________________       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K

#define _________________CANARY_R1_________________       KC_Z,    KC_F,    KS_O,    KC_U,    KC_QUOT
#define _________________CANARY_R2_________________       KC_M,    KH_N,    KH_E,    KS_I,    KY_A
#define _________________CANARY_R3_________________       KC_X,    KC_H,    KC_SCLN,  COM_EXC, DOT_QUE
