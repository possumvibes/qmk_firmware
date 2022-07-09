#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _APT = 0,
    _COMBOREF,
    _QWERTY,
    _SEMIMAK,
    _GAMENAV,
    _NETHACK,
    _FUNC,
    _NUM,
    _SYM,
    _NAV,
    _SYSTEM
};

#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
enum custom_keycodes {

    // Shortcuts and Macros
    IS_WIN = PLACEHOLDER_SAFE_RANGE, // toggles is_windows value
    BCK_FWD,  // Alt left and right
    CLEAR,    // Clears all mods, does not change layers.
    LOCKSCR,  // locks screen per is_windows value
    PANIC,    // Clears all One-Shot keys and returns to base layer.
    UND_RED,  // Ctrl Z and Y

    // Layer modes
    NUMMODE,  // activates a "num-word" smart layer toggle
    FUNMODE,  // activates a smart layer toggle for func
    NAVMODE,  // activates a smart nav layer
    SYMMODE,  // activates a smart mouse layer

    // Custom Punctuation
    COM_EXC,  // , !
    DOT_QUE,  // . ?

    // custom strings
    SPC_SFT,  // Space and OSS
    GET_SET,  // { get; set; }
    SCREEN,   // Screenshot per OS
    DBCLICK,  // double mouse click
    KY_V1,    // V1
    KY_V2,    // V2
    KY_V3,    // V3

    // macros
    ALT_F4,   // per is_windows Close Application
    QMKCOMP,  // qmk compile
    QMKFLSH,  // qmk flash
    COMMENT,  // C(KC)
    UNCOMNT,  // C(KU)
    DMENU,    // application finder (dmenu, start, etc)

    // Swapper keys
    SW_REV,  // Dead key, reverse direction for swapper
    SW_WIN,   // Alt+Tab time!
    SW_TAB,   // Ctl+Tab time!

    // Locking Mods
    ML_LCTL,  // Locking Mods
    ML_LSFT,  // Locking Mods
    ML_LALT,  // Locking Mods
    ML_LGUI,  // Locking Mods

    // N-Shot Mods
    OS_LSFT,   // OS Mods
    OS_LCTL,   // OS Mods
    OS_LALT,   // OS Mods
    OS_LGUI,   // OS Mods
    OS_LGLC,   // OS G+C
    TS_LCTL,   // Two-shot ctrl

    NEW_SAFE_RANGE  // Use for keymap-specific codes
};

/* ------ Default Values ---------- */
#define ISWIN_DF    false

/* ---------- Aliases ---------- */
#define TH(k)       LT(0,k)
#define LTH(l,k)    LT(l,k)
#define SYM(k)      LT(_SYM, k)

// Thumb Keys
#define THM_LH0     NAVMODE
#define THM_LH1     OS_LSFT

#define THM_RH0     KC_SPC
#define THM_RH1     KC_BSPC

// layer toggles
#define SYM_OSL     OSL(_SYM)
#define SYM_TG      TG(_SYM)
#define SYM_MO      MO(_SYM)
#define MOUS_TG     TG(_MOUSE)
#define NAV_TG      TG(_NAV)
#define NUM_OSL     OSL(_NUM)
#define NUM_TO      TO(_NUM)
#define FUN_OSL     OSL(_FUNC)
#define SYS_OSL     OSL(_SYSTEM)
#define SYS_TO      TO(_SYSTEM)
#define GAMENAV     TG(_GAMENAV)
#define NETHACK     TG(_NETHACK)
#define ALPHA       TO(0)

#define KY_0        SYM(KC_0)
#define KY_6        SYM(KC_6)
#define KY_7        SYM(KC_7)
#define KY_V        LT(_NUM, KC_V)

#define LCLICK      KC_BTN1
#define RCLICK      KC_BTN2
#define MCLICK      KC_BTN3

// i3 shortcuts
#define LOGOUT      G(A(KC_Q))
#define CONFIG      G(A(KC_R))
#define WKSP_1      G(KC_1)
#define WKSP_2      G(KC_2)
#define WKSP_3      G(KC_3)
#define WKSP_4      G(KC_4)
#define WKSP_5      G(KC_5)
// #define WKSP_6      G(KC_6)
// #define WKSP_7      G(KC_7)
// #define WKSP_8      G(KC_8)
// #define WKSP_9      G(KC_9)
// #define WKSP_10      G(KC_0)

// Default Layer States
#define QWERTY      DF(_QWERTY)
#define APT         DF(_APT)
#define SEMIMAK     DF(_SEMIMAK)

// Shortcuts
#define S_CUT       S(KC_DEL)
#define S_COPY      C(KC_INS)
#define S_PASTE     S(KC_INS)
#define S_UNDO      C(KC_Z)
#define S_REDO      C(KC_Y)
#define S_SAVE      C(KC_S)
#define S_ALL       C(KC_A)
#define S_BACK      A(KC_LEFT)
#define S_FWD       A(KC_RIGHT)
#define C_BSPC      C(KC_BSPC)
#define CTL_U       C(KC_U)
#define CTL_GUI     C(KC_LGUI)

#define F3_TH       TH(KC_F3)
#define F5_TH       TH(KC_F5)
#define F6_TH       TH(KC_F6)
#define F11_TH      TH(KC_F11)
#define F12_TH      TH(KC_F12)

/* ----Home Row Mods---- */
// l pinky
#define KS_C        SYM(KC_C)
#define KH_R        SYM(KC_R)
#define KY_A        SYM(KC_A)

// l ring
#define KS_R        LALT_T(KC_R)
#define KH_S        LALT_T(KC_S)
#define KY_S        LALT_T(KC_S)

// l middle
#define KS_S        LCTL_T(KC_S)
#define KH_T        LCTL_T(KC_T)
#define KY_D        LCTL_T(KC_D)

// l index
#define KS_T        LSFT_T(KC_T)
#define KH_H        LSFT_T(KC_H)
#define KY_F        LSFT_T(KC_F)

// l upper middle
#define KS_H        LGUI_T(KC_H)
#define KH_D        LGUI_T(KC_D)
#define KH_G        LGUI_T(KC_G)
#define KH_Y        LGUI_T(KC_Y)
#define KY_E        LGUI_T(KC_E)

// r upper middle
#define KS_O        RGUI_T(KC_O)
#define KH_U        RGUI_T(KC_U)
#define KY_I        RGUI_T(KC_I)

// r index
#define KS_D        RSFT_T(KC_D)
#define KH_N        RSFT_T(KC_N)
#define KY_J        RSFT_T(KC_J)

// r middle
#define KH_E        RCTL_T(KC_E)
#define KY_K        RCTL_T(KC_K)

// r ring
#define KS_I        LALT_T(KC_I)
#define KH_A        LALT_T(KC_A)
#define KY_L        LALT_T(KC_L)

// r pinky
#define KH_I        SYM(KC_I)
#define KY_QUOT     SYM(KC_QUOT)
