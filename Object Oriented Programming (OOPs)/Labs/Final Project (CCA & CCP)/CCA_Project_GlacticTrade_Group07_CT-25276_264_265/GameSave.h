// GameSave.h
#ifndef GAMESAVE_H
#define GAMESAVE_H

#include <string>
#include "Player.h"
using namespace std;

class GameSave {
private:
    string saveFile;     // where player progress is saved
    string tradeLog;     // where trade history is saved

public:
    GameSave();

    void saveGame(Player& player);           // save player progress to file
    bool loadGame(Player& player);           // load player progress from file
    void logTrade(string tradeDetails);      // append a trade entry to log
    void showTradeLog();                     // display entire trade history
    bool saveFileExists();                   // check if a save file exists
};

#endif