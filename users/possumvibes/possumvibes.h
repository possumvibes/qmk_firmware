#pragma once
#include QMK_KEYBOARD_H

/* ------ Base Layout---------- */
#include "keycodes.h"
#include "wrappers.h"

/* ------ Features  ---------- */
#include "features/mod_lock.h"
#include "features/nshot_mod.h"
#include "features/smart_layer.h"
#include "features/override_keys.h"

/* ------ Combos  ---------- */
#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

/* ------ Default Values ---------- */
#define ISWIN_DF    false
