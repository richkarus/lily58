#include QMK_KEYBOARD_H
#include "keymap_uk.h"

/* Ported from a ZSA Voyager Oryx layout.
 *
 * Voyager has 6x4 + 2 thumb keys per side (52 total); Lily58 has
 * 6x4 + 1 extra inner column key + 4 thumb keys per side (58 total).
 * Mapping decisions made where the two boards don't line up 1:1:
 *   - The Lily58's extra inner-column key on the bottom row (each side,
 *     next to the thumb cluster) has no Voyager equivalent -> KC_NO.
 *   - Voyager's thumb keys (GUI, Shift | Space, Backspace) are placed on
 *     the two innermost Lily58 thumb keys per side; the two outer/spare
 *     thumb keys per side (which the QWERTY template used for Alt/GUI and
 *     Lower/Raise) have no Voyager equivalent -> KC_NO. Layer switching
 *     is done exactly like the Voyager did it: LT() on home-row D/F.
 *   - Dropped: the mouse/navigation layer (layer 3) and all RGB_MATRIX /
 *     Oryx-specific keycodes (RGB_SLD, HSV_184_255_255, TOGGLE_LAYER_COLOR,
 *     RGB_MODE_FORWARD, ledmap, rgb_matrix_indicators_user) since Lily58
 *     uses RGBLIGHT underglow, not a per-key RGB_MATRIX, and none of that
 *     was requested. QK_LLCK (layer lock) also dropped with the mouse layer.
 *   - MAC_LOCK reimplemented as the standard macOS lock shortcut
 *     (Cmd+Ctrl+Q) instead of the ZSA-fork-only HCS() consumer macro.
 */

enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
  MAC_LOCK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_EQL,   KC_A,    KC_S,    LT(_LOWER, KC_D), LT(_RAISE, KC_F), KC_G,                  KC_H,    MT(MOD_RGUI, KC_J), MT(MOD_RCTL, KC_K), MT(MOD_RALT, KC_L), KC_SCLN, KC_QUOT,
    UK_GRV,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,     KC_NO,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 KC_NO, KC_NO, KC_LGUI,   KC_LSFT,   KC_SPC, KC_BSPC,   KC_NO,   KC_NO
  ),

/* LOWER (was Voyager layer 1) */
  [_LOWER] = LAYOUT(
    KC_ESC,   _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,   KC_EXLM, UK_HASH, _______, KC_LBRC, KC_RBRC,                             _______, _______, _______, KC_MINS, KC_SLSH, UK_PIPE,
    _______,  KC_CIRC, KC_AMPR, _______, KC_LPRN, KC_RPRN,                             _______, _______, _______, KC_PLUS, KC_ASTR, KC_BSLS,
    _______,  _______, _______, _______, KC_LCBR, KC_RCBR, KC_NO,   KC_NO,  _______,  _______, _______, KC_DOT,  KC_EQL,  _______,
                                 _______, _______, KC_NO,   _______, _______, KC_NO,   KC_NO,   KC_NO
  ),

/* RAISE (was Voyager layer 2 - media/RGB stripped down to media + nav) */
  [_RAISE] = LAYOUT(
    QK_BOOT,  _______, _______, _______, KC_BRID, KC_BRIU,                            _______, _______, _______, _______, _______, QK_BOOT,
    _______,  _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
    _______,  KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    MAC_LOCK, _______, _______, _______, _______, _______, KC_NO,   KC_NO,  _______,  LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), _______, _______, _______,
                                 _______, _______, KC_NO,   _______, _______, KC_NO,   QK_CLEAR_EEPROM, KC_NO
  ),
};

// OLED (Luna the dog + status icons) is handled entirely by oled_luna.c /
// oled_icons.c (see SRC += in rules.mk) - those define their own
// oled_init_user()/oled_task_user(), so nothing is needed here.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_LOCK:
      if (record->event.pressed) {
        tap_code16(LGUI(LCTL(KC_Q)));
      }
      return false;
  }
  return true;
}
