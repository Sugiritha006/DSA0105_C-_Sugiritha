
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int personID;
    string fullName;

public:
    Person(int id, string name) {
        personID = id;
        fullName = name;
    }
};

class Student : virtual public Person {
protected:
    double gpa;
    double creditsEarned;

public:
    Student(int id, string name, double g, double c)
        : Person(id, name) {
        gpa = g;
        creditsEarned = c;
    }
};

class Faculty : virtual public Person {
protected:
    string department;
    string rankTitle;

public:
    Faculty(int id, string name, string dept, string rank)
        : Person(id, name) {
        department = dept;
        rankTitle = rank;
    }
};

class TeachingAssistant : public Student, public Faculty {
private:
    double stipendAmount;

public:
    TeachingAssistant(int id, string name,
                      double gpaValue, double credits,
                      string dept, string rank,
                      double stipend)
        : Person(id, name),
          Student(id, name, gpaValue, credits),
          Faculty(id, name, dept, rank) {
        stipendAmount = stipend;
    }

    void displayTARecord() {
        cout << "Person ID: " << personID << endl;
        cout << "Name: " << fullName << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Credits: " << creditsEarned << endl;
        cout << "Department: " << department << endl;
        cout << "Rank: " << rankTitle << endl;
        cout << "Stipend: Rs. " << stipendAmount << endl;
    }
};

int main() {
    TeachingAssistant ta(
        101, "Arun", 8.5, 90,
        "Computer Science", "Assistant", 15000
    );

    ta.displayTARecord();

    return 0;
}
