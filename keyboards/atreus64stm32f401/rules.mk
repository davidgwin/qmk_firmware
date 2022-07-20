# MCU name
MCU = STM32F401

# Bootloader selection
BOOTLOADER = stm32-dfu


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite

EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
#BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
UNICODE_ENABLE = yes        # Unicode
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
COMBO_ENABLE = yes

WPM_ENABLE = yes