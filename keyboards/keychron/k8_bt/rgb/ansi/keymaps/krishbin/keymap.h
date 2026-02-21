#pragma once
/*
Copyright 2024 krishbin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

/* ── Bluetooth Keycodes ────────────────────────────── */
enum BT_keycodes {
    KC_BTPROF0 = SAFE_RANGE,
    KC_BTPROF1,
    KC_BTPROF2,
    KC_BTPAIR,
    KC_BTTOGL,
    KC_BTRST,
    KC_BTBATT,
    K2_SAFE_RANGE
};

#define KC_BTP0  KC_BTPROF0
#define KC_BTP1  KC_BTPROF1
#define KC_BTP2  KC_BTPROF2
#define KC_BTPR  KC_BTPAIR
#define KC_BTTG  KC_BTTOGL
#define KC_BTRT  KC_BTRST
#define KC_BTBT  KC_BTBATT

/* ── Layers ────────────────────────────────────────── */
enum layer_names {
    LAYER0 = 0,  // Base: Mac + Home Row Mods
    LAYER1 = 1,  // Nav (Vim) + Media + BT
    LAYER2 = 2,  // Standard keyboard (vanilla)
    LAYER3 = 3,  // Numpad overlay
};

/* ── Dual-Role Keys ───────────────────────────────── */
#define HYPR_E   ALL_T(KC_ESC)         // Caps pos: Esc tap │ Hyper hold
#define LY1_TAB  LT(LAYER1, KC_TAB)   // Tab pos:  Tab tap │ L1 hold

/* ── Home Row Mods (GACS: Gui-Alt-Ctrl-Shift) ─────── *
 *  Left:   A=⌘  S=⌥  D=⌃  F=⇧                        *
 *  Right:  J=⇧  K=⌃  L=⌥  ;=⌘                        */
#define HRM_A   LGUI_T(KC_A)
#define HRM_S   LALT_T(KC_S)
#define HRM_D   LCTL_T(KC_D)
#define HRM_F   LSFT_T(KC_F)
#define HRM_J   RSFT_T(KC_J)
#define HRM_K   RCTL_T(KC_K)
#define HRM_L   RALT_T(KC_L)
#define HRM_SC  RGUI_T(KC_SCLN)

/* ── macOS Shortcuts ─────────────────────────────── */
#define KC_MSSN  LGUI(KC_F3)           // Mission Control
#define KC_FIND  LALT(LGUI(KC_SPC))    // Finder
#define KC_SIRI  LGUI(KC_SPC)          // Spotlight / Siri
#define KC_MSNP  LSFT(LGUI(KC_4))     // Screenshot region (⌘⇧4)

/* ── Layer 1: Vim Navigation ─────────────────────── */
#define KC_WLFT  LALT(KC_LEFT)         // Word left   (⌥←)
#define KC_WRGT  LALT(KC_RGHT)         // Word right  (⌥→)
#define KC_WBSP  LALT(KC_BSPC)        // Del word ←  (⌥⌫)
#define KC_WDEL  LALT(KC_DEL)          // Del word →  (⌥⌦)

/* ── Layer 1: Tab / Window Management ────────────── */
#define KC_TABL  LGUI(LSFT(KC_LBRC))  // Prev tab  (⌘⇧[)
#define KC_TABR  LGUI(LSFT(KC_RBRC))  // Next tab  (⌘⇧])
#define KC_CMDW  LGUI(KC_W)            // Close tab (⌘W)
#define KC_CMDT  LGUI(KC_T)            // New tab   (⌘T)
