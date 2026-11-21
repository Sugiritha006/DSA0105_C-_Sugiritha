
#include <iostream>
#include <string>
using namespace std;

inline string formatPrefix(string tag) {
    return "[" + tag + "]";
}

class Logger {
public:
    void logEvent(string message) {
        cout << formatPrefix("INFO")
             << " " << message << endl;
    }

    void logEvent(string message,
                  int severity,
                  string timestamp = "00:00:00") {

        string level;

        switch (severity) {
            case 1: level = "LOW"; break;
            case 2: level = "MEDIUM"; break;
            case 3: level = "CRITICAL"; break;
            default: level = "UNKNOWN";
        }

        cout << "[" << level << " @ "
             << timestamp << "] "
             << message << endl;
    }

    void logHardwareFault(int module,
                          string errorCode) {
        cout << "[HARDWARE_FAULT] Module: "
             << module << " Error Code: "
             << errorCode << endl;
    }
};

int main() {
    Logger logger;

    logger.logEvent("System Started");

    logger.logEvent("High Temperature", 3);

    logger.logEvent("Sensor Warning", 2, "10:30:00");

    logger.logHardwareFault(1, "0xEF");

    return 0;
}
