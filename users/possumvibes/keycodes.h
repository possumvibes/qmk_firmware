#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _APT = 0,
    _COMBOREF,
    _QWERTY,
    _FUNC,
    _NUM,
    _MACRO,
    _SYM,
    _NAV,
    _SYSTEM
};

enum custom_keycodes {

    // Shortcuts and Macros
    IS_WIN =  QK_USER, // toggles is_windows value
    CLEAR,    // Clears all mods, does not change layers.
    LOCKSCR,  // locks screen per is_windows value
    PANIC,    // Clears all One-Shot keys and returns to base layer.
    UND_RED,  // Ctrl Z and Y

    // Layer modes
    NUMMODE,  // activates a "num-word" smart layer toggle
    FUNMODE,  // activates a smart layer toggle for func
    NAVMODE,  // activates a smart nav layer
    SYMMODE,  // activates a smart symbol layer
    MCRMODE,  // activates a smart numpad layer

    // custom strings
    GET_SET,  // { get; set; }
    RPR_SCL,  // ); ();
    LMBD_FN,  // () =>
    ANGLEBR,  // <|>
    BRCKETS,  // [|]  {|}
    MD_LINK,  // [|]()
    MD_CODE,  // ```| ```
    KY_V1,    // V1
    KY_V2,    // V2
    KY_V3,    // V3
    KY_QU,    // qu
    VI_ZZ,    // ZZ
    VI_ZQ,    // ZQ
    VI_YA,    // ya
    VI_YI,    // yi
    VI_AW,    // aw
    VI_IW,    // iw
    VI_YAW,   // yaw
    VI_YIW,   // yiw

    // macros
    ALT_F4,   // per is_windows Close Application
    DMENU,    // application finder (dmenu, start, etc)
    QMKCOMP,  // qmk compile
    QMKFLSH,  // qmk flash
    COMMENT,  // C(KC)
    UNCOMNT,  // C(KU)

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
    OSR_SFT,   // OS mod immune to rolling
    OS_LCTL,   // OS Mods
    TS_LCTL,   // Two-shot ctrl,
    OS_LALT,   // OS Mods
    OS_LGUI,   // OS Mods
    OS_LGLC,   // OS G+C

    NEW_SAFE_RANGE  // Use for keymap-specific codes
};

/* ------ Default Values ---------- */
#define ISWIN_DF    false

/* ---------- Aliases ---------- */
#define TH(k)       LT(0,k)

// aliases to keep things short in layouts
#define NON     XXXXXXX
#define CAP     KC_CAPS
#define DEL     KC_DEL
#define TL0     THM_LH0
#define TL1     THM_LH1
#define TR0     THM_RH0
#define TR1     THM_RH1

// layer toggles
#define NUM_OSL     OSL(_NUM)
#define SYS_OSL     OSL(_SYSTEM)
#define NAV_SPC     LT(_NAV, KC_SPC)

// mouse button aliases for ease of use
#define LCLICK      KC_BTN1
#define RCLICK      KC_BTN2
#define MCLICK      KC_BTN3
#define CCLICK      C(LCLICK)

// window manager shortcuts
#define LSTDESK     G(KC_TILD)
#define LSTNODE     G(KC_GRV)

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

#define F3_TH       TH(KC_F3)
#define F5_TH       TH(KC_F5)
#define F6_TH       TH(KC_F6)
#define F11_TH      TH(KC_F11)
#define F12_TH      TH(KC_F12)

