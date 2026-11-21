
#include <iostream>
using namespace std;

class Engine;
class TelemetryAuditor;

class Engine {
private:
    int temperature;
    int rpm;

public:
    Engine(int t, int r) {
        temperature = t;
        rpm = r;
    }

    friend void inspectDiagnostics(
        Engine e, TelemetryAuditor a
    );
};

class TelemetryAuditor {
private:
    int alertThreshold;

public:
    TelemetryAuditor(int threshold) {
        alertThreshold = threshold;
    }

    friend void inspectDiagnostics(
        Engine e, TelemetryAuditor a
    );
};

void inspectDiagnostics(Engine e, TelemetryAuditor a) {
    if (e.temperature > a.alertThreshold) {
        cout << "Warning: Engine Overheat!" << endl;
    }
    else {
        cout << "Engine operating normally at "
             << e.rpm << " RPM." << endl;
    }
}

int main() {
    Engine v8(105, 3200);
    TelemetryAuditor audit(100);

    inspectDiagnostics(v8, audit);

    return 0;
}
