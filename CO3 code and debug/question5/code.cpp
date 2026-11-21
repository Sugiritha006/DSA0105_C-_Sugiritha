
#include <iostream>
using namespace std;

class MathVector {
public:
    double x, y;

    MathVector(double a, double b) {
        x = a;
        y = b;
    }

    // Member function for dot product
    double operator*(const MathVector& other) const {
        return (x * other.x) + (y * other.y);
    }

    // Equality operator
    bool operator==(const MathVector& other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    MathVector v1(2.0, 3.0);
    MathVector v2(2.0, 3.0);

    cout << "Dot Product: " << v1 * v2 << endl;

    if (v1 == v2) {
        cout << "Vectors are Equal" << endl;
    }
    else {
        cout << "Vectors are Not Equal" << endl;
    }

    return 0;
}
