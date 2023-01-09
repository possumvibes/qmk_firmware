#include "possumvibes.h"
#include "g/keymap_combo.h"

bool get_combo_must_tap(uint16_t index, combo_t *combo){
    switch(index){
        case sys_lthm:
        case click_l:
        case click_l2:
        case dash:
        case underscore:
        case asterisk:
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
        case semicolon:
            return COMBO_TERM - 22

        // top row shortcuts
        case save:
        case tab:
        case undo_redo:
            return COMBO_TERM - 18;

        // home row/block shortcuts
        case dmenu:
        case cut:
        case copy:
        case paste:
        case enter:
            return COMBO_TERM - 18;

        // home-bottom verticals
        case click_l:
        case click_r:
        case click_lctl:
        case rh_mmid_bmid:
            return COMBO_TERM - 15;

        // home-bottom adjacent diagonals
        case lh_mpink_bring:
        case rh_mpink_bring:
            return COMBO_TERM - 15;

        // thumbs
        case lthumbs:
        case rthumbs:
            return COMBO_TERM - 10;

        default:
            return COMBO_TERM;
    }
}
