
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accHolder;
    double balance;

    static double totalBankReserves;

public:
    BankAccount(string name, double initialDeposit) {
        accHolder = name;
        balance = initialDeposit;
        totalBankReserves += initialDeposit;
    }

    static void displayAudit() {
        cout << "Total Reserves in Vault: Rs. "
             << totalBankReserves << endl;
    }

    void displayAccount() {
        cout << "Account Holder: " << accHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

double BankAccount::totalBankReserves = 0.0;

int main() {
    BankAccount acc1("Alice", 5000.0);
    BankAccount acc2("Bob", 3000.0);

    acc1.displayAccount();
    acc2.displayAccount();

    BankAccount::displayAudit();

    return 0;
}
