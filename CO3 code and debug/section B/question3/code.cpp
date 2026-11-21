
#include <iostream>
#include <iomanip>
using namespace std;

class Currency {
private:
    int dollars;
    int cents;

    void normalize() {
        dollars += cents / 100;
        cents %= 100;

        if (cents < 0) {
            dollars--;
            cents += 100;
        }
    }

public:
    Currency(int d = 0, int c = 0) {
        dollars = d;
        cents = c;
        normalize();
    }

    // Unary negation
    Currency operator-() const {
        return Currency(-dollars, -cents);
    }

    friend ostream& operator<<(ostream& out,
                               const Currency& c);

    friend istream& operator>>(istream& in,
                               Currency& c);
};

ostream& operator<<(ostream& out, const Currency& c) {
    out << "$" << c.dollars << "."
        << setw(2) << setfill('0') << c.cents
        << setfill(' ');
    return out;
}

istream& operator>>(istream& in, Currency& c) {
    in >> c.dollars >> c.cents;
    c.normalize();
    return in;
}

int main() {
    Currency amount;

    cout << "Enter dollars and cents: ";
    cin >> amount;

    cout << "Original Amount: " << amount << endl;

    Currency negative = -amount;

    cout << "After Negation: " << negative << endl;

    return 0;
}
