#include <iostream>
#include <string>

class Address
{
private:
    std::string city;
    int pin;

public:
    Address(const std::string& c,
            int p)
        : city(c),
          pin(p)
    {
        std::cout
            << "Address constructed\n";
    }

    ~Address()
    {
        std::cout
            << "Address destroyed\n";
    }

    std::string str() const
    {
        return city +
               "-" +
               std::to_string(pin);
    }
};

class Course
{
private:
    std::string code;
    std::string title;

public:
    Course(const std::string& c,
           const std::string& t)
        : code(c),
          title(t)
    {
        std::cout
            << "Course constructed\n";
    }

    ~Course()
    {
        std::cout
            << "Course destroyed\n";
    }

    void print() const
    {
        std::cout
            << code << " - "
            << title;
    }
};

class Person
{
protected:
    std::string name;
    int age;
    Address home;

public:
    Person(const std::string& n,
           int a,
           const Address& addr)
        : name(n),
          age(a),
          home(addr)
    {
        std::cout
            << "Person constructed\n";
    }

    virtual ~Person()
    {
        std::cout
            << "Person destroyed\n";
    }
};

class Student : public Person
{
private:
    long long regNo;
    Course course;

public:
    Student(const std::string& n,
            int a,
            const Address& addr,
            long long r,
            const Course& c)
        : Person(n, a, addr),
          regNo(r),
          course(c)
    {
        std::cout
            << "Student constructed\n";
    }

    ~Student() override
    {
        std::cout
            << "Student destroyed\n";
    }

    void print() const
    {
        std::cout
            << "\nStudent Details\n";

        std::cout
            << "Register No: "
            << regNo
            << '\n';

        std::cout
            << "Name: "
            << name
            << '\n';

        std::cout
            << "Age: "
            << age
            << '\n';

        std::cout
            << "Address: "
            << home.str()
            << '\n';

        std::cout
            << "Course: ";

        course.print();

        std::cout << '\n';
    }
};

class Staff : public Person
{
private:
    std::string department;

public:
    Staff(const std::string& n,
          int a,
          const Address& addr,
          const std::string& dept)
        : Person(n, a, addr),
          department(dept)
    {
        std::cout
            << "Staff constructed\n";
    }

    ~Staff() override
    {
        std::cout
            << "Staff destroyed\n";
    }
};

int main()
{
    Address address(
        "Salem",
        636001
    );

    Course course(
        "CS301",
        "Object Oriented Programming"
    );

    std::cout
        << "\nCreating Student...\n";

    {
        Student s(
            "Kavya",
            19,
            address,
            192311001,
            course
        );

        s.print();

        std::cout
            << "\nLeaving block...\n";
    }

    std::cout
        << "\nCreating Staff...\n";

    {
        Staff staff(
            "Ravi",
            40,
            address,
            "Computer Science"
        );
    }

    return 0;
}
