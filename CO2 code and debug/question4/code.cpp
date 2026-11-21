
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;

public:
    Student(int r, string n) {
        rollNumber = r;
        name = n;
    }

    void display() const {
        cout << "Roll: " << rollNumber
             << ", Name: " << name << endl;
    }
};

int main() {
    Student batch[3] = {
        Student(101, "Aarav"),
        Student(102, "Bhavna"),
        Student(103, "Chirag")
    };

    for (int i = 0; i < 3; i++) {
        batch[i].display();
    }

    return 0;
}
