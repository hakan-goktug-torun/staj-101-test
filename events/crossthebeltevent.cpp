#include "crossthebeltevent.h"
#include "../ui/uimanager.h"

void crossTheBeltEvent::manageEvents(std::shared_ptr<Ship> ship) {
    UIManager::asteroidFieldDetected();

    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        UIManager::asteroidEscape();
    } else {
        int damage = ship->getAsDamage();
        ship->takeDamage(damage);
        UIManager::asteroidDamage(damage);
        UIManager::printStatus(ship);
    }
}
