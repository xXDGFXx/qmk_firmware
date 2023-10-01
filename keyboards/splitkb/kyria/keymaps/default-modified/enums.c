#ifndef KEYMAP_ENUMS
#define KEYMAP_ENUM

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

// Left-hand home row mods
#define HOME_S LSFT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RSFT_T(KC_L)


#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define CTL_COPY LCTL(KC_C)
#define CTL_PASTE LCTL(KC_V)
#define CTL_CUT LCTL(KC_X)
#define CTL_UNDO LCTL(KC_Z)
#define CTL_REDO LCTL(KC_Y)

#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#endif
