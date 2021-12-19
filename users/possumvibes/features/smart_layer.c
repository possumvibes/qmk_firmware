#include "smart_layer.h"
#include "keycodes.h"

/* -------- Number Mode -------- */
static bool _num_mode_active = false;
// Turn number mode on. To be called from a custom keycode
void num_mode_enable(void) {
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
        case KC_1 ... KC_0:
        case KC_PERC:
        case KC_DLR:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_MINS:
        case KC_ASTR:
        case KC_PLUS:
        case KC_COLN:
        case KC_SCLN:
        case KC_EQL:
        // case KC_UNDS:
        case KC_BSPC:
        case KC_X:
        case SYM_MO:
            // process the code and stay in the mode *dabs*
            break;
        default:
            // All other keys disable the layer mode.
            if (record->event.pressed) {
                num_mode_disable();
            }
            break;
    }
}

/* -------- Function Mode -------- */
static bool _func_mode_active = false;

// Turn Func mode on. To be called from a custom keycode.
void func_mode_enable(void) {
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
        case KC_F1 ... KC_F12:
        case F5_TH:
        case F6_TH:
        case F11_TH:
        case F12_TH:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            // sorry about the num comment (but do process the code while remaining in the currently active layermode)
            break;
        default:
            // All other keys disable the layer mode.
            if (record->event.pressed) {
                func_mode_disable();
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
    }
}
