
#include <iostream>
using namespace std;

int main() {
    int a = 25;

    // Reference must be initialized
    int &refA = a;

    cout << "Original Value: " << refA << endl;

    // Const reference can bind to a temporary
    const int &refLiteral = 100;

    cout << "Literal Value: " << refLiteral << endl;

    double pi = 3.14159;

    // Non-const reference to double
    double &refPi = pi;

    cout << "PI Value: " << refPi << endl;

    // Const reference cannot modify the original value
    const int constantRef = 50;
    cout << "Constant Value: " << constantRef << endl;

    // Reference modification
    refA = 35;

    cout << "Updated a: " << a << endl;

    return 0;
}
