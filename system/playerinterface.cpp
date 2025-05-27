#include "playerinterface.h"
#include "shipfactory.h"
#include "scoreservice.h"
#include <iostream>

std::shared_ptr<Ship> PlayerInterface::promptForShip(std::string& outType) {
    std::string choice;
    std::cout << "Choose your ship type:\n  (s) Strong Ship\n  (f) Fast Ship\n  (n) Normal Ship\n> ";
    while (true) {
        std::cin >> choice;
        ShipType type = ShipFactory::getShipTypeFromString(choice);
        auto ship = ShipFactory::createShip(type);
        if (ship) {
            if (choice == "s") outType = "Strong";
            else if (choice == "f") outType = "Fast";
            else if (choice == "n") outType = "Normal";
            return ship;
        }
        std::cout << "Invalid choice. Try again (s/f/n): ";
    }
}

std::shared_ptr<Ship> PlayerInterface::loadOrCreateShip(std::string& outType) {
    std::cout << "Welcome to the Space Game!\n";
    std::cout << "(1) Start New Game\n(2) Load Saved Game\n> ";
    int menuChoice;
    std::cin >> menuChoice;

    if (menuChoice == 2) {
        auto [type, fuel, health, balance] = ScoreService::loadGame();
        if (type == "") return nullptr;
        outType = type;
        return ShipFactory::createShipFromSave(type, fuel, health, balance);
    } else {
        return promptForShip(outType);
    }
}

std::string PlayerInterface::askPlayerName() {
    std::string name;
    std::cout << "\nPlease enter your name for the scoreboard: ";
    std::cin >> name;
    return name;
}

bool PlayerInterface::askToSaveGame() {
    std::string saveChoice;
    std::cout << "\nWould you like to save your game before exiting? (y/n): ";
    std::cin >> saveChoice;
    return saveChoice == "y" || saveChoice == "Y";
}
