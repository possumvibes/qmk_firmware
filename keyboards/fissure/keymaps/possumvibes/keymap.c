#include "fissure.h"
#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_possum_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
                                   __ALPHATHUMB_L__, __ALPHATHUMB_R__
    )

    ,[_COMBOREF] = LAYOUT_possum_wrapper(
        ________________COMBOREF_L1________________, ________________COMBOREF_R1________________,
        ________________COMBOREF_L2________________, ________________COMBOREF_R2________________,
        ________________COMBOREF_L3________________, ________________COMBOREF_R3________________,
                                   KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC
    )

    ,[_APT] = LAYOUT_possum_wrapper(
        __________________APTv3_L1_________________, __________________APTv3_R1_________________,
        __________________APTv3_L2_________________, __________________APTv3_R2_________________,
        __________________APTv3_L3_________________, __________________APTv3_R3_________________,
                                   __ALPHATHUMB_L__, __ALPHATHUMB_R__
    )

    ,[_APTHD] = LAYOUT_possum_wrapper(
        ________________APTHD2_L1__________________, ________________APTHD2_R1__________________,
        ________________APTHD2_L2__________________, ________________APTHD2_R2__________________,
        ________________APTHD2_L3__________________, ________________APTHD2_R3__________________,
                                   _APTHD2_THUMB_L_, _APTHD2_THUMB_R_
    )

    ,[_HDLIKE] = LAYOUT_possum_wrapper(
        ________________HDLIKE_L1__________________, ________________HDLIKE_R1__________________,
        ________________HDLIKE_L2__________________, ________________HDLIKE_R2__________________,
        ________________HDLIKE_L3__________________, ________________HDLIKE_R3__________________,
                                   _HDLIKE_THUMB_L_, _HDLIKE_THUMB_R_
    )

    ,[_FUNC] = LAYOUT_possum_wrapper(
        __________________FUNC_L1__________________, __________________FUNC_R1__________________,
        __________________FUNC_L2__________________, __________________FUNC_R2__________________,
        __________________FUNC_L3__________________, __________________FUNC_R3__________________,
                                   __ALPHATHUMB_L__, __ALPHATHUMB_R__
    )

    ,[_MACRO] = LAYOUT_possum_wrapper(
        _________________MACRO_L1__________________, _________________MACRO_R1__________________,
        _________________MACRO_L2__________________, _________________MACRO_R2__________________,
        _________________MACRO_L3__________________, _________________MACRO_R3__________________,
                                   ____MACRO_LT____, ____MACRO_RT____
    )

    ,[_NUM] = LAYOUT_possum_wrapper(
        _________________NUMPADL_L1________________, _________________NUMPADL_R1________________,
        _________________NUMPADL_L2________________, _________________NUMPADL_R2________________,
        _________________NUMPADL_L3________________, _________________NUMPADL_R3________________,
                                   ____NUMPAD_LT___, ____NUMPAD_RT___
    )

    ,[_SYM] = LAYOUT_possum_wrapper(
        ___________________SYM_L1__________________, ___________________SYM_R1__________________,
        ___________________SYM_L2__________________, ___________________SYM_R2__________________,
        ___________________SYM_L3__________________, ___________________SYM_R3__________________,
                                   _____SYM_LT_____, _____SYM_RT_____
    )

    ,[_NAV] = LAYOUT_possum_wrapper(
        ___________________NAV_L1__________________, ___________________NAV_R1__________________,
        ___________________NAV_L2__________________, ___________________NAV_R2__________________,
        ___________________NAV_L3__________________, ___________________NAV_R3__________________,
                                   __ALPHATHUMB_L__, __ALPHATHUMB_R__
    )

    ,[_SYSTEM] = LAYOUT_possum_wrapper(
        ___________________SYS_L1__________________, ___________________SYS_R1__________________,
        ___________________SYS_L2__________________, ___________________SYS_R2__________________,
        ___________________SYS_L3__________________, ___________________SYS_R3__________________,
                                   __ALPHATHUMB_L__, __ALPHATHUMB_R__
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
