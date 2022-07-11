# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight. 
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
SPLIT_KEYBOARD = yes

DYNAMIC_MACRO_ENABLE = yes
# UNICODE_ENABLE = yes
# UNICODEMAP_ENABLE = yes
# LTO_ENABLE = yes

COMBO_ENABLE = yes