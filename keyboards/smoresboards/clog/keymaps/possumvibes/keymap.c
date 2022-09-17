/* Copyright 2018-2021
 * ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 * David Philip Barr <@davidphilipbarr>
 * Pierre Chevalier <pierrechevalier83@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "layout.h"

/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_possum_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    )

    ,[_COMBOREF] = LAYOUT_possum_thumbs_wrapper(
        ________________COMBOREF_L1________________, ________________COMBOREF_R1________________,
        ________________COMBOREF_L2________________, ________________COMBOREF_R2________________,
        ________________COMBOREF_L3________________, ________________COMBOREF_R3________________,
                                   KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC
    )

//     // ,[_APT] = LAYOUT_possum_wrapper(
//     //     ___________________APT_L1__________________, ___________________APT_R1__________________,
//     //     ___________________APT_L2__________________, ___________________APT_R2__________________,
//     //     ___________________APT_L3__________________, ___________________APT_R3__________________
//     // )

    ,[_APT] = LAYOUT_possum_wrapper(
        __________________APTv3_L1_________________, __________________APTv3_R1_________________,
        __________________APTv3_L2_________________, __________________APTv3_R2_________________,
        __________________APTv3_L3_________________, __________________APTv3_R3_________________
    )

    ,[_APTHD] = LAYOUT_possum_wrapper(
        __________________APTHD_L1_________________, __________________APTHD_R1_________________,
        __________________APTHD_L2_________________, __________________APTHD_R2_________________,
        __________________APTHD_L3_________________, __________________APTHD_R3_________________
    )

    ,[_FUNC] = LAYOUT_possum_wrapper(
        __________________FUNC_L1__________________, __________________FUNC_R1__________________,
        __________________FUNC_L2__________________, __________________FUNC_R2__________________,
        __________________FUNC_L3__________________, __________________FUNC_R3__________________
    )

    ,[_NUM] = LAYOUT_possum_wrapper(
        _________________NUMPADL_L1________________, _________________NUMPADL_R1________________,
        _________________NUMPADL_L2________________, _________________NUMPADL_R2________________,
        _________________NUMPADL_L3________________, _________________NUMPADL_R3________________
    )

    ,[_SYM] = LAYOUT_possum_wrapper(
        ___________________SYM_L1__________________, ___________________SYM_R1__________________,
        ___________________SYM_L2__________________, ___________________SYM_R2__________________,
        ___________________SYM_L3__________________, ___________________SYM_R3__________________
    )

    ,[_NAV] = LAYOUT_possum_wrapper(
        ___________________NAV_L1__________________, ___________________NAV_R1__________________,
        ___________________NAV_L2__________________, ___________________NAV_R2__________________,
        ___________________NAV_L3__________________, ___________________NAV_R3__________________
    )

    ,[_SYSTEM] = LAYOUT_possum_wrapper(
        ___________________SYS_L1__________________, ___________________SYS_R1__________________,
        ___________________SYS_L2__________________, ___________________SYS_R2__________________,
        ___________________SYS_L3__________________, ___________________SYS_R3__________________
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};

