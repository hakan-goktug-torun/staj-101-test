#include <iostream>
#include <ctime>
#include "shipfactory.h"
#include "gameengine.h"
#include "scoreservice.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::string choice;
    std::shared_ptr<Ship> ship;

    std::cout << "Welcome to the Space Game!\n";
    std::cout << "Choose your ship type:\n";
    std::cout << "  (s) Strong Ship\n";
    std::cout << "  (f) Fast Ship\n";
    std::cout << "  (n) Normal Ship\n> ";

    while (true) {
        std::cin >> choice;
        ship = ShipFactory::createShip(choice);
        if (ship) break;
        std::cout << "Invalid choice. Try again (s/f/n): ";
    }

    GameEngine engine;
    engine.start(ship);

    std::string playerName;
    std::cout << "\nPlease enter your name for the scoreboard: ";
    std::cin >> playerName;

    int finalScore = ScoreService::calculate(ship);
    ScoreService::display(finalScore);
    ScoreService::saveToFile(playerName, finalScore);

    return 0;
}

// (./spacegame.exe) oyunu başlatma komutu 



