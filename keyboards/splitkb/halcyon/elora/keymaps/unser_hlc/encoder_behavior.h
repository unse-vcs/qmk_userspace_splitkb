#pragma once

#include <stdbool.h>
#include <stdint.h>

static uint16_t encoder_keycode_for_layer(uint8_t layer, bool clockwise, bool shifted) {
    switch (layer) {
        case LAYER_WIN_BASE:
        case LAYER_MAC_BASE:
        case LAYER_WIN_SPEC:
        case LAYER_MAC_SPEC:
            if (shifted) {
                return clockwise ? QK_MOUSE_WHEEL_RIGHT : QK_MOUSE_WHEEL_LEFT;
            }
            return clockwise ? QK_MOUSE_WHEEL_DOWN : QK_MOUSE_WHEEL_UP;

        case LAYER_WIN_NAVNUM:
        case LAYER_MAC_NAVNUM:
            return clockwise ? KC_VOLU : KC_VOLD;
    }

    return KC_NO;
}
