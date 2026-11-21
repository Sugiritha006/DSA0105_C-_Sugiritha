
#include <iostream>
#include <cstring>
using namespace std;

class DynStr {
private:
    char *dataPtr;
    int charCount;

public:
    DynStr(const char *str = "") {
        charCount = strlen(str);
        dataPtr = new char[charCount + 1];
        strcpy(dataPtr, str);
    }

    // Deep copy constructor
    DynStr(const DynStr &other) {
        charCount = other.charCount;
        dataPtr = new char[charCount + 1];
        strcpy(dataPtr, other.dataPtr);
    }

    // Destructor
    ~DynStr() {
        delete[] dataPtr;
    }

    DynStr operator+(const DynStr &other) const {
        int newLength = charCount + other.charCount;

        char *temp = new char[newLength + 1];

        strcpy(temp, dataPtr);
        strcat(temp, other.dataPtr);

        DynStr result(temp);

        delete[] temp;

        return result;
    }

    void display() const {
        cout << dataPtr << endl;
    }
};

int main() {
    DynStr strA("Hello ");
    DynStr strB("World!");

    DynStr strC = strA + strB;

    cout << "First String: ";
    strA.display();

    cout << "Second String: ";
    strB.display();

    cout << "Concatenated String: ";
    strC.display();

    return 0;
}
