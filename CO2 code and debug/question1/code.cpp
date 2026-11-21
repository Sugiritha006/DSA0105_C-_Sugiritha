
#include <iostream>
using namespace std;

int getMaximumScaled(int a, int b, int scaleFactor) {
    int maxVal = (a > b) ? a : b;
    return maxVal * scaleFactor;
}

int& getArrayElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int x = 10, y = 20;

    int result = getMaximumScaled(x, y, 3);

    cout << "Scaled Maximum: " << result << endl;

    int data[3] = {100, 200, 300};

    int &element = getArrayElement(data, 1);
    element = 999;

    cout << "Updated Array: " << data[1] << endl;

    cout << "Array Values: ";
    for (int i = 0; i < 3; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
