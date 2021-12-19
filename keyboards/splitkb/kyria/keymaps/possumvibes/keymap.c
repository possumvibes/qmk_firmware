/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "possumvibes.h"
#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kyria_alpha_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    )

    ,[_COMBOREF] = LAYOUT_kyria_wrapper(
        XXXXXXX, ________________COMBOREF_L1________________,                                     ________________COMBOREF_R1________________, _______,
        XXXXXXX, ________________COMBOREF_L2________________,                                     ________________COMBOREF_R2________________, _______,
        XXXXXXX, ________________COMBOREF_L3________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ________________COMBOREF_R3________________, XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_ENT,  KC_TAB,  XXXXXXX, XXXXXXX, KC_BSPC, KC_SPC,  XXXXXXX, XXXXXXX
    )

    ,[_APT] = LAYOUT_kyria_alpha_wrapper(
        ___________________APT_L1__________________, ___________________APT_R1__________________,
        ___________________APT_L2__________________, ___________________APT_R2__________________,
        ___________________APT_L3__________________, ___________________APT_R3__________________
    )

    ,[_FUNC] = LAYOUT_kyria_wrapper(
        XXXXXXX, __________________FUNC_L1__________________,                                     __________________FUNC_R1__________________, _______,
        XXXXXXX, __________________FUNC_L2__________________,                                     __________________FUNC_R2__________________, _______,
        XXXXXXX, __________________FUNC_L3__________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __________________FUNC_R3__________________, XXXXXXX,
                                   _______, XXXXXXX, THM_LH0, _______, XXXXXXX, XXXXXXX, _______, THM_RH0, XXXXXXX, _______
    )

    ,[_NUM] = LAYOUT_kyria_wrapper(
        XXXXXXX, ___________________NUM_L1__________________,                                     ___________________NUM_R1__________________, _______,
        XXXXXXX, ___________________NUM_L2__________________,                                     ___________________NUM_R2__________________, _______,
        XXXXXXX, ___________________NUM_L3__________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___________________NUM_R3__________________, XXXXXXX,
                                   _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, KC_0,    XXXXXXX, _______
    )

    ,[_SYM] = LAYOUT_kyria_wrapper(
        XXXXXXX, ___________________SYM_L1__________________,                                     ___________________SYM_R1__________________, _______,
        XXXXXXX, ___________________SYM_L2__________________,                                     ___________________SYM_R2__________________, _______,
        XXXXXXX, ___________________SYM_L3__________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___________________SYM_R3__________________, XXXXXXX,
                                   _______, XXXXXXX, THM_LH0, OS_LSFT, XXXXXXX, XXXXXXX, _______, THM_RH0, XXXXXXX, _______
    )

    ,[_NAV] = LAYOUT_kyria_wrapper(
        XXXXXXX, ___________________NAV_L1__________________,                                     ___________________NAV_R1__________________, _______,
        XXXXXXX, ___________________NAV_L2__________________,                                     ___________________NAV_R2__________________, _______,
        XXXXXXX, ___________________NAV_L3__________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___________________NAV_R3__________________, XXXXXXX,
                                   _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, THM_RH0, XXXXXXX, _______
    )

    ,[_SYSTEM] = LAYOUT_kyria_wrapper(
        XXXXXXX, ___________________SYS_L1__________________,                                      ___________________SYS_R1__________________, XXXXXXX,
        XXXXXXX, ___________________SYS_L2__________________,                                      ___________________SYS_R2__________________, XXXXXXX,
        XXXXXXX, ___________________SYS_L3__________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  ___________________SYS_R3__________________, XXXXXXX,
                                   _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, QMKCOMP, XXXXXXX, _______
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
