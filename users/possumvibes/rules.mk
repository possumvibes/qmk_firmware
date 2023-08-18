# Enable common features
COMBO_ENABLE 		   = yes
MOUSEKEY_ENABLE        = yes
CAPS_WORD_ENABLE       = yes
LTO_ENABLE             = yes

# Disable unused features
MAGIC_ENABLE	       = no
CONSOLE_ENABLE         = no
BOOTMAGIC_ENABLE       = no
UNICODE_ENABLE         = no
SPACE_CADET_ENABLE     = no
GRAVE_ESC_ENABLE       = no
AUDIO_ENABLE 	       = no

VPATH += keyboards/gboards/ # using gboards combo code: see https://combos.gboards.ca/
INTROSPECTION_KEYMAP_C = process_records.c

# Add custom features
SRC += features/mod_lock.c
SRC += features/nshot_mod.c
SRC += features/smart_layer.c
SRC += features/override_keys.c

# Add configuration for built-in features
ifeq ($(strip $(COMBOS_ENABLE)), yes)
	SRC += combos.c
endif
