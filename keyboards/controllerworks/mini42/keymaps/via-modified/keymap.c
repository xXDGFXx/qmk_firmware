/*
 * Copyright 2022 Kevin Gee <info@controller.works>
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
#include <stdio.h>
#include QMK_KEYBOARD_H

#include "enums.h"
#include "features/achordion.h"

#include "bongo.h"


char wpm[42];


const uint16_t PROGMEM capsword_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM osl_fnc_combo[] = {NAV_TAB, SYM_BSPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsword_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(capslock_combo, KC_CAPS),
    COMBO(osl_fnc_combo, OSL(_FUNCTION))
};


/*
enum layer_enum {
    _BASE,
    _SYMBOLS,
    _NAVIGATE,
    _NUMBERS,
    _FUNCTIONS,
    _ADJUST,
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,KC_MINUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, NAV_TAB,LSFT_SPC,    NUM_ENT, SYM_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'

  ),

    [_NAV] = LAYOUT_split_3x6_3(
      _______,    KC_ESC,       _______,       _______,      CTL_REDO, _______,             KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______,  KC_DEL,
      _______,   KC_LGUI, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,  KC_INS,
      _______,  CTL_UNDO,       CTL_CUT,      CTL_COPY,     CTL_PASTE, _______,             _______, KC_BSPC,  KC_DEL, _______, _______, KC_PSCR,
                                                        _______, _______, _______,       _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  "   |  '   |   '    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  ~   |  [   |  (   |  {   |  =   |                              |   +  |  _   |  <   |  >   |  :   |   "    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |  `   |  ]   |  )   |  }   |  ?   |  {   |      |  |      |   }  |   -  |  |   |  ,   |  \   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_3(
      KC_GRV  , KC_EXLM , KC_AT  , KC_HASH , KC_DLR  , KC_PERC ,       KC_CIRC , KC_AMPR , KC_ASTR , KC_DQT   , KC_QUOTE , KC_QUOTE,
      KC_PIPE , KC_GRV  , KC_LBRC , KC_LPRN , KC_LCBR , KC_EQL  ,       KC_PLUS , KC_UNDS , KC_LABK , KC_RABK  , KC_COLN  , KC_DQT  ,
      KC_TILD , KC_TILD , KC_RBRC , KC_RPRN , KC_RCBR , KC_QUES ,       KC_MINUS, KC_PIPE , KC_COMM , KC_BSLS , KC_SLSH  , KC_QUES ,
                                  _______, _______, _______,          _______, _______, _______
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
     [_NUMS] = LAYOUT_split_3x6_3(
       _______, KC_ASTR , KC_7, KC_8, KC_9, KC_PLUS ,            _______, _______, _______, _______, _______, KC_BSPC,
       _______, KC_SLASH, KC_4, KC_5, KC_6, KC_MINUS,            _______, _______, _______, _______, _______, _______,
       _______, KC_0    , KC_1, KC_2, KC_3, KC_EQL  ,            _______, KC_BSPC,  KC_DEL, _______, _______, _______,
                                 KC_COMM, KC_DOT, KC_SPC,      _______, _______, _______
     ),
/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT_split_3x6_3(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,  KC_F11,              KC_F12, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,             _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,         RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,         _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,         _______, _______, _______
    ),
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


bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    if ( !process_achordion(keycode, record) ) { return false; }
    // Your macros ...
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

/**
 * Achordion control for resolving whether the key combinations pressed are tap hold.
 * Defaults to rejecting same-hand combinations
 */
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t * tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t * other_record)
{
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
char * get_rgb_mode(void) {
    if ( !rgb_matrix_is_enabled() ) {
        return "OFF";
    }

    switch ( rgb_matrix_get_mode() ) {
        case RGB_MATRIX_SOLID_COLOR:
            return "Solid Color";
        case RGB_MATRIX_ALPHAS_MODS:
            return "Alphas Mods";
        case RGB_MATRIX_GRADIENT_UP_DOWN:
            return "Grad Up Down";
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:
            return "Grad Left Right";
        case RGB_MATRIX_BREATHING:
            return "Breathing";
        case RGB_MATRIX_BAND_SAT:
            return "Band Sat";
        case RGB_MATRIX_BAND_VAL:
            return "Band Val";
        case RGB_MATRIX_BAND_PINWHEEL_SAT:
            return "Band Pinwheel Sat";
        case RGB_MATRIX_BAND_PINWHEEL_VAL:
            return "Band Pinwheel Val";
        case RGB_MATRIX_BAND_SPIRAL_SAT:
            return "Band Spiral Sat";
        case RGB_MATRIX_BAND_SPIRAL_VAL:
            return "Band Spiral Val";
        case RGB_MATRIX_CYCLE_ALL:
            return "Cycle All";
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:
            return "Cycle L-R";
        case RGB_MATRIX_CYCLE_UP_DOWN:
            return "Cycle U-D";
        case RGB_MATRIX_CYCLE_OUT_IN:
            return "Cycle O-I";
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:
            return "Cycle O-I Dual";
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:
            return "Rnbw Moving Chevron";
        case RGB_MATRIX_CYCLE_PINWHEEL:
            return "Cycle Pinwheel";
        case RGB_MATRIX_CYCLE_SPIRAL:
            return "Cycle Spiral";
        case RGB_MATRIX_DUAL_BEACON:
            return "Dual Beacon";
        case RGB_MATRIX_RAINBOW_BEACON:
            return "Rnbw Beacon";
        case RGB_MATRIX_RAINBOW_PINWHEELS:
            return "Rnbw Pinwheels";
        case RGB_MATRIX_RAINDROPS:
            return "Raindrops";
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:
            return "Jellybean Raindrops";
        case RGB_MATRIX_HUE_BREATHING:
            return "Hue Breathing";
        case RGB_MATRIX_HUE_PENDULUM:
            return "Hue Pendulum";
        case RGB_MATRIX_HUE_WAVE:
            return "Hue Wave";
        case RGB_MATRIX_PIXEL_FRACTAL:
            return "Pixel Fractal";
        case RGB_MATRIX_PIXEL_FLOW:
            return "Pixel Flow";
        case RGB_MATRIX_PIXEL_RAIN:
            return "Pixel Rain";
        case RGB_MATRIX_TYPING_HEATMAP:
            return "Typing Heatmap";
        case RGB_MATRIX_DIGITAL_RAIN:
            return "Digital Rain";
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:
            return "Solid React Simple";
        case RGB_MATRIX_SOLID_REACTIVE:
            return "Solid React";
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:
            return "Solid React Wide";
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:
            return "Solid React Multiwide";
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:
            return "Solid React Cross";
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:
            return "Solid React Multicross";
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:
            return "Solid React Nexus";
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:
            return "Solid React Multinexus";
        case RGB_MATRIX_SPLASH:
            return "Splash";
        case RGB_MATRIX_MULTISPLASH:
            return "Multisplash";
        case RGB_MATRIX_SOLID_SPLASH:
            return "Solid Splash";
        case RGB_MATRIX_SOLID_MULTISPLASH:
            return "Solid Multisplash";
        case RGB_MATRIX_EFFECT_MAX:
            return "Effect Max";
        default:
            return "None";
    }
}

const char * get_layer_name(int layer_idx) {
    switch (layer_idx) {
        case _QWERTY:
            return "Base";

        case _NAV:
            return "Navigate";

        case _SYM:
            return "Symbols";

        case _NUMS:
            return "Numpad";

        case _FUNCTION:
            return "Functions";

        case _ADJUST:
            return "Adjust";

        default:
            return "Unnamed";
    }
}

// Render left OLED
bool render_status_user(void) {
    // print wpm
    sprintf(wpm, "WPM: %03d\n", get_current_wpm());
    oled_write(wpm, false);

    char* indicators[3] = { "","","" };
    led_t led_state = host_keyboard_led_state();
    if ( led_state.num_lock ) {
        indicators[0] = "[N] ";
    }
    if (led_state.caps_lock ) {
        indicators[1] = "[C] ";
    }
    if ( led_state.scroll_lock ) {
        indicators[2] = "[S] ";
    }

    oled_write_P(PSTR("Layer: "), false);

    const int layer_idx = get_highest_layer(layer_state);
    const char* state = get_layer_name(layer_idx);
    oled_write_P(PSTR(state), false);
    oled_write_P(PSTR("\n"), false);

    uint8_t i;
    uint8_t offset = 0;
    uint8_t arr_len = (uint8_t) sizeof(indicators) / sizeof(indicators[0]);
    for (i = 0; i < arr_len; i++ ) {
        if ( strlen(indicators[i]) ) {
            offset = offset + strlen(indicators[i]);
        }
    }

    if ( offset > 0 ) {
        offset = oled_max_chars() - offset;
        oled_set_cursor(0, offset);
        for (i = 0; i < arr_len; i++) {
            if ( strlen(indicators[i]) ) {
                oled_write_P(PSTR(indicators[i]), false);
                if ( i != arr_len - 1 ) {
                    oled_write_P(PSTR(" "), false);
                }
            }
        }
        oled_write_P("\n", false);
    }
    /*
    const char* rgb_mode = get_rgb_mode();
    oled_write_P(PSTR("RGB: "), false);
    oled_write_P(PSTR(rgb_mode), false);
    oled_write_P(PSTR("\n"), false);
    */
    return false;
}

//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side
        render_status_user();
    } else {
        // Right side
        draw_bongo();
    }

	return 0;
}
