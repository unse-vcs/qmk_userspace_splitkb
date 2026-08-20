#include QMK_KEYBOARD_H

// -----------------------------------------------------------------------------
// Layers and aliases
// -----------------------------------------------------------------------------

enum layer_names {
    LAYER_WIN_BASE,
    LAYER_WIN_NAVNUM,
    LAYER_WIN_SPEC,
    LAYER_MAC_BASE,
    LAYER_MAC_NAVNUM,
    LAYER_MAC_SPEC,
};

#define WIN_NAVNUM MO(LAYER_WIN_NAVNUM)
#define WIN_SPEC   MO(LAYER_WIN_SPEC)
#define MAC_NAVNUM MO(LAYER_MAC_NAVNUM)
#define MAC_SPEC   MO(LAYER_MAC_SPEC)
#define TO_WIN     DF(LAYER_WIN_BASE)
#define TO_MAC     DF(LAYER_MAC_BASE)

// -----------------------------------------------------------------------------
// Physical Elora map
//
// The five physical rows are, from top to bottom:
//   number row, QWERTY row, home row, lower/inner row, thumb row.
//
// The lower/inner row contains eight regular keys per half. L19/R19 are the
// center-most regular keys; L27/R27 are the center-most thumb keys.
//
// NUMBER ROW
// L06 L05 L04 L03 L02 L01       R01 R02 R03 R04 R05 R06
//
// QWERTY ROW
// L12 L11 L10 L09 L08 L07       R07 R08 R09 R10 R11 R12
//
// HOME ROW
// L18 L17 L16 L15 L14 L13       R13 R14 R15 R16 R17 R18
//
// LOWER / INNER ROW (regular keys, not thumbs)
// L26 L25 L24 L23 L22 L21 L20 L19 R19 R20 R21 R22 R23 R24 R26 R27
//
// THUMB ROW (five keys per half)
//                 L31 L30 L29 L28 L27 R27 R28 R29 R30 R31
// -----------------------------------------------------------------------------

// Keep the physical layout visually aligned with the map above. The QMK
// LAYOUT macro follows the same left-to-right order for each physical row.
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Windows: normal typing and OS switching.
    [LAYER_WIN_BASE] = LAYOUT(
        // number row
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
        // QWERTY row
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // home row
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        // lower / inner row: eight regular keys per half
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, QK_CAPS_WORD_TOGGLE, TO_MAC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // thumb row: five keys per half
                                      WIN_NAVNUM, WIN_SPEC, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_APP,  KC_ENT
    ),

    // Windows: navigation, editing, numpad, and media.
    [LAYER_WIN_NAVNUM] = LAYOUT(
        // number row
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // QWERTY row
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        // home row
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS,  KC_4, KC_5, KC_6, KC_KP_DOT,   KC_KP_ASTERISK,
        // lower / inner row
        _______, _______, _______, _______, _______, _______, _______, _______,       KC_0, KC_7, KC_8, KC_9, KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
        // thumb row
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

    // Windows: symbols and shifted punctuation.
    [LAYER_WIN_SPEC] = LAYOUT(
        // number row
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // QWERTY row
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        // home row
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        // lower / inner row
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______,       _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
        // thumb row
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

    // macOS: normal typing and OS switching.
    [LAYER_MAC_BASE] = LAYOUT(
        // number row
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
        // QWERTY row
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // home row
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        // lower / inner row
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, QK_CAPS_WORD_TOGGLE, TO_WIN, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // thumb row
                                      MAC_NAVNUM, MAC_SPEC, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_APP,  KC_ENT
    ),

    // macOS: navigation, editing, numpad, and media.
    [LAYER_MAC_NAVNUM] = LAYOUT(
        // number row
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // QWERTY row
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        // home row
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS,  KC_4, KC_5, KC_6, KC_KP_DOT,   KC_KP_ASTERISK,
        // lower / inner row
        _______, _______, _______, _______, _______, _______, _______, _______,       KC_0, KC_7, KC_8, KC_9, KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
        // thumb row
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

    // macOS: symbols and shifted punctuation.
    [LAYER_MAC_SPEC] = LAYOUT(
        // number row
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // QWERTY row
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        // home row
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        // lower / inner row
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______,       _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
        // thumb row
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),
};
// clang-format on

// -----------------------------------------------------------------------------
// Encoder behaviour
// -----------------------------------------------------------------------------

bool encoder_update_user(uint8_t index, bool clockwise) {
    // The Halcyon encoder is exposed as encoder index 1 on Elora.
    if (index != 1) {
        return false;
    }

    uint8_t mods = get_mods() | get_oneshot_mods();
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case LAYER_WIN_BASE:
        case LAYER_MAC_BASE:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;

        case LAYER_WIN_NAVNUM:
        case LAYER_WIN_SPEC:
        case LAYER_MAC_NAVNUM:
        case LAYER_MAC_SPEC:
            if (mods & MOD_MASK_SHIFT) {
                tap_code(clockwise ? KC_WH_R : KC_WH_L);
            } else {
                tap_code(clockwise ? KC_WH_D : KC_WH_U);
            }
            break;
    }

    return false;
}

// -----------------------------------------------------------------------------
// Key overrides
// -----------------------------------------------------------------------------

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_key_override = ko_make_with_layers_negmods_and_options(
    MOD_MASK_SHIFT,
    KC_BSPC,
    KC_DEL,
    ~0,
    MOD_MASK_GUI,
    ko_option_no_reregister_trigger
);

const key_override_t delete_word_key_override = ko_make_with_layers_negmods_and_options(
    MOD_MASK_SHIFT | MOD_MASK_ALT,
    KC_BSPC,
    KC_DEL,
    ~0,
    MOD_MASK_GUI,
    ko_option_no_reregister_trigger
);

const key_override_t *key_overrides[] = {
    &delete_key_override,
    &delete_word_key_override,
    NULL,
};
#endif
