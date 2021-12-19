APPLY_USERSPACE			= yes	# Apply the userspace keymap

COMBO_ENABLE 			= yes 	# Enables use of combos
ENCODER_ENABLE 			= yes	# Enables use of one or more encoders
MOUSEKEY_ENABLE 		= no	# Enables mouse keys
TAP_DANCE_ENABLE		= no	# Enables Tap Dance

# keyboard does not have OLED or RGB
OLED_ENABLE 			= no
RGBLIGHT_ENABLE 		= no    # Enable keyboard RGB underglow

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tapdance.c
endif
