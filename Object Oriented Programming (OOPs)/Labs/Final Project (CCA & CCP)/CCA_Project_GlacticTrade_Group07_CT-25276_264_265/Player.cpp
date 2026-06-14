// Player.cpp
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string n) {
    name = n;
    credits = 1000;      // every player starts with 1000 credits
    fuel = 50;           // starting fuel
    cargoSpace = 10;     // can carry 10 units max
    currentCargo = 0;    // starts with empty cargo
}

// Getters
string Player::getName() { return name; }
int Player::getCredits() { return credits; }
int Player::getFuel() { return fuel; }
int Player::getCargoSpace() { return cargoSpace; }
int Player::getCurrentCargo() { return currentCargo; }

// Actions
void Player::addCredits(int amount) {
    credits += amount;
}

void Player::deductCredits(int amount) {
    credits -= amount;
}

void Player::addFuel(int amount) {
    fuel += amount;
}

void Player::consumeFuel(int amount) {
    fuel -= amount;
}

void Player::addCargo(int units) {
    currentCargo += units;
}

void Player::removeCargo(int units) {
    currentCargo -= units;
}

void Player::showStatus() {
    cout << "\n====== PLAYER STATUS ======\n";
    cout << "Name:         " << name << "\n";
    cout << "Credits:      " << credits << "\n";
    cout << "Fuel:         " << fuel << "\n";
    cout << "Cargo:        " << currentCargo << "/" << cargoSpace << " units\n";
    cout << "===========================\n";
}