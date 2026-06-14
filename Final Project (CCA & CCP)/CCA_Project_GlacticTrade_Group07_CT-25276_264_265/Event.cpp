// Event.cpp
#include "Event.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// ---- BASE CLASS ----
Event::Event(string n, string desc) {
    name = n;
    description = desc;
}

string Event::getName() { return name; }
string Event::getDescription() { return description; }

// ---- PIRATE ATTACK ----
PirateAttack::PirateAttack()
    : Event("Pirate Attack!",
            "A band of space pirates has intercepted your ship!") {
    stealAmount = 50 + rand() % 150;   // pirates steal between 50-199 credits
}

void PirateAttack::showEvent() {
    cout << "\n⚠️  EVENT: " << name << "\n";
    cout << description << "\n";
    cout << "They are trying to steal " << stealAmount << " credits!\n";
}

void PirateAttack::trigger(Player& player, Market& market) {
    showEvent();

    if (player.getCredits() >= stealAmount) {
        player.deductCredits(stealAmount);
        cout << "💸 You lost " << stealAmount << " credits to the pirates!\n";
    } else {
        // player doesn't have enough — take whatever they have
        int taken = player.getCredits();
        player.deductCredits(taken);
        cout << "💸 Pirates took all your remaining " << taken << " credits!\n";
    }
}

// ---- MARKET CRASH ----
MarketCrash::MarketCrash()
    : Event("Market Crash!",
            "Economic instability has caused prices to plummet!") {
    crashPercent = 20 + rand() % 30;   // prices drop by 20-49%
}

void MarketCrash::showEvent() {
    cout << "\n⚠️  EVENT: " << name << "\n";
    cout << description << "\n";
    cout << "All prices have dropped by " << crashPercent << "%!\n";
}

void MarketCrash::trigger(Player& player, Market& market) {
    showEvent();
    market.adjustPrices(-crashPercent);   // negative = price drop
    cout << "📉 Market prices have been updated!\n";
}

// ---- RESOURCE BOOM ----
ResourceBoom::ResourceBoom()
    : Event("Resource Boom!",
            "A massive resource discovery has flooded the market!") {
    boomPercent = 20 + rand() % 40;   // prices rise by 20-59%
}

void ResourceBoom::showEvent() {
    cout << "\n🌟 EVENT: " << name << "\n";
    cout << description << "\n";
    cout << "All prices have risen by " << boomPercent << "%!\n";
}

void ResourceBoom::trigger(Player& player, Market& market) {
    showEvent();
    market.adjustPrices(boomPercent);   // positive = price rise
    cout << "📈 Market prices have been updated!\n";
}