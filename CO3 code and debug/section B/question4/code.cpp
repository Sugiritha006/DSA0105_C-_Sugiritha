
#include <iostream>
using namespace std;

class Polynomial {
private:
    int degree;
    double *coeffArray;

public:
    Polynomial(int d) {
        degree = d;
        coeffArray = new double[degree + 1];

        for (int i = 0; i <= degree; i++) {
            coeffArray[i] = 0;
        }
    }

    Polynomial(const Polynomial& p) {
        degree = p.degree;
        coeffArray = new double[degree + 1];

        for (int i = 0; i <= degree; i++) {
            coeffArray[i] = p.coeffArray[i];
        }
    }

    ~Polynomial() {
        delete[] coeffArray;
    }

    double& operator[](int index) {
        if (index < 0 || index > degree) {
            throw out_of_range("Invalid index");
        }

        return coeffArray[index];
    }

    Polynomial operator+(const Polynomial& p) const {
        int maxDegree = degree > p.degree
                      ? degree : p.degree;

        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; i++) {
            double a = (i <= degree) ? coeffArray[i] : 0;
            double b = (i <= p.degree) ? p.coeffArray[i] : 0;

            result.coeffArray[i] = a + b;
        }

        return result;
    }

    void display() const {
        for (int i = degree; i >= 0; i--) {
            cout << coeffArray[i];

            if (i > 0)
                cout << "x^" << i << " + ";
        }

        cout << endl;
    }
};

int main() {
    Polynomial p1(2);
    Polynomial p2(2);

    // 3x^2 + 2x + 5
    p1[2] = 3;
    p1[1] = 2;
    p1[0] = 5;

    // 4x^2 + 7x + 2
    p2[2] = 4;
    p2[1] = 7;
    p2[0] = 2;

    Polynomial sum = p1 + p2;

    cout << "First Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    cout << "Sum: ";
    sum.display();

    return 0;
}
