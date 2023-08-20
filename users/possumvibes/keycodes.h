#pragma once
#include QMK_KEYBOARD_H

enum layers { _APT = 0, _COMBOREF, _QWERTY, _FUNC, _NUM, _MACRO, _SYM, _NAV, _SYSTEM };

enum custom_keycodes {
    // OS-specific utilities
    IS_WIN =  QK_USER, 
    LOCKSCR, ALT_F4, DMENU,

    // Layer modes and how to escape them
    NUMMODE, FUNMODE, NAVMODE, SYMMODE, MCRMODE, PANIC,

    // "Paired" macros: Undo/Redo, Comment/Uncomment, QMK Compile/Flash
    UND_RED, QMKCOMP, QMKFLSH, COMMENT, UNCOMNT,

	// Custom markup and programming syntax
    ANGLEBR, BRCKETS, // self-closing brackets: <|>, [|]  {|}
    MD_LINK, MD_CODE, // Markdown: [links|]() and ```codeblocks|  ```
    GET_SET,  // { get; set; }
    RPR_SCL,  // ); ();
    LMBD_FN,  // () =>

    // Quick "not typing all that" strings
    KY_QU, KY_V1, KY_V2, KY_V3,

    // Vim macros: exactly what it says on the tin (words shiftable to Words)
    VI_ZZ, VI_ZQ,   VI_YAW, VI_YIW,   VI_YA, VI_YI,   VI_AW, VI_IW,

    // Swapper keys: Windows, tabs, and generic Reverse
    SW_WIN, SW_TAB, SW_REV,

    // Locking Mods and how to escape them
    ML_LCTL, ML_LSFT, ML_LALT, ML_LGUI, CLEAR, 

    // N-Shot Mods: "normal" callum-style n-shot mods (now featuring MULTI MODS!!!)
    OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, OS_LGLC, TS_LCTL,
    OSR_SFT, // and also n-shot Thumbshift (see n-shot mods for rolling differences)

    NEW_SAFE_RANGE  // Use for keymap-specific codes
};

/* ---------- Aliases ---------- */

// oneshot layers
#define NUM_OSL     OSL(_NUM)
#define SYS_OSL     OSL(_SYSTEM)

// mouse button aliases for ease of use
#define LCLICK      KC_BTN1
#define RCLICK      KC_BTN2
#define MCLICK      KC_BTN3

// window manager shortcuts
#define LSTDESK     G(KC_TILD)
#define LSTNODE     G(KC_GRV)
#define GC_LEFT     G(C(KC_LEFT))
#define GC_RGHT     G(C(KC_RGHT))

#define TMUXPRE     C(KC_SPC)

// Default Layer States
#define QWERTY      DF(_QWERTY)
#define APT         DF(_APT)

// Shortcuts
#define S_CUT       S(KC_DEL)
#define S_COPY      C(KC_INS)
#define S_PASTE     S(KC_INS)
#define S_SAVE      C(KC_S)
#define S_BACK      A(KC_LEFT)
#define S_FWD       A(KC_RIGHT)

// Macros
#define TH(k)       LT(0,k)
#define F3_TH       TH(KC_F3)
#define F5_TH       TH(KC_F5)
#define F6_TH       TH(KC_F6)
#define F11_TH      TH(KC_F11)
#define F12_TH      TH(KC_F12)

