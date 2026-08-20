#include QMK_KEYBOARD_H
#include "keymap_german.h"

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
// QMK programs this layout in eight groups, in exactly this order:
//
//   Group 1: matrix row 0, left half, columns 6 -> 1
//   Group 2: matrix row 5, right half, columns 1 -> 6
//   Group 3: matrix row 1, left half, columns 6 -> 1
//   Group 4: matrix row 6, right half, columns 1 -> 6
//   Group 5: matrix row 2, left half, columns 6 -> 1
//   Group 6: matrix row 7, right half, columns 1 -> 6
//   Group 7: [3,6]...[3,1], [4,3], [3,0], [8,0], [9,3], [8,1]...[8,6]
//   Group 8: row 4 columns 4,2,1,5,0, then row 9 columns 0,5,1,2,4
//
// The comments inside each layer follow these QMK groups. They do not rename
// groups as rows, thumbs, or other product-level categories.
// -----------------------------------------------------------------------------

// Keep the physical layout visually aligned with the map above. The QMK
// LAYOUT macro follows the same left-to-right order for each physical row.
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Windows: German base layout.
    [LAYER_WIN_BASE] = LAYOUT(
        // First row: left six keys | right six keys
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,
        // Second row: left six keys | right six keys
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                            DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
        // Home row (third row): left six keys | right six keys
        KC_LSFT, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                            DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
        // Fourth row: left six regular keys
        KC_LCTL, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        // Fourth row: right six regular keys
        DE_N,    DE_M,    DE_COMM, DE_DOT, DE_MINS, KC_RCTL,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      KC_LGUI, KC_LALT, KC_BSPC, KC_SPC,  KC_ENT,  KC_ENT,  KC_SPC,  KC_BSPC, KC_RALT, KC_RGUI
    ),

    // Windows: navigation, editing, numpad, and media.
    [LAYER_WIN_NAVNUM] = LAYOUT(
        // First row: left six keys | right six keys
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        // Home row (third row): left six keys | right six keys
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS,  KC_4, KC_5, KC_6, KC_KP_DOT,   KC_KP_ASTERISK,
        // Fourth row: left six regular keys
        _______, _______, _______, _______, _______, _______,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        _______, _______, KC_0,    KC_7,
        // Fourth row: right six regular keys
        KC_8,    KC_9,    KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // Windows: symbols and shifted punctuation.
    [LAYER_WIN_SPEC] = LAYOUT(
        // First row: left six keys | right six keys
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        // Home row (third row): left six keys | right six keys
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        // Fourth row: left six regular keys
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_LCBR, _______, _______, KC_RCBR,
        // Fourth row: right six regular keys
        KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // macOS: German base layout.
    [LAYER_MAC_BASE] = LAYOUT(
        // First row: left six keys | right six keys
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,
        // Second row: left six keys | right six keys
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                            DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
        // Home row (third row): left six keys | right six keys
        KC_LSFT, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                            DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
        // Fourth row: left six regular keys
        KC_LCTL, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        // Fourth row: right six regular keys
        DE_N,    DE_M,    DE_COMM, DE_DOT, DE_MINS, KC_RCTL,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      KC_LCMD, KC_LOPT, KC_BSPC, KC_SPC,  KC_ENT,  KC_ENT,  KC_SPC,  KC_BSPC, KC_ROPT, KC_RCMD
    ),

    // macOS: navigation, editing, numpad, and media.
    [LAYER_MAC_NAVNUM] = LAYOUT(
        // First row: left six keys | right six keys
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        // Home row (third row): left six keys | right six keys
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS,  KC_4, KC_5, KC_6, KC_KP_DOT,   KC_KP_ASTERISK,
        // Fourth row: left six regular keys
        _______, _______, _______, _______, _______, _______,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        _______, _______, KC_0,    KC_7,
        // Fourth row: right six regular keys
        KC_8,    KC_9,    KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // macOS: symbols and shifted punctuation.
    [LAYER_MAC_SPEC] = LAYOUT(
        // First row: left six keys | right six keys
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        // Home row (third row): left six keys | right six keys
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        // Fourth row: left six regular keys
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_LCBR, _______, _______, KC_RCBR,
        // Fourth row: right six regular keys
        KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
