// Ship.h
#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

// BASE CLASS
class Ship {
protected:                  // protected so child classes can access these
    string name;
    int fuelCapacity;       // max fuel the ship can hold
    int cargoCapacity;      // max cargo units
    int speed;              // affects travel fuel cost
    int durability;         // health of the ship

public:
    Ship(string n, int fuelCap, int cargoCap, int spd, int dur);

    // Getters
    string getName();
    int getFuelCapacity();
    int getCargoCapacity();
    int getSpeed();
    int getDurability();
    void setDurability(int d);

    // Virtual function — this is KEY for polymorphism
    virtual void showStats();
    virtual string getShipType() = 0;   // pure virtual — makes Ship an abstract class
    virtual int getTravelCost();         // fuel cost to travel, each ship calculates differently

    virtual ~Ship() {}  // virtual destructor (good practice)
};

// -----------------------------------------------

// CHILD CLASS 1 — CargoShip
class CargoShip : public Ship {
public:
    CargoShip();
    void showStats() override;
    string getShipType() override;
    int getTravelCost() override;
};

// -----------------------------------------------

// CHILD CLASS 2 — FighterShip
class FighterShip : public Ship {
public:
    FighterShip();
    void showStats() override;
    string getShipType() override;
    int getTravelCost() override;
};

// -----------------------------------------------

// CHILD CLASS 3 — SmugglerShip
class SmugglerShip : public Ship {
public:
    SmugglerShip();
    void showStats() override;
    string getShipType() override;
    int getTravelCost() override;
};

#endif