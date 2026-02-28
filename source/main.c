#include <wups.h>
#include <vpad/input.h>

/**
 * King GamePad vWii Controller
 * Das ultimative Plugin für vWii-Freiheit.
 */

WUPS_MUST_REPLACE(VPADRead, WUPS_LOADER_LIBRARY_VPAD, VPADRead);

int32_t result = VPADRead(VPADChan chan, VPADStatus *buffer, uint32_t count, VPADReadError *error) {
    int32_t res = WUPS_CALL_ORIGINAL(VPADRead, chan, buffer, count, error);

    if (res > 0 && buffer) {
        // TOUCH ZU ZEIGER
        if (buffer->tpNormal.touched) {
            vWiiPointerUpdate(0, buffer->tpNormal.x, buffer->tpNormal.y, 1);
        }

        // TASTEN-MAPPING
        if (buffer->hold & VPAD_BUTTON_A) vWiiButtonUpdate(0, 1, 1);
        if (buffer->hold & VPAD_BUTTON_B) vWiiButtonUpdate(0, 2, 1);
        if (buffer->hold & VPAD_BUTTON_PLUS) vWiiButtonUpdate(0, 10, 1);
        if (buffer->hold & VPAD_BUTTON_MINUS) vWiiButtonUpdate(0, 11, 1);
        if (buffer->hold & VPAD_BUTTON_HOME) vWiiButtonUpdate(0, 12, 1);
    }
    return res;
}
