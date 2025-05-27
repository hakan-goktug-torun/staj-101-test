#include "gameengine.h"
#include "eventmanager.h"
#include "scoreservice.h"
#include "uimanager.h"
#include <iostream>
#include <algorithm>

int GameEngine::start(const std::shared_ptr<Ship>& ship) {
    EventManager eventManager;

    for (int i = 0; i < 5; ++i) {
        eventManager.triggerRandomEvent(ship);
        UIManager::printStatus(ship);

        if (ship->getFuel() <= 1) {
            UIManager::outOfFuel();
            return 0; // yakıt bitti
        }

        std::string answer;
        while (true) {
            UIManager::promptContinue();
            std::cin >> answer;
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "y" || answer == "yes" || answer == "evet" || answer == "e") break;
            if (answer == "n" || answer == "no" || answer == "hayır" || answer == "h") {
                UIManager::printThanks();
                return -1; // kullanıcı çıktı
            }
            UIManager::invalidInput();
        }
    }

    return 1; // normal bitis
}