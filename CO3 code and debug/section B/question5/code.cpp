
#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

    // Prefix increment
    Vector2D& operator++() {
        x++;
        y++;
        return *this;
    }

    // Postfix increment
    Vector2D operator++(int) {
        Vector2D temp = *this;
        x++;
        y++;
        return temp;
    }

    // Compound addition
    Vector2D& operator+=(const Vector2D& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(5, 0);
    Vector2D v2(0, 0);

    cout << "Initial v1: ";
    v1.display();

    v2 = ++v1;

    cout << "After Prefix: ";
    v2.display();

    Vector2D v3 = v1++;

    cout << "After Postfix returned value: ";
    v3.display();

    cout << "Current v1: ";
    v1.display();

    v1 += Vector2D(2, 3);

    cout << "After Compound Addition: ";
    v1.display();

    return 0;
}
