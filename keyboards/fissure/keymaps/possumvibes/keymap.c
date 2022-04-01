// Copyright 2022 crides (@crides)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "fissure.h"
#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_alpha_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    )

    ,[_COMBOREF] = LAYOUT_wrapper(
        XXXXXXX, ________________COMBOREF_L1________________, ________________COMBOREF_R1________________, XXXXXXX,
        XXXXXXX, ________________COMBOREF_L2________________, ________________COMBOREF_R2________________, XXXXXXX,
                 ________________COMBOREF_L3________________, ________________COMBOREF_R3________________,
                                   XXXXXXX, KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC,  XXXXXXX
    )

    // ,[_APT] = LAYOUT_alpha_wrapper(
    //     ___________________APT_L1__________________, ___________________APT_R1__________________,
    //     ___________________APT_L2__________________, ___________________APT_R2__________________,
    //     ___________________APT_L3__________________, ___________________APT_R3__________________
    // )

    ,[_APT] = LAYOUT_alpha_wrapper(
        __________________APTv3_L1_________________, __________________APTv3_R1_________________,
        __________________APTv3_L2_________________, __________________APTv3_R2_________________,
        __________________APTv3_L3_________________, __________________APTv3_R3_________________
    )

    ,[_FUNC] = LAYOUT_wrapper(
        _______, __________________FUNC_L1__________________, __________________FUNC_R1__________________,_______,
        _______, __________________FUNC_L2__________________, __________________FUNC_R2__________________,_______,
                 __________________FUNC_L3__________________, __________________FUNC_R3__________________,
                                   _______, _______, _______, _______, _______, _______
    )

    ,[_NUM] = LAYOUT_wrapper(
        _______, _________________NUMPADL_L1________________, _________________NUMPADL_R1________________, _______,
        _______, _________________NUMPADL_L2________________, _________________NUMPADL_R2________________, _______,
                 _________________NUMPADL_L3________________, _________________NUMPADL_R3________________,
                                   _______, _______, _______, _______, _______, _______
    )

    ,[_SYM] = LAYOUT_wrapper(
        _______, ___________________SYM_L1__________________, ___________________SYM_R1__________________, _______,
        _______, ___________________SYM_L2__________________, ___________________SYM_R2__________________, _______,
                 ___________________SYM_L3__________________, ___________________SYM_R3__________________,
                                   _______, __ALPHATHUMB_L__, __ALPHATHUMB_R__, _______
    )

    ,[_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_L1_________________, __________________MOUSE_R1_________________, _______,
        _______, __________________MOUSE_L2_________________, __________________MOUSE_R2_________________, _______,
                 __________________MOUSE_L3_________________, __________________MOUSE_R3_________________,
                                   _______, __ALPHATHUMB_L__, __ALPHATHUMB_R__, _______
    )

    ,[_NAV] = LAYOUT_wrapper(
        _______, ___________________NAV_L1__________________, ___________________NAV_R1__________________, _______,
        _______, ___________________NAV_L2__________________, ___________________NAV_R2__________________, _______,
                 ___________________NAV_L3__________________, ___________________NAV_R3__________________,
                                   _______, __ALPHATHUMB_L__, __ALPHATHUMB_R__, _______
    )

    ,[_SYSTEM] = LAYOUT_wrapper(
        _______, ___________________SYS_L1__________________, ___________________SYS_R1__________________, _______,
        _______, ___________________SYS_L2__________________, ___________________SYS_R2__________________, _______,
                 ___________________SYS_L3__________________, ___________________SYS_R3__________________,
                                   _______, __ALPHATHUMB_L__, __ALPHATHUMB_R__, _______
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
