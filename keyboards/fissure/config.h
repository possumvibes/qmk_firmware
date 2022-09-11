// Copyright 2022 crides (@crides)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6063
#define DEVICE_VER      0x0301
#define MANUFACTURER    Crides
#define PRODUCT         Fissure-v3.0
// #define DESCRIPTION     40 key split keyboard

#define USE_I2C
#define EE_HANDS
// #define SPLIT_USB_DETECT

#define RGB_DI_PIN F7
#define RGBLED_NUM 2
#define RGBLED_SPLIT {1, 1}
#define RGBLIGHT_SPLIT

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define MATRIX_ROW_PINS { E6, D7, C6, D4 }
#define MATRIX_COL_PINS { D3, D2, F4, F5, F6 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
// #define PREVENT_STUCK_MODIFIERS

#define RAW_USAGE_PAGE  0xFF60
#define RAW_USAGE_ID    0x61
#define MATRIX_SCAN_MS 20
