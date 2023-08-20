#include "possumvibes.h"

/**** n-shot mod configuration  */

// for all mods, the last key of the n-shot will always behave as such:
// [Mod down, mod up, previous n-shot keys if extant], A down, B down, A up, B up: Mod-A b
// For key progression A down, Mod down, A up, Mod up:
nshot_state_t  nshot_states[] = {
    {OS_LSFT, MOD_BIT(KC_LSFT),                         1, true,  os_up_unqueued, 0, 0, false}, // S-a
    {OS_LCTL, MOD_BIT(KC_LCTL),                         1, true,  os_up_unqueued, 0, 0, false}, // C-a
    {OS_LALT, MOD_BIT(KC_LALT),                         1, true,  os_up_unqueued, 0, 0, false}, // A-a
    {OS_LGUI, MOD_BIT(KC_LGUI),                         1, true,  os_up_unqueued, 0, 0, false}, // G-a
    {OS_LGLC, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI),      1, true,  os_up_unqueued, 0, 0, false}, // G-C-a
    {TS_LCTL, MOD_BIT(KC_LCTL),                         2, true,  os_up_unqueued, 0, 0, false}, // C-a
    {OSR_SFT, MOD_BIT(KC_LSFT),                         1, false, os_up_unqueued, 0, 0, false}  // a
};
uint8_t        NUM_NSHOT_STATES = sizeof(nshot_states) / sizeof(nshot_state_t);

bool is_nshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case PANIC:
        case CLEAR:
        case NAVMODE:
            return true;
        default:
            return false;
    }
}

bool is_nshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case NAVMODE:
        case NUM_OSL:
        case NUMMODE:
        case FUNMODE:
        case SYMMODE:
        case MCRMODE:
        case SYS_OSL:
        case OS_LSFT:
        case OS_LCTL:
        case OS_LALT:
        case OS_LGUI:
            return true;
        default:
            return false;
    }
}

/**** Processin' Records ****/

static uint16_t next_keycode;
static keyrecord_t next_record;
static uint16_t prev_keycode;
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t prev_keycode;
    if (record->event.pressed) {
        // store previous keycode for instant tap decisions
        prev_keycode = next_keycode;

        // Cache the next input for mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    return true;
}

static bool is_windows = false;
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
        case F3_TH: return override_th_hold(S(KC_F3), record);
        case F5_TH: return override_th_hold(S(KC_F5), record);
        case F6_TH: return override_th_hold(S(KC_F6), record);
        case F11_TH: return override_th_hold(S(KC_F11), record);
        case F12_TH: return override_th_hold(C(KC_F12), record);

        // Layer Modes
        case NUMMODE: return num_mode_enable(record);
        case FUNMODE: return func_mode_enable(record);
        case NAVMODE: return nav_mode_enable(record);
        case SYMMODE: return sym_mode_enable(record);
        case MCRMODE: return macro_mode_enable(record);

        // Funky Symbol Shifts
        case KC_COMM: return override_shift(is_shifted, keycode, KC_EXLM, record);
        case KC_DOT:  return override_shift(is_shifted, keycode, KC_QUES, record);
        case KC_DQUO: return send_autopair_on_shift(is_shifted, KC_DQUO, KC_DQUO, keycode, record);
        case KC_GRV:  return send_autopair_on_shift(is_shifted, KC_GRV, KC_GRV, keycode, record);

        case KC_LPRN: return send_autopair_on_shift(is_shifted, KC_LPRN, KC_RPRN, keycode, record);
        case KC_RPRN: return send_string_c_function(is_shifted, keycode, record);
        case ANGLEBR: return send_autopair(KC_LABK, KC_RABK, record);
        case BRCKETS: return is_shifted 
            ? send_autopair(KC_LCBR, KC_RCBR, record) 
            : send_autopair(KC_LBRC, KC_RBRC, record);

        case KC_LABK: return send_double_on_shift(is_shifted, keycode, record);
        case KC_RABK: return send_double_on_shift(is_shifted, keycode, record);
        case KC_AMPR: return send_double_on_shift(is_shifted, keycode, record);
        case KC_ASTR: return send_double_on_shift(is_shifted, keycode, record);
        case KC_AT:   return send_double_on_shift(is_shifted, keycode, record);
        case KC_BSLS: return send_double_on_shift(is_shifted, keycode, record);
        case KC_CIRC: return send_double_on_shift(is_shifted, keycode, record);
        case KC_EQL:  return send_double_on_shift(is_shifted, keycode, record);
        case KC_HASH: return send_double_on_shift(is_shifted, keycode, record);
        case KC_MINS: return send_double_on_shift(is_shifted, keycode, record);
        case KC_PERC: return send_double_on_shift(is_shifted, keycode, record);
        case KC_PIPE: return send_double_on_shift(is_shifted, keycode, record);
        case KC_PLUS: return send_double_on_shift(is_shifted, keycode, record);
        case KC_QUES: return send_double_on_shift(is_shifted, keycode, record);
        case KC_SLSH: return send_double_on_shift(is_shifted, keycode, record);

        #ifdef CAPS_WORD_ENABLE
        case KC_DLR:
            if (record->event.pressed) {
                if (is_shifted) {
                    ensure_lowercase(is_shifted);

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
                    clear_shift(is_shifted);

                    SEND_STRING("~/");
                    set_mods(mod_state);
                    return false;
                }
            }
            return true;

        // Other
        case GET_SET: {
            if(record->event.pressed){
                ensure_lowercase(is_shifted);
                SEND_STRING("{ get; set; }");
            }
            return false;
        }

        case RPR_SCL: {
            if(record->event.pressed){
                uint8_t mod_state = get_mods();
                clear_shift(is_shifted);

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
                    clear_shift(is_shifted);
                    SEND_STRING("() =>");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("=>");
                }
            }
            return false;
        
        // Shortcuts and macros
        
        case CLEAR: 
            clear_oneshot_mods();
            clear_mods();
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

        case UND_RED: return override_shift(is_shifted, C(KC_Z), C(KC_Y), record);

        case IS_WIN: {
            if(record->event.pressed){
                is_windows = !is_windows;
            }
            return false;
        }

        case LOCKSCR: 
            if(record ->event.pressed) {
                uint16_t code = is_windows ? G(KC_L): C(A(KC_L));
                tap_code16(code);
            }
            return false;

        case ALT_F4:
            if(record->event.pressed){
                uint16_t code = is_windows ? A(KC_F4) : G(KC_W);
                tap_code16(code);
            }
            return false;
        case DMENU:
            if(record->event.pressed){
                uint16_t code = is_windows ? KC_LGUI : G(KC_SPC);
                tap_code16(code);
            }
            return false;

        case MD_LINK: return send_string_markdown_link(record);

        case MD_CODE:
            if(record ->event.pressed) {
                // clear shift temporarily
                uint8_t mod_state = get_mods();
                clear_shift(is_shifted);

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
                clear_caps();
                SEND_STRING("qmk compile\n");
            }
            return false;
        }
        case QMKFLSH: {
            if(record->event.pressed){
                clear_caps();
                SEND_STRING("qmk flash\n");
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

        case KY_V1: return send_string_version(is_shifted, KC_1, record);
        case KY_V2: return send_string_version(is_shifted, KC_2, record);
        case KY_V3: return send_string_version(is_shifted, KC_3, record);

        case KY_QU:
            if(record->event.pressed){
                if(is_caps_word_on()){
                    // tapping keys to keep caps word enabled; note that KY_QU must be a continue-uncapitalized key for caps_word
                    tap_code16(S(KC_Q));
                    tap_code16(S(KC_U));
                    return false;
                }

                tap_code(KC_Q);

                uint8_t mod_state = get_mods();
                clear_shift(is_shifted);

                tap_code(KC_U);
                set_mods(mod_state);
            }
            return false;

        case VI_ZZ:
            if (record ->event.pressed) {
              ensure_lowercase(is_shifted);
              SEND_STRING("\e:wq\n");
            }
            return false;
        case VI_ZQ:
            if(record->event.pressed){
                ensure_lowercase(is_shifted);
                SEND_STRING("\e:q!\n");
            }
            return false;

        case VI_AW:  return send_string_vi_yiw(is_shifted, false, KC_A, true, record);
        case VI_IW:  return send_string_vi_yiw(is_shifted, false, KC_I, true, record);
        case VI_YAW: return send_string_vi_yiw(is_shifted, true, KC_A, true, record);
        case VI_YIW: return send_string_vi_yiw(is_shifted, true, KC_I, true, record);

        case VI_YI:
          if (record->event.pressed){
                uint8_t code = is_shifted ? KC_A : KC_I;
                return send_string_vi_yiw(is_shifted, true, code, false, record);
            }
          return false;
    }

    return true;
};

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KY_QU:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif 
