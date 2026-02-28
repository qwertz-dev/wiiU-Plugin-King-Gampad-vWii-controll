TARGET		:= King-Gamepad-vWii
SOURCES		:= source
INCLUDES	:= include

# Wir nutzen nur die Basis, damit der Linker nicht abbricht.
LIBS		:= -lwups -lwut

include $(WUT_ROOT)/share/wut_rules
include $(DEVKITPRO)/wups/share/wups_rules

all: $(TARGET).wps
