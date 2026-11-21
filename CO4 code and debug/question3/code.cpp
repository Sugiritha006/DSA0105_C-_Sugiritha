
#include <iostream>
using namespace std;

class Vehicle {
public:
    int maxSpeed;

    Vehicle(int speed) {
        maxSpeed = speed;
    }

    void honk() {
        cout << "General Horn" << endl;
    }
};

class SportsCar : public Vehicle {
public:
    bool turboEnabled;

    SportsCar(int speed, bool turbo)
        : Vehicle(speed), turboEnabled(turbo) {
    }

    void engageTurbo() {
        cout << "Turbo Engaged!" << endl;
    }
};

int main() {
    Vehicle *vPtr = new SportsCar(300, true);

    vPtr->honk();

    SportsCar *sportsPtr =
        dynamic_cast<SportsCar*>(vPtr);

    if (sportsPtr != nullptr) {
        sportsPtr->engageTurbo();
    }

    SportsCar car(250, true);

    Vehicle plainVehicle = car;

    cout << "Sliced Vehicle Speed: "
         << plainVehicle.maxSpeed << endl;

    delete vPtr;

    return 0;
}
