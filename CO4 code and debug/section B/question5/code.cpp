
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    int stockCount;

    Product(string n, double p, int s) {
        name = n;
        price = p;
        stockCount = s;
    }

    void display() {
        cout << name << " Rs. " << price
             << " Stock: " << stockCount << endl;
    }
};

int main() {
    Product *catalog[3];

    catalog[0] = new Product("Laptop", 1200, 10);
    catalog[1] = new Product("Mouse", 25, 50);
    catalog[2] = new Product("Monitor", 350, 15);

    cout << "Before Sorting:\n";

    for (int i = 0; i < 3; i++) {
        catalog[i]->display();
    }

    // Sort pointers by price
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (catalog[j]->price > catalog[j + 1]->price) {
                Product *temp = catalog[j];
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = temp;
            }
        }
    }

    cout << "\nAfter Sorting:\n";

    for (int i = 0; i < 3; i++) {
        catalog[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete catalog[i];
    }

    return 0;
}
