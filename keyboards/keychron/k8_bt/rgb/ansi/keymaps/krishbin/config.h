#pragma once

/* ── Home Row Mod Tuning ─────────────────────────────
 *
 *  TAPPING_TERM   — ms you must hold a key before it registers as "held"
 *                   (modifier). Tap-and-release within this window = letter.
 *                   200 ms is a safe default; lower it (e.g. 175) once you
 *                   build muscle memory.
 *
 *  QUICK_TAP_TERM — after tapping a dual-role key, if you press it again
 *                   within this window it repeats the tap (letter) instead
 *                   of activating the hold (modifier). Handy for typing
 *                   "ff", "jj", "kk" quickly.
 *
 *  PERMISSIVE_HOLD — if you hold a mod-tap key and tap another key, the
 *                    mod fires even if the mod-tap key is released before
 *                    TAPPING_TERM expires.  Helps with fast Shift+letter.
 */

#define TAPPING_TERM 175
#define QUICK_TAP_TERM 120
#define PERMISSIVE_HOLD
