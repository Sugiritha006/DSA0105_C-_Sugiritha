#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

class Staff
{
protected:
    std::string name;
    int id;
    double basic;

public:
    Staff(const std::string& n, int i, double b)
        : name(n), id(i), basic(b)
    {
    }

    virtual ~Staff() = default;

    virtual double pay() const = 0;

    void print() const
    {
        std::cout << std::left
                  << std::setw(15) << name
                  << std::setw(8) << id
                  << std::fixed
                  << std::setprecision(2)
                  << pay()
                  << '\n';
    }
};

class Professor : public Staff
{
private:
    double research;

public:
    Professor(const std::string& n,
              int i,
              double b,
              double r)
        : Staff(n, i, b),
          research(r)
    {
    }

    double pay() const override
    {
        constexpr double DA_RATE = 0.42;

        return basic +
               basic * DA_RATE +
               research;
    }
};

class LabAssistant : public Staff
{
public:
    LabAssistant(const std::string& n,
                 int i,
                 double b)
        : Staff(n, i, b)
    {
    }

    double pay() const override
    {
        constexpr double DA_RATE = 0.42;

        return basic +
               basic * DA_RATE;
    }
};

class GuestFaculty : public Staff
{
private:
    double hours;
    double rate;

public:
    GuestFaculty(const std::string& n,
                 int i,
                 double h,
                 double r)
        : Staff(n, i, 0.0),
          hours(h),
          rate(r)
    {
    }

    double pay() const override
    {
        return hours * rate;
    }
};

int main()
{
    std::vector<std::unique_ptr<Staff>> staff;

    staff.push_back(
        std::make_unique<Professor>(
            "Anita", 101, 60000, 10000));

    staff.push_back(
        std::make_unique<LabAssistant>(
            "Bala", 102, 30000));

    staff.push_back(
        std::make_unique<GuestFaculty>(
            "Chitra", 103, 40, 1000));

    std::cout
        << std::left
        << std::setw(15) << "Name"
        << std::setw(8) << "ID"
        << "Pay\n";

    std::cout
        << "--------------------------------\n";

    for (const auto& employee : staff)
    {
        employee->print();
    }

    return 0;
}
