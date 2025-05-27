#include "abandonedplanetevent.h"
#include "spacepiratesevent.h"
#include "../ui/uimanager.h"

void abandonedPlanetEvent::manageEvents(std::shared_ptr<Ship> ship) {
    UIManager::abandonedPlanetDiscovered();

    int random = rand() % 101;
    if (random >= 50) {
        ship->setBalance(ship->getBalance() + kCoinReward);
        UIManager::abandonedPlanetFoundCoins(kCoinReward);
    } else {
        UIManager::abandonedPlanetPirates();
        spacePiratesEvent pirates;
        pirates.manageEvents(ship);
    }
}
// fazlalık fonksiyonlar silindi