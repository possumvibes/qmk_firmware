#pragma once

#include "keycodes.h"

/*
   Wrappers approach is from users/drashna.
   By defining row sections in blocks like this,EWUI
   they are easily reusable in very different keyboard layouts.
*/

#define __ALPHATHUMB_L__        THM_LH0, THM_LH1
#define __ALPHATHUMB_R__        THM_RH1, THM_RH0

#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KY_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KY_A,    KY_S,    KY_D,    KY_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KY_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KY_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KY_J,    KY_K,    KY_L,    KY_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    COM_EXC, DOT_QUE, KC_SCLN


#define ________________COMBOREF_L1________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ________________COMBOREF_L2________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________COMBOREF_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COMBOREF_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ________________COMBOREF_R2________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ________________COMBOREF_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define ___________________APT_L1__________________       KC_W,    KC_C,    KH_D,    KC_F,    KC_B
#define ___________________APT_L2__________________       KH_R,    KH_S,    KH_T,    KH_H,    KC_K
#define ___________________APT_L3__________________       KC_X,    KC_G,    KC_M,    KH_P,    KC_V

#define ___________________APT_R1__________________       KC_Q,    KC_L,    KH_U,    KC_O,    KC_Y
#define ___________________APT_R2__________________       KC_J,    KH_N,    KH_E,    KH_A,    KH_I
#define ___________________APT_R3__________________       KC_Z,    KC_QUOT, COM_EXC, DOT_QUE, KC_SCLN


#define __________________FUNC_L1__________________       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX
#define __________________FUNC_L2__________________       KC_F1,   F3_TH,   F6_TH,   F12_TH,  XXXXXXX
#define __________________FUNC_L3__________________       KC_F9,   KC_F4,   KC_F2,   F5_TH,   XXXXXXX

#define __________________FUNC_R1__________________       XXXXXXX, KC_MPLY, KC_MUTE, KC_PSCR, XXXXXXX
#define __________________FUNC_R2__________________       XXXXXXX, F11_TH,  KC_F10,  KC_F8,   KC_F7
#define __________________FUNC_R3__________________       XXXXXXX, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI

#define ___________________NUM_L1__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___________________NUM_L2__________________       KY_6,    KC_4,    KC_2,    KC_0,    XXXXXXX
#define ___________________NUM_L3__________________       KC_X,    KC_QUOT, KC_DQUO, KC_9,    XXXXXXX

#define ___________________NUM_R1__________________       XXXXXXX, KC_J,    KC_K,    S(KC_G), XXXXXXX
#define ___________________NUM_R2__________________       XXXXXXX, KC_1,    KC_3,    KC_5,    KY_7
#define ___________________NUM_R3__________________       XXXXXXX, KC_9,    COM_EXC, DOT_QUE, KC_SCLN


#define __________________NUMPAD_L1________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________NUMPAD_L2________________       SYM_MO,  KC_COLN, KC_COMM, KC_0,    XXXXXXX
#define __________________NUMPAD_L3________________       KC_X,    KC_DOT,  KC_COMM, KC_DQUO, XXXXXXX

#define __________________NUMPAD_R1________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __________________NUMPAD_R2________________       XXXXXXX, KC_4,    KC_5,    KC_6,    KY_QUOT
#define __________________NUMPAD_R3________________       XXXXXXX, KC_1,    KC_2,    KC_3,    KC_SCLN


#define ___________________SYM_L1__________________       KC_BSLS, LABK_TH, KC_RABK, KC_QUES, KC_DLR
#define ___________________SYM_L2__________________       KC_COLN, LPRN_TH, RPRN_TH, KC_SCLN, KC_PERC
#define ___________________SYM_L3__________________       KC_RCBR, LBRC_TH, RBRC_TH, LCBR_TH, XXXXXXX

#define ___________________SYM_R1__________________       KC_QUOT, GET_SET, KC_RGHT, KC_EXLM, KC_GRV
#define ___________________SYM_R2__________________       KC_DOT,  KC_EQL,  KC_AMPR, KC_PLUS, KC_TILD
#define ___________________SYM_R3__________________       KC_COMM, KC_CIRC, KC_PIPE, KC_MINS, KC_SLSH


#define ___________________NAV_L1__________________       PANIC,   NUM_OSL, OS_LGUI, FUN_OSL, SYM_OSL
#define ___________________NAV_L2__________________       SW_WIN,  OS_LALT, OS_LCTL, OS_LSFT, KC_CAPS
#define ___________________NAV_L3__________________       SW_TAB,  SW_REV,  KC_CAPS, TS_LCTL, XXXXXXX

#define ___________________NAV_R1__________________       XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_DEL
#define ___________________NAV_R2__________________       F12_TH,  KC_LEFT, KC_DOWN, KC_RGHT, CLEAR
#define ___________________NAV_R3__________________       CTL_U,   ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI


#define ___________________SYS_L1__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___________________SYS_L2__________________       IS_WIN,  _______, _______, LOCKSCR, XXXXXXX
#define ___________________SYS_L3__________________       _______, _______, _______, SYS_TO,  XXXXXXX

#define ___________________SYS_R1__________________       RESET,   _______, ALT_F4,  APT,     QWERTY
#define ___________________SYS_R2__________________       XXXXXXX, QMKCOMP, COMMENT, XXXXXXX, XXXXXXX
#define ___________________SYS_R3__________________       XXXXXXX, QMKFLSH, UNCOMNT, XXXXXXX, _______


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
