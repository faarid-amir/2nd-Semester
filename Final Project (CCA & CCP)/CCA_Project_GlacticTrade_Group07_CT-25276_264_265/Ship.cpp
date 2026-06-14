// Ship.cpp
#include "Ship.h"
#include <iostream>
using namespace std;

// ---- BASE CLASS ----
Ship::Ship(string n, int fuelCap, int cargoCap, int spd, int dur) {
    name = n;
    fuelCapacity = fuelCap;
    cargoCapacity = cargoCap;
    speed = spd;
    durability = dur;
}

string Ship::getName() { return name; }
int Ship::getFuelCapacity() { return fuelCapacity; }
int Ship::getCargoCapacity() { return cargoCapacity; }
int Ship::getSpeed() { return speed; }
int Ship::getDurability() { return durability; }
void Ship::setDurability(int d) { durability = d; }

void Ship::showStats() {
    cout << "\n====== SHIP STATS ======\n";
    cout << "Name:          " << name << "\n";
    cout << "Type:          " << getShipType() << "\n";
    cout << "Fuel Capacity: " << fuelCapacity << "\n";
    cout << "Cargo Capacity:" << cargoCapacity << "\n";
    cout << "Speed:         " << speed << "\n";
    cout << "Durability:    " << durability << "\n";
    cout << "========================\n";
}

int Ship::getTravelCost() {
    return 10;  // default cost
}

// ---- CARGOSHIP ----
CargoShip::CargoShip() 
    : Ship("Cargo Hauler", 100, 50, 3, 80) {}
//         name           fuel cargo spd dur

void CargoShip::showStats() {
    Ship::showStats();  // call base class showStats
    cout << "[Bonus: Extra cargo space!]\n";
}

string CargoShip::getShipType() { return "Cargo Ship"; }

int CargoShip::getTravelCost() {
    return 8;   // fuel efficient because it's built for long hauls
}

// ---- FIGHTERSHIP ----
FighterShip::FighterShip() 
    : Ship("Star Fighter", 80, 20, 8, 150) {}

void FighterShip::showStats() {
    Ship::showStats();
    cout << "[Bonus: High durability, survives pirate attacks!]\n";
}

string FighterShip::getShipType() { return "Fighter Ship"; }

int FighterShip::getTravelCost() {
    return 12;  // burns more fuel because of high speed
}

// ---- SMUGGLERSHIP ----
SmugglerShip::SmugglerShip() 
    : Ship("Shadow Runner", 90, 30, 6, 100) {}

void SmugglerShip::showStats() {
    Ship::showStats();
    cout << "[Bonus: Access to black market deals!]\n";
}

string SmugglerShip::getShipType() { return "Smuggler Ship"; }

int SmugglerShip::getTravelCost() {
    return 10;  // balanced
}