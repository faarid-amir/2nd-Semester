// GameEngine.cpp
#include "GameEngine.h"
#include "Event.h"
#include "Exception.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Initialize static instance to nullptr
GameEngine* GameEngine::instance = nullptr;

// -----------------------------------------------
// SINGLETON — getInstance()
GameEngine* GameEngine::getInstance() {
    if (instance == nullptr) {
        instance = new GameEngine();   // only created ONCE
    }
    return instance;   // always returns the same instance
}

// -----------------------------------------------
// Private constructor
GameEngine::GameEngine() {
    srand(time(0));
    player = nullptr;
    currentShip = nullptr;
    currentPlanetIndex = 0;
    initializePlanets();
}

// -----------------------------------------------
void GameEngine::initializePlanets() {
    planets.push_back(Planet("Mars",    10, 40, 20, "A rusty red planet, rich in Iron."));
    planets.push_back(Planet("Jupiter", 20, 80, 50, "A gas giant with rare Spice deposits."));
    planets.push_back(Planet("Saturn",  15, 60, 35, "Famous for its Gem mines."));
    planets.push_back(Planet("Neptune", 25, 90, 60, "A frozen world with expensive Food."));
    planets.push_back(Planet("Kepler",  30, 120, 80, "A distant planet with exotic resources."));

    for (auto& planet : planets) {
        markets.push_back(Market(planet.getName()));
    }
}

// -----------------------------------------------
void GameEngine::handleShipSelection() {
    cout << "\n====== CHOOSE YOUR SHIP ======\n";
    cout << "1. Cargo Hauler  (High cargo, fuel efficient, low durability)\n";
    cout << "2. Star Fighter  (Low cargo, high durability, fast)\n";
    cout << "3. Shadow Runner (Balanced, black market access)\n";
    cout << "==============================\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (currentShip != nullptr) delete currentShip;

    if (choice == 1)      currentShip = new CargoShip();
    else if (choice == 2) currentShip = new FighterShip();
    else                  currentShip = new SmugglerShip();

    cout << "\n🚀 " << currentShip->getShipType() << " selected!\n";
    currentShip->showStats();
}

// -----------------------------------------------
void GameEngine::startGame() {
    cout << "==========================================\n";
    cout << "   WELCOME TO GALACTIC TRADE 🚀          \n";
    cout << "==========================================\n";

    if (gameSave.saveFileExists()) {
        cout << "\nSave file found! Load previous game? (1=Yes, 2=No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            player = new Player("temp");
            gameSave.loadGame(*player);
            handleShipSelection();
            return;
        }
    }

    cout << "\nEnter your trader name: ";
    string name;
    cin >> name;

    player = new Player(name);
    handleShipSelection();

    cout << "\nWelcome, " << name << "! Your journey begins on Mars.\n";
    cout << "Buy low, sell high, and survive the galaxy!\n";
}

// -----------------------------------------------
void GameEngine::showCurrentPlanet() {
    Planet& current = planets[currentPlanetIndex];
    current.showDescription();
    markets[currentPlanetIndex].showMarket();
}

// -----------------------------------------------
void GameEngine::travel() {
    cout << "\n====== TRAVEL ======\n";
    cout << "Available planets:\n";

    for (int i = 0; i < planets.size(); i++) {
        if (i != currentPlanetIndex) {
            cout << i + 1 << ". " << planets[i].getName() << "\n";
        }
    }

    cout << "Enter planet number: ";
    int choice;
    cin >> choice;
    choice--;   // adjust for 0-based index

    if (choice < 0 || choice >= (int)planets.size() || choice == currentPlanetIndex) {
        throw InvalidInputException();
    }

    int travelCost = currentShip->getTravelCost();

    if (player->getFuel() < travelCost) {
        throw InsufficientFuelException(travelCost, player->getFuel());
    }

    player->consumeFuel(travelCost);
    currentPlanetIndex = choice;

    cout << "🚀 Travelling to " << planets[currentPlanetIndex].getName() << "...\n";

    triggerRandomEvent();
}

// -----------------------------------------------
void GameEngine::triggerRandomEvent() {
    int chance = rand() % 100;

    if (chance < 30) {
        int eventType = rand() % 3;
        Event* event = nullptr;

        if (eventType == 0)      event = new PirateAttack();
        else if (eventType == 1) event = new MarketCrash();
        else                     event = new ResourceBoom();

        event->trigger(*player, markets[currentPlanetIndex]);
        delete event;
    }
}

// -----------------------------------------------
void GameEngine::handleMarket() {
    int choice;
    cout << "\n====== MARKET OPTIONS ======\n";
    cout << "1. Buy Resource\n";
    cout << "2. Sell Resource\n";
    cout << "3. Back\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 3) return;

    cout << "Enter resource name: ";
    string resource;
    cin.ignore();
    getline(cin, resource);
    cout << "Enter units: ";
    int units;
    cin >> units;

    try {
        if (choice == 1) {
            markets[currentPlanetIndex].buyResource(*player, resource, units);
            gameSave.logTrade(
                "Bought " + to_string(units) + " units of " + resource +
                " on " + planets[currentPlanetIndex].getName()
            );
        }
        else if (choice == 2) {
            markets[currentPlanetIndex].sellResource(*player, resource, units);
            gameSave.logTrade(
                "Sold " + to_string(units) + " units of " + resource +
                " on " + planets[currentPlanetIndex].getName()
            );
        }
    }
    catch (GameException& e) {
        cout << "❌ " << e.what() << "\n";
    }
}

// -----------------------------------------------
void GameEngine::showShipStats() {
    if (currentShip != nullptr) {
        currentShip->showStats();
    } else {
        cout << "❌ No ship selected!\n";
    }
}

// -----------------------------------------------
void GameEngine::showPlayerStatus() {
    if (player != nullptr) {
        player->showStatus();
    } else {
        cout << "❌ No player found!\n";
    }
}

// -----------------------------------------------
void GameEngine::showTradeLog() {
    gameSave.showTradeLog();
}

// -----------------------------------------------
void GameEngine::saveGame() {
    gameSave.saveGame(*player);
}

// -----------------------------------------------
void GameEngine::saveAndQuit() {
    gameSave.saveGame(*player);
    cout << "\nThanks for playing GalacticTrade! See you among the stars 🚀\n";
}

// -----------------------------------------------
GameEngine::~GameEngine() {
    delete player;
    delete currentShip;
    instance = nullptr;
}