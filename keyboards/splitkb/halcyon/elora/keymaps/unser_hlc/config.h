// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID {0x91, 0xC0, 0x72, 0xB1, 0xEA, 0x3F, 0xF0, 0xBA}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 1 }

// Increase the EEPROM size for layout options
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define CAPS_WORD_IDLE_TIMEOUT 3000
#define CIRQUE_PINNACLE_TAPPING_TERM 120

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
