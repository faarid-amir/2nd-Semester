// Market.cpp
#include "Market.h"
#include "Exception.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Market::Market(string pName) {
    planetName = pName;
    generatePrices();
}

void Market::generatePrices() {
    resourcePrices["Iron"]      = 20 + rand() % 30;
    resourcePrices["Spice"]     = 50 + rand() % 50;
    resourcePrices["Fuel Cell"] = 30 + rand() % 20;
    resourcePrices["Gems"]      = 80 + rand() % 70;
    resourcePrices["Food"]      = 10 + rand() % 15;

    resourceStock["Iron"]       = 10 + rand() % 20;
    resourceStock["Spice"]      = 5  + rand() % 10;
    resourceStock["Fuel Cell"]  = 8  + rand() % 12;
    resourceStock["Gems"]       = 3  + rand() % 8;
    resourceStock["Food"]       = 15 + rand() % 20;
}

void Market::showMarket() {
    cout << "\n====== " << planetName << " MARKET ======\n";
    cout << "Resource       Price     Stock\n";
    cout << "--------------------------------\n";

    for (auto& item : resourcePrices) {
        string resource = item.first;
        int price       = item.second;
        int stock       = resourceStock[resource];

        cout << resource << "\t\t" << price << " cr\t" << stock << " units\n";
    }
    cout << "================================\n";
}

void Market::adjustPrices(int percent) {
    for (auto& item : resourcePrices) {
        int change = item.second * percent / 100;
        item.second += change;

        if (item.second < 5) item.second = 5;
    }
}

void Market::buyResource(Player& player, string resource, int units) {
    if (resourcePrices.find(resource) == resourcePrices.end()) {
        throw ResourceNotFoundException(resource);
    }

    int totalCost = resourcePrices[resource] * units;
    int stock     = resourceStock[resource];

    if (units > stock) {
        throw GameException(
            "Not enough stock! Only " + to_string(stock) + " units available."
        );
    }

    if (player.getCredits() < totalCost) {
        throw InsufficientCreditsException(totalCost, player.getCredits());
    }

    if (player.getCurrentCargo() + units > player.getCargoSpace()) {
        throw CargoFullException(player.getCargoSpace() - player.getCurrentCargo());
    }

    player.deductCredits(totalCost);
    player.addCargo(units);
    resourceStock[resource] -= units;

    cout << "✅ Bought " << units << " units of " << resource;
    cout << " for " << totalCost << " credits!\n";
}

void Market::sellResource(Player& player, string resource, int units) {
    if (resourcePrices.find(resource) == resourcePrices.end()) {
        throw ResourceNotFoundException(resource);
    }

    if (player.getCurrentCargo() < units) {
        throw GameException(
            "You don't have " + to_string(units) + " units to sell!"
        );
    }

    int totalEarned = resourcePrices[resource] * units;

    player.addCredits(totalEarned);
    player.removeCargo(units);
    resourceStock[resource] += units;

    cout << "✅ Sold " << units << " units of " << resource;
    cout << " for " << totalEarned << " credits!\n";
}