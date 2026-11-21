
#include <iostream>
using namespace std;

class OutOfBoundsException {
public:
    const char *message() const {
        return "Temperature is outside valid range.";
    }
};

class Telemetry {
public:
    double calculateThermalSensors(
        double voltage, double resistance
    ) {
        if (resistance <= 0) {
            throw OutOfBoundsException();
        }

        return voltage / resistance;
    }

    bool potentialWarning(
        double temperature
    ) noexcept {
        return temperature > 100;
    }

    void commitTelemetry(
        double temperature
    ) noexcept {
        cout << "Telemetry committed: "
             << temperature << endl;
    }
};

int main() {
    Telemetry system;

    try {
        double voltage = 12.0;
        double resistance = 2.0;

        double temperature =
            system.calculateThermalSensors(
                voltage, resistance
            );

        cout << "Calculated Temperature: "
             << temperature << endl;

        if (system.potentialWarning(temperature)) {
            cout << "Warning detected!" << endl;
        }
        else {
            cout << "Temperature Normal." << endl;
        }

        system.commitTelemetry(temperature);
    }

    catch (const OutOfBoundsException &e) {
        cout << "Calibration Error: "
             << e.message() << endl;
    }

    return 0;
}
