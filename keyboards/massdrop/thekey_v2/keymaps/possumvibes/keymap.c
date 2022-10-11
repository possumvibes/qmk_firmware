/* Copyright 2022 Jason Wihardja
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// aliasing for my sanity
#define LCLICK      KC_BTN1
#define RCLICK      KC_BTN2
#define MCLICK      KC_BTN3

// lines so I can be indecisive
#define UPSIDE_DOWN_0      MO(1),   RCLICK,   LCLICK
#define UPSIDE_DOWN_1      _______, RGB_RMOD, RGB_MOD

#define RIGHTSIDE_UP_0      LCLICK,  RCLICK,   MO(1)
#define RIGHTSIDE_UP_1      RGB_MOD, RGB_RMOD, _______

// macro wrapper because I hate typing
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [0] = LAYOUT_wrapper(UPSIDE_DOWN_0),
    // [1] = LAYOUT_wrapper(UPSIDE_DOWN_1)

    [0] = LAYOUT_wrapper(RIGHTSIDE_UP_0),
    [1] = LAYOUT_wrapper(RIGHTSIDE_UP_1)
};
