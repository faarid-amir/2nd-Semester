#include <iostream>
using namespace std;

class Vehicle
{
private:
    string type;
    string make;
    string model;
    string color;
    int year;
    double milesDriven;

public:
    Vehicle(string type, string make, string model,
            string color, int year, double miles)
        : type(type), make(make), model(model),
          color(color), year(year), milesDriven(miles) {}

    string getType() const
    {
        return type;
    }
    string getMake() const
    {
        return make;
    }
    string getModel() const
    {
        return model;
    }
    string getColor() const
    {
        return color;
    }
    int getYear() const
    {
        return year;
    }
    double getMilesDriven() const
    {
        return milesDriven;
    }

    virtual void display() const
    {
        cout << "Type: " << type
             << " | Make: " << make
             << " | Model: " << model
             << " | Color: " << color
             << " | Year: " << year
             << " | Miles: " << milesDriven << "\n";
    }

    virtual ~Vehicle() {}
};

class GasVehicle : public Vehicle
{
private:
    double fuelTankSize;

public:
    GasVehicle(string type, string make, string model, string color,
               int year, double miles, double tankSize)
        : Vehicle(type, make, model, color, year, miles),
          fuelTankSize(tankSize) {}

    double getFuelTankSize() const
    {
        return fuelTankSize;
    }

    void display() const override
    {
        Vehicle::display();
        cout << "  Fuel Tank: " << fuelTankSize << "L\n";
    }
};

class ElectricVehicle : public Vehicle
{
private:
    double energyStorage;

public:
    ElectricVehicle(string type, string make, string model, string color,
                    int year, double miles, double energy)
        : Vehicle(type, make, model, color, year, miles),
          energyStorage(energy) {}

    double getEnergyStorage() const { return energyStorage; }

    void display() const override
    {
        Vehicle::display();
        cout << "  Battery: " << energyStorage << " kWh\n";
    }
};

class HighPerformance : public GasVehicle
{
private:
    int horsePower;
    double topSpeed;

public:
    HighPerformance(string type, string make, string model, string color,
                    int year, double miles, double tankSize,
                    int hp, double topSpeed)
        : GasVehicle(type, make, model, color, year, miles, tankSize),
          horsePower(hp), topSpeed(topSpeed) {}

    int getHorsePower() const { return horsePower; }
    double getTopSpeed() const { return topSpeed; }

    void display() const override
    {
        GasVehicle::display();
        cout << "  HP: " << horsePower << " | Top Speed: " << topSpeed << " km/h\n";
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle
{
private:
    double maxWeight;
    int numberOfWheels;
    double length;

public:
    HeavyVehicle(string type, string make, string model, string color,
                 int year, double miles,
                 double tankSize, double energy,
                 double maxWeight, int wheels, double length)
        : GasVehicle(type, make, model, color, year, miles, tankSize),
          ElectricVehicle(type, make, model, color, year, miles, energy),
          maxWeight(maxWeight), numberOfWheels(wheels), length(length) {}

    double getMaxWeight() const { return maxWeight; }
    int getNumberOfWheels() const { return numberOfWheels; }
    double getLength() const { return length; }

    void display() const override
    {
        GasVehicle::display();
        cout << "  Battery: " << ElectricVehicle::getEnergyStorage() << " kWh\n";
        cout << "  Max Weight: " << maxWeight << " tons"
             << " | Wheels: " << numberOfWheels
             << " | Length: " << length << " m\n";
    }
};

class SportsCar : public HighPerformance
{
public:
    string gearbox;
    string driveSystem;

public:
    SportsCar(string type, string make, string model, string color,
              int year, double miles, double tankSize,
              int hp, double topSpeed,
              string gearbox, string driveSystem)
        : HighPerformance(type, make, model, color, year, miles,
                          tankSize, hp, topSpeed),
          gearbox(gearbox), driveSystem(driveSystem) {}

    void display() const override
    {
        HighPerformance::display();
        cout << "  Gearbox: " << gearbox
             << " | Drive: " << driveSystem << "\n";
    }
};

class ConstructionTruck : public HeavyVehicle
{
public:
    string cargo; // cement, gravel, sand (public as per UML)

public:
    ConstructionTruck(string type, string make, string model, string color,
                      int year, double miles,
                      double tankSize, double energy,
                      double maxWeight, int wheels, double length,
                      string cargo)
        : HeavyVehicle(type, make, model, color, year, miles,
                       tankSize, energy, maxWeight, wheels, length),
          cargo(cargo) {}

    void display() const override
    {
        HeavyVehicle::display();
        cout << "  Cargo: " << cargo << "\n";
    }
};

class Bus : public HeavyVehicle
{
private:
    int numberOfSeats;

public:
    Bus(string type, string make, string model, string color,
        int year, double miles,
        double tankSize, double energy,
        double maxWeight, int wheels, double length,
        int seats)
        : HeavyVehicle(type, make, model, color, year, miles,
                       tankSize, energy, maxWeight, wheels, length),
          numberOfSeats(seats) {}

    int getNumberOfSeats() const { return numberOfSeats; }

    void display() const override
    {
        HeavyVehicle::display();
        cout << "  Seats: " << numberOfSeats << "\n";
    }
};

int main()
{

    cout << "========== Bus ==========\n";
    Bus bus(
        "Public Transit","Volvo","B8R",
        "Red", 2022, 45000.0, 200.0, 150.0, 18.0, 6, 12.5, 52);
    bus.display();

    cout << "\n========== Sports Car ==========\n";
    SportsCar car("Coupe", "Ferrari","F40", "Red", 2023, 5000.0, 90.0, 478, 324.0, "Manual",
         "Rear Wheel");
    car.display();

    cout << "========== Construction Truck ==========" << endl;
    ConstructionTruck truck( "Heavy Duty", "Caterpillar",  "CT660",  "Yellow",  2021,  80000.0, 
         400.0,  0.0, 30.0, 10,  9.0, "Gravel");
    truck.display();

    return 0;
}