// Event.h
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Player.h"
#include "Market.h"
using namespace std;

// ABSTRACT BASE CLASS
class Event {
protected:
    string name;
    string description;

public:
    Event(string n, string desc);

    string getName();
    string getDescription();

    // Pure virtual — every event MUST implement this
    virtual void trigger(Player& player, Market& market) = 0;
    virtual void showEvent() = 0;

    virtual ~Event() {}
};

// -----------------------------------------------

// CHILD CLASS 1 — Pirate Attack
class PirateAttack : public Event {
private:
    int stealAmount;     // how many credits pirates steal

public:
    PirateAttack();
    void trigger(Player& player, Market& market) override;
    void showEvent() override;
};

// -----------------------------------------------

// CHILD CLASS 2 — Market Crash
class MarketCrash : public Event {
private:
    int crashPercent;    // how much prices drop (as a percentage)

public:
    MarketCrash();
    void trigger(Player& player, Market& market) override;
    void showEvent() override;
};

// -----------------------------------------------

// CHILD CLASS 3 — Resource Boom
class ResourceBoom : public Event {
private:
    int boomPercent;     // how much prices rise (as a percentage)

public:
    ResourceBoom();
    void trigger(Player& player, Market& market) override;
    void showEvent() override;
};

#endif