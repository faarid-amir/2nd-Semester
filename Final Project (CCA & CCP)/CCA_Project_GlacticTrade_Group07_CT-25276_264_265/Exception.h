// Exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <exception>
using namespace std;

// BASE EXCEPTION CLASS
class GameException : public exception {
protected:
    string message;

public:
    GameException(string msg) {
        message = msg;
    }

    // override what() from std::exception
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// -----------------------------------------------

// When player doesn't have enough credits
class InsufficientCreditsException : public GameException {
public:
    InsufficientCreditsException(int required, int available)
        : GameException(
            "Not enough credits! Required: " + to_string(required) +
            " | Available: " + to_string(available)
          ) {}
};

// -----------------------------------------------

// When player doesn't have enough fuel
class InsufficientFuelException : public GameException {
public:
    InsufficientFuelException(int required, int available)
        : GameException(
            "Not enough fuel! Required: " + to_string(required) +
            " | Available: " + to_string(available)
          ) {}
};

// -----------------------------------------------

// When player doesn't have enough cargo space
class CargoFullException : public GameException {
public:
    CargoFullException(int available)
        : GameException(
            "Cargo hold is full! Available space: " + to_string(available) + " units"
          ) {}
};

// -----------------------------------------------

// When resource is not found in market
class ResourceNotFoundException : public GameException {
public:
    ResourceNotFoundException(string resourceName)
        : GameException(
            "Resource not found in market: " + resourceName
          ) {}
};

// -----------------------------------------------

// When player enters invalid input
class InvalidInputException : public GameException {
public:
    InvalidInputException()
        : GameException("Invalid input! Please enter a valid option.") {}
};

#endif