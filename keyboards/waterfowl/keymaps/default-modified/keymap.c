/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include <stdio.h>
#include QMK_KEYBOARD_H

#include "features/achordion.h"

#include "enums.h"

#include "combos.c"
#include "tapdance.c"

#include "oled.c"

char wpm[42];


/* TEMPLATE
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |     |    |     |  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |     |   |     |       |      |            |       |    |       |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  Z- |   | ESC | TAB |  SPACE |            |  ENTER  | BS | DEL |   |  Z+ |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */

  [_QWERTY] = LAYOUT(
  //--------------------------------------------.                    ,--------------------------------------------.
        KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_A,  HOME_S,  HOME_D,  HOME_F,     KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L, KC_SCLN,
  //--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
          C(KC_MINUS), TD(TD_GUI_ESC), NAV_TAB, LSFT_SPC, KC_MUTE,   KC_NUM,  NUM_ENT, SYM_BSPC, KC_DEL, C(KC_PLUS)
                   //`-----------------------------------'  `-----------------------------------'

  ),


    [_NAV] = LAYOUT(
        KC_ESC,  _______,  _______, CTL_REDO, _______,             KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______,  
       KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_LALT, _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,  
      CTL_UNDO,  CTL_CUT, CTL_COPY,CTL_PASTE, _______,             _______, KC_BSPC,  KC_DEL, _______, _______, 
       _______,  _______,  _______,  _______, _______,             _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                 ,-------------------------------------------.
 * |    `   |  !   |  @   |  #   |  $   |  %   |                 |   ^  |  &   |  *   |  "   |  '   |   '    |
 * |--------+------+------+------+------+------|                 |------+------+------+------+------+--------|
 * |    ~   |  ~   |  [   |  (   |  {   |  =   |                 |   +  |  _   |  <   |  >   |  :   |   "    |
 * |--------+------+------+------+------+------+------.  ,------+------+------+------+------+------+--------|
 * |    |   |  `   |  ]   |  )   |  }   |  ?   |  {   |   |   }  |   -  |  |   |  ,   |  \   |  /   |   ?    |
 * `----------------------+------+------+------+------+-  |------+------+------+------+----------------------'
 *                        |      |      |      |      |   |      |      |      |      |
 *                        |      |      |      |      |   |      |      |      |      |
 *                        `---------------------------'  `---------------------------'
 */
    [_SYM] = LAYOUT(
        KC_EXLM,   KC_AT, KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,  KC_DQT, KC_QUOTE,
         KC_GRV, KC_LBRC, KC_LPRN, KC_LCBR,  KC_EQL,                      KC_PLUS, KC_UNDS, KC_LABK, KC_RABK,  KC_COLN,
        KC_TILD, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUES,                     KC_MINUS, KC_PIPE, KC_COMM, KC_BSLS,  KC_SLSH,
                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),


/*
 * Number Layer: Dedicated Number layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   *  |   7  |   8  |   9  |   +  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   /  |   4  |   5  |   6  |   -  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   0  |   1  |   2  |   3  |   =  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |   _  |   .  |   ,  |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_NUMS] = LAYOUT(
        KC_ASTR, KC_7,    KC_8,   KC_9,  KC_PLUS,                     _______, _______, _______, _______, _______,
       KC_SLASH, KC_4,    KC_5,   KC_6, KC_MINUS,                     _______, _______, _______, _______, _______,
           KC_0, KC_1,    KC_2,   KC_3,   KC_EQL,                     _______, KC_BSPC,  KC_DEL, _______, _______,
              _______, KC_COMM, KC_DOT,   KC_SPC, _______,   _______, _______, _______, _______, _______
     ),
/*
 * Function Layer: Function keys
 *
 * ,------------------------------------------.                              ,-----------------------------------------.
 * |   F1   |   F2   |   F3   |   F4   |  F5  |                              |  F6  |   F7   |   F8  |   F9   |  F10   |
 * |--------+--------+--------+--------+------|                              |------+--------+-------+--------+--------|
 * |  LGUI  |  LSFT  | LCtrl  |  LALT  | F11  |                              | F12  |  LALT  | RCTL | RSFT |  RGUI  |
 * |--------+--------+--------+--------+------|                              |------+------+------+------+-------------|
 * |        |        |        |        |      |                              |      |      |      |      |             |
 * `-----------------+------+-------+------+------|  |------+------+------+------+------+-------------------'
 
 */
    [_FUNCTION] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
      KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,  KC_F11,                       KC_F12, KC_RALT, KC_RCTL, KC_RSFT, KC_RGUI,
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT(
      _______, _______, _______, _______,   _______,             _______, _______, _______, _______, _______,
      _______, SFT_PSCR, KC_PSCR, ALT_PSCR, _______,             _______, _______, _______, _______, _______,
      _______, _______, _______, _______,   _______,             _______, _______, _______, _______, _______,
      _______, _______, _______, _______,   _______,             _______, _______, MO(_FUNCTION), _______, _______
    ),

/**
 * [_______] = LAYOUT(
 *   _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
 *   _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
 *   _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
 *            _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
 * ),
 */
};


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        // Vim Navigation keys
        case HOME_J:
        case HOME_K:
        case HOME_L:
            return QUICK_TAP_TERM;
        default:
            return 0;
    }
}


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    if ( !process_achordion(keycode, record) ) { return false; }

    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    switch(keycode) {
        case KC_BSPC:
        {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
        }
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

/**
 * Achordion control for resolving whether the key combinations pressed are tap hold.
 * Defaults to rejecting same-hand combinations
 */
bool achordion_chord(
    uint16_t tap_hold_keycode,
    keyrecord_t * tap_hold_record,
    uint16_t other_keycode,
    keyrecord_t * other_record
) {
    switch (tap_hold_keycode) {
        case HOME_F:
            // ALT + TAB
            if ( other_keycode == NAV_TAB) {
                return true;
            }
            break;

        case HOME_D: // CTRL + <combo key>
            if (
                (other_keycode == KC_T)
                || (other_keycode == KC_R )
                || (other_keycode == KC_C )
                || (other_keycode == KC_V )
                || (other_keycode == KC_X )
                || (other_keycode == KC_W )
            ) {
                return true;
            }
            break;

        case HOME_K:
            if (
                (other_keycode == KC_N)
                || (other_keycode == KC_Y )
                || (other_keycode == KC_U )
                || (other_keycode == KC_O )
            ) {
                return true;
            }
            break;

        case HOME_S:
            if (
                ( other_keycode == KC_V ) // VIM Select line
                || ( other_keycode == KC_G ) // VIM Go to last line
            ) {
                return true;
            }
            break;

        case LSFT_T(KC_SPC): // Hold-shift left-handed
        case RSFT_T(KC_ENT): // Hold-shift right-handed
        case SYM_BSPC: // Layer-tap right
        case NAV_TAB: // Layer-tap left
            return true;
    }

    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

    return achordion_opposite_hands(tap_hold_record, other_record);
}


/**
 * Customize the Achordion tap-hold duration decision window.
 */
uint16_t achordion_timout(uint16_t tap_hold_keycode) {
    return ACHORDION_DEFAULT_TIMEOUT;
}


bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply Shift and Ctrl mods

        default:
            return false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


bool render_status_user(void) {
    oled_write_P(PSTR("Layer:\n"), false);

    const int layer_idx = get_highest_layer(layer_state);

    switch (layer_idx) {
        case _QWERTY:
            oled_write_P(PSTR("Base"), false);
            break;

        case _NAV:
            oled_write_P(PSTR("Navigate"), false);
            break;

        case _SYM:
            oled_write_P(PSTR("Symbols"), false);
            break;

        case _NUMS:
            oled_write_P(PSTR("Numpad"), false);
            break;

        case _FUNCTION:
            oled_write_P(PSTR("Functions"), false);
            break;

        default:
            oled_write_P(PSTR("Unnamed"), false);
    }
    oled_write_P(PSTR("\n"), false);

    sprintf(wpm, "WPM: %03d\n", get_current_wpm());
    oled_write(wpm, false);

    led_t led_state = host_keyboard_led_state();
    if ( led_state.num_lock ) {
        oled_write_P(PSTR("[N] "), false);
    }
    if (led_state.caps_lock ) {
        oled_write_P(PSTR("[C] "), false);
    }
    if ( led_state.scroll_lock ) {
        oled_write_P(PSTR("[S] "), false);
    }
    oled_write_P("\n", false);

    return false;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(S(KC_MS_WH_DOWN));
        } else {
            tap_code16(S(KC_MS_WH_UP));
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code16(LALT(KC_TAB));
        } else {
            tap_code16(LCA(KC_TAB));
        }
    }

    return false;    
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side
        render_status_user();
    } else {
        // Right side
        draw_oled();
    }

	return 0;
}