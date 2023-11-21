/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _GAMING
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,--------------------------------------------.                     ,----------------------------------------------.
 * |         |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |   0  |           |
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |  \        |
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * | GUI/ESC |   A  |   S  |   D  |   F  |   G  |--------.   ,--------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|  Play  |   |  Mute  |------+------+------+------+------+-----------|
 * |  LSFT   |   Z  |   X  |   C  |   V  |   B  |--------|   |--------|   N  |   M  |   ,  |   .  |   /  |  RSFT     |
 * `--------------------------------------------|        /   \        |----------------------------------------------'
 *                 |       |DELETE| LCTRL| LOWER|  BSP  /     \ Space | RAISE| RCTRL| ENTER| RALT |
 *                 `-----------------------------------'       '----------------------------------'
 */

 [_BASE] = LAYOUT(
           XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
            KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
    LGUI_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
           KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY, KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                             XXXXXXX,  KC_DEL, KC_LCTL,   LOWER, KC_BSPC,  KC_SPC,   RAISE,  KC_RCTL, KC_ENT, KC_RALT
),
/* LOWER
 * ,--------------------------------------------.                     ,----------------------------------------------.
 * |         |      |      |      |      |      |                     |      |      |      |      |      |           |
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * |         |   ^  |   &  |   *  |   -  |   +  |                     |      |   7  |   8  |   9  |   (  |  )        |
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * | GUI/ESC |   !  |   @  |   #  |   $  |   %  |--------.   ,--------|      |   4  |   5  |   6  |   {  |  }        |
 * |---------+------+------+------+------+------|  Play  |   |  Mute  |------+------+------+------+------+-----------|
 * |  LSFT   |      |   ~  |   `  |   _  |   =  |--------|   |--------|   0  |   1  |   2  |   3  |   [  |  ]        |
 * `--------------------------------------------|        /   \        |----------------------------------------------'
 *                 |       |DELETE| LCTRL| LOWER|  BSP  /     \ Space | RAISE| RCTRL| ENTER| RALT |
 *                 `-----------------------------------'       '----------------------------------'
 */

[_LOWER] = LAYOUT(
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_TAB, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,                   XXXXXXX,    KC_7,    KC_8,    KC_9, KC_LPRN, KC_RPRN,
    LGUI_T(KC_ESC), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   XXXXXXX,    KC_4,    KC_5,    KC_6, KC_LCBR, KC_RCBR,
           KC_LSFT, XXXXXXX, KC_TILD,  KC_GRV, KC_UNDS,  KC_EQL, _______, _______,    KC_0,    KC_1,    KC_2,    KC_3, KC_LBRC, KC_RBRC,
                             _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______
),
/* RAISE
 * ,--------------------------------------------.                     ,----------------------------------------------.
 * |         |      |      |      |      |      |                     |      |      |      |      |      | GAME_LAYER|
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * |         |      |  F7  |  F8  |  F9  |  F10 |                     |      | HOME | PSCR | PGUP |      |           |
 * |---------+------+------+------+------+------|                     |------+------+------+------+------+-----------|
 * | GUI/ESC |      |  F4  |  F5  |  F6  |  F11 |--------.   ,--------| LEFT | DOWN |  UP  |RIGHT |      |           |
 * |---------+------+------+------+------+------|  Play  |   |  Mute  |------+------+------+------+------+-----------|
 * |  LSFT   |      |  F1  |  F2  |  F3  |  F12 |--------|   |--------|      |  END |      | PGDN |      |  RSFT     |
 * `--------------------------------------------|        /   \        |----------------------------------------------'
 *                 |       |DELETE| LCTRL| LOWER|  BSP  /     \ Space | RAISE| RCTRL| ENTER| RALT |
 *                 `-----------------------------------'       '----------------------------------'
 */

[_RAISE] = LAYOUT(
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_GAMING),
            KC_TAB, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                   XXXXXXX, KC_HOME, KC_PSCR, KC_PGUP, XXXXXXX, XXXXXXX,
    LGUI_T(KC_ESC), XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
           KC_LSFT, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, _______, _______, XXXXXXX,  KC_END, XXXXXXX, KC_PGDN, XXXXXXX, KC_RSFT,
                             _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______
),
/* GAMING
 * ,-----------------------------------------.                    ,----------------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | BASE_LAYER|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  T   | TAB  |  Q   |  W   |  E   |  R   |                    |  Y   |  U   |  UP  |  O   |  P   |           |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  I   | LSFT |  A   |  S   |  D   |  F   |-------.    ,-------|  G   | LEFT | DOWN | RIGHT|      |           |
 * |------+------+------+------+------+------|  Play |    |  Mute |------+------+------+------+------+-----------|
 * |  M   | LCTRL|  Z   |  X   |  C   |  V   |-------|    |-------|  H   |  J   |  K   |  L   |  N   |           |
 * `-----------------------------------------/       /     \      \----------------------------------------------'
 *               |     |       |      |Space|   B   /       \      \  |      |      |     |      |
 *               `----------------------------------'       '------------------------------------'
 */

[_GAMING] = LAYOUT(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF(_BASE),
       KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,   KC_UP,    KC_O,    KC_P, XXXXXXX,
       KC_I, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      KC_G, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
       KC_M, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V, KC_MPLY, KC_MUTE,    KC_H,    KC_J,    KC_K,    KC_L,    KC_N, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("Kimiko"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
    return false;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_RAISE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAMING] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif // ENCODER_MAP_ENABLE
