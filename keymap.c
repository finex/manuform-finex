#include QMK_KEYBOARD_H

// Layer names
enum{
  _COLEMAKDH, // Base Colemak Mod-DH
  _SYMB, // Symbols
  _NAVI, // Navigation
  _NUMB, // Numbers
  _FUNC, // Functions keys
  /* _MOUS, // Mouse */
  _ADJUST // Adjust
};

// Custom keycodes
enum custom_keycodes {
  COLEMAKDH = SAFE_RANGE,
  ASC_SAR,
  ASC_DAR,
  ASC_SQT,
  ASC_DQT,
  ASC_CIRC,
  ASC_TILD,
  ASC_HAP,
  ASC_SAD,
  ASC_BKT,
  ASC_CBRL,
  ASC_CBRR,
  ASC_LAN,
  ASC_RAN
};

// Tap dance codes
enum tap_dance_codes {
  /* DANCE_1, // Delete (single), Gui (hold), Mouse layer (double hold) */
  DANCE_2, // Semicolon (single), Colon (double)
  DANCE_3, // Left Bracket (single), Left Brace (double)
  DANCE_4  // Right Bracket (single), Left Brace (double)
};

// Shortcuts to make keymap more readable
// - Adjustment Layer:
#define KC_ADHO LT(_ADJUST, KC_HOME)  // Home / _ADJUST layer
#define KC_ADPU LT(_ADJUST, KC_PGUP)  // Page Up / _ADJUST layer
// - Home row modifiers:
#define KC_GU_A LGUI_T(KC_A)          // A / Left Gui
#define KC_CT_S LCTL_T(KC_S)          // R / Left Ctrl
#define KC_AL_R LALT_T(KC_R)          // S / Left Alt
#define KC_GU_O RGUI_T(KC_O)          // O / Right Gui
#define KC_AR_X RALT_T(KC_X)          // X / Right Alt
#define KC_AL_I LALT_T(KC_I)          // E / Left Alt (left alt because used as Emacs M- )
#define KC_AR_DO RALT_T(KC_DOT)       // . / Right Alt
#define KC_CT_E RCTL_T(KC_E)          // I / Right Ctrl
#define KC_RS_N RSFT_T(KC_N)          // N / Right Shift
#define KC_LS_T LSFT_T(KC_T)          // T / Left Shift
// - Other keys/modifiers:
#define KC_ATAB RALT_T(KC_TAB)        // Tab / Alt Gr
#define KC_CESC LCTL_T(KC_ESC)        // Esc / Left Ctrlrs
#define KC_GUSP RGUI_T(KC_SPC)        // Space / Right Gui
#define KC_AEQL LALT_T(KC_EQL)        // Equals / Left Alt
#define KC_CMIN RCTL_T(KC_MINUS)      // Minus / Right Ctrl
#define KC_NUES LT(_NUMB, KC_ESC)     // Esc / _numbers
#define KC_CBSP LCTL_T(KC_BSPC)        // Backspace / Left Ctrl
#define KC_SYSP LT(_SYMB, KC_SPC)     // Space / _symbols
/* #define KC_AWEN LT(_AWES, KC_ENT)     // Enter / AwesomeWM */
#define KC_FUTA LT(_FUNC, KC_TAB)     // Tab / _functions
#define KC_CTEN LCTL_T(KC_ENT)        // Enter / Right Alt

#define KC_GUDE RGUI_T(KC_DEL)        // Delete / Right Gui
#define KC_GUEN RGUI_T(KC_ENT)        // Enter / Right Gui
#define KC_GUCO RGUI_T(KC_COMM)       // Comma / Right Gui
#define KC_SYBS LT(_SYMB, KC_BSPC)    // Backspace / _symbols
#define KC_FUDE LT(_FUNC, KC_DEL)     // Delete / _functions
#define KC_NUEN LT(_NUMB, KC_ENT)     // Enter / _numbers
#define KC_NAES LT(_NAVI, KC_ESC)     // Esc / _navi

#define KC_HYBS HYPR_T(KC_BSPC)        // Backspace / Hyper
#define KC_MEEN MEH_T(KC_ENT)          // Enter / Meh

// - Toggle layers:
#define TG_NUM TG(_NUMB)
/* #define TG_NAV TG(_NAVI) */

// - Tap dance keys:
/* #define TD_DGUM TD(DANCE_1) */
#define TD_SCLN TD(DANCE_2)
#define TD_LBRC TD(DANCE_3)
#define TD_RBRC TD(DANCE_4)
// - Awesome WM macros:
/* #define KC_AW1 LGUI(KC_1) */
/* #define KC_AW2 LGUI(KC_2) */
/* #define KC_AW3 LGUI(KC_3) */
/* #define KC_AW4 LGUI(KC_4) */
/* #define KC_AW5 LGUI(KC_5) */
/* #define KC_AW6 LGUI(KC_6) */
/* #define KC_AW7 LGUI(KC_7) */
/* #define KC_AW8 LGUI(KC_8) */
/* #define KC_AW9 LGUI(KC_9) */
/* // - Clipboard, Undo/Redo and "select all" */
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
/* #define U_UND KC_UNDO */
// #define U_RDO KC_AGIN // Emacs executes "reperat-complex-command"
#define U_UND C(KC_UNDS)
#define U_RDO A(KC_UNDS)
/* #define U_ALL C(KC_A) // Emacs need to rebind mark-whole-buffer to: C-a */


#ifdef CONSOLE_ENABLE
#include "print.h"
#endif


// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case ASC_SAR:
        SEND_STRING("->");
        return false;
      case ASC_DAR:
        SEND_STRING("=>");
        return false;
      case ASC_SQT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("'"));
        return false;
      case ASC_DQT:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("\"")));
        return false;
      case ASC_CIRC:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("^"));
        return false;
      case ASC_TILD:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("~")));
        return false;
      case ASC_HAP:
        SEND_STRING(":-) ");
        return false;
      case ASC_SAD:
        SEND_STRING(":-( ");
        return false;
      case ASC_BKT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("`"));
        return false;
      case ASC_CBRL:
        SEND_STRING("{");
        return false;
      case ASC_CBRR:
        SEND_STRING("}");
        return false;
      case ASC_LAN:
        SEND_STRING(SS_RALT("["));
        return false;
      case ASC_RAN:
        SEND_STRING(SS_RALT("]"));
        return false;
      case COLEMAKDH:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_COLEMAKDH);
        }
        return false;
        break;
    }
  }
  return true;
};

// Fine tuning of TAPPING_TERM valuer on some home row modifiers to avoid errors during typing.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  // Ring fingers
  case KC_AL_I:
  case KC_AL_R:
  case KC_AR_X:
  case KC_AR_DO:
    return TAPPING_TERM + 200;

  // Pinkies
  case KC_GU_O:
  case KC_GU_A:
    return TAPPING_TERM + 50;

  // Middle fingers
  case KC_CT_S:
  case KC_CT_E:
    return TAPPING_TERM - 30;

  // Right thumb for "symbols" layer
  case KC_SYSP:
    return TAPPING_TERM - 50;

  // Left thumb for delete/gui/mouse combo
  case KC_GUDE:
  case KC_GUEN:
    return TAPPING_TERM - 20;

  // All other keys
  default:
    return TAPPING_TERM;
  }
}


// Custom combos (test)
enum combos {
  BG_LBRC,
};

const uint16_t PROGMEM bg_combo[] = {KC_B, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [BG_LBRC] = COMBO(bg_combo, KC_LBRC),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Colemak Mod-DH
[_COLEMAKDH] = LAYOUT_5x7(
  // left hand
   KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_PSCR ,
   KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,XXXXXXX ,
   KC_CESC ,KC_GU_A ,KC_AL_R ,KC_CT_S ,KC_LS_T ,KC_G    ,TD_LBRC ,
   KC_LSPO ,KC_Z    ,KC_AR_X ,KC_C    ,KC_D    ,KC_V    ,
   KC_GUSP ,XXXXXXX ,KC_HYPR ,KC_MEH  ,
                                  KC_GUDE ,KC_CBSP ,
                                  KC_NAES ,KC_ADPU ,
                                  KC_CTEN ,KC_PGDN ,
        // right hand
                     KB_DEL  ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
                     XXXXXXX ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,TD_SCLN ,KC_EQL ,
                     TD_RBRC ,KC_M    ,KC_RS_N ,KC_CT_E ,KC_AL_I ,KC_GU_O ,KC_CMIN ,
                              KC_K    ,KC_H    ,KC_COMM ,KC_AR_DO,KC_SLSH ,KC_RSPC ,
                                       KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT,
        KC_SYSP ,KC_NUEN ,
        KC_ADHO ,KC_FUTA ,
        KC_END  ,KC_BSPC),

// Symbols
[_SYMB] = LAYOUT_5x7(
  // left hand
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,KC_PIPE ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,_______ ,
   _______ ,KC_LBRC ,KC_PMNS ,ASC_SQT ,ASC_DQT ,KC_EXLM ,ASC_SAR ,
   _______ ,KC_BSLS ,KC_UNDS ,ASC_CIRC,ASC_TILD,KC_AMPR ,
   _______ ,_______ ,_______ ,_______ ,
                                  KC_LPRN ,KC_GRV  ,
                                  KC_QUOT ,ASC_SAD ,
                                  _______ ,ASC_HAP ,
        // right hand
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                       _______ ,_______ ,_______ ,_______,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),



// Navigation
[_NAVI] = LAYOUT_5x7(
  // left hand
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
        // right hand
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,U_UND   ,U_CUT   ,U_CPY   ,U_PST   ,U_RDO   ,_______ ,
                     _______ ,_______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,_______ ,
                              _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,
                                       _______ ,_______ ,_______ ,_______,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),

// Numeric keypad layer
[_NUMB] = LAYOUT_5x7(
  // left hand
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,KC_PMNS ,KC_7    ,KC_8    ,KC_9    ,KC_PPLS ,_______ ,
   _______ ,KC_RBRC ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,_______ ,
   _______ ,KC_PSLS ,KC_1    ,KC_2    ,KC_3    ,KC_EQL ,
   _______ ,_______ ,KC_DOT  ,KC_0    ,
                                  KC_COMM ,KC_ENT  ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
        // right hand
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                       _______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),

// Function layer and some extra keys on right hand
[_FUNC] = LAYOUT_5x7(
  // left hand
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,KC_CAPS ,_______ ,
   _______ ,KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,KC_NLCK ,ASC_DAR ,
   _______ ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_INS ,
   _______ ,_______ ,_______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
        // right hand
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                       _______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),



// Adjust layer (RGB, Reset and base layer switch)
[_ADJUST] = LAYOUT_5x7(
  // left hand
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,RESET   ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
   _______ ,_______ ,_______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
        // right hand
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                              _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                       _______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),


};

//extern bool g_suspend_state;
//#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
//uint16_t last_keycode = KC_NO;
//uint8_t last_modifier = 0;

// Define "tap" structure
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

// Tap combinations
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

/* static tap dance_state = { */
/*     .is_press_action = true, */
/*     .step = 0 */
/* }; */

/* void on_dance_1(qk_tap_dance_state_t *state, void *user_data); */
/* uint8_t dance_1_dance_step(qk_tap_dance_state_t *state); */
/* void dance_1_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void dance_1_reset(qk_tap_dance_state_t *state, void *user_data); */

/* // Dance 1: Delete / Gui / _Mouse */
/* void on_dance_1(qk_tap_dance_state_t *state, void *user_data) { */
/*   if(state->count == 3) { */
/*     tap_code16(KC_DEL); */
/*     tap_code16(KC_DEL); */
/*     tap_code16(KC_DEL); */
/*   } */
/*   if(state->count > 3) { */
/*     tap_code16(KC_DEL); */
/*   } */
/* } */

/* uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) { */
/*   if (state->count == 1) { */
/*     if (state->interrupted || !state->pressed) return SINGLE_TAP; */
/*     else return SINGLE_HOLD; */
/*   } else if (state->count == 2) { */
/*     if (state->interrupted) return DOUBLE_SINGLE_TAP; */
/*     else if (state->pressed) return DOUBLE_HOLD; */
/*     else return DOUBLE_TAP; */
/*   } */
/*   return MORE_TAPS; */
/* } */
/* void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   dance_state.step = dance_1_dance_step(state); */
/*   switch (dance_state.step) { */
/*   case SINGLE_TAP: register_code16(KC_DEL); break; */
/*   case SINGLE_HOLD: register_mods(MOD_BIT(KC_LGUI)); break; */
/*   case DOUBLE_TAP: register_code16(KC_DEL); register_code16(KC_DEL); break; */
/*   case DOUBLE_HOLD: layer_on(_MOUS); break; */
/*   case DOUBLE_SINGLE_TAP: tap_code16(KC_DEL); register_code16(KC_DEL); */
/*   } */
/* } */

/* void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   wait_ms(10); */
/*   switch (dance_state.step) { */
/*   case SINGLE_TAP: unregister_code16(KC_DEL); break; */
/*   case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LGUI)); break; */
/*   case DOUBLE_TAP: unregister_code16(KC_DEL); break; */
/*   case DOUBLE_HOLD: layer_off(_MOUS); break; */
/*   case DOUBLE_SINGLE_TAP: unregister_code16(KC_DEL); break; */
/*   } */
/*   dance_state.step = 0; */
/* } */

// Dance 2: Semicolon to Colon
void dance_2_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}
void dance_2_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

// Dance 3: Square braket to curly bracket (left)
void dance_3_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_LBRC);
  }
}
void dance_3_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_LBRC);
  }
}

// Dance 4: Square braket to curly bracket (right)
void dance_4_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_RBRC);
  }
}
void dance_4_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_RBRC);
  }
}

// Match tap dance actions with the corresponding index
qk_tap_dance_action_t tap_dance_actions[] = {
  /* [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset), */
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
  [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_4_finished, dance_4_reset)
};

// Enable tapping_force_hold only for home row mods
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LS_T:
  case KC_CT_S:
  case KC_AL_R:
  case KC_GU_A:
  case KC_RS_N:
  case KC_CT_E:
  case KC_AL_I:
  case KC_GU_O:
    return true;
  default:
    return false;
  }
}
