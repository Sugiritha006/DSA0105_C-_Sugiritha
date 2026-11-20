
#include <iostream>
using namespace std;

class TaxCalculationEngine {
private:
    double grossAnnualSalary;
    double deduction80C;
    double deductionHealth;

public:
    void getData() {
        cout << "Enter Gross Annual Salary: ";
        cin >> grossAnnualSalary;

        cout << "Enter 80C Deduction: ";
        cin >> deduction80C;

        cout << "Enter Health Insurance Deduction: ";
        cin >> deductionHealth;
    }

    void calculateTax() {
        double totalDeduction = deduction80C + deductionHealth;

        double taxableIncome =
            grossAnnualSalary - totalDeduction;

        if (taxableIncome < 0)
            taxableIncome = 0;

        double tax = 0;

        if (taxableIncome <= 250000) {
            tax = 0;
        }
        else if (taxableIncome <= 500000) {
            tax = taxableIncome * 0.05;
        }
        else if (taxableIncome <= 1000000) {
            tax = 12500 + (taxableIncome - 500000) * 0.20;
        }
        else {
            tax = 112500 + (taxableIncome - 1000000) * 0.30;
        }

        double cess = tax * 0.04;
        double finalTax = tax + cess;

        int roundedTax = static_cast<int>(finalTax + 0.5);

        cout << "\nTaxable Income: " << taxableIncome << endl;
        cout << "Income Tax: " << tax << endl;
        cout << "Cess: " << cess << endl;
        cout << "Final Tax: " << roundedTax << endl;
    }
};

int main() {
    TaxCalculationEngine employee;

    employee.getData();
    employee.calculateTax();

    return 0;
}
