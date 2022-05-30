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
        case click_l:
        case click_l2:
            return false;
        // everything should be tap-only unless otherwise specified
        default: return true;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo){
    switch(index) {
        // faster combos over rolls
        case paste:
        case enter:
            return COMBO_TERM - 22
        case back_fwd:
        case cut:
        case copy:
        case save:
        case ctl_b:
        case undo_redo:
        case esc:
        case tab:
        case caps:
        case delete:
            return COMBO_TERM - 18;
        case click_l:
        case click_r:
        case dbclick_l:
        // case click_l2:
        // case click_r2:
        // case dbclick_r:
            return COMBO_TERM - 15;
        case symmode:
        case funmode:
        case nummode:
        case numosl:
        case sym_rthm:
            return COMBO_TERM - 18;
        default:
            return COMBO_TERM;
    }
}
