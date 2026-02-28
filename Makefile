TARGET		:= King-Gamepad-vWii
SOURCES		:= source
INCLUDES	:= include

# Das hier löst den Error 1: Wir sagen dem Compiler, welche Tools er nutzen soll
LIBS		:= -lwups -lwut -lvpad -lcoreinit

include $(WUT_ROOT)/share/wut_rules
include $(DEVKITPRO)/wups/share/wups_rules

all: $(TARGET).wps
