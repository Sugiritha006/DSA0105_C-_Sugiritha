
#include <iostream>
using namespace std;

int main() {
    const int correctPIN = 4821;
    int enteredPIN;
    int attempts = 0;

    double balance = 5000.0;
    int choice;

    cout << "Enter PIN: ";
    cin >> enteredPIN;

    while (enteredPIN != correctPIN && attempts < 2) {
        attempts++;

        cout << "Incorrect PIN. Try again: ";
        cin >> enteredPIN;
    }

    if (enteredPIN != correctPIN) {
        cout << "Card Locked. Too many attempts." << endl;
        return 0;
    }

    cout << "\nAuthentication Successful!" << endl;

    do {
        cout << "\n1. Balance Inquiry";
        cout << "\n2. Cash Deposit";
        cout << "\n3. Cash Withdrawal";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Available Balance: Rs. "
                     << balance << endl;
                break;

            case 2: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit Successful!" << endl;
                }
                else {
                    cout << "Invalid Amount!" << endl;
                }
                break;
            }

            case 3: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount <= 0 || amount > balance) {
                    cout << "Invalid or Insufficient Balance!" << endl;
                }
                else if (static_cast<int>(amount) % 100 != 0) {
                    cout << "Amount must be a multiple of 100." << endl;
                }
                else {
                    balance -= amount;
                    cout << "Withdrawal Successful!" << endl;
                    cout << "Remaining Balance: Rs. "
                         << balance << endl;
                }
                break;
            }

            case 4:
                cout << "Thank you for using ATM!" << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
        }

    } while (choice != 4);

    return 0;
}
