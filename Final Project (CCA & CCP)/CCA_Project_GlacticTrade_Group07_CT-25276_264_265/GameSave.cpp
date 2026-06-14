// GameSave.cpp
#include "GameSave.h"
#include "Exception.h"
#include <iostream>
#include <fstream>        // this is what gives us file reading/writing!
#include <sstream>
using namespace std;

GameSave::GameSave() {
    saveFile = "savegame.txt";
    tradeLog = "tradelog.txt";
}

// -----------------------------------------------

void GameSave::saveGame(Player& player) {
    ofstream file(saveFile);   // ofstream = output file stream (writing)

    if (!file.is_open()) {
        throw GameException("Could not open save file for writing!");
    }

    // Write player data line by line
    file << player.getName()         << "\n";
    file << player.getCredits()      << "\n";
    file << player.getFuel()         << "\n";
    file << player.getCurrentCargo() << "\n";
    file << player.getCargoSpace()   << "\n";

    file.close();
    cout << "✅ Game saved successfully!\n";
}

// -----------------------------------------------

bool GameSave::loadGame(Player& player) {
    ifstream file(saveFile);   // ifstream = input file stream (reading)

    if (!file.is_open()) {
        return false;   // no save file found
    }

    string name;
    int credits, fuel, currentCargo, cargoSpace;

    // Read line by line — same order we saved!
    getline(file, name);
    file >> credits;
    file >> fuel;
    file >> currentCargo;
    file >> cargoSpace;

    file.close();

    // Update player with loaded data
    player = Player(name);
    player.addCredits(credits - player.getCredits());  // adjust to loaded amount
    player.addFuel(fuel - player.getFuel());
    player.addCargo(currentCargo);

    cout << "✅ Game loaded successfully! Welcome back, " << name << "!\n";
    return true;
}

// -----------------------------------------------

void GameSave::logTrade(string tradeDetails) {
    // app = append mode — adds to file without deleting old content
    ofstream file(tradeLog, ios::app);

    if (!file.is_open()) {
        throw GameException("Could not open trade log for writing!");
    }

    file << tradeDetails << "\n";
    file.close();
}

// -----------------------------------------------

void GameSave::showTradeLog() {
    ifstream file(tradeLog);

    if (!file.is_open()) {
        cout << "📋 No trade history found!\n";
        return;
    }

    cout << "\n====== TRADE LOG ======\n";

    string line;
    while (getline(file, line)) {   // read line by line until end of file
        cout << line << "\n";
    }

    cout << "=======================\n";
    file.close();
}

// -----------------------------------------------

bool GameSave::saveFileExists() {
    ifstream file(saveFile);
    return file.is_open();
}