
#include <iostream>
using namespace std;

int main() {
    int tokenType = 2;
    float tokenValue = 0.0;

    switch (tokenType) {
        case 1: {
            int offset = 10;
            tokenValue = 50.0 + offset;
            break;
        }

        case 2: {
            int multiplier = 5;
            tokenValue = 20.0 * multiplier;
            break;
        }

        case 3:
            tokenValue = 100.0;
            break;

        case 4:
        case 5:
            cout << "Float token detected" << endl;
            break;

        default:
            cout << "Unknown token" << endl;
    }

    cout << "Calculated Value: "
         << tokenValue << endl;

    return 0;
}
