#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_possum_wrapper(LAYER_QWERTY)

    ,[_COMBOREF] = LAYOUT_possum_wrapper(LAYER_COMBOREF)

    ,[_APT] = LAYOUT_possum_wrapper(LAYER_APTv3)

    ,[_FUNC] = LAYOUT_possum_wrapper(LAYER_FUNC)

    ,[_MACRO] = LAYOUT_possum_wrapper(LAYER_MACRO)

    ,[_NUM] = LAYOUT_possum_wrapper(LAYER_NUM)

    ,[_SYM] = LAYOUT_possum_wrapper(LAYER_SYM)

    ,[_NAV] = LAYOUT_possum_wrapper(LAYER_NAV)

    ,[_SYSTEM] = LAYOUT_possum_wrapper(LAYER_SYSTEM)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
