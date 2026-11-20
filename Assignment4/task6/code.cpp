#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ======================================================
// ABSTRACT BASE CLASS
// ======================================================

class Vehicle
{
protected:
    std::string registration;
    double dailyRate;
    bool rented;

public:
    Vehicle(const std::string& reg,
            double rate)
        : registration(reg),
          dailyRate(rate),
          rented(false)
    {
    }

    virtual ~Vehicle() = default;

    virtual double charge(int days) const = 0;

    virtual std::string type() const = 0;

    virtual void printDetails() const = 0;

    bool rent()
    {
        if (rented)
        {
            return false;
        }

        rented = true;

        return true;
    }

    double returnVehicle(int daysUsed,
                         int allowedDays) 
    {
        if (!rented)
        {
            return 0.0;
        }

        rented = false;

        double amount =
            charge(daysUsed);

        if (daysUsed > allowedDays)
        {
            int lateDays =
                daysUsed - allowedDays;

            amount +=
                lateDays * 100.0;
        }

        return amount;
    }

    bool isRented() const
    {
        return rented;
    }

    const std::string& getRegistration() const
    {
        return registration;
    }
};

// ======================================================
// BICYCLE
// ======================================================

class Bicycle : public Vehicle
{
public:
    Bicycle(const std::string& reg,
            double rate)
        : Vehicle(reg, rate)
    {
    }

    double charge(int days) const override
    {
        return days * dailyRate;
    }

    std::string type() const override
    {
        return "Bicycle";
    }

    void printDetails() const override
    {
        std::cout
            << type()
            << " | Registration: "
            << registration
            << " | Daily rate: Rs "
            << dailyRate
            << '\n';
    }
};

// ======================================================
// TWO-WHEELER
// ======================================================

class TwoWheeler : public Vehicle
{
private:
    double fuelLevel;

public:
    TwoWheeler(const std::string& reg,
               double rate,
               double fuel)
        : Vehicle(reg, rate),
          fuelLevel(fuel)
    {
    }

    double charge(int days) const override
    {
        return days * dailyRate +
               50.0;
    }

    std::string type() const override
    {
        return "Two-Wheeler";
    }

    void printDetails() const override
    {
        std::cout
            << type()
            << " | Registration: "
            << registration
            << " | Fuel: "
            << fuelLevel
            << " L"
            << " | Daily rate: Rs "
            << dailyRate
            << '\n';
    }
};

// ======================================================
// CAR
// ======================================================

class Car : public Vehicle
{
private:
    double fuelLevel;
    int seats;

public:
    Car(const std::string& reg,
        double rate,
        double fuel,
        int s)
        : Vehicle(reg, rate),
          fuelLevel(fuel),
          seats(s)
    {
    }

    double charge(int days) const override
    {
        return days * dailyRate +
               seats * 20.0;
    }

    std::string type() const override
    {
        return "Car";
    }

    void printDetails() const override
    {
        std::cout
            << type()
            << " | Registration: "
            << registration
            << " | Fuel: "
            << fuelLevel
            << " L"
            << " | Seats: "
            << seats
            << " | Daily rate: Rs "
            << dailyRate
            << '\n';
    }
};

// ======================================================
// ELECTRIC CAR
// ======================================================

class ElectricCar : public Vehicle
{
private:
    double batteryCapacity;
    double chargePerKwh;

public:
    ElectricCar(const std::string& reg,
                double rate,
                double battery,
                double kwhRate)
        : Vehicle(reg, rate),
          batteryCapacity(battery),
          chargePerKwh(kwhRate)
    {
    }

    double charge(int days) const override
    {
        return days * dailyRate +
               batteryCapacity *
               chargePerKwh;
    }

    std::string type() const override
    {
        return "Electric Car";
    }

    void printDetails() const override
    {
        std::cout
            << type()
            << " | Registration: "
            << registration
            << " | Battery: "
            << batteryCapacity
            << " kWh"
            << " | Daily rate: Rs "
            << dailyRate
            << '\n';
    }
};

// ======================================================
// NEW VEHICLE TYPE
// ElectricBus can be added without changing the
// existing Vehicle, Bicycle, TwoWheeler, Car or
// ElectricCar classes.
// ======================================================

class ElectricBus : public Vehicle
{
private:
    int seats;
    double batteryCapacity;

public:
    ElectricBus(const std::string& reg,
                double rate,
                int s,
                double battery)
        : Vehicle(reg, rate),
          seats(s),
          batteryCapacity(battery)
    {
    }

    double charge(int days) const override
    {
        return days * dailyRate +
               seats * 5.0 +
               batteryCapacity * 2.0;
    }

    std::string type() const override
    {
        return "Electric Bus";
    }

    void printDetails() const override
    {
        std::cout
            << type()
            << " | Registration: "
            << registration
            << " | Seats: "
            << seats
            << " | Battery: "
            << batteryCapacity
            << " kWh"
            << " | Daily rate: Rs "
            << dailyRate
            << '\n';
    }
};

// ======================================================
// RENTAL FLEET
// ======================================================

class Fleet
{
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    void add(std::unique_ptr<Vehicle> vehicle)
    {
        vehicles.push_back(
            std::move(vehicle));
    }

    Vehicle* find(
        const std::string& registration)
    {
        for (auto& vehicle : vehicles)
        {
            if (vehicle->getRegistration() ==
                registration)
            {
                return vehicle.get();
            }
        }

        return nullptr;
    }

    void list() const
    {
        std::cout
            << "\n===== VEHICLE FLEET =====\n";

        for (const auto& vehicle : vehicles)
        {
            vehicle->printDetails();

            std::cout
                << "Status: "
                << (vehicle->isRented()
                        ? "Rented"
                        : "Available")
                << "\n\n";
        }
    }
};

int main()
{
    std::cout
        << std::fixed
        << std::setprecision(2);

    Fleet fleet;

    // Add all required vehicle types
    fleet.add(
        std::make_unique<Bicycle>(
            "BIKE101",
            200
        )
    );

    fleet.add(
        std::make_unique<TwoWheeler>(
            "BIKE202",
            500,
            5.0
        )
    );

    fleet.add(
        std::make_unique<Car>(
            "CAR303",
            1500,
            30.0,
            5
        )
    );

    fleet.add(
        std::make_unique<ElectricCar>(
            "EV404",
            1800,
            60.0,
            10.0
        )
    );

    // New vehicle type
    fleet.add(
        std::make_unique<ElectricBus>(
            "BUS505",
            5000,
            40,
            300.0
        )
    );

    fleet.list();

    // ==============================================
    // Rent bicycle
    // ==============================================

    Vehicle* bike =
        fleet.find("BIKE101");

    if (bike != nullptr)
    {
        if (bike->rent())
        {
            std::cout
                << "\nBIKE101 rented successfully.\n";
        }
    }

    // Return after 3 days,
    // allowed period = 2 days
    if (bike != nullptr)
    {
        double bill =
            bike->returnVehicle(3, 2);

        std::cout
            << "BIKE101 return bill: Rs "
            << bill
            << '\n';
    }

    // ==============================================
    // Rent car
    // ==============================================

    Vehicle* car =
        fleet.find("CAR303");

    if (car != nullptr)
    {
        car->rent();

        double bill =
            car->returnVehicle(5, 5);

        std::cout
            << "CAR303 return bill: Rs "
            << bill
            << '\n';
    }

    // ==============================================
    // Rent electric car
    // ==============================================

    Vehicle* electricCar =
        fleet.find("EV404");

    if (electricCar != nullptr)
    {
        electricCar->rent();

        double bill =
            electricCar->returnVehicle(
                2,
                2
            );

        std::cout
            << "EV404 return bill: Rs "
            << bill
            << '\n';
    }

    // ==============================================
    // Rent electric bus
    // ==============================================

    Vehicle* bus =
        fleet.find("BUS505");

    if (bus != nullptr)
    {
        bus->rent();

        double bill =
            bus->returnVehicle(
                4,
                3
            );

        std::cout
            << "BUS505 return bill: Rs "
            << bill
            << '\n';
    }

    fleet.list();

    return 0;
}
