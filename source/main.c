#include <wups.h>
#include <vpad/input.h>
#include <coreinit/screen.h>

WUPS_PLUGIN_NAME("King-Gamepad-vWii");
WUPS_PLUGIN_DESCRIPTION("GamePad emuliert Wii Remote (Touch/Gyro)");
WUPS_PLUGIN_VERSION("1.0");
WUPS_PLUGIN_AUTHOR("King");
WUPS_PLUGIN_LICENSE("GPL");

// Diese Funktion verarbeitet die GamePad-Daten
void update_king_controls(VPADStatus *vpad) {
    // TOUCH -> POINTER LOGIK
    if (vpad->tpNormal.touched) {
        // Hier wird der Screen-Punkt berechnet
    }
    
    // GYRO -> NEIGUNG (Lenken)
    float tilt = vpad->gyro.x;
}

INITIALIZE_PLUGIN() {
}

DEINITIALIZE_PLUGIN() {
}

// Hier wird das GamePad-Signal abgefangen
WUPS_MUST_REPLACE(VPADRead, WUPS_LOADER_LIBRARY_VPAD, VPADRead) {
    VPADReadError result = WUPS_CALL_ORIGINAL(VPADRead, chan, buffers, count, error);
    if (result == VPAD_READ_SUCCESS && chan == VPAD_CHAN_0) {
        update_king_controls(&buffers[0]);
    }
    return result;
}
