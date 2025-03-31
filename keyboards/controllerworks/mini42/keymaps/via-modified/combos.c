const uint16_t PROGMEM capsword_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM capsword_combo_v2[] = {KC_U, HOME_K, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM osl_fnc_combo[] = {NAV_TAB, SYM_BSPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsword_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(capslock_combo, KC_CAPS),
    COMBO(capsword_combo_v2, QK_CAPS_WORD_TOGGLE),
    COMBO(osl_fnc_combo, OSL(_FUNCTION))
};

