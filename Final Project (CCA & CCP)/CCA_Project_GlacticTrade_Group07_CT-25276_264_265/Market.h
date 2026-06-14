// Market.h
#ifndef MARKET_H
#define MARKET_H

#include <string>
#include <map>
#include "Player.h"
using namespace std;

class Market {
private:
    string planetName;
    map<string, int> resourcePrices;   // resource name → price per unit
    map<string, int> resourceStock;    // resource name → available stock

public:
    Market(string planetName);

    void generatePrices();             // randomly generate market prices
    void showMarket();                 // display all resources and prices
    void buyResource(Player& player, string resource, int units);
    void sellResource(Player& player, string resource, int units);
    void adjustPrices(int percent);    // increase or decrease all prices by a percentage
};

#endif