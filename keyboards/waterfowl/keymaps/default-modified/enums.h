#ifndef KEYMAP_ENUMS
#define KEYMAP_ENUMS

// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define NUMS     MO(_NUMS)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_S)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LALT_T(KC_F)

#define SYM_LSFT LSFT_T(KC_LBRC)
#define SYM_LCTL LCTL_T(KC_LPRN)
#define SYM_LALT LALT_T(KC_LCBR)

// Right-hand home row mods
#define HOME_J    LALT_T(KC_J)
#define HOME_K    RCTL_T(KC_K)
#define HOME_L    RSFT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define SYM_RSFT RSFT_T(KC_UNDS)
#define SYM_RCTL RCTL_T(KC_LABK)
#define SYM_RALT LALT_T(KC_RABK)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define CTL_COPY LCTL(KC_C)
#define CTL_PASTE LCTL(KC_V)
#define CTL_CUT LCTL(KC_X)
#define CTL_UNDO LCTL(KC_Z)
#define CTL_REDO LCTL(KC_Y)

// Thumb-keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#define LSFT_SPC LSFT_T(KC_SPC)
#define NUM_ENT LT(_NUMS, KC_ENT)
#define MED_ESC LT(_MEDIA, KC_ESC)

#define SFT_PSCR LSFT(KC_PSCR)
#define ALT_PSCR LALT(KC_PSCR)

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _NUMS,
    _MEDIA,
};


#endif
