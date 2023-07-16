#include "layout.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_34key_w(HRM(LAYER_QWERTY))

    ,[_COMBOREF] = LAYOUT_34key_w(LAYER_COMBOREF)

    ,[_APT] = LAYOUT_34key_w(HRM(LAYER_APTv3))

    ,[_FUNC] = LAYOUT_34key_w(LAYER_FUNC)

    ,[_MACRO] = LAYOUT_34key_w(LAYER_MACRO)

    ,[_NUM] = LAYOUT_34key_w(HRM(LAYER_NUM))

    ,[_SYM] = LAYOUT_34key_w(LAYER_SYM)

    ,[_NAV] = LAYOUT_34key_w(LAYER_NAV)

    ,[_SYSTEM] = LAYOUT_34key_w(LAYER_SYSTEM)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
