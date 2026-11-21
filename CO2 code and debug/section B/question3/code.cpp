
#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
private:
    int rollNo;
    string studentName;
    float marks[3];
    float percentage;
    char grade;

public:
    void readData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Student Name: ";
        cin >> studentName;

        cout << "Enter 3 subject marks: ";

        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void calculateResult() {
        float total = 0;

        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }

        percentage = total / 3.0;

        if (percentage >= 85)
            grade = 'A';
        else if (percentage >= 70)
            grade = 'B';
        else if (percentage >= 50)
            grade = 'C';
        else
            grade = 'F';
    }

    float getPercentage() {
        return percentage;
    }

    void display() {
        cout << rollNo << " "
             << studentName << " "
             << percentage << "% "
             << grade << endl;
    }
};

int main() {
    StudentRecord students[3];

    for (int i = 0; i < 3; i++) {
        students[i].readData();
        students[i].calculateResult();
    }

    // Bubble sort in descending percentage order
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (students[j].getPercentage() <
                students[j + 1].getPercentage()) {

                StudentRecord temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "\nRank List:\n";

    for (int i = 0; i < 3; i++) {
        students[i].display();
    }

    return 0;
}
