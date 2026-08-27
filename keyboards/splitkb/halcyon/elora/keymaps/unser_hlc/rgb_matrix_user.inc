#include "layers.h"
#include "rgb_layer_colors.h"

RGB_MATRIX_EFFECT(layer_colors)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool layer_colors(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t layer      = get_highest_layer(layer_state | default_layer_state);
    bool    is_mac     = layer >= LAYER_MAC_BASE;
    uint8_t brightness = rgb_matrix_get_val();

    for (uint8_t i = led_min; i < led_max; i++) {
        bool          is_top_row = rgb_layer_is_top_row(g_led_config.flags[i], g_led_config.point[i].y);
        layer_color_t color      = rgb_layer_color(is_mac, is_top_row, brightness);
        rgb_matrix_set_color(i, color.r, color.g, color.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif
