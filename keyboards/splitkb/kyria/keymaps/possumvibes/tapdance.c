#include QMK_KEYBOARD_H
#include "keycodes.h"

void dance_f5(qk_tap_dance_state_t *state, void *user_data){
    if(state->count == 1) {
        tap_code(KC_F5);
    } else {
        tap_code16(S(KC_F5));
    }
}

void dance_f6(qk_tap_dance_state_t *state, void *user_data){
    if(state->count == 1) {
        tap_code(KC_F6);
    } else {
        tap_code16(S(KC_F6));
    }
}

void dance_f11(qk_tap_dance_state_t *state, void *user_data){
    if(state->count == 1) {
        tap_code(KC_F11);
    } else {
        tap_code16(S(KC_F11));
    }
}

void dance_f12(qk_tap_dance_state_t *state, void *user_data){
    if(state->count == 1) {
        tap_code(KC_F12);
    } else {
        tap_code16(C(KC_F12));
    }
}

void dance_comment(qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        SEND_STRING(SS_LCTRL("kc"));
    } else {
        SEND_STRING(SS_LCTRL("ku"));
    }
    tap_code16(C(KC_S));
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [F5_TD] = ACTION_TAP_DANCE_FN(dance_f5),
    [F6_TD] = ACTION_TAP_DANCE_FN(dance_f6),
    [F11_TD] = ACTION_TAP_DANCE_FN(dance_f11),
    [F12_TD] = ACTION_TAP_DANCE_FN(dance_f12),
    [CMNT_TD] = ACTION_TAP_DANCE_FN(dance_comment)
};
