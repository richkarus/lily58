/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200

// Experiment: bump debounce from QMK's stock 5ms default to 20ms (an
// unverified figure attributed to the ZSA Voyager) to see if it has any
// effect on the occasional stray key-repeat reported vs. the Voyager.
#define DEBOUNCE 20

// Home-row mods (D/F layer-taps, J/K/L mod-taps): resolve a same-hand key
// roll as a hold (deliberate reach for a modifier/layer) but an opposite-hand
// key roll as a tap (normal fast typing) - this is what makes the Voyager's
// home row mods feel clean, and mainline QMK needs it turned on explicitly.
#define CHORDAL_HOLD

// Luna OLED animation (oled_luna.c/oled_icons.c): share mod/LED/layer state
// with the non-master half so its status-icon display stays in sync, and
// point at the icon font bundled with the animation module.
#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#undef OLED_FONT_H
#define OLED_FONT_H "oled_font.c"

#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_LED_COUNT 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// Underglow
/*
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 14    // Number of LEDs
#define RGBLIGHT_SLEEP
*/
