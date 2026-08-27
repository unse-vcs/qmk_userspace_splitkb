#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if __has_include("../rgb_layer_colors.h")
#    include "../rgb_layer_colors.h"
#else
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} layer_color_t;

static bool rgb_layer_is_top_row(uint8_t flags, uint8_t y) {
    (void)flags;
    (void)y;
    return false;
}

static layer_color_t rgb_layer_color(bool is_mac_layer, bool is_top_row, uint8_t brightness) {
    (void)is_mac_layer;
    (void)is_top_row;
    (void)brightness;
    return (layer_color_t){0, 0, 0};
}
#endif

static int failures;

static void expect_true(const char *name, bool condition) {
    if (!condition) {
        fprintf(stderr, "FAIL: %s\n", name);
        failures++;
    }
}

static void expect_color(const char *name, layer_color_t actual, uint8_t r, uint8_t g, uint8_t b) {
    if (actual.r != r || actual.g != g || actual.b != b) {
        fprintf(stderr, "FAIL: %s: got #%02X%02X%02X, want #%02X%02X%02X\n", name, actual.r, actual.g, actual.b, r, g, b);
        failures++;
    }
}

int main(void) {
    expect_true("top-row keylight is detected", rgb_layer_is_top_row(0x04, 9));
    expect_true("underglow at the same height is excluded", !rgb_layer_is_top_row(0x02, 2));
    expect_true("lower keylight is excluded", !rgb_layer_is_top_row(0x04, 10));

    expect_color("Windows top row is strong blue", rgb_layer_color(false, true, 255), 0x00, 0x00, 0xFF);
    expect_color("macOS top row is strong green", rgb_layer_color(true, true, 255), 0x00, 0xFF, 0x00);
    expect_color("other LEDs are white", rgb_layer_color(false, false, 255), 0xFF, 0xFF, 0xFF);
    expect_color("brightness scales the palette", rgb_layer_color(false, true, 128), 0x00, 0x00, 0x80);

    if (failures != 0) {
        fprintf(stderr, "%d RGB layer-color test(s) failed\n", failures);
        return 1;
    }

    puts("PASS: RGB layer colors and top-row selection");
    return 0;
}
