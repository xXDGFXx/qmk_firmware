enum {
    TD_GUI_ESC = 0
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_ESC)
};

