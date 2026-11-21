
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeID;
    string name;

public:
    Employee(string id, string n) {
        employeeID = id;
        name = n;
    }

    virtual double calculatePay() = 0;

    virtual void displayHeader() {
        cout << employeeID << " - " << name << endl;
    }

    virtual ~Employee() {}
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string id, string n, double salary)
        : Employee(id, n) {
        monthlySalary = salary;
    }

    double calculatePay() override {
        return monthlySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;

public:
    HourlyEmployee(string id, string n,
                   double wage, int hours)
        : Employee(id, n) {
        hourlyWage = wage;
        hoursWorked = hours;
    }

    double calculatePay() override {
        double regular = 40 * hourlyWage;
        double overtime = 0;

        if (hoursWorked > 40) {
            overtime = (hoursWorked - 40) *
                       hourlyWage * 1.5;
        }
        else {
            regular = hoursWorked * hourlyWage;
        }

        return regular + overtime;
    }
};

int main() {
    Employee *employees[2];

    employees[0] =
        new SalariedEmployee("E101", "Arun", 50000);

    employees[1] =
        new HourlyEmployee("E102", "Bala", 40, 48);

    double total = 0;

    for (int i = 0; i < 2; i++) {
        employees[i]->displayHeader();

        double pay = employees[i]->calculatePay();

        cout << "Salary: Rs. " << pay << endl;

        total += pay;
        delete employees[i];
    }

    cout << "Total Payroll: Rs. " << total << endl;

    return 0;
}
