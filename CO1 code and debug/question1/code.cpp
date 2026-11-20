
#include <iostream>
using namespace std;

int main() {
    unsigned char num = 15;

    if ((num & 1) && (num > 10)) {
        cout << "Valid Odd Number" << endl;
    } else {
        cout << "Condition Failed" << endl;
    }

    for (int i = 3; i >= 0; i--) {
        cout << i << " ";
    }

    return 0;
}
