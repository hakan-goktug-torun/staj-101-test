#include <iostream>
#include <ctime>
#include <windows.h>
#include "../ui/uimanager.h"
#include "../ui/uilang_tr.h"
#include "../ui/uilang_en.h"
#include "playerinterface.h"
#include "gameengine.h"
#include "../services/scoreservice.h"

void handleEndOfGame(const std::shared_ptr<Ship>& ship, const std::string& shipTypeStr, bool saveOnly) {
    if (PlayerInterface::askToSaveGame()) {
        ScoreService::saveGameJSON(ship, shipTypeStr);
    }

    int finalScore = ScoreService::calculate(ship);

    if (!saveOnly) {
        std::string playerName;
        UIManager::get().promptName();
        std::getline(std::cin, playerName);

        while (playerName.empty()) {
            UIManager::get().invalidInput();
            UIManager::get().promptName();
            std::getline(std::cin, playerName);
        }

        ScoreService::saveToFile(playerName, finalScore);
        UIManager::get().printCongratulations(finalScore);
        ScoreService::displayTop5();
    }

    UIManager::get().printThanks();
}

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned>(time(nullptr)));

    std::string langChoice;
    std::cout << "Select Language / Dil Seçin: (En/Tr): ";
    std::getline(std::cin, langChoice);
    std::transform(langChoice.begin(), langChoice.end(), langChoice.begin(), ::tolower);

    if (langChoice == "tr" || langChoice == "türkçe" || langChoice == "turkish") {
        UIManager::setLanguage(std::make_unique<UILangTR>());
    } else {
        UIManager::setLanguage(std::make_unique<UILangEN>());
    }

    std::string shipTypeStr;
    std::shared_ptr<Ship> ship = PlayerInterface::loadOrCreateShip(shipTypeStr);
    if (!ship) return 0;

    GameEngine engine;
    int gameResult = engine.start(ship); // 1 = tamamlandı, 0 = yakıt veya can bitti, -1 = oyuncu çıktı

    if (gameResult == -1 || gameResult == 0) {
        handleEndOfGame(ship, shipTypeStr, true);  // sadece kayıt, skor yok
        return 0;
    }

    handleEndOfGame(ship, shipTypeStr, false); // skor ve kayıt
    return 0;
}