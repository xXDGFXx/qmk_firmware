#include "enums.h"

#define DEFAULT_ENCODER_BEHAVIOR { { KC_VOLU, KC_VOLD }, { KC_PGDN, KC_PGUP } }

const uint16_t encoder_mapping[][2][2] = {
    [_QWERTY] = DEFAULT_ENCODER_BEHAVIOR,
    [_NAV] = {
        {
            LCA(KC_RIGHT), LCA(KC_LEFT)
        },
        {
            LCTL(KC_PLUS), LCTL(KC_MINUS)
        }
    },
    [_SYM] = DEFAULT_ENCODER_BEHAVIOR,
    [_FUNCTION] = DEFAULT_ENCODER_BEHAVIOR,
    [_ADJUST] = DEFAULT_ENCODER_BEHAVIOR,
};

bool activate_encoder_layer(const uint16_t encoder_map[2][2], uint8_t index, bool clockwise) {
    const uint16_t * encoder_side = encoder_map[index];
    const uint16_t encoder_key = clockwise ? encoder_side[0] : encoder_side[1];

    const uint16_t has_mod = (
        (encoder_key & MOD_MASK_CTRL)
        || (encoder_key & MOD_MASK_SHIFT)
        || (encoder_key & MOD_MASK_ALT)
        || (encoder_key & MOD_MASK_GUI)
    );

    if ( has_mod ) {
        tap_code16(encoder_key);
    }
    else {
        tap_code((uint8_t) encoder_key);
    }

    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    layer_state_t current_layer = get_highest_layer(layer_state | default_layer_state);
    switch (current_layer) {
        case _NAV:
            /**
            return activate_encoder_layer((uint16_t[2][2]) {
                {
                    LCA(KC_RIGHT), LCA(KC_LEFT)
                },
                {
                    LCTL(KC_PLUS), LCTL(KC_MINUS)
                }
            }, index, clockwise);
            */
        case _SYM:
        case _FUNCTION:
        case _ADJUST:
        case _QWERTY:
            return activate_encoder_layer(encoder_mapping[current_layer], index, clockwise);

        default:
            return true;
    }
}

