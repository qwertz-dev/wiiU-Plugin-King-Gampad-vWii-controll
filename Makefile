TARGET		:= King-Gamepad-vWii
SOURCES		:= source
INCLUDES	:= include

# Verknüpft das GamePad (vpad) direkt mit deinem Plugin
LIBS		:= -lwups -lvpad -lcoreinit -lwut

include $(WUT_ROOT)/share/wut_rules
include $(DEVKITPRO)/wups/share/wups_rules

all: $(TARGET).wps
