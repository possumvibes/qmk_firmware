#include "possumvibes.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

uint8_t mod_state;
bool is_windows = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    if(record->event.pressed)
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    mod_state = get_mods();

    bool is_shifted = (
        get_mods() & MOD_MASK_SHIFT) ||
        (get_oneshot_mods() & MOD_MASK_SHIFT);

    // Process the functions
    process_mod_lock(keycode, record);
    process_swappers(keycode, record);
    process_nshot_state(keycode, record);
    process_layermodes(keycode, record);

    // Process keymap-specifc keycodes, if extant;
    // Keymap definitions of custom codes will override user definitions.
    if(!process_record_keymap(keycode, record)){
        return false;
    }

    switch (keycode) {
        // Custom Tap/Holds
        case F3_TH:
            return override_th_hold(S(KC_F3), record);
        case F5_TH:
            return override_th_hold(S(KC_F5), record);
        case F6_TH:
            return override_th_hold(S(KC_F6), record);
        case F11_TH:
            return override_th_hold(S(KC_F11), record);
        case F12_TH:
            return override_th_hold(C(KC_F12), record);

        // Shortcuts and macros
        case IS_WIN: {
            if(record->event.pressed){
                is_windows = !is_windows;
            }
            return false;
        }
        case BCK_FWD:{
            return override_shift(is_shifted, A(KC_LEFT), A(KC_RGHT), keycode, record);
        }
        case CLEAR: {
            clear_oneshot_mods();
            clear_mods();
            return false;
        }
        case LOCKSCR: {
            uint16_t lock_key = is_windows ? KC_L : KC_ESC;
            if(record ->event.pressed) {
                tap_code16(G(lock_key));
            }
            return false;
        }
        case PANIC: {
            clear_oneshot_mods();
            clear_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(_QWERTY);
            return false;
        }
        case UND_RED: {
            return override_shift(is_shifted, C(KC_Z), C(KC_Y), keycode, record);
        }

        // Layer Modes
        case NUMMODE:
            num_mode_enable();
            return false;
        case FUNMODE:
            func_mode_enable();
            return false;
        case NAVMODE:
            nav_mode_enable();
            return false;

        // Funky Symbol Shifts
        case KC_AMPR:
        case KC_ASTR:
        case KC_CIRC:
        case KC_EQL:
        case KC_HASH:
        case KC_MINS:
        case KC_PIPE:
        case KC_PLUS:
        case KC_SLSH:
        case KC_TILD:
        {
            if(record ->event.pressed) {
                // If shifted, double these common punctuation marks.
                if(is_shifted){
                    // clear shift temporarily
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);

                    tap_code16(keycode);
                    tap_code16(keycode);

                    // restore previous shift state
                    set_mods(mod_state);
                    return false;
                }
            }
            return true;
        }
        case KC_GRV: {
            if(record ->event.pressed) {
                // if shifted,
                if(is_shifted){

                    // clear shift temporarily
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);


                    triple_tap(keycode);
                    tap_code16(KC_SPC);
                    triple_tap(keycode);
                    tap_code16(C(KC_LEFT));

                    // restore previous shift state
                    set_mods(mod_state);
                    return false;
                }
            }
            return true;
        }
        case LABK_TH:
            return override_th_bracket_pair(KC_LABK, KC_RABK, keycode, record);
        case LBRC_TH:
            return override_th_bracket_pair(KC_LBRC, KC_RBRC, keycode, record);
        case LCBR_TH:
            return override_th_bracket_pair(KC_LCBR, KC_RCBR, keycode, record);
        case LPRN_TH:
            return override_th_bracket_pair(KC_LPRN, KC_RPRN, keycode, record);
        case RBRC_TH: {
            if(record->event.pressed){
                if(record->tap.count){
                    tap_code16(KC_RBRC);
                }
                else{
                    SEND_STRING("[]()");
                    triple_tap(KC_LEFT);

                    layer_off(_SYM);
                }
            }
            return false;
        }
        case RPRN_TH: {
            if(record->event.pressed){
                if(record->tap.count){
                    tap_code16(KC_RPRN);
                } else {
                    SEND_STRING("(){}");
                    triple_tap(KC_LEFT);

                    layer_off(_SYM);
                }
            }
            return false;
        }

        case COM_EXC: {
            return override_shift(is_shifted, KC_COMM, KC_EXLM, keycode, record);
        }
        case DOT_QUE: {
            return override_shift(is_shifted, KC_DOT, KC_QUES, keycode, record);
        }

        // Other
        case SPC_SFT: {
            if(record->event.pressed){
                tap_code16(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        }

        case GET_SET: {
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }
                SEND_STRING("{ get; set; }");
            }
            return false;
        }

        case KC_QU: {
            if (record->event.pressed){
                if(is_shifted){
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    SEND_STRING("Qu");
                } else {
                    SEND_STRING("qu");
                }
            }
            return false;
        }

        case ALT_F4: {
            if(record->event.pressed){
                if(is_windows){
                    tap_code16(A(KC_F4));
                } else {
                    tap_code16(G(KC_Q));
                }
            }
            return false;
        }
        case QMKCOMP: {
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }
                SEND_STRING("qmk compile");
                tap_code16(KC_ENT);
            }
            return false;
        }
        case QMKFLSH: {
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }
                SEND_STRING("qmk flash");
                tap_code16(KC_ENT);
            }
            return false;
        }
        case COMMENT: {
            if(record->event.pressed){
                SEND_STRING(SS_LCTRL("kc"));
                tap_code16(C(KC_S));
            }
            return false;
        }
        case UNCOMNT: {
            if(record->event.pressed){
                SEND_STRING(SS_LCTRL("ku"));
                tap_code16(C(KC_S));
            }
            return false;
        }
    }

    return true;
};
