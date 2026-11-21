
#include <iostream>
using namespace std;

class StepCounter {
private:
    int steps;

public:
    StepCounter(int s = 0) {
        steps = s;
    }

    // Prefix increment
    StepCounter& operator++() {
        ++steps;
        return *this;
    }

    // Postfix increment
    StepCounter operator++(int) {
        StepCounter temp = *this;
        steps++;
        return temp;
    }

    void display() const {
        cout << "Steps: " << steps << endl;
    }
};

int main() {
    StepCounter c1(10);

    StepCounter c2 = ++c1;
    cout << "After Prefix: ";
    c2.display();

    StepCounter c3 = c1++;
    cout << "After Postfix: ";
    c3.display();

    cout << "Final Counter: ";
    c1.display();

    return 0;
}
