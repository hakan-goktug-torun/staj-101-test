#include <iostream>
#include <ctime>
#include <windows.h>
#include "../ui/uimanager.h"
#include "playerinterface.h"
#include "gameengine.h"
#include "../services/scoreservice.h"

void handleEndOfGame(const std::shared_ptr<Ship>& ship, const std::string& shipTypeStr, bool saveOnly) {
    if (ship->getFuel() > 0 && ship->getHealth() > 0) {
        if (PlayerInterface::askToSaveGame()) {
            ScoreService::saveGameJSON(ship, shipTypeStr);
        }

        if (!saveOnly) {
            std::string playerName;
            UIManager::promptName();
            std::getline(std::cin, playerName);

            while (playerName.empty()) {
                UIManager::invalidInput();
                UIManager::promptName();
                std::getline(std::cin, playerName);
            }

            int finalScore = ScoreService::calculate(ship);
            ScoreService::saveToFile(playerName, finalScore);
            UIManager::printCongratulations(finalScore);
            ScoreService::displayTop5();
        }

        UIManager::printThanks();
    }
}

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned>(time(nullptr)));

    UIManager::promptLanguage();
    std::string langChoice;
    std::cin >> langChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    UIManager::lang = UIManager::parseLanguageInput(langChoice);

    std::string shipTypeStr;
    std::shared_ptr<Ship> ship = PlayerInterface::loadOrCreateShip(shipTypeStr);
    if (!ship) return 0;

    GameEngine engine;
    int gameResult = engine.start(ship); // 1 = tamamlandı, 0 = yakıt bitti, -1 = kullanıcı çıkışı

    if (gameResult == -1 || gameResult == 0) {
        handleEndOfGame(ship, shipTypeStr, true);  // sadece kayıt, skor yok
        return 0;
    }

    handleEndOfGame(ship, shipTypeStr, false); // skor ve kayıt
    return 0;
}
