#include "possumvibes.h"

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t index, combo_t *combo){
    switch(index) {
        // faster combos over rolls
        case l_crx_up:
        case r_crx_hm:
        case r_hrz_hm_mid_ind:
        case r_crx_dn:
            return COMBO_TERM - 7; // 14 ms

        // top row shortcuts
        case l_hrz_up_mid_ind:
        case r_hrz_up_mid_ind:
        case r_hrz_up_ind_lat:
        case dmenu:

        // home row/block shortcuts
        case cut:
        case copy:
        case paste:
        case enter:
            return COMBO_TERM - 3; // 18 ms

        default:
            return COMBO_TERM;
    }
}
#endif
