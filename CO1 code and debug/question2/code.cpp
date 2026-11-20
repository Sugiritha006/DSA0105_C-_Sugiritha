
#include <iostream>
using namespace std;

double taxRate = 0.18;

int main() {
    double itemPrice = 1000.0;
    double taxRate = 0.05;

    cout << "Local Tax: " << taxRate << endl;

    double totalWithGlobalTax =
        itemPrice + (itemPrice * ::taxRate);

    cout << "Global Tax Calculation: "
         << totalWithGlobalTax << endl;

    {
        double taxRate = 0.12;

        double totalWithLocalTax =
            itemPrice + (itemPrice * taxRate);

        cout << "Inner Local Tax: "
             << totalWithLocalTax << endl;
    }

    cout << "Final Global Calculation: "
         << itemPrice + (itemPrice * ::taxRate)
         << endl;

    return 0;
}
