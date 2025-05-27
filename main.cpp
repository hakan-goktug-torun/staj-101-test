#include <iostream>
#include <ctime>
#include <windows.h>
#include "system/uimanager.h"
#include "system/playerinterface.h"
#include "system/gameengine.h"
#include "system/scoreservice.h"

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned>(time(nullptr)));

    UIManager::promptLanguage();
    std::string langChoice;
    std::cin >> langChoice;
    if (langChoice == "tr") UIManager::lang = Language::TR;
    else UIManager::lang = Language::EN;

    std::string shipTypeStr;
    std::shared_ptr<Ship> ship = PlayerInterface::loadOrCreateShip(shipTypeStr);
    if (!ship) return 0;

    GameEngine engine;
    int gameResult = engine.start(ship); // 1 = normal bitis, 0 = yakit bitti, -1 = kullanici cikti

    if (gameResult == -1) return 0; // Kullanıcı "h" dedi, skor vs. yok

    if (gameResult == 0) {
        if (ship->getFuel() > 0 && ship->getHealth() > 0) {
            if (PlayerInterface::askToSaveGame()) {
                ScoreService::saveGame(ship, shipTypeStr);
            }

            int finalScore = ScoreService::calculate(ship);
            UIManager::promptName();
            std::string playerName;
            std::cin >> playerName;
            ScoreService::saveToFile(playerName, finalScore);
            UIManager::printCongratulations(finalScore);
            ScoreService::displayTop5();
        }
        return 0;
    }

    int finalScore = ScoreService::calculate(ship);

    if (ship->getFuel() > 0 && ship->getHealth() > 0) {
        if (PlayerInterface::askToSaveGame()) {
            ScoreService::saveGame(ship, shipTypeStr);
        }

        UIManager::promptName();
        std::string playerName;
        std::cin >> playerName;
        ScoreService::saveToFile(playerName, finalScore);
        UIManager::printCongratulations(finalScore);
        ScoreService::displayTop5();
    }

    return 0;
}