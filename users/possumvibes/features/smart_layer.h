#pragma once
#include QMK_KEYBOARD_H

/* -------- Number Mode -------- */
// Turn number mode on. To be called from a custom keycode
void num_mode_enable(void);

// Turn number mode off.
void num_mode_disable(void);

// Handle each key for number mode.
void num_mode_process(uint16_t keycode, keyrecord_t *record);

/* -------- Function Mode -------- */
// Turn Func mode on. To be called from a custom keycode.
void func_mode_enable(void);

// Turn func mode off.
void func_mode_disable(void);

// Handle each key for func mode.
void func_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Nav Mode -------- */
// Turn Nav mode on. To be called from a custom keycode.
void nav_mode_enable(void);

// Turn nav mode off.
void nav_mode_disable(void);

// Handle each key for nav mode.
void nav_mode_process(uint16_t keycode, keyrecord_t *record);

/* -------- Mus Mode -------- */
// Turn Mus mode on. To be called from a custom keycode.
void mus_mode_enable(void);

// Turn mus mode off.
void mus_mode_disable(void);

// Handle each key for mus mode.
void mus_mode_process(uint16_t keycode, keyrecord_t *record);

/* -------- Process Record -------- */
void process_layermodes(uint16_t keycode, keyrecord_t *record);
