
#include <iostream>
using namespace std;

class Matrix2D {
private:
    int grid[3][3];

public:
    void initialize() {
        cout << "Enter 9 elements: ";

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
            }
        }
    }

    void display() {
        cout << "\nMatrix:\n";

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend int computeCrossTrace(
        Matrix2D A, Matrix2D B
    );
};

int computeCrossTrace(Matrix2D A, Matrix2D B) {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        sum += A.grid[i][i] * B.grid[i][i];
    }

    return sum;
}

int main() {
    Matrix2D A, B;

    cout << "First Matrix:\n";
    A.initialize();

    cout << "Second Matrix:\n";
    B.initialize();

    A.display();
    B.display();

    cout << "Cross Trace: "
         << computeCrossTrace(A, B) << endl;

    return 0;
}
