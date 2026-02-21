/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Thomas Bowman Mørch (tbowmo)
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
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  LAYER 0 — Base (macOS + Home Row Mods)
 *  ┌──────────────────────────────────────────────────────────────────────┐ ┌──────────────┐
 *  │ ESC │   │ F1│ F2│ F3│ F4│   │ F5│ F6│ F7│ F8│   │ F9│F10│F11│F12│  │ │⌘⇧4 │Spot│RGB │
 *  ├──────────────────────────────────────────────────────────────────────┤ ├──────────────┤
 *  │  `  │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │  BKSP   │  │ INS │HOME│PgU │
 *  ├──────────────────────────────────────────────────────────────────────┤ ├──────────────┤
 *  │Tab/L1 │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │   \    │  │ DEL │END │PgD │
 *  ├──────────────────────────────────────────────────────────────────────┤ └──────────────┘
 *  │Esc/Hypr │⌘A│⌥S│⌃D│⇧F│ G │ H │⇧J│⌃K│⌥L│⌘; │ ' │    RETURN     │
 *  ├──────────────────────────────────────────────────────────────────────┤      ┌────┐
 *  │  LSHIFT   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   RSHIFT    │      │ UP │
 *  ├──────────────────────────────────────────────────────────────────────┤ ┌────┼────┼────┐
 *  │LCTL│LOPT│LCMD│           SPACE            │MO(1)│RCMD│ROPT│RCTL│  │ │ ←  │ ↓  │ →  │
 *  └──────────────────────────────────────────────────────────────────────┘ └────┴────┴────┘
 *
 *  Home Row Mods (hold = modifier, tap = letter):
 *    A=⌘  S=⌥  D=⌃  F=⇧  |  J=⇧  K=⌃  L=⌥  ;=⌘
 *
 *  CapsLock → Esc (tap) / Hyper ⌃⌥⇧⌘ (hold)  — perfect for Hammerspoon
 *  Tab      → Tab (tap) / Layer 1 (hold)       — instant access to nav layer
 */
    [LAYER0] = LAYOUT_tkl_ansi(
        KC_ESC,              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,      KC_MSNP,  KC_SIRI,  RGB_MOD,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,     KC_INS,   KC_HOME,  KC_PGUP,
        LY1_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,     KC_DEL,   KC_END,   KC_PGDN,
        HYPR_E,     HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,    KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SC,  KC_QUOT,            KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                          KC_UP,
        KC_LCTL,    KC_LALT, KC_LGUI,                   KC_SPC,                                   MO(LAYER1), KC_RGUI, KC_RALT,   KC_RCTL,     KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

/*  LAYER 1 — Navigation (Vim) + Media + Bluetooth
 *
 *  Right-hand Vim navigation — three tiers:
 *   ┌──────┬──────┬──────┬──────┐
 *   │ Home │ PgDn │ PgUp │ End  │  Y U I O  — Document / Page
 *   ├──────┼──────┼──────┼──────┤
 *   │  ←   │  ↓   │  ↑   │  →   │  H J K L  — Character (HJKL)
 *   ├──────┼──────┼──────┼──────┤
 *   │ W←   │ W⌫   │ W⌦   │ W→   │  N M , .  — Word level
 *   └──────┴──────┴──────┴──────┘
 *
 *  Left-hand transparent = home row mods still active!
 *    hold Tab + hold A(⌘) + L(→) = ⌘→ (end of line)
 *    hold Tab + hold F(⇧) + J(↓) = ⇧↓ (select line down)
 *    hold Tab + hold A(⌘) + F(⇧) + L(→) = ⌘⇧→ (select to end of line)
 *
 *  Tab management: W=prev  E=close  R=next  T=new
 */
    [LAYER1] = LAYOUT_tkl_ansi(
        QK_BOOT,          KC_BRID, KC_BRIU, KC_MSSN, KC_FIND, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,      KC_VOLU,     _______,  KC_WAKE,  RGB_TOG,
        KC_BTPR, KC_BTP0, KC_BTP1, KC_BTP2, KC_BTRT, _______, _______, _______, _______, _______, _______, _______, TG(LAYER3),   KC_DEL,      _______,  RGB_SPI,  RGB_HUI,
        _______, KC_TABL, KC_CMDW, KC_TABR, _______, KC_CMDT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,      _______,     _______,  RGB_SPD,  RGB_HUD,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,               _______,
        _______, _______, _______, _______, _______, KC_BTBT, KC_WLFT, KC_WBSP, KC_WDEL, KC_WRGT, _______,          KC_CAPS,                             _______,
        _______, _______, GU_ON,                     _______,                                     _______, GU_OFF,  _______,      _______,     RGB_SAD,  _______,  RGB_SAI
    ),

/*  LAYER 2 — Standard keyboard (vanilla macOS, no home row mods)
 *  Use this when you need a clean layout (gaming, lending keyboard, etc.)
 */
    [LAYER2] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,        KC_MSNP, KC_SIRI, RGB_MOD,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,       KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                           KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                    MO(LAYER3), KC_RALT, KC_RGUI, KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT
    ),

/*  LAYER 3 — Numpad (TKL nav cluster → numpad)
 *  Toggle on/off with = key on Layer 1, or TG(LAYER3) from Esc on this layer.
 *  Nav cluster becomes:  7 8 9 / 4 5 6 / 1 2 3  with 0 on backslash key.
 */
    [LAYER3] = LAYOUT_tkl_ansi(
        TG(LAYER3),       KC_BRID, KC_BRIU, KC_MSSN, KC_FIND, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,         KC_P7,   KC_P8,   KC_P9,
        KC_BTPR, KC_BTP0, KC_BTP1, KC_BTP2, KC_BTRT, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_PPLS, KC_BSPC,         KC_P4,   KC_P5,   KC_P6,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_P0,           KC_P1,   KC_P2,   KC_P3,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                           KC_UP,
        _______, _______, _______,                   _______,                                     _______, _______, _______, KC_NUM,          KC_LEFT, KC_DOWN, KC_RGHT
    )
};

void keyboard_post_init_user(void) {
    // debug_enable   = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse    = true;
}
