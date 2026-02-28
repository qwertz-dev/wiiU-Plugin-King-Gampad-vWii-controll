#include <wups.h>

/**
 * Ohne diese Zeilen gibt es immer Error 1.
 * Wir halten es extrem simpel für den ersten Erfolg.
 */
WUPS_PLUGIN_NAME("King-Gamepad-vWii");
WUPS_PLUGIN_DESCRIPTION("vWii GamePad Test");
WUPS_PLUGIN_VERSION("1.0");
WUPS_PLUGIN_AUTHOR("King");
WUPS_PLUGIN_LICENSE("GPL");

INITIALIZE_PLUGIN() {
    // Erst mal leer lassen, um Error 1 zu besiegen!
}

DEINITIALIZE_PLUGIN() {
}
