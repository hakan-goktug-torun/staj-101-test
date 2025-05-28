#include "crossthebeltevent.h"
#include "../ui/uimanager.h"

void crossTheBeltEvent::manageEvents(std::shared_ptr<Ship> ship) {
    UIManager::get().asteroidFieldDetected();

    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        UIManager::get().asteroidEscape();
    } else {
        int damage = ship->getAsDamage();
        ship->takeDamage(damage);
        UIManager::get().asteroidDamage(damage);
        UIManager::get().printStatus(ship);
    }
}

