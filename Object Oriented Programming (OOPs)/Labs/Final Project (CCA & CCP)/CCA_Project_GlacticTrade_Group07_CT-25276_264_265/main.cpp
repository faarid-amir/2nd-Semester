// main.cpp
#include <iostream>
#include <string>
#include <limits>
#include "GameEngine.h"
#include "Exception.h"
using namespace std;

// -----------------------------------------------
// Template function — Requirement 2 (Templates)!
// This ensures any numeric input is valid
template <typename T>
T getValidInput(string prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();   // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard bad input
            cout << "❌ Invalid input! Please try again.\n";
        } else {
            return value;
        }
    }
}

// -----------------------------------------------
void showMainMenu() {
    cout << "\n==========================================\n";
    cout << "           GALACTIC TRADE 🚀              \n";
    cout << "==========================================\n";
    cout << "1. View Current Planet & Market\n";
    cout << "2. Buy Resource\n";
    cout << "3. Sell Resource\n";
    cout << "4. Travel to Another Planet\n";
    cout << "5. View Ship Stats\n";
    cout << "6. View Player Status\n";
    cout << "7. View Trade Log\n";
    cout << "8. Save Game\n";
    cout << "9. Quit\n";
    cout << "==========================================\n";
    cout << "Enter choice: ";
}

// -----------------------------------------------
int main() {
    // Get the one and only GameEngine instance
    // This is our Singleton pattern in action!
    GameEngine* engine = GameEngine::getInstance();

    // Start the game — handles new game / load game
    engine->startGame();

    bool running = true;

    // THE MAIN GAME LOOP
    while (running) {
        showMainMenu();

        int choice = getValidInput<int>("");  // template function used here!

        try {
            switch (choice) {
                case 1:
                    engine->showCurrentPlanet();
                    break;

                case 2:
                    engine->handleMarket();
                    break;

                case 3:
                    engine->handleMarket();
                    break;

                case 4:
                    engine->travel();
                    break;

                case 5:
                    engine->showShipStats();
                    break;

                case 6:
                    engine->showPlayerStatus();
                    break;

                case 7:
                    engine->showTradeLog();
                    break;

                case 8:
                    engine->saveGame();
                    cout << "✅ Game saved!\n";
                    break;

                case 9:
                    engine->saveAndQuit();
                    running = false;
                    break;

                default:
                    throw InvalidInputException();
            }
        }
        catch (InvalidInputException& e) {
            cout << "❌ " << e.what() << "\n";
        }
        catch (InsufficientFuelException& e) {
            cout << "❌ " << e.what() << "\n";
        }
        catch (GameException& e) {
            cout << "❌ " << e.what() << "\n";
        }
        catch (...) {
            cout << "❌ An unexpected error occurred! Please try again.\n";
        }
    }

    return 0;
}