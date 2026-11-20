
#include <iostream>
using namespace std;

int main() {
    unsigned int statusRegister;

    cout << "Enter hexadecimal status register: ";
    cin >> hex >> statusRegister;

    unsigned int mandatoryMask = 0x07;
    unsigned int inhibitorMask = 0xB0;

    bool mandatoryOK =
        (statusRegister & mandatoryMask) == mandatoryMask;

    bool inhibitorsOK =
        (statusRegister & inhibitorMask) == 0;

    if (mandatoryOK && inhibitorsOK) {
        cout << "Flight Ready" << endl;
    }
    else {
        cout << "Flight Not Ready" << endl;

        if (!mandatoryOK)
            cout << "Mandatory sensor missing" << endl;

        if (!inhibitorsOK)
            cout << "Warning or failure detected" << endl;
    }

    if (statusRegister & 0x40)
        cout << "Radio Telemetry Link Active" << endl;

    return 0;
}
