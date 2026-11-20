
#include <iostream>
using namespace std;

int main() {
    int size = 5;

    int *readings = new int[size];

    cout << "Enter 5 readings: ";

    for (int i = 0; i < size; i++) {
        cin >> readings[i];
    }

    int total = 0;

    for (int i = 0; i < size; i++) {
        total += readings[i];
    }

    cout << "Total: " << total << endl;

    delete[] readings;

    return 0;
}
