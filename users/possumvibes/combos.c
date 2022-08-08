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
        case esc:
        case esc_l:
            return COMBO_TERM - 22

        // top row shortcuts
        case back_fwd:
        case dmenu:
        case save:
        case tab:
        case undo_redo:
            return COMBO_TERM - 18;

        // home row/block shortcuts
        case cut:
        case copy:
        case paste:
        case nummode:
        case numosl:
        case enter:
            return COMBO_TERM - 18;

        // inner/outer cols (including cross-row)
        case funmode:
        case navmode:
        case nummode_l:
        case panic_r:
        case symmode_l:
        case symmode_r:
            return COMBO_TERM - 15;

        // home row verticals
        case click_l:
        case click_r:
        case dbclick_l:
        case fslash2:
            return COMBO_TERM - 15;

        // thumbs
        case rthumb:
        case outer_thumb:
            return COMBO_TERM - 10;

        default:
            return COMBO_TERM;
    }
}
