/* Copyright 2018 MechMerlin
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

// iproved hhkb layout with more functionality


#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum custom_keycodes {
    KX_AE = SAFE_RANGE,
    KX_OE,
    KX_UE,
    KX_SS,
    KX_EURO,
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2)), // Alt+0252 → ü
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_0)), // Alt+0220 → Ü
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // Alt+0223 → ß
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // Alt+0223 → ß
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0128 → €
    }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_NO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
      KC_LGUI, KC_LGUI, KC_LALT,                   LT(2, KC_SPACE),                 KC_RALT, KC_RGUI, KC_RGUI
      ),

  [1] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_TRNS,
      KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_DEL,
      KC_RCTL, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, KC_MSTP, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_PLUS, KC_UNDS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
      ),
	  
	  
  [2] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_TRNS,
      KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KX_UE, KC_TRNS, KC_DEL,
      KC_RCTL, KC_TRNS, KX_SS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KX_OE, KX_AE, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
      KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
      )
};



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) return true;
    
    switch (keycode) {
    case KX_AE: case KX_OE: case KX_UE: case KX_SS: case KX_EURO: {
        uint16_t index = keycode - KX_AE;
        uint8_t shift = get_mods()&MODS_SHIFT_MASK;
        
        unregister_code(KC_LSFT); // Gotta temporarily disable both shift keys, else this whole thing may behave oddly
        unregister_code(KC_RSFT);
        
        // Choose Alt code based on which key was pressed and whether Shift was held.
        send_string(alt_codes[index][ (bool)shift]);
        
        if (shift &MOD_BIT(KC_LSFT)) register_code(KC_LSFT); // Restore shift keys to previous state
        if (shift &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);
        
        return false;
    }
    default:
        return true;
    }
}