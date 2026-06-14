// Planet.cpp
#include "Planet.h"
#include <iostream>
using namespace std;

// Default constructor
Planet::Planet() {
    name = "Unknown";
    fuelPrice = 0;
    cargoSellPrice = 0;
    cargoBuyPrice = 0;
    description = "A mysterious planet.";
}

// Parameterized constructor
Planet::Planet(string n, int fuelP, int sellP, int buyP, string desc) {
    name = n;
    fuelPrice = fuelP;
    cargoSellPrice = sellP;
    cargoBuyPrice = buyP;
    description = desc;
}

// Getters
string Planet::getName() { return name; }
int Planet::getFuelPrice() { return fuelPrice; }
int Planet::getCargoSellPrice() { return cargoSellPrice; }
int Planet::getCargoBuyPrice() { return cargoBuyPrice; }
string Planet::getDescription() { return description; }

// Actions
void Planet::showMarket() {
    cout << "\n====== " << name << " MARKET ======\n";
    cout << "Fuel Price:       " << fuelPrice << " credits\n";
    cout << "Buy Cargo (cost): " << cargoBuyPrice << " credits/unit\n";
    cout << "Sell Cargo (earn):" << cargoSellPrice << " credits/unit\n";
    cout << "================================\n";
}

void Planet::showDescription() {
    cout << "\n🪐 " << name << "\n";
    cout << description << "\n";
}