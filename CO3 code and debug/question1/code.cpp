
#include <iostream>
#include <cstring>
using namespace std;

class DynamicString {
private:
    char *buffer;
    int length;

public:
    DynamicString(const char *str) {
        length = strlen(str);
        buffer = new char[length + 1];
        strcpy(buffer, str);
    }

    // Correct copy constructor using reference
    DynamicString(const DynamicString &source) {
        length = source.length;
        buffer = new char[length + 1];
        strcpy(buffer, source.buffer);
    }

    ~DynamicString() {
        delete[] buffer;
    }

    void print() const {
        cout << buffer << endl;
    }
};

int main() {
    DynamicString s1("Antigravity C++");

    DynamicString s2 = s1;

    cout << "Original String: ";
    s1.print();

    cout << "Copied String: ";
    s2.print();

    return 0;
}
