#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_WIN_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_CAPS, TO_MAC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                      WIN_NAVNUM, WIN_SPEC, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_ENT
    ),

    [LAYER_WIN_NAVNUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS, KC_4, KC_5, KC_6, KC_KP_DOT, KC_KP_ASTERISK,
        _______, _______, _______, _______, _______, _______, _______, _______,       KC_0, KC_7, KC_8, KC_9, KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_WIN_SPEC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______,       _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_MAC_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_CAPS, TO_WIN, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                      MAC_NAVNUM, MAC_SPEC, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_ENT
    ),

    [LAYER_MAC_NAVNUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TAB,  KC_DEL,                         KC_KP_MINUS, KC_1, KC_2, KC_3, KC_KP_COMMA, KC_KP_SLASH,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LCTL, KC_LSFT,                         KC_KP_PLUS, KC_4, KC_5, KC_6, KC_KP_DOT, KC_KP_ASTERISK,
        _______, _______, _______, _______, _______, _______, _______, _______,       KC_0, KC_7, KC_8, KC_9, KC_KP_EQUAL, KC_MPRV, KC_MPLY, KC_MNXT,
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_MAC_SPEC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,                            KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______,       _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_QUES,
                                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
