TARGET		:= King-Gamepad-vWii
SOURCES		:= source
include $(WUT_ROOT)/share/wut_rules
include $(DEVKITPRO)/wups/share/wups_rules
all: $(TARGET).wps
