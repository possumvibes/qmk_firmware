// Copyright 2022 crides (@crides)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L40, L10, L11, L12, L13, L14,                 R10, R11, R12, R13, R14, R44, \
    L41, L20, L21, L22, L23, L24,                 R20, R21, R22, R23, R24, R43, \
         L30, L31, L32, L33, L34,                 R30, R31, R32, R33, R34, \
                        L42, L43, L44,            R40, R41, R42 \
    ) \
    { \
        { L10, L11, L12, L13, L14 }, \
        { L20, L21, L22, L23, L24 }, \
        { L30, L31, L32, L33, L34 }, \
        { L40, L41, L42, L43, L44 }, \
        { R14, R13, R12, R11, R10 }, \
        { R24, R23, R22, R21, R20 }, \
        { R34, R33, R32, R31, R30 }, \
        { R44, R43, R42, R41, R40 } \
    }
