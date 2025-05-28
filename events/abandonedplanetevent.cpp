#include "abandonedplanetevent.h"
#include "spacepiratesevent.h"
#include "../ui/uimanager.h"

void abandonedPlanetEvent::manageEvents(std::shared_ptr<Ship> ship) {
    UIManager::get().abandonedPlanetDiscovered();

    int random = rand() % 101;
    if (random >= 50) {
        ship->setBalance(ship->getBalance() + kCoinReward);
        UIManager::get().abandonedPlanetFoundCoins(kCoinReward);
    } else {
        UIManager::get().abandonedPlanetPirates();
        spacePiratesEvent pirates;
        pirates.manageEvents(ship);
    }
}
