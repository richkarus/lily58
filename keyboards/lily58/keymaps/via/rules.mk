LTO_ENABLE = yes            # Link Time Optimization enabled
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite (hold top-left key at plug-in to reset EEPROM)
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control (needed for volume/media keys)
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = yes           # OLED display
VIA_ENABLE = yes            # Enable VIA/VIAL live configuration

# Luna the dog OLED animation (from filterpaper/qmk_oled_animations), master
# half animates Luna, the other half shows layer/modifier status icons.
SRC += oled_luna.c oled_icons.c
