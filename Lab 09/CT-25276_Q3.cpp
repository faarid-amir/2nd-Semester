#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Vehicle {
protected:
    int carId;
    string brand;
    string model;

public:
    Vehicle(int id, string b, string m) {
        carId = id;
        brand = b;
        model = m;
    }

    virtual bool isAvailable() = 0; // Pure virtual function
    virtual void rent() = 0;        // Pure virtual function
    virtual void returnVehicle() = 0; // Pure virtual function

    void displayInfo() {
        cout << "Car ID: " << carId << " | Brand: " << brand << " | Model: " << model;
    }

    virtual ~Vehicle() {} // Virtual destructor
};

// Derived Class: Car
class Car : public Vehicle {
    bool available;

public:
    Car(int id, string b, string m) : Vehicle(id, b, m) {
        available = true; // Car is available by default
    }

    bool isAvailable() override {
        return available;
    }

    void rent() override {
        if (available) {
            available = false;
            cout << "Car rented successfully -> ";
            displayInfo();
            cout << endl;
        } else {
            cout << "Car not available -> ";
            displayInfo();
            cout << endl;
        }
    }

    void returnVehicle() override {
        available = true;
        cout << "Car returned successfully -> ";
        displayInfo();
        cout << endl;
    }
};

// Rental System Class
class RentalSystem {
public:
    void rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
        } else {
            cout << "Sorry, this vehicle is not available for rent!" << endl;
        }
    }

    void returnVehicle(Vehicle* v) {
        v->returnVehicle();
    }
};

// Customer Class
class Customer {
    string name;
    RentalSystem rs;

public:
    Customer(string n) {
        name = n;
    }

    void rentVehicle(Vehicle* v) {
        cout << "\n" << name << " is trying to rent a car..." << endl;
        rs.rentVehicle(v);
    }

    void returnVehicle(Vehicle* v) {
        cout << "\n" << name << " is returning a car..." << endl;
        rs.returnVehicle(v);
    }
};

// Main - Array of base class pointers with dynamic memory
int main() {
    // Array of base class pointers with dynamic memory allocation
    Vehicle* fleet[3];
    fleet[0] = new Car(101, "Toyota", "Corolla");
    fleet[1] = new Car(102, "Honda", "Civic");
    fleet[2] = new Car(103, "Audi", "r8");

    // Display all cars
    cout << "===== Available Cars in Fleet =====" << endl;
    for (int i = 0; i < 3; i++) {
        fleet[i]->displayInfo();
        cout << " | Status: " << (fleet[i]->isAvailable() ? "Available" : "Rented") << endl;
    }

    // Customers
    Customer c1("Ali");
    Customer c2("Faarid");

    // Rent operations
    c1.rentVehicle(fleet[0]); // Ali rents Toyota Corolla
    c2.rentVehicle(fleet[0]); // Sara tries to rent same car (not available)
    c2.rentVehicle(fleet[1]); // Sara rents Honda Civic

    // Return operations
    c1.returnVehicle(fleet[0]); // Ali returns Toyota Corolla
    c2.rentVehicle(fleet[0]);   // Sara rents it again

    // Display final status
    cout << "\n===== Final Fleet Status =====" << endl;
    for (int i = 0; i < 3; i++) {
        fleet[i]->displayInfo();
        cout << " | Status: " << (fleet[i]->isAvailable() ? "Available" : "Rented") << endl;
    }

    // Free dynamic memory
    for (int i = 0; i < 3; i++)
        delete fleet[i];

    return 0;
}