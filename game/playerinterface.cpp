#include "playerinterface.h"
#include "../services/shipfactory.h"
#include "../services/scoreservice.h"
#include "../ui/uimanager.h"
#include <iostream>
#include <sstream>
#include <algorithm>  // transform

std::shared_ptr<Ship> PlayerInterface::promptForShip(std::string& outType) {
    std::string choice;
    while (true) {
        std::getline(std::cin, choice);

        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        ShipType type = ShipFactory::StringToShipType(choice);
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

    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int menuChoice = 0;
    ss >> menuChoice;

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
    std::getline(std::cin, name);

    while (name.empty()) {
        UIManager::invalidInput();
        UIManager::promptName();
        std::getline(std::cin, name);
    }
    return name;
}

bool PlayerInterface::askToSaveGame() {
    std::string saveChoice;
    UIManager::askToSave();
    std::getline(std::cin, saveChoice);

    std::transform(saveChoice.begin(), saveChoice.end(), saveChoice.begin(), ::tolower);
    return saveChoice == "y" || saveChoice == "e";
}
