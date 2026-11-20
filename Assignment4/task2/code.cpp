#include <iostream>
#include <string>

class Person
{
protected:
    std::string name;
    int id;
    std::string phone;

public:
    Person(const std::string& n,
           int i,
           const std::string& p)
        : name(n),
          id(i),
          phone(p)
    {
    }

    virtual ~Person() = default;

    void printPerson() const
    {
        std::cout
            << name << " "
            << id << " "
            << phone;
    }
};

// Virtual inheritance
class Student : virtual public Person
{
protected:
    std::string programme;
    double cgpa;

public:
    Student(const std::string& n,
            int i,
            const std::string& p,
            const std::string& prog,
            double c)
        : Person(n, i, p),
          programme(prog),
          cgpa(c)
    {
    }

    void printStudent() const
    {
        std::cout
            << "Programme: "
            << programme
            << ", CGPA: "
            << cgpa;
    }
};

// Virtual inheritance
class Staff : virtual public Person
{
protected:
    std::string department;
    double salary;

public:
    Staff(const std::string& n,
          int i,
          const std::string& p,
          const std::string& dept,
          double sal)
        : Person(n, i, p),
          department(dept),
          salary(sal)
    {
    }

    void printStaff() const
    {
        std::cout
            << "Department: "
            << department
            << ", Salary: "
            << salary;
    }
};

// Multiple inheritance
class TeachingAssistant
    : public Student,
      public Staff
{
private:
    std::string subject;

public:
    TeachingAssistant(
        const std::string& n,
        int i,
        const std::string& p,
        const std::string& prog,
        double c,
        const std::string& dept,
        double sal,
        const std::string& sub)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, sal),
          subject(sub)
    {
    }

    void print() const
    {
        std::cout << "\nTeaching Assistant\n";

        printPerson();

        std::cout
            << "\n";

        printStudent();

        std::cout
            << "\n";

        printStaff();

        std::cout
            << "\nSubject: "
            << subject
            << '\n';
    }
};

// ResearchScholar is a Student
// with additional fellowship information.
class ResearchScholar : public Student
{
private:
    double fellowship;

public:
    ResearchScholar(
        const std::string& n,
        int i,
        const std::string& p,
        const std::string& prog,
        double c,
        double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f)
    {
    }

    void print() const
    {
        std::cout
            << "\nResearch Scholar\n";

        printPerson();

        std::cout << '\n';

        printStudent();

        std::cout
            << ", Fellowship: "
            << fellowship
            << '\n';
    }
};

int main()
{
    TeachingAssistant ta(
        "Kavya",
        101,
        "9876543210",
        "CSE",
        8.7,
        "Computer Science",
        45000,
        "OOP"
    );

    ResearchScholar scholar(
        "Rahul",
        102,
        "9123456780",
        "CSE",
        9.1,
        30000
    );

    ta.print();
    scholar.print();

    return 0;
}
