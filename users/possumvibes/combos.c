#include "possumvibes.h"
#include "g/keymap_combo.h"

bool get_combo_must_hold(uint16_t index, combo_t *combo){
    switch(index) {
        default:
            return false;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo){
    switch(index){
        case sys_lthm:
            return false;
        // everything should be tap-only unless otherwise specified
        default: return true;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo){
    switch(index) {
        // faster combos, home row and home thumb
        case back_fwd:
        case cut:
        case copy:
        case paste:
        case save:
        // case select_all:
        case undo_redo:
            return COMBO_TERM - 10;
        // right hand home/upper combos gotta be faster than left?
        case esc:
        case tab:
        case underscore_rthm:
            return COMBO_TERM - 12;
        case nummode:
        case funmode:
        case turbonav:
            return COMBO_TERM - 15;
        // case os_num:
        // case os_sym:
        // case os_fun:
            // return COMBO_TERM - 5;
        default:
            return COMBO_TERM;
    }
}
