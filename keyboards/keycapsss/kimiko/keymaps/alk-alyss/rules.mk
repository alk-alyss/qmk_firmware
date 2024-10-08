BOOTLOADER = caterina
# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes

NKRO_ENABLE = yes

OLED_ENABLE = no
OLED_DRIVER = SSD1306     # Enables the use of OLED displays

ENCODER_ENABLE = yes      # Enables the use of one or more encoders
ENCODER_MAP_ENABLE = yes  # Enables encoder mapping

RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

CAPS_WORD_ENABLE = yes
