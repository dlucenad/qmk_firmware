ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

COMMAND_ENABLE = no

DYNAMIC_TAPPING_TERM_ENABLE = yes

CAPS_WORD_ENABLE = yes