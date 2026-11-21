
#include <iostream>
using namespace std;

class RegisterBank {
private:
    int registers[8];
    int errorSink;

public:
    RegisterBank() {
        errorSink = -1;

        for (int i = 0; i < 8; i++) {
            registers[i] = 0;
        }
    }

    int& getRegister(int index) {
        if (index >= 0 && index < 8) {
            return registers[index];
        }

        return errorSink;
    }

    void displayStatus() {
        cout << "Register Values (Hex): ";

        for (int i = 0; i < 8; i++) {
            cout << hex << registers[i] << " ";
        }

        cout << dec << endl;
    }
};

int main() {
    RegisterBank bank;

    bank.getRegister(2) = 25;
    bank.getRegister(5) = 255;

    cout << "Register 2: "
         << bank.getRegister(2) << endl;

    cout << "Register 5: "
         << bank.getRegister(5) << endl;

    bank.getRegister(10) = 100;

    cout << "Out-of-bounds operation handled." << endl;

    bank.displayStatus();

    return 0;
}
