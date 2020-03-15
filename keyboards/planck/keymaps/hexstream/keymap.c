#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  INSERT_PARENTHESES,
  INSERT_CURLY_BRACES
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPACE,KC_GRAVE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_DELETE,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_ENTER,TOGGLE_LAYER_COLOR,RALT_T(KC_F15),LOWER,RAISE,KC_LCTRL,KC_SPACE,KC_NO,KC_LALT,KC_LSHIFT,KC_DOWN,KC_UP,TT(4)),

  [_LOWER] = LAYOUT_planck_grid(DYN_REC_STOP,KC_F11,KC_F12,KC_F13,KC_PGUP,KC_F15,KC_END,KC_F17,KC_F18,KC_F19,KC_F20,LSFT(KC_2),DYN_REC_START1,RALT(KC_Q),KC_NONUS_HASH,RALT(KC_MINUS),LSFT(KC_9),DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,LSFT(KC_0),RALT(KC_EQUAL),LSFT(KC_NONUS_HASH),RALT(KC_NONUS_HASH),INSERT_CURLY_BRACES,DYN_REC_START2,LCTL(LGUI(KC_1)),LCTL(LGUI(KC_2)),LCTL(LGUI(KC_3)),LCTL(LGUI(KC_4)),LCTL(LGUI(KC_0)),KC_HOME,KC_F14,KC_EQUAL,KC_PGDOWN,LSFT(KC_NONUS_HASH),KC_KP_ENTER,LGUI(KC_PGDOWN),LGUI(KC_PGUP),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_D),LSFT(KC_RBRACKET),KC_TRANSPARENT),

  [_RAISE] = LAYOUT_planck_grid(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_UP,KC_F5,KC_RIGHT,KC_F7,KC_F8,KC_F9,KC_F10,KC_LBRACKET,RALT(KC_GRAVE),KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,INSERT_PARENTHESES,RALT(KC_2),LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),KC_F6,KC_LEFT,RALT(KC_Z),KC_MINUS,KC_DOWN,KC_NONUS_HASH,LSFT(KC_3),KC_LGUI,KC_F4,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_A),KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_PSCREEN,KC_RBRACKET,KC_TRANSPARENT),

  [_ADJUST] = LAYOUT_planck_grid(WEBUSB_PAIR,KC_F21,KC_F22,KC_F23,KC_F24,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,MAGIC_TOGGLE_NKRO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_HUI,RGB_VAI,RGB_TOG,TOGGLE_LAYER_COLOR,KC_TRANSPARENT,KC_TRANSPARENT,AU_TOG,MU_TOG,KC_NO,RGB_MOD,RGB_SLD,LED_LEVEL,RGB_HUD,RGB_VAD),

  [_LAYER4] = LAYOUT_planck_grid(KC_PGUP,KC_HOME,KC_DOWN,KC_MS_UP,KC_UP,KC_END,KC_CAPSLOCK,KC_SCROLLLOCK,KC_LSHIFT,KC_LALT,KC_NUMLOCK,KC_BSPACE,KC_PGDOWN,KC_MS_WH_DOWN,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_UP,MO(6),KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,KC_KP_ENTER,KC_PGUP,LGUI(KC_KP_DOT),KC_MS_WH_LEFT,KC_LEFT,KC_MS_BTN3,KC_RIGHT,KC_MS_WH_RIGHT,TG(7),LGUI(KC_N),KC_HOME,KC_UP,KC_END,KC_PGDOWN,KC_MS_BTN5,KC_MS_BTN4,KC_MS_BTN2,MO(5),KC_MS_BTN1,TO(0),KC_NO,KC_LCTRL,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT),

  [_LAYER5] = LAYOUT_planck_grid(KC_TRANSPARENT,LALT(LGUI(LSFT(KC_A))),LALT(LGUI(KC_A)),LALT(LGUI(KC_N)),LALT(LGUI(KC_I)),LALT(LGUI(LSFT(KC_I))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LSHIFT,LALT(LGUI(LSFT(KC_H))),LALT(LGUI(KC_H)),LALT(LGUI(KC_D)),LALT(LGUI(KC_Y)),LALT(LGUI(LSFT(KC_Y))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LGUI(LSFT(KC_U))),LALT(LGUI(KC_U)),LALT(LGUI(KC_J)),LALT(LGUI(KC_G)),LALT(LGUI(LSFT(KC_G))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LGUI(LSFT(KC_J))),KC_TRANSPARENT,LALT(LGUI(LSFT(KC_N))),KC_TRANSPARENT,KC_NO,KC_LSHIFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER6] = LAYOUT_planck_grid(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_UP),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_LEFT),LGUI(KC_DOWN),LGUI(KC_RIGHT),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER7] = LAYOUT_planck_grid(KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_UP,KC_END,KC_TRANSPARENT,KC_CAPSLOCK,KC_KP_7,KC_KP_8,KC_KP_9,KC_NUMLOCK,KC_BSPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_PLUS,KC_KP_MINUS,KC_DELETE,KC_TRANSPARENT,KC_PGDOWN,KC_INSERT,KC_PGUP,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_ENTER,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LGUI,KC_LSHIFT,KC_LCTRL,KC_LALT,KC_NO,KC_0,KC_KP_DOT,KC_KP_COMMA,KC_SCROLLLOCK,TO(0)),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {86,255,255}, {0,0,0}, {172,255,255}, {172,255,255}, {0,0,0} },

    [1] = { {0,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {172,255,255}, {31,255,255}, {172,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {169,120,255}, {0,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {169,120,255}, {169,120,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {169,120,255}, {169,120,255}, {215,188,157}, {215,188,157}, {215,188,157}, {215,188,157}, {215,188,157}, {172,255,255}, {31,255,255}, {0,0,0}, {172,255,255}, {0,0,0}, {31,255,255}, {215,188,157}, {215,188,157}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {172,255,255}, {31,255,255}, {172,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {169,120,255}, {0,0,0}, {215,188,157}, {215,188,157}, {215,188,157}, {215,188,157}, {31,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {0,255,255}, {0,0,255}, {172,255,255}, {0,0,0} },

    [4] = { {172,255,255}, {0,0,0}, {172,255,255}, {215,188,157}, {172,255,255}, {0,0,0}, {169,120,255}, {169,120,255}, {86,255,255}, {86,255,255}, {169,120,255}, {0,255,255}, {172,255,255}, {0,0,0}, {215,188,157}, {215,188,157}, {215,188,157}, {0,0,0}, {31,255,255}, {215,188,157}, {215,188,157}, {215,188,157}, {31,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {172,255,255}, {86,255,255}, {172,255,255}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {31,255,255}, {86,255,255}, {0,0,0}, {86,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {169,120,255}, {172,255,255}, {172,255,255}, {172,255,255}, {169,120,255}, {0,255,255}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {172,255,255}, {86,255,255}, {86,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {86,255,255}, {86,255,255}, {0,255,255}, {0,0,0}, {172,255,255}, {0,0,0}, {172,255,255}, {0,0,0}, {31,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {0,0,0}, {0,0,0}, {169,120,255}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;

    case INSERT_PARENTHESES:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_CTRL) {
          SEND_STRING(SS_UP(X_LCTRL));
          if (get_mods() & MOD_MASK_ALT) {
            SEND_STRING(SS_UP(X_LALT));
            SEND_STRING("qqqq" SS_TAP(X_LEFT)); // ``
            SEND_STRING(SS_DOWN(X_LALT));
          } else {
            SEND_STRING(SS_RALT("-=") SS_TAP(X_LEFT)); // []
          }
          SEND_STRING(SS_DOWN(X_LCTRL));
        } else if (get_mods() & MOD_MASK_ALT) {
          SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_LSFT("22") SS_TAP(X_LEFT)); // ""
          SEND_STRING(SS_DOWN(X_LALT));
        } else if (get_mods() & MOD_MASK_SHIFT) {
          SEND_STRING(SS_LSFT("88") SS_TAP(X_LEFT)); // **
        } else {
          SEND_STRING("()" SS_TAP(X_LEFT)); // ()
        }
      }
      break;

    case INSERT_CURLY_BRACES:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          SEND_STRING(SS_UP(X_LSHIFT));
          SEND_STRING(SS_TAP(X_NONUS_HASH) SS_LSFT(SS_TAP(X_NONUS_HASH)) SS_TAP(X_LEFT)); // <>
          SEND_STRING(SS_DOWN(X_LSHIFT));
        } else if (get_mods() & MOD_MASK_ALT) {
          SEND_STRING(SS_UP(X_LALT));
          SEND_STRING(SS_LSFT("ww") SS_TAP(X_LEFT)); // ''
          SEND_STRING(SS_DOWN(X_LALT));
        } else {
          SEND_STRING(SS_RALT("q" SS_TAP(X_NONUS_HASH)) SS_TAP(X_LEFT)); // {}
        }
      }
      break;

  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
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
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
