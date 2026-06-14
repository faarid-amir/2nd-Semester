// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    int credits;
    int fuel;
    int cargoSpace;      // how many cargo units player can carry
    int currentCargo;    // how many units player is currently carrying

public:
    Player(string n);    // constructor

    // Getters
    string getName();
    int getCredits();
    int getFuel();
    int getCargoSpace();
    int getCurrentCargo();

    // Actions
    void addCredits(int amount);
    void deductCredits(int amount);
    void addFuel(int amount);
    void consumeFuel(int amount);
    void addCargo(int units);
    void removeCargo(int units);

    void showStatus();   // display player info
};

#endif