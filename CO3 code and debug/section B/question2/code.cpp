
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r) {
        real = r;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    void display() const {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 4);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    return 0;
}
