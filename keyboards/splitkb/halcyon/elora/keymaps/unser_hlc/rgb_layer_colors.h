#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "layers.h"

#ifndef LED_FLAG_KEYLIGHT
#    define LED_FLAG_KEYLIGHT 0x04
#endif

#define RGB_LAYER_THUMB_COLORS

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} layer_color_t;

static inline bool rgb_layer_is_top_row(uint8_t flags, uint8_t y) {
    return (flags & LED_FLAG_KEYLIGHT) != 0 && y <= 9;
}

static inline bool rgb_layer_is_thumb(uint8_t flags, uint8_t y) {
    return (flags & LED_FLAG_KEYLIGHT) != 0 && y >= 49;
}

static inline uint8_t rgb_layer_scale_component(uint8_t component, uint8_t brightness) {
    return ((uint16_t)component * brightness) / 255;
}

static inline layer_color_t rgb_layer_color_for_led(uint8_t layer, bool is_top_row, bool is_thumb, uint8_t brightness) {
    uint8_t r = 0xFF;
    uint8_t g = 0xFF;
    uint8_t b = 0xFF;

    if (is_thumb && (layer == LAYER_WIN_NAVNUM || layer == LAYER_MAC_NAVNUM)) {
        r = 0x80;
        g = 0x00;
        b = 0xFF;
    } else if (is_thumb && (layer == LAYER_WIN_SPEC || layer == LAYER_MAC_SPEC)) {
        r = 0xFF;
        g = 0xD0;
        b = 0x00;
    } else if (is_top_row) {
        bool is_mac_layer = layer >= LAYER_MAC_BASE;

        r = 0x00;
        g = is_mac_layer ? 0xFF : 0x00;
        b = is_mac_layer ? 0x00 : 0xFF;
    }

    return (layer_color_t){
        rgb_layer_scale_component(r, brightness),
        rgb_layer_scale_component(g, brightness),
        rgb_layer_scale_component(b, brightness),
    };
}
