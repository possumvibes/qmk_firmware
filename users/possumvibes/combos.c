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
        case back_fwd:
        case cut:
        case copy:
        case paste:
        case save:
        case undo_redo:
        case caps:
        case delete:
        case click_l:
        case click_r:
        case click_l2:
        case click_r2:
        case dbclick_l:
        case dbclick_r:
        case esc:
        case funmode:
        case musmode:
        case nummode:
        case numosl:
        case tab:
        case turbonav:
        case underscore_rthm:
            return COMBO_TERM - 18;
        default:
            return COMBO_TERM;
    }
}
