
#include <iostream>
using namespace std;

class Person {
public:
    int idNumber;

    Person(int id) {
        idNumber = id;
        cout << "Person initialized: " << idNumber << endl;
    }
};

class Student : virtual public Person {
public:
    Student(int id) : Person(id) {}
};

class Employee : virtual public Person {
public:
    Employee(int id) : Person(id) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int id1, int id2, int mainID)
        : Person(mainID), Student(id1), Employee(id2) {
    }
};

int main() {
    TeachingAssistant ta(101, 202, 303);

    cout << "TA ID: " << ta.idNumber << endl;

    return 0;
}
