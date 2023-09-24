#include "enums.h"

const uint16_t encoder_mapping[][2][3] = {
    [_QWERTY] = {{ KC_VOLU, KC_VOLD, 0 }, { KC_PGDN, KC_PGUP, 0} },
    [_NAV] = {{ LCA(KC_RIGHT), LCA(KC_LEFT), 1 }, { LCTL(KC_PLUS), LCTL(KC_MINUS),1} },
    [_SYM] = {{ KC_VOLU, KC_VOLD,0 }, { KC_PGDN, KC_PGUP, 0} },
    [_FUNCTION] = {{ KC_VOLU, KC_VOLD,0 }, { KC_PGDN, KC_PGUP,0} },
    [_ADJUST] = {{ KC_VOLU, KC_VOLD,0 }, { KC_PGDN, KC_PGUP,0} },
};


bool activate_encoder(const uint16_t encoder_map[2][3], uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (encoder_map[0][2] ) {
                tap_code16(encoder_map[0][0]);
            }
            else {
                tap_code((uint8_t) encoder_map[0][0]);
            }
        } else {
            if (encoder_map[0][2] ) {
                tap_code16(encoder_map[0][1]);
            }
            else {
                tap_code((uint8_t) encoder_map[0][1]);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            if (encoder_map[1][2] ) {
                tap_code16(encoder_map[1][0]);
            }
            else {
                tap_code((uint8_t) encoder_map[1][0]);
            }
        } else {
            if (encoder_map[1][2] ) {
                tap_code16(encoder_map[1][1]);
            }
            else {
                tap_code((uint8_t) encoder_map[1][1]);
            }
        }
    }

    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    layer_state_t current_layer = get_highest_layer(layer_state | default_layer_state);
    switch (current_layer) {
        case _NAV:
        case _SYM:
        case _FUNCTION:
        case _ADJUST:
        case _QWERTY:
            return activate_encoder(encoder_mapping[current_layer], index, clockwise);
        default:
            return true;
    }
}

