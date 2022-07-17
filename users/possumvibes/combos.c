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
        case enter:
        case esc:
        case esc_l:
            return COMBO_TERM - 22
        // shortcuts get faster taps for fewer roll activations
        case back_fwd:
        case dmenu:
        case cut:
        case copy:
        case paste:
        case save:
        case tab:
        case undo_redo:
            return COMBO_TERM - 18;
        // things that are VERY EASY TO TYPO get real fast terms
        case click_l:
        case click_r:
        case dbclick_l:
        case lcbracket:
        case lbracket:
        case lparen:
        case rparen:
        case os_lglc:
        case osgui_r:
        case osgui_l:
            return COMBO_TERM - 15;
        // layer activations get faster to prevent shenanigans
        case funmode:
        case nummode:
        case numosl:
        case sym_rthm:
            return COMBO_TERM - 18;
        default:
            return COMBO_TERM;
    }
}
