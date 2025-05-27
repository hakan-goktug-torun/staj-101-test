#include "gameengine.h"
#include "eventmanager.h"
#include "scoreservice.h"
#include "../ships/ship.h"
#include <iostream>
#include <algorithm>

void GameEngine::printStatus(const std::shared_ptr<Ship>& ship) {
    std::cout << "\n=== Ship Status ===\n";
    std::cout << "Fuel: " << ship->getFuel() << "\n";
    std::cout << "Health: " << ship->getHealth() << "\n";
    std::cout << "Balance: " << ship->getBalance() << "\n";
    std::cout << "===================\n";
}

bool GameEngine::start(const std::shared_ptr<Ship>& ship) {
    EventManager eventManager;

    for (int i = 0; i < 5; ++i) {
        if (ship->getFuel() <= 1 && i != 0) {

            std::cout << "\nYour ship is out of fuel!\n";
            ScoreService::display(ScoreService::calculate(ship));
            return false;
        }

        eventManager.triggerRandomEvent(ship);
        printStatus(ship); // HER EVENTTEN SONRA DURUMU GÖSTER

        std::string answer;  
        while (true) {
            std::cout << "\nDo you want to continue? (y/n): ";
            std::cin >> answer;
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "y" || answer == "yes") break;
            if (answer == "n" || answer == "no") {
                std::cout << "\nThanks for playing!\n";
                ScoreService::display(ScoreService::calculate(ship));
                return true; // oyun kendi isteğiyle bitti, save yapılabilir
            }
            std::cout << "Invalid input. Please enter y or n.\n";
        }
    }

    ScoreService::display(ScoreService::calculate(ship));
    return true;
}