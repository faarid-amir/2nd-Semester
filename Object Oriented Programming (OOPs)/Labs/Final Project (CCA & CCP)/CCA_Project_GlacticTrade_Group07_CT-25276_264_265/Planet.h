// Planet.h
#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

class Planet {
private:
    string name;
    int fuelPrice;       // cost of fuel on this planet
    int cargoSellPrice;  // price player gets when selling cargo here
    int cargoBuyPrice;   // price player pays when buying cargo here
    string description;  // short flavour text for the planet

public:
    Planet();            // default constructor
    Planet(string n, int fuelP, int sellP, int buyP, string desc);  // parameterized constructor

    // Getters
    string getName();
    int getFuelPrice();
    int getCargoSellPrice();
    int getCargoBuyPrice();
    string getDescription();

    // Actions
    void showMarket();   // display planet market info
    void showDescription();
};

#endif