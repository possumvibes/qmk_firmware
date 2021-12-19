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
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KY_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KY_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KY_J,    KY_K,    KY_L,    KY_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    COM_EXC, DOT_QUE, KC_SCLN


#define ________________COMBOREF_L1________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ________________COMBOREF_L2________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ________________COMBOREF_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COMBOREF_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ________________COMBOREF_R2________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define ________________COMBOREF_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define ___________________APT_L1__________________       KC_X,    KC_C,    KH_D,    KC_K,    KC_Q
#define ___________________APT_L2__________________       KH_R,    KH_S,    KH_T,    KH_L,    KC_M
#define ___________________APT_L3__________________       KC_W,    KC_G,    KH_B,    KC_H,    KC_V

#define ___________________APT_R1__________________       KC_J,    KC_P,    KH_U,    KC_O,    KC_QUOT
#define ___________________APT_R2__________________       KC_Y,    KH_N,    KH_E,    KH_A,    KH_I
#define ___________________APT_R3__________________       KC_Z,    KC_F,    COM_EXC, DOT_QUE, KC_SCLN


#define __________________FUNC_L1__________________       OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX
#define __________________FUNC_L2__________________       SYM_MO,  KC_F3,   F6_TH,   F12_TH,  XXXXXXX
#define __________________FUNC_L3__________________       XXXXXXX, KC_F1,   KC_F8,   F5_TH,   XXXXXXX

#define __________________FUNC_R1__________________       XXXXXXX, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI
#define __________________FUNC_R2__________________       XXXXXXX, F11_TH,  KC_F10,  KC_F7,   XXXXXXX
#define __________________FUNC_R3__________________       XXXXXXX, KC_F2,   KC_F4,   KC_F9,   XXXXXXX


#define ___________________NUM_L1__________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ___________________NUM_L2__________________       SYM_MO,  OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX
#define ___________________NUM_L3__________________       NUM_TO,  KC_X,    OS_LGUI, KC_DLR,  XXXXXXX

#define ___________________NUM_R1__________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_DOT
#define ___________________NUM_R2__________________       XXXXXXX, KC_4,    KC_5,    KC_6,    KY_QUOT
#define ___________________NUM_R3__________________       XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM


#define ___________________SYM_L1__________________       KC_BSLS, LABK_TH, KC_RABK, KC_QUES, XXXXXXX
#define ___________________SYM_L2__________________       KC_COLN, LPRN_TH, RPRN_TH, KC_SCLN, XXXXXXX
#define ___________________SYM_L3__________________       KC_RCBR, LBRC_TH, RBRC_TH, LCBR_TH, XXXXXXX

#define ___________________SYM_R1__________________       XXXXXXX, GET_SET, KC_RGHT, KC_EXLM, KC_GRV
#define ___________________SYM_R2__________________       XXXXXXX, KC_EQL,  KC_AMPR, KC_PLUS, KC_TILD
#define ___________________SYM_R3__________________       XXXXXXX, KC_CIRC, KC_PIPE, KC_MINS, KC_SLSH


#define ___________________NAV_L1__________________       _______, _______, OS_LGUI, FUNMODE, XXXXXXX
#define ___________________NAV_L2__________________       SW_WIN,  OS_LALT, OS_LCTL, OS_LSFT, XXXXXXX
#define ___________________NAV_L3__________________       SW_TAB,  SW_REV,  KC_CAPS, TS_LCTL, XXXXXXX

#define ___________________NAV_R1__________________       XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_DEL
#define ___________________NAV_R2__________________       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, CLEAR
#define ___________________NAV_R3__________________       XXXXXXX, ML_LSFT, ML_LCTL, ML_LALT, ML_LGUI


#define ___________________SYS_L1__________________       IS_WIN,  KC_MPRV, KC_MNXT, KC_MUTE, XXXXXXX
#define ___________________SYS_L2__________________       _______, ALT_F4,  _______, KC_MPLY, XXXXXXX
#define ___________________SYS_L3__________________       _______, _______, _______, SYS_TG,  XXXXXXX

#define ___________________SYS_R1__________________       RESET,   _______, _______, APT,     QWERTY
#define ___________________SYS_R2__________________       XXXXXXX, QMKCOMP, COMMENT, SCREEN,  LOCKSCR
#define ___________________SYS_R3__________________       XXXXXXX, QMKFLSH, UNCOMNT, _______, _______


/* ------ Gaming Layers ------ */
// QWERTY with Home Row Mods and no layer toggles
#define ________________GAME_NAV_L0________________       PANIC, SYS_OSL, NUM_TO,  GAMENAV, PANIC
#define ________________GAME_NAV_R0________________       PANIC, GAMENAV, NUM_TO,  SYS_OSL, PANIC

#define _______________NETHACK_VIM_R1______________       KC_Y,    KC_K,    KC_U,    KC_COMM, KC_COLN
#define _______________NETHACK_VIM_R2______________       KC_H,    KC_S,    KC_L,    KC_SLSH, KC_SCLN
#define _______________NETHACK_VIM_R3______________       KC_B,    KC_J,    KC_N,    KC_DOT,  KC_UP,
#define _______________NETHACK_VIM_R4______________       KC_BSPC, KC_SPC,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT

#define _______________NETHACK_NUM_R1_______________________       KC_7,    KC_8,    KC_9,    KC_COMM, KC_COLN, KC_Y
#define _______________NETHACK_NUM_R2_______________________       KC_4,    KC_5,    KC_6,    KC_SLSH, KC_SCLN, KC_QUOT
#define _______________NETHACK_NUM_R3_______________________       KC_1,    KC_2,    KC_3,    KC_DOT,  KC_UP,   KC_N
#define _______________NETHACK_NUM_R4_______________________       KC_BSPC, KC_SPC,  OS_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT
