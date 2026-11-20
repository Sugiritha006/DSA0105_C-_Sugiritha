
#include <iostream>
#include <string>
using namespace std;

class WaterConsumer {
private:
    string consumerID;
    double previousReading;
    double currentReading;
    double unitsConsumed;
    double totalBill;

public:
    void initialize(string id, double prev, double curr) {
        consumerID = id;
        previousReading = prev;
        currentReading = curr;
        unitsConsumed = 0;
        totalBill = 0;
    }

    void calculateConsumption() {
        if (currentReading < previousReading ||
            previousReading < 0) {
            cout << "Invalid meter readings!" << endl;
            return;
        }

        unitsConsumed = currentReading - previousReading;

        if (unitsConsumed <= 100) {
            totalBill = unitsConsumed * 1.50;
        }
        else if (unitsConsumed <= 300) {
            totalBill = (100 * 1.50) +
                        ((unitsConsumed - 100) * 2.50);
        }
        else {
            totalBill = (100 * 1.50) +
                        (200 * 2.50) +
                        ((unitsConsumed - 300) * 4.00);

            totalBill += totalBill * 0.10;
        }
    }

    void displayBill() {
        cout << "\nConsumer ID: " << consumerID << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
        cout << "Total Bill: Rs. " << totalBill << endl;
    }
};

int main() {
    WaterConsumer consumer;

    string id;
    double previous, current;

    cout << "Enter Consumer ID: ";
    cin >> id;

    cout << "Enter Previous Reading: ";
    cin >> previous;

    cout << "Enter Current Reading: ";
    cin >> current;

    consumer.initialize(id, previous, current);
    consumer.calculateConsumption();
    consumer.displayBill();

    return 0;
}
