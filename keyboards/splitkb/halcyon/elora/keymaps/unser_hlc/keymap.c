#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "layers.h"
#include "encoder_behavior.h"

// -----------------------------------------------------------------------------
// Layers and aliases
// -----------------------------------------------------------------------------

#define WIN_NAVNUM MO(LAYER_WIN_NAVNUM)
#define WIN_SPEC   MO(LAYER_WIN_SPEC)
#define MAC_NAVNUM MO(LAYER_MAC_NAVNUM)
#define MAC_SPEC   MO(LAYER_MAC_SPEC)
#define TO_WIN     DF(LAYER_WIN_BASE)
#define TO_MAC     DF(LAYER_MAC_BASE)

enum custom_keycodes {
    RGB_DFLT = SAFE_RANGE,
};

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
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                            DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
        // Home row (third row): left six keys | right six keys
        KC_LSFT, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                            DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, KC_RSFT,
        // Fourth row: left six regular keys
        KC_LCTL, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2,
        // Fourth row: right six regular keys
        DE_N,    DE_M,    DE_COMM, DE_DOT, DE_MINS, KC_RCTL,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      KC_LALT, KC_LGUI, KC_BSPC, KC_SPC,  LT(LAYER_WIN_NAVNUM, KC_ENT),  TT(LAYER_WIN_NAVNUM),  TT(LAYER_WIN_SPEC),  KC_HYPR, KC_LGUI, KC_LALT
    ),

    // Windows: navigation, editing, numpad, and media.
    [LAYER_WIN_NAVNUM] = LAYOUT(
        // First row: left six keys | right six keys
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        // Second row: left six keys | right six keys
        KC_PSCR, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                         KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_KP_SLASH, KC_F12,
        // Home row (third row): left six keys | right six keys
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                         KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_ASTERISK, _______,
        // Fourth row: left six regular keys
        _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_APP,   KC_NUM,  _______, _______,
        // Fourth row: right six regular keys
        KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_KP_COMMA, _______,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, _______
    ),

    // Windows: symbols and shifted punctuation.
    [LAYER_WIN_SPEC] = LAYOUT(
        // First row: left six keys | right six keys
        TO_MAC,  _______, RGB_DFLT, RM_PREV, RM_NEXT, RM_TOGG,                        _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        _______, DE_CIRC, DE_DEG,  DE_LABK, DE_RABK, DE_PIPE,                         DE_TILD, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR, DE_ASTR,
        // Home row (third row): left six keys | right six keys
        _______, DE_EXLM, DE_AT,   DE_DQUO, DE_PERC, DE_AMPR,                         DE_QUOT, DE_LPRN, DE_RPRN, DE_EQL,  DE_QUES, DE_ADIA,
        // Fourth row: left six regular keys
        _______, XXXXXXX, XXXXXXX, LCTL(KC_INS), LSFT(KC_INS), KC_INS,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        _______, _______, _______, _______,
        // Fourth row: right six regular keys
        DE_ACUT, DE_SLSH, DE_BSLS, DE_HASH, XXXXXXX, _______,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // macOS: German base layout.
    [LAYER_MAC_BASE] = LAYOUT(
        // First row: left six keys | right six keys
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_SS,
        // Second row: left six keys | right six keys
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                            DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
        // Home row (third row): left six keys | right six keys
        KC_LSFT, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                            DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, KC_RSFT,
        // Fourth row: left six regular keys
        KC_LCTL, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2,
        // Fourth row: right six regular keys
        DE_N,    DE_M,    DE_COMM, DE_DOT, DE_MINS, KC_RCTL,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                       KC_LOPT, KC_LCMD, KC_BSPC, KC_SPC,  LT(LAYER_MAC_NAVNUM, KC_ENT),  TT(LAYER_MAC_NAVNUM),  TT(LAYER_MAC_SPEC),  KC_HYPR, KC_LCMD, KC_LOPT
    ),

    // macOS: navigation, editing, numpad, and media.
    [LAYER_MAC_NAVNUM] = LAYOUT(
        // First row: left six keys | right six keys
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        // Second row: left six keys | right six keys
        SGUI(KC_4), XXXXXXX, LGUI(KC_LEFT), KC_UP,   LGUI(KC_RGHT), KC_PGUP,          KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_KP_SLASH, KC_F12,
        // Home row (third row): left six keys | right six keys
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                         KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_ASTERISK, _______,
        // Fourth row: left six regular keys
        _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        KC_BTN2, KC_NUM,  _______, _______,
        // Fourth row: right six regular keys
        KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_KP_COMMA, _______,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, _______
    ),

    // macOS: symbols and shifted punctuation.
    //      macOS swaps the ISO KC_GRV and KC_NUBS positions for this keyboard.
    //      Reverse the German aliases here so the resulting characters remain ^ ° < >.
    [LAYER_MAC_SPEC] = LAYOUT(
        // First row: left six keys | right six keys
        TO_WIN,  _______, RGB_DFLT, RM_PREV, RM_NEXT, RM_TOGG,                        _______, _______, _______, _______, _______, _______,
        // Second row: left six keys | right six keys
        _______, DE_LABK, DE_RABK,  DE_CIRC, DE_DEG, LALT(KC_7),                      LALT(DE_N), LALT(KC_5), LALT(KC_6), LALT(KC_8), LALT(KC_9), DE_ASTR,
        // Home row (third row): left six keys | right six keys
        _______, DE_EXLM, LALT(DE_L), DE_DQUO, DE_PERC, DE_AMPR,                      DE_QUOT, DE_LPRN, DE_RPRN, DE_EQL,  DE_QUES, DE_ADIA,
        // Fourth row: left six regular keys
        _______, XXXXXXX, XXXXXXX, LGUI(DE_C), LGUI(DE_V), XXXXXXX,
        // Fourth row: left two upper-thumb keys | right two upper-thumb keys
        _______, _______, _______, _______,
        // Fourth row: right six regular keys
        DE_ACUT, DE_SLSH, LSA(KC_7), DE_HASH, XXXXXXX, _______,
        // Fifth row: left five lower-thumb keys | right five lower-thumb keys
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

// -----------------------------------------------------------------------------
// RGB matrix behaviour
// -----------------------------------------------------------------------------

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_layer_colors);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == RGB_DFLT) {
        if (record->event.pressed) {
            rgb_matrix_enable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_layer_colors);
        }
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// Encoder behaviour
// -----------------------------------------------------------------------------

bool encoder_update_user(uint8_t index, bool clockwise) {
    // The Halcyon encoder is exposed as encoder index 1 on Elora.
    if (index != 1) {
        return false;
    }

    uint8_t  mods    = get_mods() | get_oneshot_mods();
    uint8_t  layer   = get_highest_layer(layer_state | default_layer_state);
    uint16_t keycode = encoder_keycode_for_layer(layer, clockwise, mods & MOD_MASK_SHIFT);

    if (keycode != KC_NO) {
        tap_code(keycode);
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
