# Enable common features
COMBO_ENABLE 		 = yes 	# Enables use of combos
MOUSEKEY_ENABLE  = yes	  # Enables mouse keys
CAPS_WORD_ENABLE = yes	  # Enables shift-based caps word
LTO_ENABLE       = yes   # Longer compile, smaller file; disables deprecated functionality

# Disable unused features
MAGIC_ENABLE	      = no
CONSOLE_ENABLE      = no
BOOTMAGIC_ENABLE    = no
UNICODE_ENABLE      = no
SPACE_CADET_ENABLE  = no
GRAVE_ESC_ENABLE    = no
AUDIO_ENABLE 			  = no

VPATH += keyboards/gboards/ # using gboards combo code: see https://combos.gboards.ca/
INTROSPECTION_KEYMAP_C = process_records.c
SRC += possumvibes.c

ifeq ($(strip $(COMBOS_ENABLE)), yes)
	SRC += combos.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoders.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += capsword.c
endif

SRC += tap_holds.c

# Add custom features
SRC += features/mod_lock.c
SRC += features/nshot_mod.c
SRC += features/smart_layer.c
SRC += features/swapper.c
