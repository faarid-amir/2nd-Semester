// GameEngine.h
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include "Player.h"
#include "Planet.h"
#include "Market.h"
#include "Ship.h"
#include "GameSave.h"
using namespace std;

class GameEngine {
private:
    // SINGLETON — private constructor
    GameEngine();

    // The one and only instance
    static GameEngine* instance;

    // Game data
    Player* player;
    Ship* currentShip;
    vector<Planet> planets;
    vector<Market> markets;
    int currentPlanetIndex;
    GameSave gameSave;

    // Private helper functions
    void initializePlanets();
    void triggerRandomEvent();

public:
    // SINGLETON — only way to get the GameEngine
    static GameEngine* getInstance();

    // Delete copy constructor and assignment
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

    // Core game functions
    void startGame();
    void travel();
    void showCurrentPlanet();
    void handleMarket();
    void handleShipSelection();
    void saveAndQuit();

    // Added functions
    void showShipStats();
    void showPlayerStatus();
    void showTradeLog();
    void saveGame();

    // Destructor
    ~GameEngine();
};

#endif