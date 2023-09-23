#include "enums.h"

const uint8_t encoder_mapping[][2][2] = {
    [_QWERTY] = {{ KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP} },
    [_NAV] = {{ KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP} },
    [_SYM] = {{ KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP} },
    [_FUNCTION] = {{ KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP} },
    [_ADJUST] = {{ KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP} },
};


bool activate_encoder(const uint8_t encoder_map[2][2], uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(encoder_map[0][0]);
        } else {
            tap_code(encoder_map[0][1]);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(encoder_map[1][0]);
        } else {
            tap_code(encoder_map[1][1]);
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

