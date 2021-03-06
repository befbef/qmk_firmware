#include "gh80_1800.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _MA 0 //Main layer
#define _FN 1

#define ______ KC_TRNS
#define FN_CAPS LT(_FN, KC_CAPS)

//Tap Dance Declarations
enum {
  TD_SHIFT_CAPS = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MA] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                       KC_INS,  KC_HOME,  KC_PGUP, KC_PSCR, \
                                                                                                                                             KC_DEL,  KC_END,   KC_PGDN, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,    KC_NLCK, KC_PSLS,  KC_PAST, KC_PMNS, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,    KC_P7,   KC_P8,    KC_P9,   KC_PPLS, \
        KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, KC_ENT,               KC_P4,   KC_P5,    KC_P6,   KC_PPLS, \
        TD(TD_SHIFT_CAPS), KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,               KC_P1,   KC_P2,    KC_P3, KC_PENT,  \
        KC_LGUI, KC_LGUI, KC_LALT,                 LT(_FN, KC_SPACE),                 KC_RALT, KC_RALT, KC_RCTL,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,             KC_P0,    KC_PDOT, KC_PENT
    ),
    [_FN] = LAYOUT(
        ______,  ______,  ______,  ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,                       ______,  ______,   ______,  ______,  \
                                                                                                                                             RESET,  ______,   ______,  ______,  \
        ______,  ______,  ______,  ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,   ______,      KC_SLCK,  ______,   ______,  ______,  \
        ______,  ______,  ______,  ______, ______, ______, ______, KC_HOME, KC_UP,   KC_END,  ______,  ______,  ______,           ______,     ______,  ______,   ______,  ______,  \
        ______,  ______,  ______,  ______, ______, ______, ______, KC_LEFT,KC_DOWN, KC_RGHT, ______,  ______,           ______,   ______,    ______,  ______,   ______,  ______,  \
        ______,  ______,  ______,  ______, ______, ______, ______, ______, ______, ______, ______,          ______,  ______,   ______,       ______,  ______,   ______,  ______,      \
        ______,  ______,  ______,                  ______,                 ______,  ______,  ______,  ______,  ______,  ______,  ______,              ______,   ______,  ______
    )
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        DDRD |= (1 << 6);
    } else {
        DDRD &= ~(1 << 6);
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRD |= (1 << 7);
    } else {
        DDRD &= ~(1 << 7);
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        DDRD |= (1 << 4);
    } else {
        DDRD &= ~(1 << 4);
    }
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

