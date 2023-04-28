#include QMK_KEYBOARD_H
/* #include "features/caps_word.h" */

// Layer names
enum{
  _COLEMAKDH, // Base Colemak Mod-DH
  _SYMB, // Symbols
  _NAVI, // Navigation
  _NUMB, // Numbers
  _FUNC, // Functions keys
  _MOUS, // Mouse
  _WSPC, // Workspace
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
  ASC_COP,
  ASC_CCL,
  ASC_DDS,
  ASC_SSL
};


// Shortcuts to make keymap more readable
// - Adjustment Layer:
#define KC_ADHO LT(_ADJUST, KC_HOME)  // Home / _ADJUST layer
#define KC_ADPU LT(_ADJUST, KC_PGUP)  // Page Up / _ADJUST layer
// - Home row modifiers:
#define KC_GU_A LGUI_T(KC_A)          // A / Left Gui
#define KC_CT_S LCTL_T(KC_S)          // R / Left Ctrl
#define KC_AL_R LALT_T(KC_R)          // S / Left Alt
#define KC_LS_T LSFT_T(KC_T)          // T / Left Shift
#define KC_GU_O RGUI_T(KC_O)          // O / Right Gui
#define KC_AL_I LALT_T(KC_I)          // E / Left Alt (left alt because used as Emacs M- )
#define KC_CT_E RCTL_T(KC_E)          // I / Right Ctrl
#define KC_RS_N RSFT_T(KC_N)          // N / Right Shift
#define KC_AR_X RALT_T(KC_X)          // X / Right Alt
#define KC_AR_DO RALT_T(KC_DOT)       // . / Right Alt
#define KC_HY_G HYPR_T(KC_G)          // G / Hypr
#define KC_HY_M HYPR_T(KC_M)          // M / Hypr

// - Thumbs keys/modifiers:
#define KC_SYSP LT(_SYMB, KC_SPC)     // Space / _symbols
#define KC_FUEN LT(_FUNC, KC_ENT)     // Enter / _functions
#define KC_NUTA LT(_NUMB, KC_TAB)     // Tab / _numbers
#define KC_NABS LT(_NAVI, KC_BSPC)    // Backspace / _navigation
#define KC_MOES LT(_MOUS, KC_ESC)     // Esc / _mouse
#define KC_WSDE LT(_WSPC, KC_DEL)     // Del / _workspace
#define KC_GUDE LGUI_T(KC_DEL)     // Del / _workspace

// - Toggle layers:
#define TG_NUM TG(_NUMB)
/* #define TG_NAV TG(_NAVI) */

// - Awesome WM macros:
#define KC_AW1 LGUI(KC_1)
#define KC_AW2 LGUI(KC_2)
#define KC_AW3 LGUI(KC_3)
#define KC_AW4 LGUI(KC_4)
#define KC_AW5 LGUI(KC_5)
#define KC_AW6 LGUI(KC_6)
#define KC_AW7 LGUI(KC_7)
#define KC_AW8 LGUI(KC_8)
#define KC_AW9 LGUI(KC_9)
// - Clipboard, Undo/Redo and "select all" (should work almost everywhere, including Emacs)
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
//#define U_UND KC_UNDO
//#define U_RDO KC_AGIN
#define U_UND LCTL(KC_Z) // Doesn't work on Emacs
#define U_RDO LCTL(LSFT(KC_Z)) // Doesn't work on Emacs
/* #define U_ALL C(KC_A) // Emacs need to rebind mark-whole-buffer to: C-a */

//- Macros
#define KC_PTAB RCS(KC_TAB)
#define KC_NTAB C(KC_TAB)

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
      case ASC_COP:
        SEND_STRING("/*");
        return false;
      case ASC_CCL:
        SEND_STRING("*/");
        return false;
      case ASC_DDS:
        SEND_STRING("../");
        return false;
      case ASC_SSL:
        SEND_STRING("//");
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

  // Pinkies
  case KC_GU_O:
    return TAPPING_TERM + 200;
  case KC_GU_A:
    return TAPPING_TERM + 100;

  // Ring fingers
  case KC_AL_I:
  case KC_AL_R:
  case KC_AR_X:
  case KC_AR_DO:
    return TAPPING_TERM + 200;

  // Middle fingers
  case KC_CT_S:
  case KC_CT_E:
    return TAPPING_TERM - 30;

  // Index fingers
  case KC_LS_T:
  case KC_RS_N:
    return TAPPING_TERM - 40;

  // Right thumbs
  case KC_SYSP:
    return TAPPING_TERM - 80;
  case KC_NUTA:
  case KC_FUEN:
    return TAPPING_TERM - 20;

  // All other keys
  default:
    return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// -----------------------------------------------------------------------------
// Colemak Mod-DH
// -----------------------------------------------------------------------------
[_COLEMAKDH] = LAYOUT_5x7(
   // left hand
   KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,XXXXXXX ,
   KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,XXXXXXX ,
   KC_ESC  ,KC_GU_A ,KC_AL_R ,KC_CT_S ,KC_LS_T ,KC_HY_G ,XXXXXXX ,
   SC_LSPO ,KC_Z    ,KC_AR_X ,KC_C    ,KC_D    ,KC_V    ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  KC_MOES ,KC_NABS ,
                                  KC_GUDE ,KC_ADPU ,
                                  KC_ENT  ,KC_PGDN ,
   // right hand
                     XXXXXXX ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,TG_NUM  ,
                     XXXXXXX ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
                     XXXXXXX ,KC_HY_M ,KC_RS_N ,KC_CT_E ,KC_AL_I ,KC_GU_O ,KC_MINS ,
                              KC_K    ,KC_H    ,KC_COMM ,KC_AR_DO,KC_SLSH ,SC_RSPC ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        KC_SYSP ,KC_NUTA ,
        KC_ADHO ,KC_FUEN,
        KC_END  ,LT(_NAVI, KC_DEL)),


// -----------------------------------------------------------------------------
// Symbols
// -----------------------------------------------------------------------------
[_SYMB] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,XXXXXXX ,
   XXXXXXX ,KC_PIPE ,KC_PMNS ,ASC_SQT ,ASC_DQT ,KC_GRV  ,XXXXXXX ,
   XXXXXXX ,KC_BSLS ,KC_UNDS ,KC_LCBR ,KC_LBRC ,KC_EQL  ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  KC_RPRN ,KC_LPRN ,
                                  ASC_HAP ,ASC_SAD ,
                                  XXXXXXX ,XXXXXXX ,
  // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,ASC_CIRC,KC_AMPR ,KC_ASTR ,ASC_COP ,ASC_CCL ,XXXXXXX ,
                     XXXXXXX ,KC_QUOT ,KC_COLN ,ASC_TILD,ASC_SAR ,ASC_DAR ,XXXXXXX ,
                              ASC_BKT ,KC_RBRC ,KC_RCBR ,ASC_DDS ,ASC_SSL ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        _______ ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX),


// -----------------------------------------------------------------------------
// Navigation
// -----------------------------------------------------------------------------
[_NAVI] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,KC_TAB  ,KC_PTAB ,KC_NTAB ,KC_SPC  ,XXXXXXX ,
   XXXXXXX ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_ENT  ,XXXXXXX ,
   XXXXXXX ,U_UND   ,U_CUT   ,U_CPY   ,U_PST   ,U_RDO   ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  _______ ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,XXXXXXX ,RCS(KC_LEFT)  ,C(KC_LEFT)   ,C(KC_RGHT)   ,RCS(KC_RGHT)   ,XXXXXXX ,
                     XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,
                              _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX),

// -----------------------------------------------------------------------------
// Mouse
// -----------------------------------------------------------------------------
[_MOUS] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,C(KC_Q) ,C(KC_W) ,C(KC_F) ,C(KC_P) ,C(KC_B) ,XXXXXXX ,
   XXXXXXX ,C(KC_A) ,C(KC_R) ,C(KC_S) ,C(KC_T) ,C(KC_G) ,XXXXXXX ,
   XXXXXXX ,U_UND   ,U_CUT   ,U_CPY   ,U_PST   ,U_RDO   ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  _______ ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX ,
                              XXXXXXX ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        KC_BTN1 ,KC_BTN2 ,
        XXXXXXX ,KC_BTN3 ,
        XXXXXXX ,XXXXXXX),

// -----------------------------------------------------------------------------
// Numeric keypad layer
// -----------------------------------------------------------------------------
[_NUMB] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,KC_PMNS ,KC_7    ,KC_8    ,KC_9    ,KC_PPLS ,XXXXXXX ,
   XXXXXXX ,KC_DOT  ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,XXXXXXX ,
   XXXXXXX ,KC_PSLS ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  KC_COMM ,KC_0    ,
                                  KC_BSPC ,KC_SPC  ,
                                  KC_ENT  ,XXXXXXX ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                     XXXXXXX ,KC_HYPR ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,XXXXXXX ,
                              XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,_______ ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX),

// -----------------------------------------------------------------------------
// Function layer and some extra keys on right hand
// -----------------------------------------------------------------------------
[_FUNC] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,KC_CAPS ,XXXXXXX ,
   XXXXXXX ,KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,KC_PSCR ,XXXXXXX ,
   XXXXXXX ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_INS  ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,XXXXXXX ,
                     XXXXXXX ,KC_HYPR ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,XXXXXXX ,
                              XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,_______ ,
        XXXXXXX ,XXXXXXX),


// -----------------------------------------------------------------------------
// Workspace (AwesomeWM navigation) - CURRENTLY DISABLED
// -----------------------------------------------------------------------------
[_WSPC] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,G(KC_Q) ,KC_AW7  ,KC_AW8  ,KC_AW9  ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,KC_AW4  ,KC_AW5  ,KC_AW6  ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,KC_AW1  ,KC_AW2  ,KC_AW3  ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
                                  XXXXXXX ,XXXXXXX ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                     XXXXXXX ,XXXXXXX ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,XXXXXXX ,
                              XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,
        XXXXXXX ,_______ ,
        XXXXXXX ,XXXXXXX),


// -----------------------------------------------------------------------------
// Adjust layer (RGB, Reset and base layer switch)
// -----------------------------------------------------------------------------
[_ADJUST] = LAYOUT_5x7(
  // left hand
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
                                  _______ ,_______ ,
   // right hand
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,XXXXXXX ,
                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                              XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        _______ ,_______ ,
        _______ ,_______ ,
        _______ ,_______),
};




// -----------------------------------------------------------------------------
// Combos
// -----------------------------------------------------------------------------
enum combos {
  /* BG_DEL, */
  /* JM_ENT, */
  DH_ESC
};

/* const uint16_t PROGMEM bg_combo[] = {KC_B, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END}; */
const uint16_t PROGMEM dh_combo[] = {KC_D, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  /* [BG_DEL] = COMBO(bg_combo, KC_DEL), */
  /* [JM_ENT] = COMBO(jm_combo, KC_ENT), */
  [DH_ESC] = COMBO(dh_combo, KC_ESC)
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
  case KC_AR_X:
  case KC_AR_DO:
    return true;
  default:
    return false;
  }
}
