#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "../layers.h"

#define KC_NO                       0x00
#define KC_VOLU                     0x80
#define KC_VOLD                     0x81
#define QK_MOUSE_WHEEL_UP           0xD9
#define QK_MOUSE_WHEEL_DOWN         0xDA
#define QK_MOUSE_WHEEL_LEFT         0xDB
#define QK_MOUSE_WHEEL_RIGHT        0xDC

#if __has_include("../encoder_behavior.h")
#    include "../encoder_behavior.h"
#else
static uint16_t encoder_keycode_for_layer(uint8_t layer, bool clockwise, bool shifted) {
    (void)layer;
    (void)clockwise;
    (void)shifted;
    return KC_NO;
}
#endif

static int failures;

static void expect_keycode(const char *name, uint16_t actual, uint16_t expected) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: got 0x%04X, want 0x%04X\n", name, actual, expected);
        failures++;
    }
}

int main(void) {
    expect_keycode("Windows base scrolls down clockwise", encoder_keycode_for_layer(LAYER_WIN_BASE, true, false), QK_MOUSE_WHEEL_DOWN);
    expect_keycode("macOS base scrolls down clockwise", encoder_keycode_for_layer(LAYER_MAC_BASE, true, false), QK_MOUSE_WHEEL_DOWN);
    expect_keycode("macOS base scrolls horizontally with Shift", encoder_keycode_for_layer(LAYER_MAC_BASE, false, true), QK_MOUSE_WHEEL_LEFT);
    expect_keycode("macOS NAV controls volume", encoder_keycode_for_layer(LAYER_MAC_NAVNUM, true, false), KC_VOLU);
    expect_keycode("macOS SPEC scrolls up counterclockwise", encoder_keycode_for_layer(LAYER_MAC_SPEC, false, false), QK_MOUSE_WHEEL_UP);

    if (failures != 0) {
        fprintf(stderr, "%d encoder behavior test(s) failed\n", failures);
        return 1;
    }

    puts("PASS: Windows and macOS encoder behavior");
    return 0;
}
