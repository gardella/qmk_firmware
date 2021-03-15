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
  MOOM9,
  ONEP,
  TWO,
  TWOTAP,
  MICMUTE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOOM0:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_0)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM1:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_1)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM2:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_2)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM3:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_3)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM4:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_4)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM5:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_5)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM6:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_6)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM7:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_7)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM8:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_8)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MOOM9:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        //SEND_STRING(SS_DOWN(X_F2)SS_TAP(X_9)SS_UP(X_F2));
        SEND_STRING(SS_DOWN(X_F2)SS_DELAY(500)SS_TAP(X_9)SS_UP(X_F2));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case ONEP:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case TWO:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case MICMUTE:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LCTRL)SS_TAP(X_BSLS)SS_UP(X_LCMD)SS_UP(X_LCTRL));
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |               | Knob 2: Brightness Dn/Up |
        | Press: Mute       | Hold: Layer 2 | Press: Play/Pause        |
        | MOOM1             | MOOM3         | MOOM5                    |
        | MOOM2             | MOOM4         | MOOM6                    |
     */
    [0] = LAYOUT(
	KC__MUTE, MO(1), KC_MPLY,
        MOOM1, MOOM3, MOOM5,
        MOOM2, MOOM4, MOOM6
    ),
    /*
        | RESET    | Held: Layer 2   | Media Stop |
        | MOOM7    | MOOM8           | MOOM9  |
        | TWOTAP   | MOOM0           | ONEP |
     */
    [1] = LAYOUT(
        RESET, _______, KC_STOP,
        MOOM7, MOOM8, MOOM9,
        TWO, MOOM0, ONEP
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRMD);
        } else {
            tap_code(KC_BRMU);
        }
    }
}
