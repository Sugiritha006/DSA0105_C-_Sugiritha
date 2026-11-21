
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    // Friend function for stream insertion
    friend ostream& operator<<(ostream& out,
                               const Fraction& f);
};

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

int main() {
    Fraction f(3, 4);

    cout << "Fraction: " << f << endl;

    return 0;
}
