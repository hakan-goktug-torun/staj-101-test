#include "playerinterface.h"
#include "../services/shipfactory.h"
#include "../services/scoreservice.h"
#include "../ui/uimanager.h"
#include <iostream>

std::shared_ptr<Ship> PlayerInterface::promptForShip(std::string& outType) {
    std::string choice;
    while (true) {
        std::cin >> choice;
        ShipType type = ShipFactory::getShipTypeFromString(choice);
        auto ship = ShipFactory::createShip(type);
        if (ship) {
            if (choice == "s" || choice == "g") outType = "Strong";
            else if (choice == "f" || choice == "h") outType = "Fast";
            else if (choice == "n") outType = "Normal";
            return ship;
        }
        UIManager::invalidInput();
        UIManager::chooseShipPrompt();
    }
}

std::shared_ptr<Ship> PlayerInterface::loadOrCreateShip(std::string& outType) {
    UIManager::printWelcomeMenu();

    int menuChoice;
    std::cin >> menuChoice;

    if (menuChoice == 2) {
        auto [type, fuel, health, balance] = ScoreService::loadGame();
        if (type == "") return nullptr;
        outType = type;
        return ShipFactory::createShipFromSave(type, fuel, health, balance);
    } else {
        UIManager::chooseShipPrompt();
        return promptForShip(outType);
    }
}

std::string PlayerInterface::askPlayerName() {
    std::string name;
    UIManager::promptName();
    std::cin >> name;
    return name;
}

bool PlayerInterface::askToSaveGame() {
    std::string saveChoice;
    UIManager::askToSave();
    std::cin >> saveChoice;
    return saveChoice == "y" || saveChoice == "Y" || saveChoice == "e" || saveChoice == "E";
}
