#include <iostream>
#include <ctime>
#include <windows.h>
#include "../ui/uimanager.h"
#include "playerinterface.h"
#include "gameengine.h"
#include "../services/scoreservice.h"

void handleEndOfGame(const std::shared_ptr<Ship>& ship, const std::string& shipTypeStr) {
    if (ship->getFuel() > 0 && ship->getHealth() > 0) {
        if (PlayerInterface::askToSaveGame()) {
            ScoreService::saveGame(ship, shipTypeStr);
        }

        UIManager::promptName();
        std::string playerName;
        std::getline(std::cin, playerName);

        int finalScore = ScoreService::calculate(ship);
        ScoreService::saveToFile(playerName, finalScore);
        UIManager::printCongratulations(finalScore);
        ScoreService::displayTop5();
    }
}

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned>(time(nullptr)));

    UIManager::promptLanguage();
    std::string langChoice;
    std::getline(std::cin, langChoice);
    UIManager::lang = UIManager::parseLanguageInput(langChoice);

    std::string shipTypeStr;
    std::shared_ptr<Ship> ship = PlayerInterface::loadOrCreateShip(shipTypeStr);
    if (!ship) return 0;

    GameEngine engine;
    int gameResult = engine.start(ship); // 1 = normal bitiş, 0 = yakıt bitti, -1 = kullanıcı çıkışı

    if (gameResult == -1) return 0;

    handleEndOfGame(ship, shipTypeStr);

    return 0;
}


