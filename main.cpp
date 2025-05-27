#include <iostream>
#include <ctime>
#include "playerinterface.h"
#include "gameengine.h"
#include "scoreservice.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::string shipTypeStr;
    std::shared_ptr<Ship> ship = PlayerInterface::loadOrCreateShip(shipTypeStr);
    if (!ship) return 0;

    GameEngine engine;
    bool eligibleToSave = engine.start(ship);

    if (eligibleToSave && ship->getFuel() > 0 && ship->getHealth() > 0) {
        if (PlayerInterface::askToSaveGame()) {
            ScoreService::saveGame(ship, shipTypeStr);
        }
    }

    std::string playerName = PlayerInterface::askPlayerName();
    int finalScore = ScoreService::calculate(ship);
    ScoreService::saveToFile(playerName, finalScore);
    ScoreService::displayTop5();

    return 0;
}


// (./spacegame.exe) oyunu başlatma komutu



