RGBLIGHT_ENABLE = no
COMMAND_ENABLE = no
KEY_LOCK_ENABLE = yes
TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes # slow down compilation time but the compiled file size is smaller
CONSOLE_ENABLE = no
AUTO_SHIFT_ENABLE = no
MOUSEKEY_ENABLE = yes

COMBO_ENABLE = yes

BOOTLOADER = qmk-dfu

SRC += features/caps_word.c
