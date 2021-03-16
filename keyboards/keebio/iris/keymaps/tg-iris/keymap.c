#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  ALTSFT,
  MICMT,
  SCSHT,
  SCSHTS,
  NEWTAB,
  TABRGT,
  TABLFT,
  KILTAB,
  APPSWP,
  RSPC,
  LSPC,
  CUT,
  COPY,
  PST,
  PSTNFM,
  NOTIF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NOTIF,            RAISE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, LOWER,                     KC_SPC,  KC_BSPC,   LALT(KC_ENT)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |PrtScr|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |SPACE | LSPC |KILTAB| RSPC |SSSAVE|                    | PGUP |      |  UP  |  [{  |  ]}  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |BACKSP|TABLFT|NEWTAB|TABRGT|  SS  |-------.    ,-------| PGDN | LEFT | DOWN |RIGHT |  |   |      |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |      |ENTER | CUT  | COPY | PST  |PSTNFM|-------|    |-------|NOTIF |      |   ,<  | .>  |  \   |ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |ALTSFT|LGUI  | /Lower  /       \SPACE \  |BackSP|RAISE |SSSAVE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_SPACE, LSPC,  LGUI(KC_W), RSPC,  SCSHTS,                             KC_PGUP, _______, KC_UP,   KC_LBRC, KC_RBRC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BSPC, LGUI(LALT(KC_LEFT)), LGUI(KC_T), LGUI(LALT(KC_RIGHT)), SCSHT,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PIPE, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, KC_ENT,  LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), PSTNFM, _______,          _______,   NOTIF, _______, _______, _______, KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, _______, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, _______, KC_MINS, _______,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ALTSFT:
      if (record->event.pressed) {
        // when keycode ALTSFT is pressed
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSHIFT));
      } else {
        // when keycode ALTSFT is released
        SEND_STRING(SS_UP(X_LALT)SS_UP(X_LSHIFT));
      }
      break;
    case SCSHT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LCTRL)SS_DOWN(X_LSFT)SS_TAP(X_4)SS_UP(X_LCMD)SS_UP(X_LCTRL)SS_UP(X_LSFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case SCSHTS:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LSFT)SS_TAP(X_4)SS_UP(X_LCMD)SS_UP(X_LSFT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case NEWTAB:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        //SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_T)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case KILTAB:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_W)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case TABRGT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LALT)SS_TAP(X_RIGHT)SS_UP(X_LCMD)SS_UP(X_LALT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case TABLFT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LALT)SS_TAP(X_LEFT)SS_UP(X_LCMD)SS_UP(X_LALT));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case LSPC:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_LEFT)SS_UP(X_LCTRL));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case RSPC:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_RIGHT)SS_UP(X_LCTRL));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case CUT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_X)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case COPY:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_C)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case PST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_V)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case PSTNFM:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LSFT)SS_TAP(X_V)SS_UP(X_LSFT)SS_UP(X_LCMD));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case NOTIF:  //open notifications on mac
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSFT)SS_TAP(X_GRAVE)SS_UP(X_LSFT)SS_UP(X_LCTRL));
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
