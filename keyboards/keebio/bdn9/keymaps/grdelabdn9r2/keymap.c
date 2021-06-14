/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_keycodes {
  MOOM0 = SAFE_RANGE,
  MOOM1,
  MOOM2,
  MOOM3,
  MOOM4,
  MOOM5,
  MOOM6,
  MOOM7,
  MOOM8,
  MOOM9
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOOM0:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_0)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM1:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_1)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM2:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_2)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM3:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_3)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM4:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_4)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM5:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_5)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM6:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_6)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM7:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_7)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM8:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_8)SS_UP(X_F2));
      } else {
      }
      break;
    case MOOM9:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_9)SS_UP(X_F2));
      } else {
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
	KC_MUTE, MO(1),   MOOM0,
        MOOM4  , MOOM5  , MOOM6,
        MOOM1  , MOOM2  , MOOM3
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RESET  , _______, KC_STOP,
        BL_STEP, KC_HOME, RGB_MOD,
        KC_MPRV, MOOM0  , KC_MNXT
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
