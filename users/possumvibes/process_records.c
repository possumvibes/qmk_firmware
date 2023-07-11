#include "possumvibes.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

bool is_windows = ISWIN_DF;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    if(record->event.pressed)
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    bool is_shifted =
        (get_mods() & MOD_MASK_SHIFT) ||
        (get_oneshot_mods() & MOD_MASK_SHIFT);

    // Process the functions
    process_mod_lock(keycode, record);
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
        case KY_V1:
            if(record->event.pressed){
                // Tap V in whatever shift format is present
                tap_code(KC_V);

                // Remove shift before pressing the number
                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(KC_1);
            }
            return false;
        case KY_V2:
            if(record->event.pressed){
                // Tap V in whatever shift format is present
                tap_code(KC_V);

                // Remove shift before pressing the number
                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(KC_2);
            }
            return false;
        case KY_V3:
            if(record->event.pressed){
                // Tap V in whatever shift format is present
                tap_code(KC_V);

                // Remove shift before pressing the number
                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(KC_3);
            }
            return false;
        case KY_QU:
            if(record->event.pressed){
                if(is_caps_word_on()){
                    tap_code16(S(KC_Q));
                    tap_code16(S(KC_U));
                    return false;
                }

                tap_code(KC_Q);
                
                if(is_shifted){
                    uint8_t mod_state = get_mods();
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);

                    tap_code(KC_U);
                    set_mods(mod_state);
                    return false;
                }
                
                tap_code(KC_U);
            }
            return false;
        case VI_ZZ:
        case VI_ZQ:
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }

                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(KC_ESC);
                
                if (keycode == VI_ZZ)
                {
                    SEND_STRING(":wq");
                }
                else
                {
                    SEND_STRING(":q!");
                }
                
                tap_code16(KC_ENT);
            }
            return false;
        case VI_YI:
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }

                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                uint8_t code = is_shifted ? KC_A : KC_I;
                tap_code(KC_Y);
                tap_code(code);
            }
            return false;
        case VI_AW:
        case VI_IW:
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }

                uint8_t textobject = keycode == VI_AW ? KC_A : KC_I;
                uint16_t word_code = is_shifted ? S(KC_W) : KC_W;

                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(textobject);
                tap_code16(word_code);
            }
            return false;
        case VI_YAW:
        case VI_YIW:
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }

                uint8_t textobject = keycode == VI_YAW ? KC_A : KC_I;
                uint16_t word_code = is_shifted ? S(KC_W) : KC_W;

                if(is_shifted){
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                }

                tap_code(KC_Y);
                tap_code(textobject);
                tap_code16(word_code);
            }
            return false;
        // Shortcuts and macros
        case IS_WIN: {
            if(record->event.pressed){
                is_windows = !is_windows;
            }
            return false;
        }
        
        case CLEAR: 
            clear_oneshot_mods();
            clear_mods();
            return false;
        
        case LOCKSCR: 
            if(record ->event.pressed) {
                if(is_windows){
                    tap_code16(G(KC_L));
                } else {
                    tap_code16(C(A(KC_L))); // xflock4
                }
            }
            return false;
        
        case PANIC: {
            clear_oneshot_mods();
            clear_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(0);
            caps_word_off();
            return false;
        }
        case UND_RED: return process_custom_key(is_shifted, C(KC_Z), C(KC_Y), keycode, record);
        

        // Layer Modes
        case NUMMODE: return num_mode_enable(record);
        case FUNMODE: return func_mode_enable(record);
        case NAVMODE: return nav_mode_enable(record);
        case SYMMODE: return sym_mode_enable(record);
        case MCRMODE: return macro_mode_enable(record);

        // Funky Symbol Shifts
        case KC_LABK:
        case KC_RABK:
        case KC_AMPR:
        case KC_ASTR:
        case KC_AT:
        case KC_BSLS:
        case KC_CIRC:
        case KC_EQL:
        case KC_HASH:
        case KC_MINS:
        case KC_PERC:
        case KC_PIPE:
        case KC_PLUS:
        case KC_QUES:
        case KC_SLSH:
        {
            if(record ->event.pressed) {
                // If shifted, double these common punctuation marks.
                if(is_shifted){
                    uint8_t mod_state = get_mods();

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

        #ifdef CAPS_WORD_ENABLE
        case KC_DLR:
            if (record->event.pressed) {
                if (is_shifted) {
                    del_mods(MOD_MASK_SHIFT);

                    register_code16(KC_DLR);
                    caps_word_on();

                    return false;
                }
            }
            else {
                unregister_code16(KC_DLR);
            }

            return true;
        #endif
        case KC_TILD:
            if(record->event.pressed) {
                if (is_shifted) {
                    uint8_t mod_state = get_mods();
                    del_mods(MOD_MASK_SHIFT);

                    SEND_STRING("~/");
                    set_mods(mod_state);
                    return false;
                }
            }
            return true;

        case KC_COMM: return override_shift(is_shifted, KC_EXLM, keycode, record);
        case KC_DOT:  return override_shift(is_shifted, KC_QUES, keycode, record);
        case KC_DQUO: return send_autopair_on_shift(is_shifted, KC_DQUO, KC_DQUO, keycode, record);
        case KC_GRV:  return send_autopair_on_shift(is_shifted, KC_GRV, KC_GRV, keycode, record);

        case KC_LPRN: return send_autopair_on_shift(is_shifted, KC_LPRN, KC_RPRN, keycode, record);
        case KC_RPRN: return send_function_bracket_string(is_shifted, keycode, record);
        case ANGLEBR: return send_autopair(KC_LABK, KC_RABK, record);
		case BRCKETS: return is_shifted 
 			? send_autopair(KC_LCBR, KC_RCBR, record) 
  			: send_autopair(KC_LBRC, KC_RBRC, record);

        // Other
        case GET_SET: {
            if(record->event.pressed){
                if(host_keyboard_led_state().caps_lock){
                    tap_code16(KC_CAPS);
                }
                SEND_STRING("{ get; set; }");
            }
            return false;
        }

        case RPR_SCL: {
            if(record->event.pressed){
                uint8_t mod_state = get_mods();
                del_oneshot_mods(MOD_MASK_SHIFT);
                del_mods(MOD_MASK_SHIFT);

                if(is_shifted){
                    tap_code16(KC_LPRN);
                }
                tap_code16(KC_RPRN);
                tap_code16(KC_SCLN);
                set_mods(mod_state);
            }
            return false;
        }

        case LMBD_FN:
            if(record->event.pressed){
                if(is_shifted){
                    uint8_t mod_state = get_mods();
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("() =>");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("=>");
                }
            }
            return false;


  				
        case ALT_F4:
            if(record->event.pressed){
                if(is_windows){
                    tap_code16(A(KC_F4));
                } else {
                    tap_code16(G(KC_W)); // sxhkd kill window
                }
            }
            return false;
        case DMENU:
            if(record->event.pressed){
                if(is_windows){
                    tap_code(KC_LGUI); // start menu, kde applauncher
                } else {
                    tap_code16(G(KC_SPC)); // rofi shortcut
                }
            }
            return false;
        case MD_LINK:
            if (record->event.pressed) {
                uint8_t mod_state = get_mods();
                del_mods(MOD_MASK_SHIFT);

                SEND_STRING("[]()");
                triple_tap(KC_LEFT);

                set_mods(mod_state);
            }
            return false;
        case MD_CODE:
            if(record ->event.pressed) {
                // clear shift temporarily
                uint8_t mod_state = get_mods();
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);

                // ``` ```|
                SEND_STRING("``` ```");

                // ```| ```
                triple_tap(KC_LEFT);
                tap_code(KC_LEFT);

                // restore previous shift state
                set_mods(mod_state);
            }
            return false;
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
                SEND_STRING(SS_LCTL("kc"));
                tap_code16(C(KC_S));
            }
            return false;
        }
        case UNCOMNT: {
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("ku"));
                tap_code16(C(KC_S));
            }
            return false;
        }
    }

    return true;
};
