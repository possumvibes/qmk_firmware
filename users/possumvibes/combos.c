#include "possumvibes.h"

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t index, combo_t *combo){
    switch(index) {
        // faster combos over rolls
        case l_crx_up:
        case r_crx_up:
        case r_crx_hm:
        case r_hrz_hm_mid_ind:
        case r_crx_dn:
        case l_ful_hm:
        case r_ful_hm:
            return COMBO_TERM - 22; // 14 ms

        // top row shortcuts
        case l_hrz_up_mid_ind:
        case r_hrz_up_mid_ind:
        case r_hrz_up_ind_lat:
        case dmenu:
            return COMBO_TERM - 18; // 18 ms

        // home row/block shortcuts
        case cut:
        case copy:
        case paste:
        case enter:
            return COMBO_TERM - 19; // 17 ms

        // home-bottom verticals
        case click_l:
        case click_r:
        case click_lctl:
        case r_vert_hm_ind:
        case r_vert_hm_mid:
            return COMBO_TERM - 15; // 21 ms

        // home-bottom adjacent diagonals
        case l_diag_hm_pnk:
        case r_diag_hm_pnk:
            return COMBO_TERM - 15;

        // thumbs
        case lthumbs:
        case rthumbs:
            return COMBO_TERM - 10; // 26 ms

        default:
            return COMBO_TERM;
    }
}
#endif
