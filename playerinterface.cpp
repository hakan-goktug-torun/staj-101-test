#include "playerinterface.h"
#include "shipfactory.h"
#include "scoreservice.h"
#include <iostream>
#include <algorithm>

std::shared_ptr<Ship> PlayerInterface::selectShip() {
    std::string choice;
    std::shared_ptr<Ship> ship;

    std::cout << "Welcome to the Space Game!\n";
    std::cout << "Choose your ship type:\n";
    std::cout << "  (s) Strong Ship\n";
    std::cout << "  (f) Fast Ship\n";
    std::cout << "  (n) Normal Ship\n> ";

    while (true) {
        std::cin >> choice;
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        ShipType type = ShipFactory::getShipTypeFromString(choice);
        ship = ShipFactory::createShip(type);
        if (ship) break;
        std::cout << "Invalid choice. Try again (s/f/n): ";
    }

    return ship;
}

void PlayerInterface::askAndSaveScore(const std::shared_ptr<Ship>& ship) {
    std::string playerName;
    std::cout << "\nPlease enter your name for the scoreboard: ";
    std::cin >> playerName;

    int finalScore = ScoreService::calculate(ship);
    ScoreService::saveToFile(playerName, finalScore);
}
