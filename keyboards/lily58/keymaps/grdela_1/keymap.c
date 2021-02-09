#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef OLED_DRIVER_ENABLE
  #include "ssd1306.h"
#endif



#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

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

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |  F2  |LGUI  | /Lower  /       \SPACE \  |BackSP|RAISE |AltEnt|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT, \
  KC_LALT, KC_F2, KC_LGUI, LOWER,    KC_SPC,   KC_BSPC, RAISE  , LALT(KC_ENT) \
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
[_LOWER] = LAYOUT( \
  KC_ESC, _______, _______, _______, _______, KC_PSCR,                     _______, _______, _______, _______, _______,  _______, \
  _______, KC_SPACE, LSPC, LGUI(KC_W), RSPC, SCSHTS,                   KC_PGUP, _______, KC_UP, KC_LBRC, KC_RBRC, _______, \
  _______, KC_BSPC, LGUI(LALT(KC_LEFT)), LGUI(KC_T), LGUI(LALT(KC_RIGHT)), SCSHT,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, _______, \
  _______, KC_ENT, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), PSTNFM, _______, _______, NOTIF, _______, _______, _______, KC_BSLS, _______, \
                             _______, ALTSFT, _______, _______, _______,  _______, _______, SCSHTS \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  | F4 |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |ALTSFT|LGUI  | /Lower  /       \SPACE \  |BackSP|RAISE |SSSAVE|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    /* //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h */
    /* #ifdef OLED_DRIVER_ENABLE */
    /*     iota_gfx_init(!has_usb());   // turns on the display */
    /* #endif */
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
/* #ifdef OLED_DRIVER_ENABLE */

/* // When add source files to SRC in rules.mk, you can use functions. */
/* const char *read_layer_state(void); */
/* const char *read_logo(void); */
/* void set_keylog(uint16_t keycode, keyrecord_t *record); */
/* const char *read_keylog(void); */
/* const char *read_keylogs(void); */

/* // const char *read_mode_icon(bool swap); */
/* // const char *read_host_led_state(void); */
/* // void set_timelog(void); */
/* // const char *read_timelog(void); */

/* void matrix_scan_user(void) { */
/*    iota_gfx_task(); */
/* } */

/* void matrix_render_user(struct CharacterMatrix *matrix) { */
/*   if (is_master) { */
/*     // If you want to change the display of OLED, you need to change here */
/*     matrix_write_ln(matrix, read_layer_state()); */
/*     matrix_write_ln(matrix, read_keylog()); */
/*     matrix_write_ln(matrix, read_keylogs()); */
/*     //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui)); */
/*     //matrix_write_ln(matrix, read_host_led_state()); */
/*     //matrix_write_ln(matrix, read_timelog()); */
/*   } else { */
/*     matrix_write(matrix, read_logo()); */
/*   } */
/* } */

/* void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) { */
/*   if (memcmp(dest->display, source->display, sizeof(dest->display))) { */
/*     memcpy(dest->display, source->display, sizeof(dest->display)); */
/*     dest->dirty = true; */
/*   } */
/* } */

/* void iota_gfx_task_user(void) { */
/*   struct CharacterMatrix matrix; */
/*   matrix_clear(&matrix); */
/*   matrix_render_user(&matrix); */
/*   matrix_update(&display, &matrix); */
/* } */
/* #endif//SSD1306OLED */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

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
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case MICMT:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LCTRL)SS_TAP(X_BSLS)SS_UP(X_LCMD)SS_UP(X_LCTRL));
      } else {
        // when keycode QMKBEST is released
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
    case APPSWP:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_TAP(X_TAB)SS_UP(X_LCMD));
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
