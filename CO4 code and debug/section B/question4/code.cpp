
#include <iostream>
using namespace std;

class Vehicle {
protected:
    int vehicleID;

public:
    Vehicle(int id) {
        vehicleID = id;
        cout << "Vehicle initialized." << endl;
    }

    virtual void displaySpecs() {
        cout << "Vehicle ID: " << vehicleID << endl;
    }

    virtual ~Vehicle() {}
};

class AutonomousVehicle : public Vehicle {
protected:
    string lidarSensor;

public:
    AutonomousVehicle(int id, string lidar)
        : Vehicle(id) {
        lidarSensor = lidar;
        cout << "Autonomous Vehicle initialized." << endl;
    }

    void displaySpecs() override {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Lidar: " << lidarSensor << endl;
    }
};

class DeliveryDrone : public AutonomousVehicle {
private:
    double payloadCapacity;

public:
    DeliveryDrone(int id, string lidar, double payload)
        : AutonomousVehicle(id, lidar) {
        payloadCapacity = payload;
        cout << "Delivery Drone initialized." << endl;
    }

    void displaySpecs() override {
        AutonomousVehicle::displaySpecs();
        cout << "Payload: "
             << payloadCapacity << " kg" << endl;
    }

    void displayFlightTelemetry() {
        cout << "Drone Flight Telemetry Active." << endl;
    }
};

int main() {
    Vehicle *ptr =
        new DeliveryDrone(101, "Lidar-X", 5.5);

    ptr->displaySpecs();

    DeliveryDrone *drone =
        dynamic_cast<DeliveryDrone*>(ptr);

    if (drone != nullptr) {
        drone->displayFlightTelemetry();
    }

    delete ptr;

    return 0;
}
