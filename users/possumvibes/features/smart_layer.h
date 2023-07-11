#pragma once
#include QMK_KEYBOARD_H

/* -------- Number Mode -------- */
// Turn number mode on. To be called from a custom keycode
bool num_mode_enable(keyrecord_t *record);

// Turn number mode off.
void num_mode_disable(void);

// Handle each key for number mode.
void num_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Function Mode -------- */
// Turn Func mode on. To be called from a custom keycode.
bool func_mode_enable(keyrecord_t *record);

// Turn func mode off.
void func_mode_disable(void);

// Handle each key for func mode.
void func_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Nav Mode -------- */
// Turn Nav mode on. To be called from a custom keycode.
bool nav_mode_enable(keyrecord_t *record);

// Turn nav mode off.
void nav_mode_disable(void);

// Handle each key for nav mode.
void nav_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Sym Mode -------- */
// Turn Sym mode on. To be called from a custom keycode.
bool sym_mode_enable(keyrecord_t *record);

// Turn sym mode off.
void sym_mode_disable(void);

// Handle each key for sym mode.
void sym_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Macro Mode -------- */
// Turn Macro mode on. To be called from a custom keycode.
bool macro_mode_enable(keyrecord_t *record);

// Turn macro mode off.
void macro_mode_disable(void);

// Handle each key for macro mode.
void macro_mode_process(uint16_t keycode, keyrecord_t *record);


/* -------- Process Record -------- */
void process_layermodes(uint16_t keycode, keyrecord_t *record);
