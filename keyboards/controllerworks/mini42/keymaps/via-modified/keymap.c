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
#include "bongo.h"
// #include "features/achordion.h"


char wpm[42];


enum {
    BASE,
    SYMBOLS,
    NAVIGATE,
    FUNCTIONS,
} layer_enum;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_SPC,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,                      XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_PGDN,                      KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ESC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_ESC,     KC_DEL, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_NUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

const char* states[8] = {
    "Base",
    "Symbols",
    "Navigate",
    "Functions",
    "Adjust",
    "Alternate",
    // "Layer 6",
    // "Layer 7"
};


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

// Render left OLED
bool render_status_user(void) {
    // print wpm
    sprintf(wpm, "WPM: %03d\n", get_current_wpm());
    oled_write(wpm, false);

    oled_write_P(PSTR("Layer: "), false);
    const int layer_idx = get_highest_layer(layer_state);
    const char* state = states[layer_idx];
    oled_write_P(PSTR(state), false);
    oled_write_P(PSTR("\n"), false);

    led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    // TODO: Move this onto the WPM Line
    oled_write_P(led_state.num_lock ? PSTR("[N] ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("[C] ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("[S] ") : PSTR("    "), false);
    oled_write_P(PSTR("\n"), false);

    const char* rgb_mode = get_rgb_mode();
    const uint8_t offset = oled_max_chars() - strlen(rgb_mode);
    oled_set_cursor(offset, 0);
    oled_write_P(PSTR(rgb_mode), false);
    return false;
}


/*
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    // your macros
    return true;
}


void matrix_scan_user(void) {
    achordion_task();
}
*/

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
