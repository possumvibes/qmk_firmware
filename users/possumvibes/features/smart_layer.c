#include "smart_layer.h"
#include "keycodes.h"

/* -------- Number Mode -------- */
static bool _num_mode_active = false;
// Turn number mode on. To be called from a custom keycode
void num_mode_enable(keyrecord_t *record) {
    _num_mode_active = true;
    layer_on(_NUM);
}

// Turn number mode off.
void num_mode_disable(void) {
    _num_mode_active = false;
    layer_off(_NUM);
}

void num_mode_process(uint16_t keycode, keyrecord_t *record) {
    // Assess if we should exit layermode or continue processing normally.
    switch (keycode) {
        case OS_LSFT ... OS_LGUI:
        case KC_1 ... KC_0:
        case KY_8:
        case KY_4:
        case KY_5:
        case KY_6:
        case KC_DLR:
        case KC_QUOT:
        case KC_SLSH:
        case KC_SCLN:
        case KC_COLN:
        case KC_COMM:
        case KC_DOT:
        case KC_MINS:
        case KC_ASTR:
        case KC_EQL:
        case KC_PLUS:
        case BRCKETS:
        case KC_V:
        case KC_X:
            // process the code and stay in the mode *dabs*
            break;
        default:
            // All other keys disable the layer mode on keyup.
            if (!record->event.pressed) {
                num_mode_disable();
            }
            break;
    }
}

/* -------- Function Mode -------- */
static bool _func_mode_active = false;

// Turn Func mode on. To be called from a custom keycode.
void func_mode_enable(keyrecord_t *record) {
    _func_mode_active = true;
    layer_on(_FUNC);
}

// Turn func mode off.
void func_mode_disable(void) {
    _func_mode_active = false;
    layer_off(_FUNC);
}

// Handle each key for func mode.
void func_mode_process(uint16_t keycode, keyrecord_t *record) {
    // todo possum strip keycode from lt/modtaps if needed

    // Assess if we should exit layermode or continue processing normally.
    switch (keycode) {
        case KC_F3:
        case F5_TH:
        case KC_F8:
        case KC_F10:
        case F11_TH:
        case F12_TH:
        case OS_LSFT ... OS_LGUI:
            break;
        default:
            // All other keys disable the layer mode.
            if (!record->event.pressed) {
                func_mode_disable();
            }
            break;
    }
}

/*--------- Nav Mode ---------------*/
static bool _nav_mode_active = false;
static uint16_t nav_mode_timer;
// Turn nav mode on. To be called from a custom keycode.
void nav_mode_enable(keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_NAV);
        nav_mode_timer = timer_read();
    } else {
        if (timer_elapsed(nav_mode_timer) < TAPPING_TERM) {
            // Tapping enables layer mode
            _nav_mode_active = true;
        } else {
            // Holding treats as a normal LT
            layer_off(_NAV);
        }
    }

}

// Turn nav mode off.
void nav_mode_disable(void) {
    _nav_mode_active = false;
    layer_off(_NAV);
}

void nav_mode_process(uint16_t keycode, keyrecord_t *record){
    // Assess if we should exit layermode or continue processing normally.
    switch (keycode) {
        case OS_LSFT ... OS_LGUI:
        case ML_LCTL ... ML_LGUI:
        case KC_HOME ... KC_UP:
        case KC_MS_U ... KC_ACL2:
        case CLEAR:
        // case F12_TH:
        // case CTL_U:
            break;
        default:
            // All other keys disable the layer mode.
            if (!record->event.pressed) {
                nav_mode_disable();
            }
            break;
    }
}

/*--------- Sym Mode ---------------*/
static bool _sym_mode_active = false;
static uint16_t sym_mode_timer;

// Turn sym mode on. To be called from a custom keycode.
void sym_mode_enable(keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(_SYM);
        sym_mode_timer = timer_read();
    } else {
        if (timer_elapsed(sym_mode_timer) < TAPPING_TERM) {
            // Tapping enables layer mode
            _sym_mode_active = true;
        } else {
            // Holding treats as a normal LT
            layer_off(_SYM);
        }
    }
}

// Turn sym mode off.
void sym_mode_disable(void) {
    _sym_mode_active = false;
    layer_off(_SYM);
}

void sym_mode_process(uint16_t keycode, keyrecord_t *record){
    // todo possum strip keycode from lt/modtaps if needed

    // Assess if we should exit layermode or continue processing normally.
    switch (keycode) {
        // SYMMODE is a glorified oneshot layer that lets you hit shift without breaking.
        case OS_LSFT ... OS_LGUI:
            break;
        default:
            // All other keys disable the layer mode.
            if (!record->event.pressed) {
                sym_mode_disable();
            }
            break;
    }
}

/* -------- Macro Mode -------- */
static bool _macro_mode_active = false;
// Turn macro mode on. To be called from a custom keycode
void macro_mode_enable(keyrecord_t *record) {
    _macro_mode_active = true;
    layer_on(_MACRO);
}

// Turn macro mode off.
void macro_mode_disable(void) {
    _macro_mode_active = false;
    layer_off(_MACRO);
}

void macro_mode_process(uint16_t keycode, keyrecord_t *record) {
    // Assess if we should exit layermode or continue processing normally.
    switch (keycode) {
        case OS_LSFT ... OS_LGUI:
            break;
        default:
            // All other keys disable the layer mode on keyup.
            if (!record->event.pressed) {
                macro_mode_disable();
            }
            break;
    }
}

/* -------- Process Record -------- */
void process_layermodes(uint16_t keycode, keyrecord_t *record) {
    if (_num_mode_active) {
        num_mode_process(keycode, record);
    } else if (_func_mode_active) {
        func_mode_process(keycode, record);
    } else if (_nav_mode_active){
        nav_mode_process(keycode, record);
    } else if (_sym_mode_active){
        sym_mode_process(keycode, record);
    } else if (_macro_mode_active){
        macro_mode_process(keycode, record);
    }
}
