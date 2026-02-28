#include <wups.h>
#include <vpad/input.h>
#include <coreinit/screen.h>
#include <vcore/vcore.h> // Wichtig für die vWii-Kommunikation

WUPS_PLUGIN_NAME("King-Gamepad-vWii");
WUPS_PLUGIN_DESCRIPTION("GamePad als vWii Remote (Touch & Gyro)");
WUPS_PLUGIN_VERSION("1.0");
WUPS_PLUGIN_AUTHOR("King");
WUPS_PLUGIN_LICENSE("GPL");

// Variablen für die Pointer-Glättung
static float last_x = 0.5f;
static float last_y = 0.5f;

/**
 * Kern-Logik: Wandelt GamePad-Eingaben in vWii-Signale um
 */
void update_king_controller() {
    VPADStatus vpad;
    VPADReadError error;
    VPADRead(VPAD_CHAN_0, &vpad, 1, &error);

    if (error != VPAD_READ_SUCCESS) return;

    // 1. TOUCHSCREEN ZU WII-POINTER (Ohne Sensorleiste)
    if (vpad.tpNormal.touched) {
        last_x = vpad.tpNormal.x;
        last_y = vpad.tpNormal.y;
        
        // Hier wird der vWii mitgeteilt, wo der Zeiger ist
        vCoreSetIRPointer(0, last_x, last_y);
    }

    // 2. GYRO ZU WII-TILT (Für Rennspiele wie Mario Kart Wii)
    if (vpad.gyro.x != 0.0f || vpad.gyro.y != 0.0f) {
        // Nutzt die Neigung des GamePads für die vWii Lenkung
        vCoreSetGyroTilt(0, vpad.gyro.x, vpad.gyro.y, vpad.gyro.z);
    }

    // 3. BUTTON-MAPPING (Gamepad Buttons -> Wii Remote)
    if (vpad.hold & VPAD_BUTTON_A) vCoreSetButton(0, BUTTON_A, true);
    if (vpad.hold & VPAD_BUTTON_B) vCoreSetButton(0, BUTTON_B, true);
}

/**
 * Das Plugin in den vWii-Prozess einklinken
 */
INITIALIZE_PLUGIN() {
    // Initialisiert die vWii-Schnittstelle ohne echte Remote
    vCoreInit();
}

// Wird jeden Frame im Hintergrund ausgeführt
WUPS_ON_LOGGING_STATUS_CHANGED(bool enabled) {
    if (enabled) {
        update_king_controller();
    }
}

DEINITIALIZE_PLUGIN() {
    vCoreExit();
}
