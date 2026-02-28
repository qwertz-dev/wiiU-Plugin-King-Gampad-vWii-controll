TARGET		:= King-Gamepad-vWii
SOURCES		:= source
INCLUDES	:= include

# Diese Zeile löst den Error 1 in deinem Paket:
LIBS		:= -lwups -lvpad -lcoreinit -lwut

include $(WUT_ROOT)/share/wut_rules
include $(DEVKITPRO)/wups/share/wups_rules

all: $(TARGET).wps
