#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifndef LED_FLAG_KEYLIGHT
#    define LED_FLAG_KEYLIGHT 0x04
#endif

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} layer_color_t;

static inline bool rgb_layer_is_top_row(uint8_t flags, uint8_t y) {
    return (flags & LED_FLAG_KEYLIGHT) != 0 && y <= 9;
}

static inline uint8_t rgb_layer_scale_component(uint8_t component, uint8_t brightness) {
    return ((uint16_t)component * brightness) / 255;
}

static inline layer_color_t rgb_layer_color(bool is_mac_layer, bool is_top_row, uint8_t brightness) {
    uint8_t r = 0xFF;
    uint8_t g = 0xFF;
    uint8_t b = 0xFF;

    if (is_top_row) {
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
