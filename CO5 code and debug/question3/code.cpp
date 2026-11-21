
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseError : public exception {
protected:
    string errorDetails;

public:
    DatabaseError(string msg) {
        errorDetails = msg;
    }

    const char* what() const noexcept override {
        return errorDetails.c_str();
    }
};

class TimeoutError : public DatabaseError {
public:
    int timeoutMs;

    TimeoutError(string msg, int ms)
        : DatabaseError(msg) {
        timeoutMs = ms;
    }
};

void executeQuery() {
    throw TimeoutError("Query timed out", 5000);
}

void intermediateAuditor() {
    try {
        executeQuery();
    }
    catch (const DatabaseError &e) {
        cout << "AUDIT LOG: " << e.what() << endl;

        // Rethrow original exception
        throw;
    }
}

int main() {
    try {
        intermediateAuditor();
    }

    catch (const TimeoutError &e) {
        cout << "Client caught TimeoutError: "
             << e.what() << endl;

        cout << "Timeout: "
             << e.timeoutMs << " ms" << endl;
    }

    catch (const DatabaseError &e) {
        cout << "Client caught generic DatabaseError: "
             << e.what() << endl;
    }

    return 0;
}
