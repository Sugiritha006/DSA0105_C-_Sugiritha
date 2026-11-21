
#include <iostream>
#include <string>
using namespace std;

class BranchOffice {
private:
    string branchID;
    string branchName;
    double currentBalance;

    static double totalVaultReserves;
    static int totalBranchesActive;

public:
    BranchOffice(string id, string name, double openingDeposit) {
        branchID = id;
        branchName = name;
        currentBalance = openingDeposit;

        totalVaultReserves += openingDeposit;
        totalBranchesActive++;
    }

    void deposit(double amount) {
        if (amount > 0) {
            currentBalance += amount;
            totalVaultReserves += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= currentBalance) {
            currentBalance -= amount;
            totalVaultReserves -= amount;
            return true;
        }
        return false;
    }

    void displaySummary() {
        cout << branchID << " - " << branchName
             << ": Rs. " << currentBalance << endl;
    }

    static void displayVaultSummary() {
        cout << "Active Branches: "
             << totalBranchesActive << endl;

        cout << "Total Vault Reserves: Rs. "
             << totalVaultReserves << endl;
    }
};

double BranchOffice::totalVaultReserves = 0;
int BranchOffice::totalBranchesActive = 0;

int main() {
    BranchOffice b1("B001", "Chennai", 10000);
    BranchOffice b2("B002", "Coimbatore", 15000);

    b1.deposit(5000);
    b2.withdraw(3000);

    b1.displaySummary();
    b2.displaySummary();

    BranchOffice::displayVaultSummary();

    return 0;
}
