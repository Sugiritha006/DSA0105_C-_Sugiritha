
#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Enter a positive integer: ";
    cin >> N;

    while (N <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        cin >> N;
    }

    int sum = 0;

    cout << "Divisors: ";

    for (int i = 1; i <= N / i; i++) {
        if (N % i != 0)
            continue;

        cout << i << " ";
        sum += i;

        if (i != N / i) {
            cout << N / i << " ";
            sum += N / i;
        }
    }

    cout << "\nSum of Divisors: " << sum << endl;

    if (sum == 2 * N)
        cout << "Perfect Number" << endl;
    else if (sum > 2 * N)
        cout << "Abundant Number" << endl;
    else
        cout << "Deficient Number" << endl;

    return 0;
}
