
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ResourceGuard {
public:
    ResourceGuard() {
        cout << "Resource Guard Acquired." << endl;
    }

    ~ResourceGuard() {
        cout << "Resource Guard Released." << endl;
    }
};

class CRCValidationException {
public:
    string message;

    CRCValidationException(string msg) {
        message = msg;
    }
};

void ingestDataStream(string fileName) {
    ResourceGuard guard;

    ifstream file(fileName);

    if (!file) {
        throw CRCValidationException(
            "Unable to open input file."
        );
    }

    int expectedCRC = 1234;
    int calculatedCRC = 5678;

    cout << "Reading data blocks..." << endl;

    if (expectedCRC != calculatedCRC) {
        throw CRCValidationException(
            "CRC checksum mismatch."
        );
    }

    cout << "Data validated successfully." << endl;
}

int main() {
    try {
        ingestDataStream("input.txt");
    }

    catch (const CRCValidationException &e) {
        cout << "CRC Error: "
             << e.message << endl;
    }

    return 0;
}
