# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina
SPLIT_KEYBOARD = yes

# Build Options
#   change yes to no to disable
#
LTO_ENABLE = yes		    # Longer compile, smaller file; disables deprecated functionality
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
