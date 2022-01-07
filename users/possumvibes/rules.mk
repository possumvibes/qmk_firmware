VPATH += keyboards/gboards/ # using gboards combo code: see https://combos.gboards.ca/

# let's save some space
LTO_ENABLE 				= yes   # Longer compile, smaller file; disables deprecated functionality

SPACE_CADET_ENABLE 		= no	# Enable space cadet shift
GRAVE_ESC_ENABLE   		= no	# Enable grave escape
MAGIC_ENABLE       		= no	# Enable magic keys
AUDIO_ENABLE 			= no

# Apply userspace keymap only to boards explicitly requesting it
ifeq ($(strip $(APPLY_USERSPACE)), yes)

# Add process_record content
	SRC += possumvibes.c
	SRC += process_records.c
	ifeq ($(strip $(COMBOS_ENABLE)), yes)
		SRC += combos.c
	endif

	ifeq ($(strip $(ENCODER_ENABLE)), yes)
		SRC += encoders.c
	endif

	SRC += tap_holds.c

# Add custom features
	SRC += features/mod_lock.c
	SRC += features/nshot_mod.c
	SRC += features/smart_layer.c
	SRC += features/swapper.c
endif
