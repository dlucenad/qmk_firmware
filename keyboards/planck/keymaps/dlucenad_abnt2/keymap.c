/* Copyright 2024 dlucenad
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
#include "keymap_brazilian_abnt2.h"
 
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _NAV,
  _NUM,
  _SYM,
  _FUNCTION,
  _ADJUST//,
  //_MIDI
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define SYM   LT(_SYM,KC_MINS)
#define FUN   LT(_FUNCTION, KC_LEFT)
#define MYGRV LT(_NAV, KC_GRV)
#define MYNAV LT(_NAV, KC_DEL)
#define MYNUM LT(_NUM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 ,-----------------------------------------------------------------------------------.
 | Mute |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |acute |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   '  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ~C  |  ~   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | _(S) |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ;  |Enter(Shift)|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Ctrl |  GUI | Alt  |'(SYM)|DelNAV|_(Shft| Space|BS(NUM|L(FUN)| Down |  Up  |R(Ctrl)|
 `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT_planck_grid(
         KC_MUTE,         KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,           KC_Y,         KC_U,         KC_I,         KC_O,    KC_P,         BR_ACUT,
           MYGRV, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),           KC_G,           KC_H, LCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), BR_CCED,         BR_TILD,
         SC_LSPO,         KC_Z,         KC_X,         KC_C,         KC_V,           KC_B,           KC_N,         KC_M,      KC_COMM,       KC_DOT, BR_SCLN,         SC_SENT,
  LCTL_T(KC_GRV),      KC_LGUI,      KC_LALT,          SYM,        MYNAV, LSFT_T(KC_TAB), LSFT_T(KC_SPC),        MYNUM,          FUN,      KC_DOWN,   KC_UP, LCTL_T(KC_RGHT)
),

/* Navigation
 ,-----------------------------------------------------------------------------------.
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Home |  Up  | End  |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  GUI |  Alt | Ctrl | Shift|      | Enter| Left | Down | Right|      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |  Esc |  C(z)|  C(x)|  C(c)|  C(v)|  C(b)|      | Pg Up| Del  | Pg Dn|      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |  NUM | Prev | Stop | Play | Next |
 `-----------------------------------------------------------------------------------'
*/
[_NAV] = LAYOUT_planck_grid(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_HOME,   KC_UP,  KC_END, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,  KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
   KC_ESC, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), _______, KC_PGUP,  KC_DEL, KC_PGDN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,   MYNUM, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT
),

/* Numbers
 ,-----------------------------------------------------------------------------------.
 |      |   _  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   +  | Alt  |   /  |   *  |   =  | Enter|   4  |   5  |   6  |   ,  |   +  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   %  |   .  |   ,  |   (  |   )  | Calc |   1  |   2  |   3  |      |   =  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |  NAV |      |      |      |   0  |   .  |   ,  | Space|
 `-----------------------------------------------------------------------------------'
*/
[_NUM] = LAYOUT_planck_grid(
  _______, BR_UNDS,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, BR_MINS,
  _______, BR_PLUS, KC_LALT, BR_SLSH, BR_ASTR,  BR_EQL,  KC_ENT,    KC_4,    KC_5,    KC_6, BR_COMM, BR_PLUS,
  _______, BR_PERC, BR_DOT, BR_COMM,  KC_LBRC, KC_RBRC, KC_CALC,    KC_1,    KC_2,    KC_3, _______,  BR_EQL,
  _______, _______, _______, _______,   MYNAV, _______, _______, _______,    KC_0,  BR_DOT, KC_COMM,  KC_SPC
),

/* Symbol
 ,-----------------------------------------------------------------------------------.
 |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   ?  |   \  |   |  |   /  |   =  | Enter|   +  |   _  |   [  |   ]  |   -  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Caps |      |      |      |      |      |      |   =  |   -  |   {  |   }  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 `-----------------------------------------------------------------------------------'
*/
[_SYM] = LAYOUT_planck_grid(
  _______, BR_EXLM,   BR_AT, BR_HASH, BR_DLR,  BR_PERC, BR_DIAE, BR_AMPR, BR_ASTR, BR_LPRN, BR_RPRN, BR_UNDS,
  _______, BR_QUES, BR_BSLS, BR_PIPE, BR_SLSH,  BR_EQL,  KC_ENT, BR_PLUS, BR_UNDS, BR_LBRC, BR_RBRC, BR_MINS,
  KC_CAPS, _______, _______, _______, _______, _______, _______,  BR_EQL, BR_MINS, BR_LCBR, BR_RCBR, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Function
 ,-----------------------------------------------------------------------------------.
 |      |   /  |   ?  |  deg |      |      |      |      |      |      |Print |Insert|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |Pause |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |  Esc |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 `-----------------------------------------------------------------------------------'
*/
[_FUNCTION] = LAYOUT_planck_grid(
  _______, BR_SLSH, BR_QUES,  BR_DEG, _______, _______, _______, _______, _______, _______, KC_PSCR,  KC_INS,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, _______, _______, _______, KC_PAUS,
   KC_ESC,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Navigation + Numbers)
                      v------------------------RGB CONTROL--------------------v
 ,-----------------------------------------------------------------------------------.
 | Reset|      | Brite| RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Debug|      |MUSmod|Aud on|Audoff|      |      |Qwerty|      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      | TTDWN| TTUP |PrntTT|      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 `-----------------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_planck_grid(
  QK_BOOT, _______, BACKLIT, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
  DB_TOGG, _______, MU_NEXT,   AU_ON,  AU_OFF, _______, _______,  QWERTY, _______, _______, _______, _______,
  _______, AU_PREV, AU_NEXT,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF, _______, DT_DOWN,   DT_UP, DT_PRNT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

/* MIDI layer
 [_MIDI] = LAYOUT_planck_mit(
    MI_Cs,   MI_Ds,   _______, MI_Fs,   MI_Gs,   MI_As,   _______, MI_Cs,   MI_Ds,   _______, MI_Fs,   MI_Gs,
    MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,    MI_B,    MI_C,    MI_D,    MI_E,    MI_F,    MI_G,
    MI_BENDU,MI_OCTU, MI_TRNSU,MI_VELU, _______, _______, _______, _______, _______, MI_ON,   MI_CHU,  MI_TOG,
    MI_BENDD,MI_OCTD, MI_TRNSD,MI_VELD, MYNAV,       MI_SUS,       MYNUM, _______,   MI_OFF,  MI_CHD,  MI_ALLOFF
 )
*/

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]          = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]       = SONG(PLOVER_GOODBYE_SOUND);
  float caps_lock_on_sound[][2]   = SONG(CAPS_LOCK_ON_SOUND);
  float caps_lock_off_sound[][2]  = SONG(CAPS_LOCK_OFF_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

/* 
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
  return false;
}
*/

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_NUM)) {
		if (clockwise) {
			register_code(KC_LALT);
			register_code(KC_TAB);
			unregister_code(KC_TAB);
			unregister_code(KC_LALT);
		}	else {
			register_code(KC_LALT);
      register_code(KC_LSFT);
			register_code(KC_TAB);
      unregister_code(KC_TAB);
			unregister_code(KC_LSFT);
			unregister_code(KC_LALT);
		}
  } else {
      if (IS_LAYER_ON(_NAV)) {
        if (clockwise) {
          register_code(KC_LCTL);
			    register_code(KC_Y);
			    unregister_code(KC_Y);
			    unregister_code(KC_LCTL);
        } else {
			    register_code(KC_LCTL);
          register_code(KC_Z);
			    unregister_code(KC_Z);
         unregister_code(KC_LCTL);  
        }
      } else {
          if (clockwise) {
            tap_code(KC_VOLU);
          } else {
            tap_code(KC_VOLD);
          }
      }
  }
  return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case MYNUM:
    case MYNAV:
      return false;
    default:
      return true;
  }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        PLAY_SONG(caps_lock_on_sound);
    } else {
        // Do something when Caps Word deactivates.
        PLAY_SONG(caps_lock_off_sound);
    }
}